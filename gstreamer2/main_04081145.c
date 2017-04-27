/**
 * main_04081145.c : learn to use on-request pads by name
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

int main(int argc, char *argv[])
{
	GstElement *source = NULL, *tee= NULL, *demux = NULL, *pipeline = NULL; 
	GstPad *pad = NULL;
	gchar *name = NULL;
	guint err = 0;

	printf("%s build : %s %s\n", argv[0], __DATE__, __TIME__);

	/* init */
	gst_init(&argc, &argv);

	printf("GStreamer version %d.%d\n", GST_VERSION_MAJOR, GST_VERSION_MINOR);
	printf("GLib ersion %d.%d.%d\n", GLIB_MAJOR_VERSION, GLIB_MINOR_VERSION, GLIB_MICRO_VERSION);

	/* create elements */
	pipeline = gst_pipeline_new(NULL);
	ERROR_BIT_WR(err, pipeline);

	source = gst_element_factory_make("filesrc", NULL);
	ERROR_BIT_WR(err, source);
	/* download sample clip from http://techslides.com/demos/sample-videos/small.ogv */
	g_object_set(source, "location", "/home/a003257/Videos/small.ogv", NULL);

	demux = gst_element_factory_make("oggdemux", NULL);
	ERROR_BIT_WR(err, demux);

	tee = gst_element_factory_make("tee", NULL);
	ERROR_BIT_WR(err, tee);
	
	pad = gst_element_get_request_pad(tee, "src_%u");
	ERROR_BIT_WR(err, pad);
	name = gst_pad_get_name(GST_OBJECT(pad));
	if (name) {
		g_print("A new pad %s was created: ", name);
	}
	switch (gst_pad_get_direction(pad)) {
		case GST_PAD_SRC:
			g_print("direction source\n");
			break;
		case GST_PAD_SINK:
			g_print("direction sink\n");
			break;
		case GST_PAD_UNKNOWN:
		default:
			g_print("direction unknown\n");
			break;
	}
	gst_element_release_request_pad(tee, pad);

	/* check the created elements */
	if (err) {
		g_print("Fail to create elements 0x%x\n", err);
		return -__LINE__;
	}

	/* put together a pipeline */
	gst_bin_add_many(GST_BIN(pipeline), source, tee, demux, NULL);

	if (!gst_element_link_pads(source, "src", tee, "sink")) {
		g_print("Fail to link pads\n");
		return -__LINE__;
	}

	if (!gst_element_link_pads(tee, name, demux, "sink")) {
		g_print("Fail to link pads\n");
		return -__LINE__;
	}

	g_free(name);

	if (GST_STATE_CHANGE_FAILURE == gst_element_set_state(pipeline, GST_STATE_PLAYING)) {
		g_print("Fail to change state\n");
		return -__LINE__;
	}

	/* finish the program itself */
	g_timeout_add(5000 /* millisecond */, gsrcfunc, pipeline); 

	loop = g_main_loop_new(NULL, FALSE);
	g_main_loop_run(loop);

	/* cleanup */
	g_main_loop_unref(loop);
	g_object_unref(GST_OBJECT(pad));
	gst_object_unref(pipeline);

	return 0;
}

