// Mysis webbrowser_plugin.h v0.1
#ifndef __WEBBROWSER_PLUGIN_H__
#define __WEBBROWSER_PLUGIN_H__
#include "vshtypes.h"

_VSH_BEGIN

typedef struct webbrowser_plugin_interface_t
{
	int (*PluginWakeup)(int); //1 Parameter: int (=usually 0)
	int (*PluginWakeupWithUrl)(const char* url);
	int (*PluginWakeupWithUrlAndRestriction)(const char* url, int value); //(dis-/enable bookmark/history/setting)
	int (*Shutdown)(void); //browser shutdown
	int (*SetMotionType)(int motion_type);
	int (*DoUnk5)(char*); //GetUrl?
	int (*PluginWakeupWithUrlString)(int*);    //1 Parameter: struct { , char * url, ... }
	int (*PluginWakeupWithSearchString)(int*); //1 Parameter: struct { , char * url, ... }
	int (*PluginWakeupWithUrlAndExitHandler)(const char* url, void* callback);
	int (*DoUnk9)(const char*, const char*);
	int (*UpdatePointerDisplayPos)(int pointerX, int pointerY, int pointerMode);
} webbrowser_plugin_interface; // Interface Id 1

typedef struct
{
	int (*Action)(const char *);
} webbrowser_act0_if; // Interface ACT0

_VSH_END

#endif // __WEBBROWSER_PLUGIN_H__

