// Mysis nas_plugin.h v0.1
typedef struct
{
	int (*DoUnk0)(int);                              // 1 Parameter: int (0 - 0x29) - create nas_dialog, nas_installer, page_nas - page_default_theme / page_wallpaper_theme (0, 1000.0f)
	int (*DoUnk1)(int,int);                          // 2 Parameter: int do, int bgdl_id - (loadNewStorePlugin? ("psvp:bgdl?id=0x%08x"))
	int (*DoUnk2)(void);                             // 0 Parameter: - set 0x28 / 0x1C0 - create nas_dialog, nas_installer, page_nas
	int (*DoUnk3)(void);                             // 0 Parameter: - set 0x29 / 0x300 - create nas_dialog, nas_installer, page_nas
	int (*DoUnk4)(void *,int,int,int,void *,int);    // 6 Parameter: list { char * items} , item count (<=0x10), cb_arg_0 , cb_arg_1, void * callback,Memory Container
	int (*DoUnk5)(char *,int,int,void*,int);         // 5 Parameter: char * CategoryID, cb_arg_0, cb_arg_1,void * callback,Memory Container
	int (*DoUnk6_SetCallback)(void *,int);           // SetCallback, 2 Parameter: void * handler, int interface ? - for Unload?/Exit?
	int (*DoUnk7)(void *);                           // 1 Parameter: download struct - set 0x1F, create nas_dialog, nas_installer, activate nas_dialog
	int (*DoUnk8)(char * username, char * password); // Set, 2 Parameter: char * username[0x40], char * password[0x20]
	int (*DoUnk9)(void);                             // 0 Parameter: - edy_plugin interface 1 func 4
	int (*DoUnk10)(void *);  //  1 Parameter: download struct - 0, set 0x1F, create nas_dialog, nas_installer, activate nas_dialog
	int (*DoUnk11)(void *);  //  1 Parameter: download struct - 1, set 0x1F, create nas_dialog, nas_installer, activate nas_dialog
	int (*DoUnk12)(void *);  //  1 Parameter: download struct - set 0x1F, create nas_dialog, nas_installer, activate nas_dialog
	int (*DoUnk13)(void *);  //  1 Parameter: download struct - set 0x1F, create nas_dialog, nas_installer, activate nas_dialog
	int (*DoUnk14)(void *);  //  1 Parameter: download struct - set 0x20 (progress bar?), create nas_dialog, nas_installer, activate nas_dialog
	int (*DoUnk15)(void *);  //  1 Parameter: download struct - set 0x21 (streaming?), create nas_dialog, nas_installer, activate nas_dialog
	int (*DoUnk16)(void *);  //  1 Parameter: download struct - set 0x21 (streaming?), create nas_dialog, nas_installer, activate nas_dialog
	int (*DoUnk17)(void *);  //  1 Parameter: download struct - set 0x21 (streaming?), create nas_dialog, nas_installer, activate nas_dialog
	int (*DoUnk18)(void *);  //  1 Parameter: struct { "%s", , , flags } - set 0x21 (streaming?), create nas_dialog, nas_installer, activate nas_dialog
	int (*DoUnk19)(int * bgdl_id);                   //  Get, 1 Parameter: int * bgdl_id
	int (*DoUnk20_installerDrmActivation)(int drmActivationItemAction,int drmActivationItemTarget,int drmActivationItemOption); //  installerDrmActivation, 3 Parameter: int drmActivationItemAction(0-4),int drmActivationItemTarget(1=authorize/0=not), int drmActivationItemOption - 6,create nas_dialog, nas_installer, activate nas_dialog
	int (*DoUnk21)(char *,const void * input,int len);                    //  3 Parameter: char *, const void *input (cellHttpUtilBase64Encoder), size_t len - 7, create nas_dialog, nas_installer, activate nas_dialog
	int (*DoUnk22_installerDownload)(void);                               //  1 Parameter: - installerDownload - 0x21, create nas_dialog, nas_installer, activate nas_dialog
	int (*DoUnk23)(int, void *);                                          //  2 Parameter: int, void *
	int (*DoUnk24)(char *);                                               //  1 Parameter: char * path
	int (*DoUnk25)(int task_id, int flags);                               //  2 Parameter: int bgdl_task_id, int flags - set 0x1F , create nas_dialog, nas_installer, activate nas_dialog
	int (*DoUnk26)(void);                                                 //  0 Parameter: return int error_code
	int (*DoUnk27)(void *);                                               //  1 Parameter: { char * path, int pic?, char * titleid?, void *, wchar_t *, char * SysVersion} - set 0x22 , create nas_dialog, nas_installer, activate nas_dialog
	int (*DoUnk28)(char * path);                                          //  1 Parameter: char * path - set 0x23
	int (*DoUnk29)(unsigned long long *,unsigned long long *);            //  Get, 2 Parameter: uint64_t *, uint64_t * - DL Time ?
	int (*DoUnk30)(void *);                                               //  1 Parameter: struct - set 0x21 , create nas_dialog, nas_installer, activate nas_dialog
	int (*DoUnk31)(void *);                                               //  1 Parameter: { int, int, uint64_t } - msgdialog
	int (*DoUnk32_ResumeMarlinVideoStreaming)(void * callback); //?       //  ResumeMarlinVideoStreaming, 1 Parameter: void * callback - set 0x24 , create nas_dialog, nas_installer, activate nas_dialog
	int (*DoUnk33)(char *,int,unsigned long long *,unsigned long long *); //  4 Parameter: char * [0x100], 0x100, uint64_t * , uint64_t *
	int (*DoUnk34)(void *);                                               //  1 Parameter: void * [0x178?]
} nas_plugin_interface;

nas_plugin_interface * nas_interface;
