/**
 * main_04071515.c : try to parse the message
 */

#include <stdio.h>
#include <unistd.h>
#include <gst/gst.h>

static GMainLoop *loop;

static gboolean mybusfunc(	GstBus *bus,
				GstMessage *message,
				gpointer user_data
			)
{
	GstState prev_state, curr_state;

	g_print("Got %s\n", GST_MESSAGE_TYPE_NAME(message));

	switch (GST_MESSAGE_TYPE(message)) {
		case GST_MESSAGE_UNKNOWN:
			break;
		case GST_MESSAGE_ERROR:
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

gboolean gsrcfunc(gpointer user_data)
{
	GstElement *pipeline = (GstElement *) user_data;
		
	gst_element_set_state(pipeline, GST_STATE_NULL);
	g_print("pipeline nulled...\n");
	g_main_loop_quit(loop);

	return G_SOURCE_REMOVE;
}

int main(int argc, char *argv[])
{
	GstElement	*source = NULL, *filter = NULL, *sink = NULL, *pipeline = NULL; 
	GstBus		*bus = NULL;
	guint bus_watch_id;

	printf("%s build : %s %s\n", argv[0], __DATE__, __TIME__);

	gst_init(&argc, &argv);

	printf("GStreamer version %d.%d\n", GST_VERSION_MAJOR, GST_VERSION_MINOR);

	pipeline = gst_pipeline_new(NULL);
	if (!pipeline) {
		g_print("Fail to new a pipeline\n");
		return -__LINE__;
	}

	bus = gst_pipeline_get_bus(GST_PIPELINE(pipeline));
	if (!bus) {
		g_print("Fail to new a bus\n");
		return -__LINE__;
	}

	bus_watch_id = gst_bus_add_watch(bus, mybusfunc, NULL);
	g_object_unref(bus);

	/* name of new element, or NULL to automatically create a unique name */
	source = gst_element_factory_make("fakesrc", NULL);
	filter = gst_element_factory_make("identity", NULL);
	sink = gst_element_factory_make("fakesink", NULL);
	if (!source || !filter || !sink) {
		g_print("Fail to create element\n");
		return -__LINE__;
	}

	gst_bin_add_many(GST_BIN(pipeline), source, filter, sink, NULL);
	if (!gst_element_link_many(source, filter, sink, NULL)) {
		g_print("Fail to chain elements\n");
	}

	if (GST_STATE_CHANGE_ASYNC == gst_element_set_state(pipeline, GST_STATE_PLAYING)) {
		g_print("pipeline started...\n");
	}

	g_timeout_add(5000 /* millisecond */, gsrcfunc, pipeline); 

	loop = g_main_loop_new(NULL, FALSE);
	g_main_loop_run(loop);

	g_source_remove(bus_watch_id);
	g_main_loop_unref(loop);

	gst_object_unref(pipeline);

	return 0;
}

