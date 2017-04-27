/**
 * main_04011630.c : the very first GStreamer exercise - init and get version
 */

#include <stdio.h>
#include <gst/gst.h>

int main(int argc, char *argv[])
{
	guint major, minor, micro, nano;
	
	printf("%s build : %s %s\n", argv[0], __DATE__, __TIME__);

	//gst_init(&argc, &argv);
	gst_init(NULL, NULL);

	gst_version(&major, &minor, &micro, &nano);
	
	printf("GStreamer version %d.%d.%d.%d\n", major, minor, micro, nano);
	printf("GStreamer version %d.%d.%d.%d\n", GST_VERSION_MAJOR, GST_VERSION_MINOR, GST_VERSION_MICRO, GST_VERSION_NANO);
	
	return 0;
}

