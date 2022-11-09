#ifndef __WBOARD_PLUGIN_HPP__
#define __WBOARD_PLUGIN_HPP__

// Interface 1

class wboard_plugin_interface_t
{
public:
    int(*DoUnk0)(int);
    int(*DoUnk1)(void);
    int(*SetWBEXBTInfoText)(wchar_t *);
};


// Interface ACT0 (0x41435430)

class wboard_plugin_act0_t
{
public:
    int(*Action)(char *);
};


// Interface MOD0 (0x4D4F4430)

class wboard_plugin_mod0_t
{
public:
    int(*DoUnk0)(void);
    int(*DoUnk1)(void);
    int(*DoUnk2)(void);
    int(*DoUnk3)(int);
};

#endif // __WBOARD_PLUGIN_HPP__