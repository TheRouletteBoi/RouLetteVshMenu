#ifndef __WEBBROWSER_PLUGIN_H__
#define __WEBBROWSER_PLUGIN_H__
// Mysis webbrowser_plugin.h v0.1
typedef struct webbrowser_plugin_interface_t
{
	int (*PluginWakeup)(int);
	int (*PluginWakeupWithUrl)(const char *);
	int (*PluginWakeupWithUrlAndRestriction)(const char *, int);
	int (*Shutdown)(void);
	int (*SetMotionType)(int);
	int (*DoUnk5)(char *);
	int (*PluginWakeupWithUrlString)(int *);
	int (*PluginWakeupWithSearchString)(int *);
	int (*PluginWakeupWithUrlAndExitHandler)(const char *, void *);
	int (*DoUnk9)(const char *, const char *);
	int (*UpdatePointerDisplayPos)(int, int, int);
} webbrowser_plugin_interface; // Interface Id 1

webbrowser_plugin_interface * webbrowser_interface;

typedef struct
{
	int (*Action)(const char *);
} webbrowser_act0_if; // Interface ACT0

webbrowser_act0_if * webbrowser_act0;

#endif // __WEBBROWSER_PLUGIN_H__

