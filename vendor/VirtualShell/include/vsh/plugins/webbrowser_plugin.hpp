#ifndef __WEBBROWSER_PLUGIN_HPP__
#define __WEBBROWSER_PLUGIN_HPP__

// Interface 1

class webbrowser_plugin_interface_t
{
public:
    int(*PluginWakeup)(int);													//1 Parameter: int (=usually 0)
    int(*PluginWakeupWithUrl)(const char *url);
    int(*PluginWakeupWithUrlAndRestriction)(const char *url, int value);		//(dis-/enable bookmark/history/setting)
    int(*Shutdown)(void);														//browser shutdown
    int(*SetMotionType)(int motion_type);
    int(*DoUnk5)(char *);														//GetUrl?
    int(*PluginWakeupWithUrlString)(int *);										//1 Parameter: struct { , char * url, ... }
    int(*PluginWakeupWithSearchString)(int *);									//1 Parameter: struct { , char * url, ... }
    int(*PluginWakeupWithUrlAndExitHandler)(const char *url, void *callback);
    int(*DoUnk9)(const char *, const char *);
    int(*UpdatePointerDisplayPos)(int pointerX, int pointerY, int pointerMode);
};


// Interface ACT0 (0x41435430)

class webbrowser_plugin_act0_t
{
public:
    int(*Action)(const char *);
};

#endif // __WEBBROWSER_PLUGIN_HPP__