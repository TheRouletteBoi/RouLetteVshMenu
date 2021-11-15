// Mysis friend_plugin.h v0.1
typedef struct
{
	int (*SetFriendimExit)(void);
	int (*PluginRecvLaunch)(void);
	int (*PluginSendLaunch)(void);
	int (*PluginNewMessageLaunch)(void);
	int (*PluginFriendAddNormalLaunch)(void);
	int (*PluginFriendAddIdLaunch)(void);
	int (*PluginUpdateCommentLaunch)(void);
	int (*PluginSentEdtiLaunch)(void);
	int (*DoUnk8)(void);
	int (*DoUnk9)(void);
	int (*DoUnk10)(void);
	int (*DoUnk11)(void);
	int (*DoUnk12)(void);
	int (*DoUnk13)(void);
	int (*DoUnk14)(void);
	int (*DoUnk15)(void);
	int (*DoUnk16)(void);
	int (*sendFriendAddRequestBySceNpUserInfoLaunch)(void);
	int (*DoUnk18)(void);
	int (*sendMessageBySceNpUserInfoNoCallbackLaunch)(void);
	int (*DoUnk20)(void);
	int (*DoUnk21)(void);
	int (*DoUnk22)(void);
	int (*DoUnk23)(void);
	int (*DoUnk24)(void);
	int (*DoUnk25)(void);
	int (*AbortGui)(void);
	int (*DoUnk27)(void);
	int (*DoUnk28)(void);
	int (*DoUnk29)(void);
	int (*RecommendGame)(char * contentid, char * title, int);
	int (*sendBrowserWakeup)(void);
	int (*DoUnk32)(void);
	int (*DoUnk33)(void);
	int (*DoUnk34)(void);
	int (*DoUnk35)(void);
	int (*DoUnk36)(void);
	int (*sendEtcLaunch)(void);
	int (*DoUnk38)(void);
	int (*DoUnk39)(void);
	int (*TellFriend)(void);
} friendim_plugin_interface;

friendim_plugin_interface * friendim_interface;
