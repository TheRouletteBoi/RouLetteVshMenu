#ifndef __WEBRENDER_PLUGIN_H__
#define __WEBRENDER_PLUGIN_H__
// bguerville webrender_plugin.h v0.1
typedef struct webrender_plugin_interface_t
{

	int (*DoUnk3)(void);

} webrender_plugin_interface; // Interface Id 1

webrender_plugin_interface * webrender_interface;

typedef struct
{
	int (*Action)(const char *);

} webrender_act0_interface; // Interface ACT0

webrender_act0_interface * webrender_act0;

typedef struct
{
	int (*DoUnk0)(void);
	int (*DoUnk1)(void);
	int (*DoUnk2)(void);
	int (*DoUnk3)(void);
	int (*DoUnk4)(void);

} webrender_plugin_mod0;

webrender_plugin_mod0 * webrender_mod0_interface;

#endif // __WEBRENDER_PLUGIN_H__
