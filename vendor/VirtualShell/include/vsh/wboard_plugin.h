// Mysis wboard_plugin.h v0.1
#ifndef __WBOARD_PLUGIN_H__
#define __WBOARD_PLUGIN_H__
#include "vshtypes.h"


_VSH_BEGIN

typedef struct
{
	int (*DoUnk0)(int);
	int (*DoUnk1)(void);
	int (*SetWBEXBTInfoText)(wchar_t *);
} wboard_if; // Interface Id 1

typedef struct
{
	int (*Action)(char *);
} wboard_act0_if; // Interface ACT0

typedef struct
{
	int (*DoUnk0)(void);
	int (*DoUnk1)(void);
	int (*DoUnk2)(void);
	int (*DoUnk3)(int);
} wboard_mod0_if; // Interface MOD0


_VSH_END

#endif // __WBOARD_PLUGIN_H__