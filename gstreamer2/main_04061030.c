/**
 * main_04061030.c	the very first GStreamer exercise - init and get version
 * 			run ./main_04061030 -h/-c test/-s/-o test to see results of g_option_context_parse
 */

#include <stdio.h>
#include <gst/gst.h>

gboolean callbackfunc(	const gchar *option_name,
			const gchar *value,
			gpointer data,
			GError **error	)
{
	g_print("--- %s ---\n", __func__);
	g_print("option_name = %s\n", option_name);
	g_print("value = %s\n", value);
	return TRUE;
}

int main(int argc, char *argv[])
{
	GOptionContext *ctx = NULL;
	gboolean silent;
	gchar *savefile;
	GOptionEntry entries[] = {
		{"silent", 's', 0, G_OPTION_ARG_NONE, &silent,
		"do not output status information", NULL},
		{"output", 'o', 0, G_OPTION_ARG_STRING, &savefile,
		"save xml representation of pipeline to FILE and exit", "FILE"},
		{"callback", 'c', 0, G_OPTION_ARG_CALLBACK, callbackfunc,
	      	"test a callback function", NULL}, 	
		{NULL}
	};
	GOptionGroup *grp;
	GError *err;

	printf("%s build : %s %s\n", argv[0], __DATE__, __TIME__);

	gst_init(&argc, &argv);

	if (gst_is_initialized()) {
		g_print("Is initialized\n");
	} else {
		g_print("Failed to initialized\n");
	}

	printf("GStreamer version %d.%d\n", GST_VERSION_MAJOR, GST_VERSION_MINOR);

	ctx = g_option_context_new("my application");
	g_option_context_add_main_entries(ctx, entries, NULL);
	grp = gst_init_get_option_group();
	g_option_context_add_group(ctx, grp);
	if (!g_option_context_parse(ctx, &argc, &argv, &err)) {
		g_print("Fail to init: %s\n", err->message);
		g_clear_error(&err);
	}

	g_option_context_free(ctx);

	gst_deinit();

	return 0;
}

