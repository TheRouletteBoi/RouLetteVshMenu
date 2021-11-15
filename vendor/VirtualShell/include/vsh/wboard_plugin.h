// Mysis wboard_plugin.h v0.1
typedef struct
{
	int (*DoUnk0)(int);
	int (*DoUnk1)(void);
	int (*SetWBEXBTInfoText)(wchar_t *);
} wboard_if; // Interface Id 1

wboard_if * wboard_interface;

typedef struct
{
	int (*Action)(char *);
} wboard_act0_if; // Interface ACT0

wboard_act0_if * wboard_act0;

typedef struct
{
	int (*DoUnk0)(void);
	int (*DoUnk1)(void);
	int (*DoUnk2)(void);
	int (*DoUnk3)(int);
} wboard_mod0_if; // Interface MOD0

wboard_mod0_if * wboard_mod0;
