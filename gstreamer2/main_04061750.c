/**
 * main_04061750.c : a full graph with fake elements
 */

#include <stdio.h>
#include <unistd.h>
#include <gst/gst.h>

int main(int argc, char *argv[])
{
	GstElement *source = NULL, *filter = NULL, *sink = NULL, *pipeline = NULL;

	printf("%s build : %s %s\n", argv[0], __DATE__, __TIME__);

	gst_init(&argc, &argv);

	printf("GStreamer version %d.%d\n", GST_VERSION_MAJOR, GST_VERSION_MINOR);

	pipeline = gst_pipeline_new("test");
	if (!pipeline) {
		g_print("Fail to new a pipeline\n");
		return -__LINE__;
	}

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

	sleep(10);

	if (GST_STATE_CHANGE_ASYNC == gst_element_set_state(pipeline, GST_STATE_PAUSED)) {
		g_print("pipeline paused...\n");
	}
	return 0;
}

