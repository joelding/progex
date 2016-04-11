/**
 * helloworld.c : a simple Ogg/Vorbis command-line audio player
 */

#include <stdio.h>
#include <gst/gst.h>


static gboolean mybusfunc(GstBus *bus, GstMessage *message, gpointer user_data)
{
	GMainLoop *loop = (GMainLoop *) user_data;
	GstState prev_state, curr_state;

	g_print("Got %s\n", GST_MESSAGE_TYPE_NAME(message));

	switch (GST_MESSAGE_TYPE(message)) {
		case GST_MESSAGE_EOS:
			break;
		case GST_MESSAGE_ERROR:
			gst_message_parse_error();
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

int main(int argc, char *argv[])
{
	GstElement	*source = NULL, 
			*demuxer = NULL,
			*decoder = NULL,
			*conv = NULL,
			*sink = NULL,
			*pipeline = NULL;
	GstBus		*bus = NULL;

	if (argc != 2) {
		g_print("Usage: %s <filename>\n", argv[0]);
		return -1;
	}

	printf("%s build : %s %s\n", argv[0], __DATE__, __TIME__);
	printf("GStreamer version %d.%d\n", GST_VERSION_MAJOR, GST_VERSION_MINOR);
	printf("GLib ersion %d.%d.%d\n", GLIB_MAJOR_VERSION, GLIB_MINOR_VERSION, GLIB_MICRO_VERSION);

	/* init */
	gst_init(&argc, &argv);

	/* create elements */
	source = gst_element_factory_make("filesrc", NULL);
	g_return_val_if_fail(source != NULL, -1);
	g_object_set(source, "location", argv[1], NULL);

	demuxer = gst_element_factory_make("oggdemuxer", NULL);
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
	watch = gst_bus_add_watch(bus, mybusfunc, NULL);
	g_object_unref(bus);
	
	/* put together a pipeline */
	gst_bin_add_many(GST_BIN(pipeline), source, demuxer, decoder, conv, sink, NULL);

	/* link */
	gst_element_link(source, demuxer);
	gst_element_link_many(demuxer, decoder, cov, sink, NULL);

	/* main loop */
	loop = g_main_loop_new(NULL, FALSE);
	g_main_loop_run(loop);

	return 0;
}
