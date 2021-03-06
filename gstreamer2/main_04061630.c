/**
 * main_04061630.c : gst_object_get/set_name
 */

#include <stdio.h>
#include <gst/gst.h>

#define ALTERNATIVES

int main(int argc, char *argv[])
{
	GstElement *element = NULL;
#if defined(ALTERNATIVES) 
	GstElementFactory *factory = NULL;
#endif

	printf("%s build : %s %s\n", argv[0], __DATE__, __TIME__);

	gst_init(&argc, &argv);

	printf("GStreamer version %d.%d\n", GST_VERSION_MAJOR, GST_VERSION_MINOR);

	/* name of new element, or NULL to automatically create a unique name */
#if !defined(ALTERNATIVES) 
	g_print("way #1\n");
	element = gst_element_factory_make("fakesrc", NULL);
#else
	g_print("way #2\n");
	factory = gst_element_factory_find("fakesrc");	
	if (!factory) {
		g_print("Fail to find factory\n");
		return -2;
	}

	element = gst_element_factory_create(factory, NULL);
#endif
	if (!element) {
		g_print("Fail to create element of type fakesrc\n");
		return -1;
	}

	g_print("%s\n%s\n%s\n", gst_plugin_feature_get_name(GST_PLUGIN_FEATURE(factory)),
		gst_element_factory_get_metadata(factory, GST_ELEMENT_METADATA_KLASS),
		gst_element_factory_get_metadata(factory, GST_ELEMENT_METADATA_DESCRIPTION));

	gst_object_unref(element);

	return 0;
}

