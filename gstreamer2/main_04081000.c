/**
 * main_04081000.c : test sometimes pads
 */

#include <stdio.h>
#include <unistd.h>
#include <gst/gst.h>

#define ERROR_BIT_WR(err, var) ((err) = ((err) << 1) | ((NULL == (var)) ? 1 : 0))

static GMainLoop *loop;

static gboolean gsrcfunc(gpointer user_data)
{
	GstElement *pipeline = (GstElement *) user_data;
		
	gst_element_set_state(pipeline, GST_STATE_NULL);
	g_print("pipeline nulled...\n");
	g_main_loop_quit(loop);

	return G_SOURCE_REMOVE;
}

static void gcallback(void)
{
	g_print("received a signal pad-added\n");
}

int main(int argc, char *argv[])
{
	GstElement	*source = NULL, *demux= NULL, *pipeline = NULL; 
	guint err = 0;

	printf("%s build : %s %s\n", argv[0], __DATE__, __TIME__);

	/* init */
	gst_init(&argc, &argv);

	printf("GStreamer version %d.%d\n", GST_VERSION_MAJOR, GST_VERSION_MINOR);
	printf("GLib ersion %d.%d.%d\n", GLIB_MAJOR_VERSION, GLIB_MINOR_VERSION, GLIB_MICRO_VERSION);

	/* create elements */
	pipeline = gst_pipeline_new(NULL);
//	err = (NULL == pipeline) ? 1 : 0;
	ERROR_BIT_WR(err, pipeline);
	source = gst_element_factory_make("filesrc", NULL);
//	err = (err << 1) | ((NULL == source) ? 1 : 0);
	ERROR_BIT_WR(err, source);
	/* download sample clip from http://techslides.com/demos/sample-videos/small.ogv */
	g_object_set(source, "location", "/home/a003257/Videos/small.ogv", NULL);
	demux = gst_element_factory_make("oggdemux", NULL);
//	err = (err << 1) | ((NULL == demux) ? 1 : 0);
	ERROR_BIT_WR(err, demux);

	/* check the created elements */
	if (err) {
		g_print("Fail to create elements 0x%x\n", err);
		return -__LINE__;
	}

	/* put together a pipeline */
	gst_bin_add_many(GST_BIN(pipeline), source, demux, NULL);
#if 0
	if (!gst_element_link_many(source, demux, NULL)) {
		g_print("Fail to link elements\n");
		return -__LINE__;
	}
#else
	if (!gst_element_link_pads(source, "src", demux, "sink")) {
		g_print("Fail to link pads\n");
		return -__LINE__;
	}
#endif

	if (GST_STATE_CHANGE_FAILURE == gst_element_set_state(pipeline, GST_STATE_PLAYING)) {
		g_print("Fail to change state\n");
		return -__LINE__;
	}


	/* listen to activities of the demux */
	g_signal_connect(demux, "pad-added", G_CALLBACK(gcallback), NULL);

	/* finish the program itself */
	g_timeout_add(5000 /* millisecond */, gsrcfunc, pipeline); 

	loop = g_main_loop_new(NULL, FALSE);
	g_main_loop_run(loop);

	/* cleanup */
	g_main_loop_unref(loop);
	gst_object_unref(pipeline);

	return 0;
}

