/**
 * main_04081545.c : learn to use capability for metadata
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
	GstPad *tee_srcpad = NULL, *demux_snkpad = NULL;
	const GstCaps *caps = NULL;
	GstStructure *structure = NULL;
	guint idx = 0;
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
#if 1
	demux_snkpad = gst_element_get_static_pad(demux, "sink"); 
	ERROR_BIT_WR(err, demux_snkpad);
#endif

	tee = gst_element_factory_make("tee", NULL);
	ERROR_BIT_WR(err, tee);
#if 0	
	tee_srcpad = gst_element_get_request_pad(tee, "src_%u");
#else
	tee_srcpad = gst_element_get_compatible_pad(tee, demux_snkpad, NULL);
#endif
	ERROR_BIT_WR(err, tee_srcpad);

	caps = gst_pad_get_current_caps(tee_srcpad);
	structure = gst_caps_get_structure(caps, idx++);
	while (structure) {
		g_print("name: %s\n", gst_structure_get_name(structure));
		structure = gst_caps_get_structure(caps, idx++);
	}
	g_object_unref(GST_OBJECT(caps));

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

	if (!gst_element_link_pads(tee, NULL, demux, "sink")) {
		g_print("Fail to link pads\n");
		return -__LINE__;
	}

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
	g_object_unref(GST_OBJECT(demux_snkpad));
	g_object_unref(GST_OBJECT(tee_srcpad));
	gst_object_unref(pipeline);

	return 0;
}

