#ifndef __VSHMAIN_H__
#define __VSHMAIN_H__
#include "vshtypes.h"

_VSH_BEGIN
CDECL_BEGIN

enum class eCooperationMode : uint32_t
{
   XmbMode,
   GameMode,
   VideoPlayerMode,
   EmulatorMode
};

// vshmain_68FBDB9F  //
// vshmain_F078B063  // avset_cec_control(void)
// vshmain_F0D290E0  //
// vshmain_8C067C7C  //
// vshmain_2E1AA6EF  //

void vshmain_45D85C54(uint32_t flag);   // set running mode flag
static void SetCooperationMode(eCooperationMode mode) { vshmain_45D85C54((uint32_t)mode); }

uint32_t vshmain_EB757101(void);        // _ZN3vsh18GetCooperationModeEv	 | vsh::GetCooperationMode(void) 
// get running mode flag, 0 = XMB is running
//                        1 = PS3 Game is running
//                        2 = Video Player (DVD/BD) is running
//                        3 = PSX/PSP Emu is running
static eCooperationMode GetCooperationMode() { return (eCooperationMode)vshmain_EB757101(); }

uint32_t vshmain_5046CFAB(void); // vshmain_5046CFAB  // always return 0
static void ApplyCooperationMode() { vshmain_5046CFAB(); }

// vshmain_0648F3BB  //
// vshmain_1F7BE1C8  // _ZN3vsh15RaiseFatalErrorENS_14FatalErrorTypeE | vsh::RaiseFatalError(vsh::FatalErrorType)

// vshmain_071EC82E  // ret 0x8001000A(EBUSY) | sys_event_port_send using static sys_event_port_t | int vshmain_71EC82E(uint64_t data1, uint64_t data2, uint64_t data3)
// vshmain_14F8AB14  // ret 0x8001000A(EBUSY)
// vshmain_85CB2261  // ret 0x8001000A(EBUSY) | sys_event_port_send using static sys_event_port_t | int vshmain_85CB2261(uint64_t data1, uint64_t data2, uint64_t data3)

// vshmain_6BFD6A5A  // interface -> paf_D7138829()

// vshmain_2906AFB9  // set u32 ?

// vshmain_1524F9DC  // get u8 ?
// vshmain_02517B76  // get s32 ?

// vshmain_5104DF42  //

// vshmain_8243CE25  //

// vshmain_0A3F6669  //
// vshmain_52945678  //
// vshmain_03FE9845  //
// vshmain_4F9D12D6  //
// vshmain_8084F3E6  //
// vshmain_1E36B202  // get struct(4 * u32), ret u8(flag) ?
// vshmain_92B27B03  // set struct(4 * u32), set u8(flag) to 1, counterpart of vshmain_1E36B202()

// vshmain_D870C882  //

// vshmain_9E135C0B  //
// vshmain_3BEEEEF6  //
// vshmain_DB003739  // set ?
// vshmain_27A2023C  // -> vshmain_3BEEEEF6()
// vshmain_358BF778  //

// vshmain_02C54237  //
// vshmain_925FC708  //
// vshmain_D5BB8C92  // -> vshmain_02C54237()

// vshmain_2823E246  //
// vshmain_C21E5ECB  //
// vshmain_18E2F99A  //
// vshmain_D2C82089  //
// vshmain_5086096A  //
// vshmain_2E3CB3E8  // "explore_plugin" get interface ?
// vshmain_F9ED0497  // "audioplayer_plugin" get interface ?

// vshmain_8F757D0E  // error, module+line

// vshmain_BFE12104  //

// vshmain_6C080C7E  //
// vshmain_7B3EF952  //
// vshmain_12BFE4D5  //
// vshmain_6B14B9E0  //
// vshmain_31229470  //
// vshmain_73861125  //
// vshmain_8364A155  //
// vshmain_CAA863A1  //

int vshmain_87BB0001(int param);  // shutdown_reset()
static int vsh_shutdown() { return vshmain_87BB0001(1); }
static int vsh_reboot() { return vshmain_87BB0001(2); }

// vshmain_7B3BBD9D  //
// vshmain_242E9C0C  //
// vshmain_1A4D136F  //
// vshmain_6F9F3126  // get struct addr
// vshmain_75A22E21  // get struct addr
// vshmain_F78B2215  // memset() structs
// vshmain_4F99DA2B  // set u32 gametool version, 2 or 3 | with 1 and 8 you can lock "settings" column items	vshmain_4F99DA2B(int)
// vshmain_BC0F8BCA  // get u32 gametool version, counterpart of vshmain_4F99DA2B() | _ZN3vsh16GetReleaseTargetEv | vsh::GetReleaseTarget(void)

// vshmain_BE16BB9D  // get u8 ?
// vshmain_130FDD8C  // set s32, ret old value

// vshmain_FD980F51  //
// vshmain_7752D5A8  //

// vshmain_487DD832  //

// vshmain_D739CF6B  //
// vshmain_2E3D4F4D  //

// vshmain_B75A2507  //
// vshmain_0D3DE9FE  //
// vshmain_3AECDD23  // -> vshmain_B75A2507() r8 = 1
// vshmain_64CA2FF4  //

// vshmain_81F3F967  // "/dev_hdd0/tmp/turnoff.bak", unlink()

// vshmain_7606AF6F  // open/decode/parse "/dev_flash/vsh/etc/index.dat" | _ZN3vsh11VersionFile3GetEPS0_ | vsh::VersionFile::Get(vsh::VersionFile*)

// vshmain_E63AB3D9  //
// vshmain_749704FB  //

// vshmain_0EB95CBB  // set u8(flag) to 1
// vshmain_D776E372  // set s32, ret old value
// vshmain_58B3E7FC  // get u8
// vshmain_5E8B9813  // get u8
// vshmain_04ACCA52  // set u8
// vshmain_E7D2DB56  // get u8
// vshmain_CE7BB5C7  // set 2 * u32 to 0 | _ZN3vsh9ExitParamC1Ev | vsh::ExitParam::ExitParam(void)

// vshmain_A17966C2  //
// vshmain_0BE18478  // get s32

// vshmain_C6FFF132  //

// vshmain_74105666  //

// vshmain_74A54CBF  //
// vshmain_5F5729FB  //

// vshmain_08B435B9  //
// vshmain_5EA75F0F  // set u8
// vshmain_047F4617  // get u8, counterpart of vshmain_5EA75F0F()

// vshmain_E6F481BA  // set u8
// vshmain_EA1D3983  //

// vshmain_0CD60664  //
// vshmain_97D7B33F  //

int32_t vshmain_A4338777(void);  // get flag XXXX

// vshmain_050CCCCE  // set u32

int32_t vshmain_AE35CF2D(char *, int value);  // call_xmb_plugin | Executes Action based on Input (XMB Plugin XMM0 Interface 23), Examples: "http://www.psdevwiki.com",0; "copy:device",1; "regcam:reg?",1

// vshmain_D609A2F6  // show_xmb_login | void vshmain_D609A2F6(int user_id /*starting from 1*/, bool connected /*true if already in a session*/ )
// vshmain_455FBFBA  // "explore_plugin" |

// vshmain_E46A17F0  // "avc2_text_plugin"

// vshmain_B575A332  // "friendml_plugin"
// vshmain_85DFCA8E  // "profile_plugin"
// vshmain_44994447  // "friendtrophy_plugin"
// vshmain_8B1026E1  // "friendim_plugin"
// vshmain_8BA51EED  // "xmb_plugin", xmb_plugin_normal

// vshmain_5C3E01A1  // End InGame XMB | void vshmain_5C3E01A1(void)

// vshmain_A3E81C3B  // "xmb_plugin", "ViewLoad_InGameXMB" | loads up Ingame XMB | int vshmain_A3E81C3B(-1,-1,0)

int32_t vshmain_6D5FC398(int dev_type, int port_num, int intr_type);  // Show Ingame XMB || int vshmain_6D5FC398_0, 0, 0) | int vshmain_6D5FC398(int dev_type, int port_num (pad id), int intr_type)
static int32_t Show_InGameXMB(int port_num) { return vshmain_6D5FC398(0, port_num, 0); }

// vshmain_BEFC4BA2  //
// vshmain_6D8BD460  //

// vshmain_E32ED60A  //

// vshmain_E563B825  //

// vshmain_25CE539E  //

// vshmain_784023D0  //
// vshmain_5F95D6F5  // rtc alarm shutdown/stop 	int vshmain_5F95D6F5(char * app_id)

// vshmain_F29D3952  //
// vshmain_B613E8C8  //
// vshmain_BD1C32E5  //

// vshmain_EB2B08C2  //

// vshmain_CFE616D0  //

// vshmain_079E9986  //
// vshmain_97B36F51  //
// vshmain_8F7F7B5C  //

// vshmain_E18DD7CC  // set u8

// vshmain_905D36E1  // load "autodownload_plugin" 	vshmain_905D36E1(int load_mode, void * callback?)
// vshmain_D322FE35  // "vshatdl"

// vshmain_B84B751A  // saveRegistryNetautoDlFlag | saveRegistryNetautoDlFlag ( uint8 )
// vshmain_F32CEC81  // loadRegistryNetautoDlFlag | int loadRegistryNetautoDlFlag (void)

// vshmain_E12AD560  //
// vshmain_9F747C7C  //
// vshmain_21685E40  //

// vshmain_66AFF63C  //

// vshmain_20C06B9A  //

// vshmain_84CB2C9D  //

// vshmain_FE855FD1  //

// vshmain_6E6ED20F  //

// vshmain_302125E4  //

// vshmain_106C87C1  //

int32_t vshmain_BEF63A14(void);  // setting net, base pointer for recording stuff
// vshmain_24C860B0  //

uint32_t vshmain_0624D3AE(void);  // returns game u32 process id
static uint32_t GetGameProcessID() { return vshmain_0624D3AE(); }

// vshmain_005B064D  // _ZN3vsh23sysutil_cxmlutil_server15MallocAllocatorEN4cxml14AllocationTypeEPvS3_jPS3_Pj | vsh::sysutil_cxmlutil_server::MallocAllocator(cxml::AllocationType, void *, void *, unsigned int, void **, unsigned int *)
// vshmain_0D257CFF  // Get dev_type, port_num (pad id), intr_type | vshmain_D257CFF(1, int * [3] {dev_type, port_num (pad id), intr_type} )

// vshmain_3DC5C0C0  //

// vshmain_AE8FBFC6  // ? int 0 or 1, const char *cxml_magic, void *entry | _ZN3vsh7sysutil10SetHandlerEiPKcPFiPKvjE | vsh::sysutil::SetHandler(int, char const*, int (*)(void const*, unsigned int))
// vshmain_6797B097  //

// vshmain_0F3F75BE  // sysutil_BeginService

// vshmain_36C01263  //
// vshmain_D8026119  //

// vshmain_B6B8F46B  //

// vshmain_AA19DA98  //

// vshmain_A2720DF2  // cellSysutilPacketWrite

// vshmain_23DC28E8  // cellSysutilEventPortSend | int cellSysutilEventPortSend(uint64_t data1, uint64_t data2, uint64_t data3, bool)

// vshmain_BC00D5EF  // cellSysutilSharedMemoryFree | int cellSysutilSharedMemoryFree(0 /*ignored*/, sys_addr_t start_addr, uint64_t mode /* 0x200 (unmap) or 0x400 (unmap and free) */)
// vshmain_51E7CC21  // cellSysutilSharedMemoryAlloc
// vshmain_134034CE  //

// vshmain_4986187C  // _ZN8cxmlutil16CheckElementNameERKN4cxml7ElementEPKc | cxmlutil::CheckElementName(cxml::Element const&, char const*)
// vshmain_6AF9FD89  // _ZN8cxmlutil16FindChildElementERKN4cxml7ElementEPKcS5_S5_ | cxml::Element cxmlutil::FindChildElement(const cxml::Element& parent, const char* name, const char* idname, const char* idvalue)
// vshmain_BA7437D9  //
// vshmain_6CE65E82  //

// vshmain_505FA917  // VersionFile_get
// vshmain_D80EA56E  //
// vshmain_FB1E70A0  //
// vshmain_0633EDC2  //

// vshmain_A971E5A3  //
// vshmain_E77FAFB5  //

// vshmain_B401D9AD  // cxml::Document::GetSize() | Gets the size of a cxml document | int cxml::Document::GetSize()

// vshmain_B172E9CB  //
// vshmain_BCF4D026  // cxml::Element::GetName()
// vshmain_E04F6BC8  //
// vshmain_523A54A6  //
// vshmain_58B963E5  // _ZN4cxml7Element11AppendChildERS0_ | cxml::Element::AppendChild(cxml::Element&) int cxml::Element::AppendChild( Element & child )

// vshmain_D526FD70  // cxml::Attribute::GetInt()

// vshmain_3329CAAA  // cxml::Attribute::GetFloat()

// vshmain_D03F99CF  // cxml::Attribute::GetFloatArray()

// vshmain_79EFF338  //

// vshmain_2CD62587  // cxml::Document::SetHeaderMagic()

// vshmain_7907768A  // cxml::Document::GetHeaderMagic()

// vshmain_7F4E4139  // cxml::Document::Clear() | int cxml::Document::Document() (Constructor) | Clears a cxml document.
// vshmain_6EEE1B61  // cxml::Document::CreateFromBuffer()
// vshmain_5EC145E2  // -> vshmain_7F4E4139(), cxml::Document::Clear() | cxml::Document::~Document() | Destroys a cxml document.
// vshmain_CFAD36DE  // cxml::Document::Document()  // Creates a blank cxml document for VSH Service/Process Communication

// vshmain_6BA1D72F  // cxml::Document::CreateElement() | _ZN4cxml8Document13CreateElementEPKciPNS_7ElementE | int cxml::Document::CreateElement(const char * name, int attr_num, Element * element), Creates an element on a cxml document. Example: cxml::Document doc; doc.CreateElement( "basicPresenceOffline", 0, element );
// vshmain_8AD11D24  //
// vshmain_54CC1C3F  //
// vshmain_E7D9F074  //
// vshmain_1C5F3492  // cxml::Element::GetAttribute()
// vshmain_4D89A149  // cxml::Attribute::GetFile()

// vshmain_AFF2957B  // cxml::File::Load
// vshmain_32EF17EE  // cxml::Document::WriteToFile() | _ZN4cxml8Document11WriteToFileEPKc | int cxml::Document::WriteToFile( const char * filename )

// vshmain_3848A5D4  // cxml:Document:CreateFromFile()

// vshmain_9367CAE0  // "MUSC"
// vshmain_EDAB5E5E  // "MUSC", BgmPlaybackEnable

// vshmain_57C48F5B  // "MUDE"
// vshmain_2B0678BE  // "MUDE"

// vshmain_D184B2AE  // "PRIN"
// vshmain_79B82B4D  // "PRIN"

int32_t vshmain_981D7E9F(void);     // GetScreenshotFlag
static int32_t GetScreenshotFlag() { return vshmain_981D7E9F(); }

// vshmain_08AA0F15  //

// vshmain_9C741986  //
// vshmain_C6F44333  // "vshpodl"

// vshmain_032CE51B  //
// vshmain_41345351  //

// vshmain_1A36F945  //
// vshmain_068ED6DA  //

// vshmain_EAF88E5F  //
// vshmain_0C554460  //
// vshmain_282F11CD  //
// vshmain_9A864017  //
// vshmain_F27C6E04  //

// vshmain_A3DB7243  // "vshpodl"

// vshmain_0D6DC1E3  // "PESM"
// vshmain_9217DD89  // "PESM"


CDECL_END
_VSH_END

#endif // __VSHMAIN_H__
