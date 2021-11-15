// Mysis system_plugin.h v0.1
typedef struct
{
	int (*DoUnk0)(const char *, int); // char * , int flags - dev_hdd0/theme related, loads theme?
	int (*DoUnk1)(float,int);
	int (*DoUnk2)(float *);
	int (*DoUnk3)(float *);
	int (*DoUnk4)(int *); // uint8_t [0x100?]- collects Progress Base/bar textures (tex_default_progress_base, tex_default_progress_base_shadow, and tex_default_progress_slider?)
	int (*DoUnk5)(int *); // uint8_t [0x148] - collects sounds (snd_decide, snd_cancel, snd_cursor and snd_category_decide)
	int (*DoUnk6)(void);
	int (*DoUnk7)(int, float);   // uint8 , float - page_default_theme / page_wallpaper_theme
	int (*DoUnk8)(int, float);   // uint8 , float (500.00) - page_default_theme / page_wallpaper_theme
	int (*DoUnk9)(float, float); // wallpaper_theme_plane
	int (*DoUnk10)(int, float);
	int (*DoUnk11)(int *, int *,const wchar_t *, const char *, int); // int * tex_dialog (ex. infoicon), int* tex_dialog_shadow (infoicon_shadow) , wchar * infotext1, char * infotext2, int type - create page_infobar /infoicon /infotext1/infotext2
	int (*DoUnk12)(int);    // uint8 ( 0 = _vshcommon_8D173737, else -> PageClose )- page_infobar
	int (*DoUnk13)(void);   // return uint8 (infobar activated (1)/closed (0)?)
	int (*DoUnk14)(int *);  // uint8_t [ ] - infoicon
	int (*DoUnk15)(void *); // uint8_t [0x1C] {wchar * } - infotext1
	int (*DoUnk16)(void *); // uint8_t [0x1C] {wchar * } - infotext2
	int (*DoUnk17)(void);   // busy_increase (clock hands "long" and "short" textures rotates in clockwise direction)
	int (*DoUnk18)(void);   // busy_decrease (clock hands "long" and "short" textures rotates in counterclockwise direction)
	int (*DoUnk19)(int);    // uint8_t 0=False/1=True - show page_busy
	int (*DoUnk20)(int);    // uint8_t - busy_long / busy_short
	int (*DoUnk21)(int);    // uint8_t - anim_cross_circle_show_hide
	int (*DoUnk22)(int);    // uint8_t - anim_cross_circle_show_hide
	int (*DoUnk23)(int);    // uint8_t - anim_triangle_show_hide
	int (*DoUnk24)(int);    // uint8_t - anim_triangle_show_hide
	int (*DoUnk25)(void *, const wchar_t *); // uint8_t [0x1C], wchar * - cross_text
	int (*DoUnk26)(void *, const wchar_t *); // uint8_t [0x1C], wchar * - circle_text
	int (*DoUnk27)(void *, const wchar_t *); // uint8_t [0x1C], wchar * - triangle_text
	int (*DoUnk28)(void *, const wchar_t *); // uint8_t [0x1C], wchar * - rectangle_text
	int (*DoUnk29)(float, int, char *, int, int *, int *, char *, char *); // notification
	int (*DoUnk30)(const char *); // char * (Example: "msg_press_ps_button")
	int (*saveBMP)(const char *); // char * bmp_path ("%s/screen%03d.bmp") - "saveBMP", takes a XMB screendump (make sure you set a dynamic theme, else console freezes after dump)
	int (*DoUnk32)(void); // Set up page_notification
	int (*DoUnk33)(void); // Dummy XMB start (DEX)
	int (*DoUnk34)(void); // Dummy XMB stop (DEX)
	int (*DoUnk35)(void); // Dummy XMB start/stop (DEX)
} system_plugin_interface;

system_plugin_interface * system_interface;
