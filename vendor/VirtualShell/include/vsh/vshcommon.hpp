#ifndef __VSHCOMMON_HPP__
#define __VSHCOMMON_HPP__

#include "paf.hpp"
#include "vshmain.hpp"

namespace vsh
{
    class NavigationMessage;

    CDECL_BEGIN

    // vshcommon_6FD850FF(void);  // custom_render_plugin IF 1: - (decrease)
    // vshcommon_EC73D438(void);  // custom_render_plugin IF 1: - (increase)
    // vshcommon_BF88BEE4(void);  // custom_render_plugin IF 1: - blur (decrease?)
    // vshcommon_C8FFD88F(void);  // custom_render_plugin IF 1: - blur (increase?)
    // vshcommon_16E29622(const char *str);  // custom_render_plugin IF 1:
    // vshcommon_5723C3C1(float x, const char * str, int y);  // ?
    // vshcommon_25111EFB  // ?

    // vshcommon_D81578DB  // ?
    // vshcommon_73F85259(uint8_t x);  // system_plugin interface_1: 24: anim_rectangle_show_hide
    // vshcommon_E011E7D0(uint8_t x);  // system_plugin interface_1: 23: anim_triangle_show_hide
    // vshcommon_9BD8429E(uint8_t x);  // system_plugin interface_1: 22: anim_cross_circle_show_hide
    // vshcommon_2438F1A4(uint8_t x);  // system_plugin interface_1: 21: anim_cross_circle_show_hide

    // vshcommon_F7A67D49(uint8_t x[0x1C], wchar *s);  // system_plugin interface_1: 28: rectangle_text
    // vshcommon_F7A67D49  // _ZN3vsh30SetButtonNavigationString_ViewEPKw vsh::SetButtonNavigationString_View(wchar_t const*) System_plugin#1_Interface func 28 rectangle
    // vshcommon_60DEE5B3  // _ZN3vsh32SetButtonNavigationString_OptionEPKw	vsh::SetButtonNavigationString_Option(wchar_t const*) System_plugin#1_Interface func 27 triangle
    // vshcommon_75DC9C2D  // _ZN3vsh30SetButtonNavigationString_BackEPKw	vsh::SetButtonNavigationString_Back(wchar_t const*) System_plugin#1_Interface func 26 cross_circle
    // vshcommon_79A562D5  // _ZN3vsh31SetButtonNavigationString_EnterEPKw	vsh::SetButtonNavigationString_Enter(wchar_t const*) System_plugin#1_Interface func 25 circle_cross
    // vshcommon_B9473E7A  // ?
    // vshcommon_D1DE9F38  // ?

    // vshcommon_85AD7A58  // ?

    // vshcommon_AE251F8F  // ?

    // vshcommon_E43C21F6  // ?

    // vshcommon_8C7F3E6F  // ?

    // vshcommon_55A60B1A  // ?

    // vshcommon_F9E43DA2(void);  // returns localized string of "msg_ok"
    // vshcommon_CCD2C319(void);  // returns localized string of "msg_cancel"
    // vshcommon_746C5F88(void);  // returns localized string of "msg_option"
    // vshcommon_F995E53F(void);  // returns localized string of "msg_back"
    // vshcommon_26F18EDF(void);  // returns localized string of "msg_enter"
    // vshcommon_0E9E8DA5(void);  // returns localized string of "msg_no"
    // vshcommon_B8E256D7(void);  // returns localized string of "msg_yes"
    // vshcommon_8D173737  // ?

    // vshcommon_28549FD0  // ?
    // vshcommon_015D4314  // ?
    // vshcommon_94F43BE7  // ?
    // vshcommon_7F5C551B  // ?
    // vshcommon_14FF1DDC  // ?
    // vshcommon_884E740C  // ?

    // vshcommon_12D25E5F  // ?
    // vshcommon_61D97E3B  // ?
    // vshcommon_DEC761F1  // ?

    // vshcommon_D87C3834  // ?

    // vshcommon_98D73408  // ?
    // vshcommon_FDA63F52  // ?
    // vshcommon_DFD99C55  // ?
    // vshcommon_63210A1C  // ?

    // vshcommon_3A8D0E1C  // ?
    // vshcommon_24FF1870  // ?
    // vshcommon_EA95C3F5  // ?

    // vshcommon_3B634FCC  // ?

    // vshcommon_38815260  // ?
    // vshcommon_425277FA  // ?

    // vshcommon_0EBAC3B5  // ?
    // vshcommon_1851C6A6  // ?
    // vshcommon_3F731CC3  // ?
    // vshcommon_B045A8DC  // ?
    // vshcommon_95302AE6  // ?
    // vshcommon_C398D8BA  // ?
    // vshcommon_50DE40CE  // ?
    // vshcommon_85A3D9F3  // ?
    // vshcommon_6A784AE5  // ?
    // vshcommon_933A54F5  // ?
    // vshcommon_5A6C0DB6  // ?

    // vshcommon_7C139D36  // ?
    // vshcommon_459C02B6  // ?

    // vshcommon_33C12393  // ?
    // vshcommon_9CB87B0D  // ?
    // vshcommon_CE57965F  // ?
    // vshcommon_74EAD50B  // ?
    // vshcommon_F06004CD  // ?

    int vshcommon_A20E43DB(int r3, const char* eventName, int r5, paf::SurfacePtr& texture, void* r7, const char* r8, const char* r9, float f1, const wchar_t* text, int r13, bool isLooped, int r14);
    
    static int ShowNotificationBySurfaceTexture(paf::SurfacePtr& texture, wchar_t const* text, bool isLooped = false)
    {
        int unknownOut = 0;
        return vshcommon_A20E43DB(0, "", 0, texture, &unknownOut, "", "", 0.0f, text, 0, isLooped, 0);
    }
    
    void vshcommon_7504447B(void); // null subroutine 

    void vshcommon_F1918912(NavigationMessage const* thisMessage, float duration); // adjust duration of navigationMessage

    void vshcommon_21806775(NavigationMessage const* thisMessage);

    NavigationMessage* vshcommon_F55812AE(paf::PhWidget* parent, wchar_t const* message, int r5, int r6); // r5 = 4, r6 = 0

    // vshcommon_61D17188  // ?
    // vshcommon_EA790023  // ?
    // vshcommon_D59AEAD0  // ?
    // vshcommon_5DC484F8  // ?

    // vshcommon_E21C3432  // ?

    // vshcommon_00EDDB5B  // ?

    // vshcommon_5CE195FA  // ?
    // vshcommon_E607C2BA  // ?

    // vshcommon_C499E073  // ?

    // vshcommon_CDF4C62A  // ?
    // vshcommon_53ECE7ED  // ?
    // vshcommon_1379FF05  // ?
    // vshcommon_AB6951A3  // ?
    // vshcommon_ABCA6F32  // ?
    // vshcommon_5DD71B31  // ?
    // vshcommon_4A6E257D  // ?

    // vshcommon_A6525AE6  // ?
    // vshcommon_DAC7FC51  // ?

    // vshcommon_B2D04619  // ?
    // vshcommon_B7F2EFD5  // ?

    // vshcommon_9DAB12AA  // ?

    // vshcommon_025EC4EE  // ?

    // vshcommon_E7DFF7FE  // ?

    // vshcommon_D9B63654  // ?

    // vshcommon_BB2EC9CD  // PageCloses "page_pointcursor"

    // vshcommon_ABEB01DA  // PageCreates "page_pointcursor"

    // vshcommon_980513A4  // ?

    // vshcommon_5C9F85CB  // ?
    // vshcommon_E9790F7A  // ?

    // vshcommon_EDB3F1F2  // ?
    // vshcommon_390E5621  // ?
    // vshcommon_B7517F9B  // ?
    // vshcommon_73B454A2  // ?

    // vshcommon_C27EF445  // ?

    // vshcommon_D55C9CEE  // ?
    // vshcommon_7C7F21E0  // ?
    // vshcommon_1452A4D3  // ?

    // vshcommon_6F5A9C38  // ?
    // vshcommon_16106ACD  // returns "impose_plugin" interface 1 -> uint vshcommon_16106ACD()

    // vshcommon_C08C2D22  // ?
    // vshcommon_98E05EDA  // ?
    // vshcommon_D17A0968  // ?

    // vshcommon_AA6178EE  // ?
    // vshcommon_F4E3246A  // ?

    // vshcommon_83E28B3C  // ?

    // vshcommon_8B7F8F80  // ?
    // vshcommon_7C3ACA85  // ?
    // vshcommon_19535F4C  // ?
    // vshcommon_B0B677BC  // ?
    // vshcommon_3DBB0BB2  // ?
    // vshcommon_DC712BA3  // ?
    // vshcommon_940FE097  // ?
    // vshcommon_EC44C999  // ?
    // vshcommon_B9FDA9D4  // ?
    // vshcommon_B6C9D197  // ?
    // vshcommon_13F9024E  // ?

    // vshcommon_FB104BD2  // ?

    // vshcommon_7BD54E23  // ?
    // vshcommon_3F8C6AED  // ?

    // vshcommon_31573F9A  // ?

    // vshcommon_4B8EE123  // ?
    // vshcommon_AB7E2E69  // ?
    // vshcommon_AF168DD4  // ?

    // vshcommon_D996B261  // ?
    // vshcommon_52692705  // ?

    // vshcommon_CA3CBF5D  // ?

    // vshcommon_2D2F3A6E  // ?
    // vshcommon_44726825  // ?
    // vshcommon_B53FD739  // ?
    // vshcommon_252838CF  // ?
    // vshcommon_3851B803  // ?
    // vshcommon_B4BAF07E  // ?

    // vshcommon_97E53BCA  // ?
    // vshcommon_54D13728  // ?

    // vshcommon_DB0320D8  // ?
    // vshcommon_0A007C99  // ?
    // vshcommon_8F0C0B33  // ?
    // vshcommon_D59C7D79  // ?
    // vshcommon_0BECDA92  // ?
    // vshcommon_79A546A1  // ?
    // vshcommon_39D01FCA  // ?

    // vshcommon_34A05733  // ?

    // vshcommon_A2312283  // ?

    // vshcommon_CC2C67F2  // reads /pushlist/patch.dat vshcommon_CC2C67F2(int* count,uint8_t buf[0x680])

    // vshcommon_09A43140  // adds info to /pushlist/patch.dat
    // vshcommon_7EE0068F  // ?

    // vshcommon_B49AF109  // ?
    // vshcommon_D010D338  // ?
    // vshcommon_BC200324  // ?
    // vshcommon_774C200A  // ?

    // vshcommon_13BAFB22  // ?
    // vshcommon_6DF64AAF  // ?

    // vshcommon_FAEA4EF9  // ?
    // vshcommon_50CBEE73  // ?
    // vshcommon_A05B2B54  // ?
    // vshcommon_E2D6F3D7  // ?

    // vshcommon_8B2110D5  // reads boot_history.dat
    // vshcommon_9EA67737  // vsh::ws_boot_history::Set() { uint8 type, char TitleId [0x1F] } titleid to boot_history.dat (creates if not present)

    CDECL_END

    enum class NotifyIcon
    {
        // system_plugin
        Info,
        Caution,
        Friend,
        Slider,
        WrongWay,
        Dialog,
        DalogShadow,
        Text,
        Pointer,
        Grab,
        Hand,
        Pen,
        Finger,
        Arrow,
        ArrowRight,
        Progress,
        Trophy1,
        Trophy2,
        Trophy3,
        Trophy4,
        Keypad,
        Mediaserver,
        Music,
        Settings,
        Triangle,

        // explore_plugin
        PS3,
        PS4,
        Vita,
        DefaultAvatar,
        Lock,
        PlusSign,
        WhiteController,
        BlueDisc,
        BrownDisc,
        GrayDisc,
        Walkman,
        PSButtons,
        Error,
        Pause,
        Facebook,
        Rench,
        PSNFolder,
        BronzeStarTrophy,
        PSStore,
        PS3Logo,
        BlueVerifiedCheckmark,
        Blocked,
        AFK,
        OrangeWait,
        BlueCircle,
        RedCirleCross,
        OrangeCircleNEW,
        PSPlus,
        PSPlusBig,
        PSNIcon,
        PSNIconBig,
        RedExclamationPoint
    };

    enum class NotifySound
    {
        None = -1,
        Cancel = 0,
        CategoryDecide,
        Cursor,
        Decide,
        Error,
        Option,
        NG,
        OK,
        Trophy,
    };

    class NavigationMessage
    {
    public:
        // NavigationMessage(paf::PhWidget* parent, const std::wstring& message, int r6, int r7); // sub_34D938
        ~NavigationMessage() 
        {
            m_Data._byte_0x10 = 1;
            vshcommon_21806775(this);
        }

        void SetDuration(float duration) // idk if its related to the duration   xD
        { 
            vshcommon_F1918912(this, duration);
        }

    private:
        struct
        { // reversed with IDA pro, too lazy to check via debugger so i'm not sure if these are correct
            paf::PhWidget* parent; // child of page_notification that serves as a 'group'
            paf::PhPlane* planeShadow;
            paf::PhPlane* planeBackground;
            paf::PhText* message;
            uint8_t _byte_0x10;
            uint8_t __padding_0x11[0xF];
            uint32_t _dword_0x20;
            float duration; // 5000 by default
            uint32_t _dword_0x28; // r7 from constructor
            uint32_t _dword_02C;
            float _float_0x30;
            float _float_0x34;
            uint8_t __padding_0x38[0x8];
        } m_Data;
    };

    // L"\uF880" = Dualshock circle button-Button
    // L"\uF881" = Dualshock cross button-Button
    // L"\uF882" = Dualshock square button-Button
    // L"\uF883" = Dualshock triangle button-Button
    // L"\uF884" = D-Pad UP Button-Button
    // L"\uF885" = D-Pad DOWN Button-Button
    // L"\uF886" = D-Pad LEFT Button-Button
    // L"\uF887" = D-Pad RIGHT Button-Button
    // L"\uF888" = Dualshock L1 button-Button
    // L"\uF889" = Dualshock L2 button-Button
    // L"\uF88A" = Dualshock L3 button-Button
    // L"\uF88B" = Dualshock R1 button-Button
    // L"\uF88C" = Dualshock R2 button-Button
    // L"\uF88D" = Dualshock R3 button-Button
    // L"\uF88E" = Dualshock select button-Button
    // L"\uF88F" = Dualshock start button-Button
    // L"\uF892" = Dualshock PS button-Button
    // L"\uF893" = Dualshock L2 buttonD-Pad LEFT Button-Combo
    // L"\uF894" = Dualshock R2 buttonD-Pad RIGHT Button-Combo

    static void ShowNavigationMessage(wchar_t const* message) 
    {
        static NavigationMessage* previousNavMsg = nullptr;

        paf::View* systemPlugin = paf::View::Find("system_plugin");
        paf::PhWidget* pageAutoOffGuide = systemPlugin ? systemPlugin->FindWidget("page_autooff_guide") : nullptr;

        if (pageAutoOffGuide)
        {
            if (previousNavMsg) 
            {
                previousNavMsg->~NavigationMessage();
                previousNavMsg = nullptr;
            }

            previousNavMsg = vshcommon_F55812AE(pageAutoOffGuide, message, 4, 0);
        }
    }

    static void ShowNotificationWithIcon(const std::wstring& text, NotifyIcon notifyType, NotifySound soundType = NotifySound::Trophy)
    {
        paf::View* explorePlugin = paf::View::Find("explore_plugin");
        paf::View* systemPlugin = paf::View::Find("system_plugin");

        if (!systemPlugin)
            return;

        const char* systemPlugin_SoundNames[] =
        {
           "snd_cancel", "snd_category_decide", "snd_cursor", "snd_decide",
           "snd_error", "snd_option", "snd_system_ng", "snd_system_ok", "snd_trophy"
        };

        const char* notification_TextureNames[] =
        {
            // "system_plugin"
            "tex_notification_info", "tex_notification_caution", "tex_notification_friend",
            "tex_default_scroll_slider", "tex_notification_psbutton_insensitive", "tex_common_dialog",
            "tex_common_dialog_shadow", "tex_3x3_focus", "tex_pointer_click", "tex_pointer_grab",
            "tex_pointer_hand", "tex_pointer_pen", "tex_pointer_finger", "tex_pointer_arrow",
            "tex_arrow_right", "tex_default_progress_slider", "tex_notification_trophy_bronze",
            "tex_notification_trophy_silver", "tex_notification_trophy_gold",
            "tex_notification_trophy_platinum", "tex_notification_keypad", "tex_notification_mediasever",
            "tex_notification_music", "tex_notification_settings", "tex_triangle",

            // "explore_plugin" & "explore_plugin_full"
            "item_tex_ps3format", "item_tex_ps4format", "item_tex_vitaformat", "tex_Avatar_Default",
            "tex_lock_icon", "trophy_tex_addon", "game_tex_load", "item_tex_disc_bd", "item_tex_disc_dvd",
            "item_tex_disc_icon", "item_tex_walkman", "ps3sd_tex_default", "bgdl_tex_error", "bgdl_tex_pause",
            "item_tex_cam_facebook", "item_tex_cam_icon", "item_tex_online_storage", "item_tex_Profile_LevelIcon",
            "item_tex_ps_store", "item_tex_ps3logo", "tex_check_ws", "tex_go_bubu", "tex_indi_AFK", "tex_indi_NewRoom",
            "tex_indi_Sign_in", "tex_indi_Sign_out", "tex_new_ws", "tex_psplus_icon", "tex_ps_plus_invitation",
            "tex_psn", "tex_psn_big", "tex_urgent_ws"
        };

        paf::SurfacePtr pTexture = paf::SurfacePtr();
        if (explorePlugin != nullptr && GetCooperationMode() == CooperationMode::XMB)
        {
            if (notifyType < NotifyIcon::PS3)
                pTexture = systemPlugin->GetTexture(notification_TextureNames[(int)notifyType]); // explore_plugin icons
            else
                pTexture = explorePlugin->GetTexture(notification_TextureNames[(int)notifyType]); // system_plugin icons
        }
        else
        {
            if (notifyType < NotifyIcon::PS3)
                pTexture = systemPlugin->GetTexture(notification_TextureNames[(int)notifyType]); // explore_plugin icons
            else
                pTexture = systemPlugin->GetTexture(notification_TextureNames[(int)NotifyIcon::Pen]); // default
        }

        ShowNotificationBySurfaceTexture(pTexture, text.c_str());

        if (soundType != NotifySound::None)
            systemPlugin->PlaySound(systemPlugin_SoundNames[(int)soundType]);
    }

}

#endif // __VSHCOMMON_HPP__