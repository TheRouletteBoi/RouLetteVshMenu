// Mysis impose_plugin.h v0.1
typedef struct
{
	int (*DoUnk0)(int,void *);     // 2 Parameter: int value (1=Blue Screen of Death,2=Red Screen of Death,Else=page_btnnavi), void * ptr_handler
	int (*DoUnk1)(void);
	int (*DoUnk2)(void);           // 0 Parameter: - setWidget "impose_blankscreen", return View "impose_plane_dark"
	int (*DoUnk3)(int);            // Set,1 Parameter: uint8 (=0 -> create impose page, !=0 -> skip create impose_page)
	int (*DoUnk4)(int);            // Set,1 Parameter: int value (-1 = disable/enable Controller Setting in Game Exit Message,0 =,1=,2=,3=,4=msg_quit2,5=)
	int (*DoUnk5)(int);            // 1 Parameter: uint8 (for example: Controller Setting in Game Exit Message-Enable/Disable)
	int (*DoUnk6)(void);           // 0 Parameter: - PageClose "impose_blankscreen"
	int (*DoUnk7)(void);           // 3 Parameter: int pad %d, float (2000.0), float (100.0) - "impose_pad_battery_notice"
	int (*DoUnk8)(void);           // 1 Parameter: float value (100.0) - impose_pad_battery_notice
	int (*DoUnk9)(void);           // 1 Parameter: int value (-11, 1, -13)
	int (*DoUnk10)(void);          //: 1 Parameter: uint8 [0x1A0] - "page_confirm_gameupdate_dialog"
	int (*DoUnk11)(void);          //: 0 Parameter: - create "impose_waitfor_background_task"
	int (*DoUnk12)(void);          //: 0 Parameter: - update_error_text_plane
	int (*DoUnk13_start_xmb)(int); //: 1 Parameter: int pad id - "impose_page" - (start_xmb)
	int (*DoUnk14)(void);          //: 0 Parameter: - gamepad 0, create "notification_a" + "page_btnnavi" Widgets
	int (*DoUnk15)(void);          //: 1 Parameter: uint (1) - Creates "impose_exit_game" Widget etc.
	int (*DoUnk16)(void);          //: Set, 1 Parameter: uint vibrationEnable flag
	int (*DoUnk17)(int);           //: Set impose psbutton notification not ingameXMB, 1 Parameter: uint - (0 = BeginInGameXMB ,1 =  _notification_psbutton)
	int (*DoUnk18)(void);
} impose_plugin_interface;

impose_plugin_interface * impose_interface;


















