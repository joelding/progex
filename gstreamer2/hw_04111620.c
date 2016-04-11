/**
 * hw_04111620.c : getting metadata
 */

#include <stdio.h>
#include <gst/gst.h>

static void on_pad_added(GstElement *element, GstPad *pad, gpointer data)
{
	GstElement *fakesink = (GstElement *) data;
	GstPad *sinkpad = NULL;

	g_print("Dynamic pad created, linking decoder/sink\n");
	sinkpad = gst_element_get_static_pad(fakesink, "sink");

	if (!gst_pad_is_linked(sinkpad)) {
		if (GST_PAD_LINK_OK != gst_pad_link(pad, sinkpad)) {
			g_error("Fail to link pads\n");
		}
	}

	gst_object_unref(sinkpad);	
}

void print_one_tag(const GstTagList *list, const gchar *tag, gpointer user_data)
{
	int i, num;

	num = gst_tag_list_get_tag_size(list, tag);
	for (i = 0; i < num; ++i) {
		const GValue *val;

		val = gst_tag_list_get_value_index(list, tag, i);
		if (G_VALUE_HOLDS_STRING(val)) {
			g_print("%20s: %s\n", tag, g_value_get_string(val));
		} else if (G_VALUE_HOLDS_UINT(val)) {
			g_print("%20s: %u\n", tag, g_value_get_uint(val));
		} else if (G_VALUE_HOLDS_DOUBLE(val)) {
			g_print("%20s: %g\n", tag, g_value_get_double(val));
		} else if (G_VALUE_HOLDS_BOOLEAN(val)) {
			g_print("%20s: %s\n", tag, g_value_get_boolean(val) ? "true" : "false");
		} else if (GST_VALUE_HOLDS_BUFFER(val)) {
			GstBuffer *buf = gst_value_get_buffer(val);
			guint buf_size = gst_buffer_get_size(buf);
			g_print("%20s: buffer size %u\n", tag, buf_size);
		} else if (GST_VALUE_HOLDS_DATE_TIME(val)) {
			GstDateTime *dt = g_value_get_boxed(val);
			gchar *dt_str = gst_date_time_to_iso8601_string(dt);
			g_print("%20s: %s\n", tag, dt_str);
			g_free(dt_str);
		} else {
			g_print("%20s: tag of type %s\n", tag, G_VALUE_TYPE_NAME(val));
		}
	}
}

int main(int argc, char *argv[])
{
	GstElement	*decoder = NULL,
			*sink = NULL,
			*pipeline = NULL;
	GMainLoop 	*loop = NULL;
	gchar 		*uri = NULL;
	GstTagList	*list = NULL;
	GstMessage	*msg = NULL;
	GError		*err = NULL;

	if (argc != 2) {
		g_print("Usage: %s FILE or URI\n", argv[0]);
		return -1;
	}

	printf("%s build : %s %s\n", argv[0], __DATE__, __TIME__);
	printf("GStreamer version %d.%d\n", GST_VERSION_MAJOR, GST_VERSION_MINOR);
	printf("GLib ersion %d.%d.%d\n", GLIB_MAJOR_VERSION, GLIB_MINOR_VERSION, GLIB_MICRO_VERSION);

	/* init */
	gst_init(&argc, &argv);

	loop = g_main_loop_new(NULL, FALSE);

	/* create elements */
	if (gst_uri_is_valid(argv[1])) {
		g_print("Valid URI\n");
		uri = g_strdup(argv[1]);
	} else {
		g_print("Invalid URI\n");
		uri = gst_filename_to_uri(argv[1], NULL);
	}

	decoder = gst_element_factory_make("uridecodebin", NULL);
	g_return_val_if_fail(decoder != NULL, -1);
	g_object_set(decoder, "uri", uri, NULL);

	sink = gst_element_factory_make("fakesink", NULL);
	g_return_val_if_fail(sink != NULL, -1);

	pipeline = gst_pipeline_new(NULL);
	g_return_val_if_fail(pipeline != NULL, -1);

	/* put together a pipeline */
	gst_bin_add_many(GST_BIN(pipeline), decoder, sink, NULL);


	/* listen to activities of the demux */
	g_signal_connect(decoder, "pad-added", G_CALLBACK(on_pad_added), sink);

	if (GST_STATE_CHANGE_FAILURE == gst_element_set_state(pipeline, GST_STATE_PAUSED)) {
		g_print("Fail to change state\n");
		return -1;
	}

	while (TRUE) {
		msg = gst_bus_timed_pop_filtered(GST_ELEMENT_BUS(pipeline), GST_CLOCK_TIME_NONE,
			GST_MESSAGE_ASYNC_DONE | GST_MESSAGE_TAG | GST_MESSAGE_ERROR);

		if (GST_MESSAGE_TYPE(msg) != GST_MESSAGE_TAG) {
			break;
		}

		gst_message_parse_tag(msg, &list);
		g_print("Got tags from element %s:\n", GST_OBJECT_NAME(msg->src));
		gst_tag_list_foreach(list, print_one_tag, NULL);
		g_print("\n");
		gst_tag_list_unref(list);
		gst_message_unref(msg);
	}

	if (GST_MESSAGE_TYPE(msg) == GST_MESSAGE_ERROR) {
		gst_message_parse_error(msg, &err, NULL);
		g_printerr("Got error: %s\n", err->message);
		g_error_free(err);
	}

	/* start the main loop */
//	g_print("Running...\n");
//	g_main_loop_run(loop);

	/* the main loop terminates */
	g_print("Closing...\n");
	gst_element_set_state(pipeline, GST_STATE_NULL);

	/* cleanup */
	g_main_loop_unref(loop);
	gst_object_unref(pipeline);
	g_free(uri);

	return 0;
}
