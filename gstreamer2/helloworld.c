/**
 * helloworld.c : a simple Ogg/Vorbis command-line audio player
 */

#include <stdio.h>
#include <gst/gst.h>


static gboolean mybusfunc(GstBus *bus, GstMessage *message, gpointer user_data)
{
	GMainLoop *loop = (GMainLoop *) user_data;
	GstState prev_state, curr_state;
	GError *err = NULL;
	gchar *debug_info = NULL;

	g_print("Got %s\n", GST_MESSAGE_TYPE_NAME(message));

	switch (GST_MESSAGE_TYPE(message)) {
		case GST_MESSAGE_EOS:
			g_print("End of stream\n");
			g_main_loop_quit(loop);
			break;

		case GST_MESSAGE_ERROR:
			gst_message_parse_error(message, &err, &debug_info);
			g_printerr("Error from element %s: %s\n", GST_OBJECT_NAME(message->src), err->message);
			g_printerr("Debugging info: %s\n", (debug_info) ? debug_info : "none");
			g_error_free(err);
			g_free(debug_info);
			g_main_loop_quit(loop);
			break;

		case GST_MESSAGE_STATE_CHANGED:
			gst_message_parse_state_changed(message, &prev_state, &curr_state, NULL);
			g_print("Element %s changed from %s to %s\n", 
				GST_OBJECT_NAME(message->src), 
				gst_element_state_get_name(prev_state),
				gst_element_state_get_name(curr_state));
			break;

		default:
			g_print("Unhandled messages");
			break;
	}

	g_print("\n");

	return TRUE;
}

static void on_pad_added(GstElement *element, GstPad *pad, gpointer data)
{
	GstElement *decoder = (GstElement *) data;
	GstPad *sinkpad = NULL;

	g_print("Dynamic pad created, linking demuxer/decoder\n");
	sinkpad = gst_element_get_static_pad(decoder, "sink");
	gst_pad_link(pad, sinkpad);
	gst_object_unref(sinkpad);	
}

int main(int argc, char *argv[])
{
	GstElement	*source = NULL, 
			*demuxer = NULL,
			*decoder = NULL,
			*conv = NULL,
			*sink = NULL,
			*pipeline = NULL;
	GstBus		*bus = NULL;
	guint		watchpt;
	GMainLoop 	*loop = NULL;

	if (argc != 2) {
		g_print("Usage: %s <filename>\n", argv[0]);
		return -1;
	}

	printf("%s build : %s %s\n", argv[0], __DATE__, __TIME__);
	printf("GStreamer version %d.%d\n", GST_VERSION_MAJOR, GST_VERSION_MINOR);
	printf("GLib ersion %d.%d.%d\n", GLIB_MAJOR_VERSION, GLIB_MINOR_VERSION, GLIB_MICRO_VERSION);

	/* init */
	gst_init(&argc, &argv);

	loop = g_main_loop_new(NULL, FALSE);

	/* create elements */
	source = gst_element_factory_make("filesrc", NULL);
	g_return_val_if_fail(source != NULL, -1);
	g_object_set(source, "location", argv[1], NULL);

	demuxer = gst_element_factory_make("oggdemux", NULL);
	g_return_val_if_fail(demuxer != NULL, -1);

	decoder = gst_element_factory_make("vorbisdec", NULL);
	g_return_val_if_fail(decoder != NULL, -1);

	conv = gst_element_factory_make("audioconvert", NULL);
	g_return_val_if_fail(conv != NULL, -1);

	sink = gst_element_factory_make("autoaudiosink", NULL);
	g_return_val_if_fail(sink != NULL, -1);

	pipeline = gst_pipeline_new(NULL);
	g_return_val_if_fail(pipeline != NULL, -1);
	bus = gst_pipeline_get_bus(GST_PIPELINE(pipeline));
	g_return_val_if_fail(bus != NULL, -1);
	watchpt = gst_bus_add_watch(bus, mybusfunc, loop);
	g_object_unref(bus);
	
	/* put together a pipeline */
	gst_bin_add_many(GST_BIN(pipeline), source, demuxer, decoder, conv, sink, NULL);

	/* link */
	gst_element_link(source, demuxer);
	gst_element_link_many(decoder, conv, sink, NULL);

	/* listen to activities of the demux */
	g_signal_connect(demuxer, "pad-added", G_CALLBACK(on_pad_added), decoder);

	if (GST_STATE_CHANGE_FAILURE == gst_element_set_state(pipeline, GST_STATE_PLAYING)) {
		g_print("Fail to change state\n");
		return -1;
	}

	/* start the main loop */
	g_print("Running...\n");
	g_main_loop_run(loop);

	/* the main loop terminates */
	g_print("Closing...\n");
	gst_element_set_state(pipeline, GST_STATE_NULL);

	/* cleanup */
	g_source_remove(watchpt);
	g_main_loop_unref(loop);
	gst_object_unref(pipeline);

	return 0;
}
