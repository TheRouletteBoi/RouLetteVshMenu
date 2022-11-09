#ifndef __VSHTASK_HPP__
#define __VSHTASK_HPP__

namespace vshtask
{
    CDECL_BEGIN

    int vshtask_0F80B71F(const char *path);  // auth_module, checks sprx SCE header	int vshtask_F80B71F(char * path)

    int vshtask_166551C5(char *app_id);      // RTC Alarm Unregister
    //int vshtask_668E3C94(char * app_id?, uint8_t [0x4C]);  // some RTC Alarm Register
    int vshtask_8D03E0FD(void);              // ?
    int vshtask_784023D0(uint8_t status[0x1D0]); //	RTC Alarm Get Status	int vshtask_784023D0

    int vshtask_A02D46E7(int32_t arg, char const*msg);  // vshtask_notification_msg()  -> Displays a notification in XMB, calls vshcommon_A20E43DB with texture "tex_notification_info"
    static int Notify(char const* message) { return vshtask_A02D46E7(0, message); }

    CDECL_END
}

#endif // __VSHTASK_HPP__