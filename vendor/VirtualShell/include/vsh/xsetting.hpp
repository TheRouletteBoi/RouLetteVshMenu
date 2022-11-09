#ifndef __XSETTING_HPP__
#define __XSETTING_HPP__

class xsetting_0AF1F161_t
{
public:
    int(*GetProductCode)(void);
    int(*GetProductSubCode)(void);			// Model Type, Mobo Id
    int(*GetUnk1)(void *);					// uint8_t [0x1C] { hdmi, ieee802.11, msslot, sdslot, cfslot }
    int(*SetUnk2)(void *);
    int(*GetEnterButtonAssign)(int *);
    int(*SetEnterButtonAssign)(int);
    int(*GetLicenseArea)(int *);
    int(*SetSystemInitialize)(int);
    int(*GetSystemInitialize)(int *);
    int(*SetSystemLanguage)(int);
    int(*GetSystemLanguage)(int *);
    int(*SetSystemNickname)(char *);
    int(*GetSystemNickname)(char *, int *);	// nick, length
    int(*SetSystemCharacterCodeOem)(int);
    int(*GetSystemCharacterCodeOem)(int *);
    int(*SetSystemCharacterCodeOemValue)(int);
    int(*GetSystemCharacterCodeOemValue)(int *);
    int(*SetsystemCharacterCodeAnsi)(int);
    int(*GetSystemCharacterCodeAnsi)(int *);
    int(*ResetNicknameDvdRegionDlnaFlag)(void);
    int(*SetSystemNotificationEnabled)(int);
    int(*GetSystemNotificationEnabled)(int *);
    int(*SetSystemDiscBootFirstEnabled)(int);
    int(*GetSystemDiscBootFirstEnabled)(int *);
    int(*SetSystemSoundEffectEnabled)(int);
    int(*GetSystemSoundEffectEnabled)(int *);
    int(*unk_new)(void *, void *);
    int(*unk_delete)(void *, void *);
};

class xsetting_154430FC_t
{
public:
    //int (*sub_4617B0) ?
    //int (*sub_461774) ?
    //int (*sub_461718) ?
    //int (*sub_4616DC) ?
    //int (*sub_4617DC) ?
    //int (*sub_461674) ?
    //int (*sub_461638) ?
    //int (*sub_4615FC) ?
    //int (*sub_4615B0) ?
    //int (*sub_461564) ?
    //int (*sub_461528) ?
    //int (*sub_4614EC) ?
    //int (*sub_4614B0) ?
    //int (*sub_461474) ?
    //int (*sub_461428) ?
    //int (*sub_4613DC) ?
    //int (*sub_461390) ?
    //int (*sub_461354) ?
    //int (*sub_461308) ?
    //int (*sub_4612BC) ?
    //int (*sub_461270) ?
    //int (*sub_461224) ?
    //int (*sub_4611E8) ?
    //int (*sub_4611AC) ?
    //int (*sub_461160) ?
    //int (*sub_461134) ?
    //int (*sub_4610F8) ?
    //int (*sub_4610BC) ?
    //int (*sub_461080) ?
    //int (*sub_461034) ?
    //int (*sub_460FF8) ?
    //int (*sub_460FBC) ?
    //int (*sub_460F70) ?
    //int (*sub_460F10) ?
    //int (*sub_460ED4) ?
    //int (*sub_460E98) ?
    //int (*sub_460E5C) ?
    //int (*sub_460E20) ?
    //int (*sub_460DF4) ?
    //int (*sub_460DC8) ?
    //int (*sub_460D8C) ?
    //int (*sub_460D50) ?
    //int (*sub_460D14) ?
    //int (*sub_460CD8) ?
    //int (*sub_460CAC) ?
    //int (*sub_460C70) ?
    //int (*sub_460C34) ?
    //int (*sub_460BE8) ?
};

class xsetting_16A8A805_t
{
public:
    int(*SetBdMenuLanguage)(int);
    int(*GetBdMenuLanguage)(int *);
    int(*SetBdSoundLanguage)(int);
    int(*GetBdSoundLanguage)(int *);
    int(*SetBdCaptionLanguage)(int);
    int(*GetBdCaptionLanguage)(int *);
    int(*Set_unk6)(int);
    int(*Get_unk7)(int *);
    int(*SetDvdMenuLanguage)(int);
    int(*GetDvdMenuLanguage)(int *);
    int(*SetDvdSoundLanguage)(int);
    int(*GetDvdSoundLanguage)(int *);
    int(*SetDvdCaptionLanguage)(int);
    int(*GetDvdCaptionLanguage)(int *);
    int(*Set_unk14)(int);
    int(*Get_unk15)(int *);
    int(*SetFnr)(int);
    int(*GetFnr)(int *);
    int(*SetBnr)(int);
    int(*GetBnr)(int *);
    int(*SetMnr)(int);
    int(*GetMnr)(int *);
    int(*SetFnrForDvdRom)(int);
    int(*GetFnrForDvdRom)(int *);
    int(*SetBnrForDvdRom)(int);
    int(*GetBnrForDvdRom)(int *);
    int(*SetMnrForDvdRom)(int);
    int(*GetMnrForDvdRom)(int *);
    int(*SetCinemaConversion)(int);
    int(*GetCinemaConversion)(int *);
    int(*SetVolume)(int);
    int(*GetVolume)(int *);
    int(*SetDvdWideScreen)(int);
    int(*GetDvdWideScreen)(int *);
    int(*SetDvdRegionCode)(int);
    int(*GetDvdRegionCode)(int *);
    int(*SetBdRegionCode)(int);
    int(*GetBdRegionCode)(int *);
    int(*SetDvdTvSystem)(int);
    int(*GetDvdTvSystem)(int *);
    int(*SetDvdUpConvert)(int);
    int(*GetDvdUpConvert)(int *);
    int(*SetDrc)(int);
    int(*GetDrc)(int *);
    int(*GetColorButtonAssign)(int *);
    int(*SetNetworkConnect)(int);
    int(*GetNetworkConnect)(int *);
    int(*GetSoundFormatHdmi)(int *);
    int(*SetSoundFormatHdmi)(int);
    int(*GetVideoFormatHdmiColorSpace)(int *);
    int(*SetVideoFormatHdmiColorSpace)(int);
    int(*GetVideoFormatHdmi1080_24p)(int *);
    int(*SetVideoFormatHdmi1080_24p)(int);
};

class xsetting_1D6D60D4_t // printer
{
public:
    //int (*sub_4707D4) ?
    //int (*sub_470688) ?
    //int (*sub_470580) ?
    //int (*sub_470484) ?
};

class xsetting_43F98936_t
{
public:
    int(*sub_448B10)(void);   // ret 0x8002B261
    // int (*sub_448AC8) ?
    // int (*sub_4489C8) ?
    // int (*sub_448894) ?
    // int (*sub_4487B4) ?
    // int (*sub_4486C4) ?
    // int (*sub_448414) ?
    // int (*sub_448328) ?
    // int (*sub_448244) ?
    // int (*sub_447E70) ?
    // int (*sub_447964) ?
    // int (*sub_447424) ?
    // int (*sub_447220) ?
    // int (*sub_447174) ?
    // int (*sub_4470D4) ?
};

class xsetting_4712F276_t
{
public:
    //int (*sub_453EE4) ?
    //int (*sub_453E74) ?
    //int (*sub_453E0C) ?
    //int (*sub_456778) ?
    //int (*sub_4550E4) ?
    //int (*sub_457920) ?
    //int (*sub_4547A4) ?
    //int (*sub_456B00) ?
    //int (*sub_453D94) ?
    //int (*sub_453D38) ?
    //int (*sub_453CDC) ?
    //int (*sub_453C54) ?
    //int (*sub_453BCC) ?
    //int (*sub_453B58) ?
    //int (*sub_45206C) ?
    //int (*sub_453AE4) ?
    //int (*sub_453A5C) ?
    //int (*sub_4539E8) ?
    //int (*sub_453944) ?
    //int (*sub_453860) ?
    //int (*sub_45378C) ?
    //int (*sub_453660) ?
    //int (*sub_453608) ?
    //int (*sub_4566F0) ?
    //int (*sub_456460) ?
    //int (*sub_4535A8) ?
    //int (*sub_453544) ?
    //int (*sub_45441C) ?
    //int (*sub_457270) ?
    //int (*sub_455F70) ?
    //int (*sub_45756C) ?
    //int (*sub_454B54) ?
    //int (*sub_453494) ?
    //int (*sub_45341C) ?
    //int (*sub_4533D0) ?
    //int (*sub_455A8C) ?
    //int (*sub_4555D0) ?
    //int (*sub_453320) ?
    //int (*sub_453F54) ?
    //int (*sub_456F8C) ?
    //int (*sub_454F24) ?
    //int (*sub_457D48) ?
    //int (*sub_454D48) ?
    //int (*sub_457F20) ?
    //int (*sub_456D1C) ?
    //int (*sub_452E5C) ?
    //int (*sub_4528D4) ?
    //int (*sub_452DAC) ?
    //int (*sub_452838) ?
    //int (*sub_452D20) ?
    //int (*sub_452C10) ?
    //int (*sub_452B80) ?
    //int (*sub_4527BC) ?
    //int (*sub_4530C8) ?
    //int (*sub_452A40) ?
    //int (*sub_4526B0) ?
    //int (*sub_4529B0) ?
    //int (*sub_452634) ?
    //int (*sub_452AD0) ?
    //int (*sub_45272C) ?
    //int (*sub_45304C) ?
    //int (*sub_452F60) ?
    //int (*sub_452FD4) ?
    //int (*sub_452F28) ?
    //int (*sub_452EF0) ?
    //int (*sub_452C9C) ?
    //int (*sub_452934) ?
    //int (*sub_4525D0) ?
    //int (*sub_45663C) ?
    //int (*sub_452448) ?
    //int (*sub_4523C8) ?
    //int (*sub_452354) ?
    //int (*sub_4522D4) ?
    //int (*sub_452268) ?
    //int (*sub_4521F0) ?
    //int (*sub_452180) ?
    //int (*sub_452110) ?
    //int (*sub_4520AC) ?
    //int (*sub_452008) ?
};

class xsetting_58560CA4_t
{
public:
    int(*GetVideoScreenMode)(int *);
    int(*SetVideoScreenMode)(int);
    int(*GetVideoOutputChannel)(int *);
    int(*SetVideoOutputChannel)(int);
    int(*GetVideoPlayerVolume)(int *);
    int(*SetVideoPlayerVolume)(int);
};

class xsetting_5FB90B89_t // bluetooth ?
{
public:
    //int (*sub_46CB78) ?
    //int (*sub_46CB54) ?
    //int (*sub_46CB30) ?
    //int (*sub_46CB0C) ?
    //int (*sub_46CAE8) ?
    //int (*sub_46CAC4) ?
    //int (*sub_46CAA0) ?
    //int (*sub_46CA7C) ?
    //int (*sub_46CA58) ?
    //int (*sub_46CA34) ?
    //int (*sub_46CA10) ?
    //int (*sub_46C9E8) ?
    //int (*sub_46C998) ?
    //int (*sub_46C948) ?
    //int (*sub_46C8FC) ?
    //int (*sub_46C8B4) ?
    //int (*sub_46C890) ?
    //int (*sub_46C86C) ?
    //int (*sub_46C9C4) ?
    //int (*sub_46C970) ?
    //int (*sub_46C924) ?
    //int (*sub_46C8D8) ?
    //int (*sub_46C848) ?
    //int (*sub_46C824) ?
    //int (*sub_46C800) ?
    //int (*sub_46C7CC) ?
    //int (*sub_46C7A4) ?
    //int (*sub_46C77C) ?
};

class xsetting_660ECC35_t
{
public:
    int(*SetPhotoNormalScenario)(int);
    int(*GetPhotoNormalScenario)(int *);
    int(*SetPhotoSlideScenario)(int);
    int(*GetPhotoSlideScenario)(int *);
    int(*SetPhotoSlideInterval)(int);
    int(*GetPhotoSlideInterval)(int *);
    int(*SetPhotoSlideRepeat)(int);
    int(*GetPhotoSlideRepeat)(int *);
};

class xsetting_69C19C7F_t
{
public:
    //int(*sub_450C40) ?
    //int(*sub_450B8C) ?
    //int(*sub_44E990) ?
    //int(*sub_44E854) ?
    //int(*sub_44E6E8) ?
    //int(*sub_44C8E4) ?
    //int(*sub_44C8A4) ?
    //int(*sub_44C884) ?
    //int(*sub_44C854) ?
    //int(*sub_44C824) ?
    //int(*sub_44C7E4) ?
    //int(*sub_44C7C4) ?
    //int(*sub_44C794) ?
    //int(*sub_44C764) ?
    //int(*sub_44C724) ?
    //int(*sub_44C704) ?
    //int(*sub_44C6D4) ?
    //int(*sub_44BD70) ?
    //int(*sub_44BD44) ?
    //int(*sub_44BD1C) ?
    //int(*sub_44BCF4) ?
    //int(*sub_44BCCC) ?
    //int(*sub_44BCA4) ?
};

class xsetting_7125FEB5_t
{
public:
    int(*SaveMusicCodec)(int);
    int(*loadMusicCodec)(int *);
    int(*SaveBitRateAac)(int);
    int(*loadBitRateAac)(int *);
    int(*SaveBitRateMp3)(int);
    int(*loadBitRateMp3)(int *);
    int(*SaveBitRateAtrac)(int);
    int(*loadBitRateAtrac)(int *);
    int(*SaveCrossFadePlay)(int);
    int(*loadCrossFadePlay)(int *);
    int(*SaveRepeatMode)(int);
    int(*loadRepeatMode)(int *);
    int(*SaveShuffleMode)(int);
    int(*loadShuffleMode)(int *);
    int(*SaveVisualizerSelect)(int);
    int(*loadVisualizerSelect)(int *);
    int(*SaveCddaEula)(int);
    int(*loadCddaEula)(int *);
    int(*SaveCddaServer)(int);
    int(*loadCddaServer)(int *);
    int(*SaveAudioplayerVolume)(int);
    int(*loadAudioplayerVolume)(int *);
    int(*SaveSacdPlayerVolume)(int);
    int(*loadSacdPlayerVolume)(int *);
    int(*SaveAtracActivation)(int);
    int(*loadAtracActivation)(int *);
    int(*SaveWmaActivation)(int);
    int(*loadWmaActivation)(int *);
    int(*SaveCdOutputFs)(int);
    int(*loadCdOutputFs)(int *);
    int(*SaveDitherSetting)(int);
    int(*loadDitherSetting)(int *);
    int(*SaveBitmappingSetting)(int);
    int(*loadBitmappingSetting)(int *);
};

class xsetting_7EDDAD29_t
{
public:
    int(*loadParentalInformation)(void *);  // uint8_t [0x20] { parental passwordNumber, bdPc, bdPcAge, dvdRegion, dvdLevel, gameLevel, browserStartControl }
    int(*SaveDvdRegion)(char *);
    int(*SaveBdPc)(int);
    int(*SaveBdPcAge)(int);
    int(*SaveDvdRegionWithCheck)(int);
    int(*SaveDvdLevel)(int);
    int(*SaveGameLevel)(int);
    int(*SaveBrowserStartControl)(int);
};

class xsetting_8B69F85A_t
{
public:
    int(*loadDateTimeInformation)(void *);	//uint8_t [0x18] {diffTime, dateFormat, timeFormat, timeZone, summerTime }
    int(*SaveDiffTime)(int);
    int(*SaveDateFormat)(int);
    int(*SaveTimeFormat)(int);
    int(*SaveTimeZone)(int);
    int(*SaveSummerTime)(int);
    //int (*sub_448B10)(void);				// ret 0x8002B261
    //int(*sub_448C74) ?
    //int(*sub_448C40) ?
    //int(*sub_448C0C) ?					// ret 0
    //int(*sub_448BB8)(int, int);			// set timezone and summertime
    //int(*sub_448B44) ?					// ret 0
};

class xsetting_9EE60B4E_t
{
public:
    //int(*sub_4617B0) ?
    //int(*sub_461774) ?
    //int(*sub_461718) ?
    //int(*sub_4616DC) ?
    //int(*sub_4617DC) ?
    //int(*sub_461674) ?
    //int(*sub_461638) ?
    //int(*sub_4615FC) ?
    //int(*sub_4615B0) ?
    //int(*sub_461564) ?
    //int(*sub_461528) ?
    //int(*sub_4614EC) ?
    //int(*sub_4614B0) ?
    //int(*sub_461474) ?
    //int(*sub_461428) ?
    //int(*sub_4613DC) ?
    //int(*sub_461390) ?
    //int(*sub_461354) ?
    //int(*sub_461308) ?
    //int(*sub_4612BC) ?
    //int(*sub_461270) ?
    //int(*sub_461224) ?
    //int(*sub_4611E8) ?
    //int(*sub_4611AC) ?
    //int(*sub_461160) ?
    //int(*sub_461134) ?
    //int(*sub_4610F8) ?
    //int(*sub_4610BC) ?
    //int(*sub_461080) ?
    //int(*sub_461034) ?
    //int(*sub_460FF8) ?
    //int(*sub_460FBC) ?
    //int(*sub_460F70) ?
    //int(*sub_460F10) ?
    //int(*sub_460ED4) ?
    //int(*sub_460E98) ?
    //int(*sub_460E5C) ?
    //int(*sub_460E20) ?
    //int(*sub_460DF4) ?
    //int(*sub_460DC8) ?
    //int(*sub_460D8C) ?
    //int(*sub_460D50) ?
    //int(*sub_460D14) ?
    //int(*sub_460CD8) ?
    //int(*sub_460CAC) ?
    //int(*sub_460C70) ?
    //int(*sub_460C34) ?
    //int(*sub_460BE8) ?
};

class xsetting_C1008335_t // io_mouse ?
{
public:
    //int(*sub_45E244) ?
    //int(*sub_45E200) ?
    //int(*sub_45E2CC) ?
    //int(*sub_45E288) ?
    //int(*sub_45E1B8) ret 0x800315A6
    //int(*sub_45E1C4) ret 0x800315A6
    //int(*sub_45E1D0) ret 0x800315A6
    //int(*sub_45E1DC) ret 0x800315A6
    //int(*sub_45E1E8) ret 0x800315A6
    //int(*sub_45E1F4) ret 0x800315A6
};

class xsetting_CC56EB2D_t
{
public:
    int(*sub_486D98)(void);
    int(*sub_486D5C)(void);
    int(*sub_486D30)(void);
    int(*sub_486D04)(void);
    int(*sub_486CC8)(void);
    int(*sub_486C9C)(void);
    int(*sub_486C50)(void);
    int(*sub_486BF0)(void);
    int(*sub_486B84)(void);
    int(*sub_486B48)(void);
    int(*sub_486AFC)(void);
    int(*sub_486AB0)(void);
    int(*GetCurrentUserNumber)(void);
    int(*sub_486A58)(void);
    int(*sub_486A1C)(void);
    int(*sub_4869E0)(void);
    int(*GetRegistryValue)(int userid, int packetid, int *value);
    int(*GetRegistryString)(int userid, int packetid, char * value, int maxlen);
    int(*SetRegistryValue)(int userid, int packetid, int value);
    int(*SetRegistryString)(int userid, int packetid, char *value, int maxlen);
    int(*sub_486814)(void);
    int(*sub_4867D8)(void);
    int(*sub_48678C)(void);
    int(*sub_486740)(void);
    int(*sub_4866F4)(void);
    int(*sub_4866A8)(void);
    int(*sub_48665C)(void);  // ret 0x80031605
    int(*sub_486610)(void);  // ret 0x80031605
    int(*sub_4865C4)(void);  // ret 0x80031605
    int(*sub_486578)(void);  // ret 0x80031605
    int(*sub_48652C)(void);  // ret 0x80031605
    int(*sub_4864E0)(void);  // ret 0x80031605
    int(*GetRegistryHomePath)(int userid, char *path);
    int(*sub_486448)(void);
    int(*sub_48640C)(void);
    int(*sub_4863B0)(void);
    int(*sub_486384)(void);
    int(*sub_486358)(void);
    int(*sub_4862F8)(void);
    int(*sub_48628C)(void);
    int(*sub_48623C)(void);
    int(*sub_4861D4)(void);

    int GetRegistryKeyboardType() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x14, &v); return v; }
    int GetRegistryKeyboardJapaneseInput() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x15, &v); return v; }
    int GetRegistryKeyboardTradChineseInput() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x16, &v); return v; }
    int GetRegistryKeyboardBind() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x17, &v); return v; }
    int GetRegistryKeyboardRepeatStartingTime() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x18, &v); return v; }
    int GetRegistryKeyboardRepeadSpeed() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x19, &v); return v; }
    int GetRegistryMouseType() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x1E, &v); return v; }
    int GetRegistryMouseSpeed() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x1F, &v); return v; }
    int GetRegistryBrowserHomeUri(char * uri) { return GetRegistryString(GetCurrentUserNumber(), 0x28, uri, 0x80); }
    int GetRegistryBrowserCookieMode() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x29, &v); return v; }
    int GetRegistryBrowserJavascript() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x2A, &v); return v; }
    int GetRegistryBrowserDisplayMode() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x2B, &v); return v; }
    int GetRegistryBrowserExitConfirmation() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x2C, &v); return v; }
    int GetRegistryBrowserOverscan() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x2D, &v); return v; }
    int GetRegistryBrowserWindowSize() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x2E, &v); return v; }
    int GetRegistryBrowserFontSize() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x2F, &v); return v; }
    int GetRegistryBrowserEncoding() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x30, &v); return v; }
    int GetRegistryBrowserCacheSize() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x31, &v); return v; }
    int GetRegistryBrowserRestoreWindow() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x32, &v); return v; }
    int GetRegistryBrowserPopupBlock() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x33, &v); return v; }
    int GetRegistryBrowserDpi() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x34, &v); return v; }
    int GetRegistryBrowserInterlaceFilter() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x35, &v); return v; }
    int GetRegistryBrowserIfilter() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x36, &v); return v; }
    int GetRegistryBrowserIfilterAddress() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x37, &v); return v; }
    int GetRegistryBrowserIfilterPort() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x38, &v); return v; }
    int GetRegistryBrowserIfilterUsername() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x39, &v); return v; }
    int GetRegistryBrowserIfilterPassword() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x3A, &v); return v; }
    int GetRegistryBrowserIfilterBase64() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x3B, &v); return v; }
    int GetRegistryBrowserTrendEula() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x3C, &v); return v; }
    int GetRegistryBrowserTrendEnable() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x3D, &v); return v; }
    int GetRegistryInputForecastDictionary() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x46, &v); return v; }
    int GetRegistryInputTenKeyInputType() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x47, &v); return v; }
    int GetRegistryInputForecastDictionaryCh() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x48, &v); return v; }
    int GetRegistryInputKeyLayoutType() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x49, &v); return v; }
    int GetRegistryEdyEula() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x50, &v); return v; }
    int GetRegistryThemeWallpaper() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x5A, &v); return v; }
    int GetRegistryThemeFont() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x5B, &v); return v; }
    int GetRegistryThemeFontEu() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x5C, &v); return v; }
    int GetRegistryThemeFontRu() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x5D, &v); return v; }
    int GetRegistryThemeFile(char * f) { return GetRegistryString(GetCurrentUserNumber(), 0x5E, f, 0x80); }
    int GetRegistryThemeColor() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x5F, &v); return v; }
    int GetRegistryThemeEndarkbg() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x60, &v); return v; }
    int GetRegistryMicPitchshift() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x64, &v); return v; }
    int GetRegistryUserRestoreSignInPassword(char * p) { return GetRegistryString(GetCurrentUserNumber(), 0x6E, p, 0x80); }
    int GetRegistryUserRestoreSignInStatus() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x6F, &v); return v; }
    int GetRegistryYtaccountAccountid(char * a) { return GetRegistryString(GetCurrentUserNumber(), 0x78, a, 0x80); }
    int GetRegistryYtaccountPassword(char * p) { return GetRegistryString(GetCurrentUserNumber(), 0x79, p, 0x80); }
    int GetRegistryNpGuestCountry(char * c) { return GetRegistryString(GetCurrentUserNumber(), 0x82, c, 0x80); }
    int GetRegistryNpGuestLang(char * l) { return GetRegistryString(GetCurrentUserNumber(), 0x83, l, 0x80); }
    int GetRegistryNpGuestBirth() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x84, &v); return v; }
    int GetRegistryWBoardEnable() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x8C, &v); return v; }
    int GetRegistryWBoardFocusMask(){ int v; GetRegistryValue(GetCurrentUserNumber(), 0x8D, &v); return v; }
    int GetRegistryNetOnlineFlag() { int v; GetRegistryValue(GetCurrentUserNumber(), 0x96, &v); return v; }
    int GetRegistryFacebookAccount(char * a) { return GetRegistryString(GetCurrentUserNumber(), 0xC8, a, 0x80); }
    int GetRegistryFacebookSessionKey() { int v; GetRegistryValue(GetCurrentUserNumber(), 0xC9, &v); return v; }
    int GetRegistryFacebookSessionSecret() { int v; GetRegistryValue(GetCurrentUserNumber(), 0xCA, &v); return v; }
    int GetRegistryFacebookUid() { int v; GetRegistryValue(GetCurrentUserNumber(), 0xCB, &v); return v; }
    int GetRegistryFacebookTrophy() { int v; GetRegistryValue(GetCurrentUserNumber(), 0xCC, &v); return v; }
    int GetRegistryFacebookPurchase() { int v; GetRegistryValue(GetCurrentUserNumber(), 0xCD, &v); return v; }
    int GetRegistryFacebookGameEvent() { int v; GetRegistryValue(GetCurrentUserNumber(), 0xCE, &v); return v; }
    int GetRegistryFacebookHknwEnable() { int v; GetRegistryValue(GetCurrentUserNumber(), 0xCF, &v); return v; }
    int GetRegistryFacebookAccessToken() { int v; GetRegistryValue(GetCurrentUserNumber(), 0xD0, &v); return v; }
    int GetRegistryFacebookGameIntegrations() { int v; GetRegistryValue(GetCurrentUserNumber(), 0xD1, &v); return v; }
    int GetRegistryPicasaMail(char * m) { return GetRegistryString(GetCurrentUserNumber(), 0xD2, m, 0x80); }
    int GetRegistryPicasaPassword(char * p) { return GetRegistryString(GetCurrentUserNumber(), 0xD3, p, 0x80); }
    int GetRegistryPicasaHknwEnable() { int v; GetRegistryValue(GetCurrentUserNumber(), 0xD4, &v); return v; }
    int GetRegistryFlickrMail(char * m) { return GetRegistryString(GetCurrentUserNumber(), 0xDC, m, 0x80); }
    int GetRegistryFlickrPassword(char * p) { return GetRegistryString(GetCurrentUserNumber(), 0xDD, p, 0x80); }
    int GetRegistryFacebookRating() { int v; GetRegistryValue(GetCurrentUserNumber(), 0xE6, &v); return v; }
    int SetRegistryWBoardFocusMask(int v) { return SetRegistryValue(GetCurrentUserNumber(), 0x8D, v); }
};

class xsetting_CE27E884_t
{
public:
    int(*savePremoPSPInformation)(void *); // uint8_t [0x4B8]
    int(*loadPremoPSPInformation)(void *); // uint8_t [0x4B8]
    int(*saveRemoteBoot)(int);
    int(*loadRemoteBoot)(int *);
    int(*saveBootCount)(int);
    int(*loadBootCount)(int *);
    int(*savePowerOffTime)(void *);
    int(*loadPowerOffTime)(void *);
    int(*saveAudioConfig)(int);
    int(*loadAudioConfig)(int *);
};

class xsetting_D0261D72_t
{
public:
    int(*saveAvcInitialCameraMode)(int);
    int(*loadAvcInitialCameraMode)(int *);
    int(*saveNpEnvironment)(char *, int *);              // env, len
    int(*loadNpEnvironment)(char *, int *);              // env, len
    int(*saveRegistryIntValue)(int, int);            // id, value
    int(*loadRegistryIntValue)(int, int*);           // id, value
    int(*saveRegistryStringValue)(int, char *, int); // id, string, len
    int(*loadRegistryStringValue)(int, char *, int); // id, string, len
    int(*Setunk1)(int);
    int(*Getunk2)(int, int *);
    int(*Setunk3)(int, int);

    int loadRegistryAvcVgaLastBitrate() { int v; loadRegistryIntValue(0x00, &v); return v; }											//0x00 || "/setting/avc/vga/lastBitrate"
    int loadRegistryGameLevel0Control() { int v; loadRegistryIntValue(0x01, &v); return v; }											//0x01 || "/setting/parental/gameLevel0Control"
    int loadRegistryNetworkServiceControl() { int v; loadRegistryIntValue(0x02, &v); return v; }										//0x02 || "/setting/parental/networkServiceControl"
    int loadRegistryCddaServer() { int v; loadRegistryIntValue(0x03, &v); return v; }													//0x03 || "/setting/music/cddaServer"
    int loadRegistryGameBgmPlayback() { int v; loadRegistryIntValue(0x04, &v); return v; }												//0x04 || "/setting/music/gameBgmPlayback"
    int loadRegistryGameBgmVolume() { int v; loadRegistryIntValue(0x05, &v); return v; }												//0x05 || "/setting/music/gameBgmVolume"
    int loadRegistryDummyBgmPlayer() { int v; loadRegistryIntValue(0x06, &v); return v; }												//0x06 || "/setting/music/dummyBgmPlayer"
    int loadRegistryDynamicNormalizer() { int v; loadRegistryIntValue(0x07, &v); return v; }											//0x07 || "/setting/music/dynamicNormalizer"
    int loadRegistryNpDebug() { int v; loadRegistryIntValue(0x08, &v); return v; }														//0x08 || "/setting/np/debug"
    int loadRegistryNpTitleId(char * titleid, int max_len) { return loadRegistryStringValue(0x09, titleid, max_len); }					//0x09 || "/setting/np/titleId"
    int loadRegistryNavOnly() { int v; loadRegistryIntValue(0x0A, &v); return v; }														//0x0A || "/setting/np/navOnly"
    int loadRegistryNpAdClockDiff() { int v; loadRegistryIntValue(0x0B, &v); return v; }												//0x0B || "/setting/np/npAdClockDiff"
    int loadRegistryDebugDrmError() { int v; loadRegistryIntValue(0x0C, &v); return v; }												//0x0C || "/setting/np/debugDrmError"
    int loadRegistryDebugDrmClock() { int v; loadRegistryIntValue(0x0D, &v); return v; }												//0x0D || "/setting/np/debugDrmClock"
    int loadRegistryDebugConsoleBind() { int v; loadRegistryIntValue(0x0E, &v); return v; }												//0x0E || "/setting/np/debugConsoleBind"
    int loadRegistryDebugIngameCommerce2() { int v; loadRegistryIntValue(0x0F, &v); return v; }											//0x0F || "/setting/np/debugIngameCommerce2"
    int loadRegistryDebugSFForce() { int v; loadRegistryIntValue(0x10, &v); return v; }													//0x10 || "/setting/np/debugSFForce"
    int loadRegistryDebugSFManifest() { int v; loadRegistryIntValue(0x11, &v); return v; }												//0x11 || "/setting/np/debugSFManifest"
    int loadRegistryDebugSFManifestURL() { int v; loadRegistryIntValue(0x12, &v); return v; }											//0x12 || "/setting/np/debugSFManifestURL"
    int loadRegistryNpGeoFiltering() { int v; loadRegistryIntValue(0x13, &v); return v; }												//0x13 || "/setting/np/npGeoFiltering"
    int loadRegistryGameUpdateImposeTest() { int v; loadRegistryIntValue(0x14, &v); return v; }											//0x14 || "/setting/np/gameUpdateImposeTest"
    int loadRegistryGameUpdateForceOverwrite() { int v; loadRegistryIntValue(0x15, &v); return v; }										//0x15 || "/setting/np/gameUpdateForceOverwrite"
    int loadRegistryFakeNpSnsThrottle() { int v; loadRegistryIntValue(0x16, &v); return v; }											//0x16 || "/setting/np/fakeNpSnsThrottle"
    int loadRegistryFakeNpSnsThrottleWaitSeconds() { int v; loadRegistryIntValue(0x17, &v); return v; }									//0x17 || "/setting/np/fakeNpSnsThrottleWaitSeconds"
    int loadRegistryTppsProxyFlag() { int v; loadRegistryIntValue(0x18, &v); return v; }												//0x18 || "/setting/np/tppsProxyFlag"
    int loadRegistryTppsProxyServer(char * server, int max_len) { return loadRegistryStringValue(0x19, server, max_len); }  // ???		//0x19 || "/setting/np/tppsProxyServer"
    int loadRegistryTppsProxyPort() { int v; loadRegistryIntValue(0x1A, &v); return v; }												//0x1A || "/setting/np/tppsProxyPort"
    int loadRegistryTppsProxyUserName(char * username, int max_len) { return loadRegistryStringValue(0x1B, username, max_len); }		//0x1B || "/setting/np/tppsProxyUserName"
    int loadRegistryTppsProxyPassword(char * password, int max_len) { return loadRegistryStringValue(0x1C, password, max_len); }		//0x1C || "/setting/np/tppsProxyPassword"
    int loadRegistryRegion() { int v; loadRegistryIntValue(0x1D, &v); return v; }														//0x1D || "/setting/system/region"
    int loadRegistryNotificationTrophy() { int v; loadRegistryIntValue(0x1E, &v); return v; }											//0x1E || "/setting/system/notificationTrophy"
    int loadRegistryLicenseArea() { int v; loadRegistryIntValue(0x1F, &v); return v; }													//0x1F || "/setting/system/licenseArea"
    int loadRegistryHddSerial(char * hddserial) { return loadRegistryStringValue(0x20, hddserial, 0x3D); }								//0x20 || "/setting/system/hddSerial"
    int loadRegistryCoreDump() { int v; loadRegistryIntValue(0x21, &v); return v; }														//0x21 || "/setting/system/coreDump"
    int loadRegistryCoreDumpOptionTrigger() { int v; loadRegistryIntValue(0x22, &v); return v; }										//0x22 || "/setting/system/coreDumpOptionTrigger"
    int loadRegistryCoreDumpOptionFileGen() { int v; loadRegistryIntValue(0x23, &v); return v; }										//0x23 || "/setting/system/coreDumpOptionFileGen"
    int loadRegistryCoreDumpOptionExeCtrl() { int v; loadRegistryIntValue(0x24, &v); return v; }										//0x24 || "/setting/system/coreDumpOptionExeCtrl"
    int loadRegistryMatEnable() { int v; loadRegistryIntValue(0x25, &v); return v; }													//0x25 || "/setting/system/matEnable"
    int loadRegistryUpdateServerUrl(char * url, int max_len) { return loadRegistryStringValue(0x26, url, max_len); }					//0x26 || "/setting/system/updateServerUrl"
    int loadRegistryFakeLimitSize() { int v; loadRegistryIntValue(0x27, &v); return v; }												//0x27 || "/setting/system/fakeLimitSize"
    int loadRegistryFakeFreeSpace() { int v; loadRegistryIntValue(0x28, &v); return v; }												//0x28 || "/setting/system/fakeFreeSpace"
    int loadRegistryFakeSavedataOwner() { int v; loadRegistryIntValue(0x29, &v); return v; }											//0x29 || "/setting/system/fakeSavedataOwner"
    int loadRegistryFakeHddSpeed() { int v; loadRegistryIntValue(0x2A, &v); return v; }													//0x2A || "/setting/system/fakeHddSpeed"
    int loadRegistryDebugGameType() { int v; loadRegistryIntValue(0x2B, &v); return v; }												//0x2B || "/setting/system/debugGameType"
    int loadRegistryDebugBootPath() { int v; loadRegistryIntValue(0x2C, &v); return v; }												//0x2C || "/setting/system/debugBootPath"
    int loadRegistryDebugDirName(char * path, int max_len) { return loadRegistryStringValue(0x2D, path, max_len); }						//0x2D || "/setting/system/debugDirName"
    int loadRegistryAppHomeBootPath() { int v; loadRegistryIntValue(0x2E, &v); return v; }												//0x2E || "/setting/system/appHomeBootPath"
    int loadRegistryWolDex() { int v; loadRegistryIntValue(0x2F, &v); return v; }														//0x2F || "/setting/system/wolDex"
    int loadRegistryDispHddSpace() { int v; loadRegistryIntValue(0x30, &v); return v; }													//0x30 || "/setting/system/dispHddSpace"
    int loadRegistryAutoNetworkUpdate() { int v; loadRegistryIntValue(0x31, &v); return v; }											//0x31 || "/setting/system/autoNetworkUpdate"
    int loadRegistryAutoPowerOff() { int v; loadRegistryIntValue(0x32, &v); return v; }													//0x32 || "/setting/system/autoPowerOff"
    int loadRegistryAutoPowerOffEx() { int v; loadRegistryIntValue(0x33, &v); return v; }												//0x33 || "/setting/system/autoPowerOffEx"
    int loadRegistryAutoPowerOffDebug() { int v; loadRegistryIntValue(0x34, &v); return v; }											//0x34 || "/setting/system/autoPowerOffDebug"
    int loadRegistryHdmiControl() { int v; loadRegistryIntValue(0x35, &v); return v; }													//0x35 || "/setting/system/hdmiControl"
    int loadRegistryHdmiControlEx() { int v; loadRegistryIntValue(0x36, &v); return v; }												//0x36 || "/setting/system/hdmiControlEx"
    int loadRegistryPowerOnDiscBoot() { int v; loadRegistryIntValue(0x37, &v); return v; }												//0x37 || "/setting/system/powerOnDiscBoot"
    int loadRegistryPowerOnReset() { int v; loadRegistryIntValue(0x38, &v); return v; }													//0x38 || "/setting/system/powerOnReset"
    int loadRegistryDisable15Timeout() { int v; loadRegistryIntValue(0x39, &v); return v; }												//0x39 || "/setting/system/disable15Timeout"
    int loadRegistryDebugSystemUpdate() { int v; loadRegistryIntValue(0x3A, &v); return v; }											//0x3A || "/setting/system/debugSystemUpdate"
    int loadRegistryFakePlus() { int v; loadRegistryIntValue(0x3B, &v); return v; }														//0x3B || "/setting/system/fakePlus"
    int loadRegistryTurnOffWarning() { int v; loadRegistryIntValue(0x3C, &v); return v; }												//0x3C || "/setting/system/turnOffWarning"
    int loadRegistryBootMode(char * bootmode, int max_len) { return loadRegistryStringValue(0x3D, bootmode, max_len); }					//0x3D || "/setting/system/bootMode"
    int loadRegistryCrashreportCrepo() { int v; loadRegistryIntValue(0x3E, &v); return v; }												//0x3E || "/setting/system/crashreport/crepo"
    int loadRegistryCrashreportReporterStatus() { int v; loadRegistryIntValue(0x3F, &v); return v; }									//0x3F || "/setting/system/crashreport/reporterStatus"
    int loadRegistryCrashreportVshGeneratorEnableFlag() { int v; loadRegistryIntValue(0x40, &v); return v; }							//0x40 || "/setting/system/crashreport/vshGeneratorEnableFlag"
    int loadRegistryDateTimeAutoCorrection() { int v; loadRegistryIntValue(0x41, &v); return v; }										//0x41 || "/setting/dateTime/autoCorrection"
    int loadRegistryAutobootStartTime() { int v; loadRegistryIntValue(0x42, &v); return v; }											//0x42 || "/setting/autoboot/startTime"
    int loadRegistryEdyDebug() { int v; loadRegistryIntValue(0x43, &v); return v; }														//0x43 || "/setting/edy/debug"
    int loadRegistryUpConvert() { int v; loadRegistryIntValue(0x44, &v); return v; }													//0x44 || "/setting/video/upConvert"
    int loadRegistryFnrLevel() { int v; loadRegistryIntValue(0x45, &v); return v; }														//0x45 || "/setting/video/fnr"
    int loadRegistryBnrLevel() { int v; loadRegistryIntValue(0x46, &v); return v; }														//0x46 || "/setting/video/bnr"
    int loadRegistryMnrLevel() { int v; loadRegistryIntValue(0x47, &v); return v; }														//0x47 || "/setting/video/mnr"
    int loadRegistrySequentialPlay() { int v; loadRegistryIntValue(0x48, &v); return v; }												//0x48 || "/setting/video/sequentialPlay"
    int loadRegistryHD50HzOutput() { int v; loadRegistryIntValue(0x49, &v); return v; }													//0x49 || "/setting/video/hd50HzOutput"
    int loadRegistryOutputExtMenu() { int v; loadRegistryIntValue(0x4A, &v); return v; }												//0x4A || "/setting/video/outputExtMenu"
    int loadRegistryOutputExtFunc() { int v; loadRegistryIntValue(0x4B, &v); return v; }												//0x4B || "/setting/video/outputExtFunc"
    int loadRegistryDtcpIpSettingMenu() { int v; loadRegistryIntValue(0x4C, &v); return v; }											//0x4C || "/setting/video/dtcpipActMenu"
    int loadRegistryDefaultSubTitleLanguage() { int v; loadRegistryIntValue(0x4D, &v); return v; }										//0x4D || "/setting/video/hddCaptionLanguage"
    int loadRegistryDefaultAudioLanguage() { int v; loadRegistryIntValue(0x4E, &v); return v; }											//0x4E || "/setting/video/hddSoundLanguage"
    int loadRegistryDefaultClosedCaption() { int v; loadRegistryIntValue(0x4F, &v); return v; }											//0x4F || "/setting/video/closedCaption"
    int loadRegistryEmuUpConvert() { int v; loadRegistryIntValue(0x50, &v); return v; }													//0x50 || "/setting/game/emuUpConvert"
    int loadRegistryEmuSmoothing() { int v; loadRegistryIntValue(0x51, &v); return v; }													//0x51 || "/setting/game/emuSmoothing"
    int loadRegistryMinisUpConvert() { int v; loadRegistryIntValue(0x52, &v); return v; }												//0x52 || "/setting/game/minisUpConvert"
    int loadRegistryPspemuViewmode() { int v; loadRegistryIntValue(0x53, &v); return v; }												//0x53 || "/setting/game/pspemuViewmode"
    int loadRegistryPspemu3dDisplay() { int v; loadRegistryIntValue(0x54, &v); return v; }												//0x54 || "/setting/game/pspemu3dDisplay"
    int loadRegistryPspemu3dDepthAdjust() { int v; loadRegistryIntValue(0x55, &v); return v; }											//0x55 || "/setting/game/pspemu3dDepthAdjust"
    int loadRegistryPspemu3dMenu() { int v; loadRegistryIntValue(0x56, &v); return v; }													//0x56 || "/setting/game/pspemu3dMenu"
    int loadRegistryPspemuAdhocModeWlan() { int v; loadRegistryIntValue(0x57, &v); return v; }											//0x57 || "/setting/game/pspemuAdhocModeWlan"
    int loadRegistryPspemuAdhocModeCh() { int v; loadRegistryIntValue(0x58, &v); return v; }											//0x58 || "/setting/game/pspemuAdhocModeCh"
    int loadRegistryPs2emuSaveUtility() { int v; loadRegistryIntValue(0x59, &v); return v; }											//0x59 || "/setting/game/ps2emuSaveUtility"
    int loadRegistryPs2softemuFunc() { int v; loadRegistryIntValue(0x5A, &v); return v; }												//0x5A || "/setting/game/ps2softemuFunc"
    int loadRegistryPs2BgCaution() { int v; loadRegistryIntValue(0x5B, &v); return v; }													//0x5B || "/setting/game/ps2BgCaution"
    int loadRegistryCameraPlfreq() { int v; loadRegistryIntValue(0x5C, &v); return v; }													//0x5C || "/setting/camera/plfreq"
    int loadRegistryTvCategory() { int v; loadRegistryIntValue(0x5D, &v); return v; }													//0x5D || "/setting/xmb/tvCategory"
    int loadRegistryHomeInstaller() { int v; loadRegistryIntValue(0x5E, &v); return v; }												//0x5E || "/setting/xmb/homeInstaller"
    int loadRegistryHomeQAMode() { int v; loadRegistryIntValue(0x5F, &v); return v; }													//0x5F || "/setting/xmb/homeQAMode"
    int loadRegistryDummyInGameXMB() { int v; loadRegistryIntValue(0x60, &v); return v; }												//0x60 || "/setting/xmb/dummyInGameXMB"
    int loadRegistryYconExplained() { int v; loadRegistryIntValue(0x61, &v); return v; }												//0x61 || "/setting/xmb/yconExplained"
    int loadRegistryXaiDebugFlag() { int v; loadRegistryIntValue(0x62, &v); return v; }													//0x62 || "/setting/xai/debugFlag"
    int loadRegistryAdServerURL(char * url, int max_len) { return loadRegistryStringValue(0x63, url, max_len); }						//0x63 || "/setting/libad/adServerURL"
    int loadRegistryAdCatalogVersion(char * version, int max_len) { return loadRegistryStringValue(0x64, version, max_len); }			//0x64 || "/setting/libad/adCatalogVersion"
    int loadRegistryAdEnableNotification() { int v; loadRegistryIntValue(0x65, &v); return v; }											//0x65 || "/setting/libad/adEnableNotification"
    int loadRegistryUploadDebug() { int v; loadRegistryIntValue(0x66, &v); return v; }													//0x66 || "/setting/upload/debug"
    int loadRegistryNetAutoDlDebug() { int v; loadRegistryIntValue(0x67, &v); return v; }												//0x67 || "/setting/net/autoDlDebug"
    int loadRegistryNetAutoDlFlag() { int v; loadRegistryIntValue(0x68, &v); return v; }												//0x68 || "/setting/net/autoDlFlag"
    int loadRegistryNetAutoDlTime() { int v; loadRegistryIntValue(0x69, &v); return v; }												//0x69 || "/setting/net/autoDlTime"
    int loadRegistryNetAutoDlFunc() { int v; loadRegistryIntValue(0x6A, &v); return v; }												//0x6A || "/setting/net/autoDlFunc"
    int loadRegistryNetEmulationType() { int v; loadRegistryIntValue(0x6B, &v); return v; }   // questionable							//0x6B || "/setting/net/emulationType"
    int loadRegistryNetAdhocSsidPrefix(char * prefix, int max_len) { return loadRegistryStringValue(0x6C, prefix, max_len); }			//0x6C || "/setting/net/adhocSsidPrefix"
    int loadRegistryPadVibrationEnable() { int v; loadRegistryIntValue(0x6D, &v); return v; }											//0x6D || "/setting/pad/vibrationEnable"
    int loadRegistryPadAutoPowerOff() { int v; loadRegistryIntValue(0x6E, &v); return v; }												//0x6E || "/setting/pad/autoPowerOff"
    int loadRegistryPadMagnetometer() { int v; loadRegistryIntValue(0x6F, &v); return v; }												//0x6F || "/setting/pad/magnetometer"
    int loadRegistrySound0Initial() { int v; loadRegistryIntValue(0x70, &v); return v; }												//0x70 || "/setting/sound/0/initial"
    int loadRegistrySound1UsbHeadSetSound() { int v; loadRegistryIntValue(0x71, &v); return v; }   // questionable						//0x71 || "/setting/sound/1/usbHeadsetSound"
    int loadRegistryDlnaFlag() { int v; loadRegistryIntValue(0x72, &v); return v; }														//0x72 || "/setting/dlna/dlnaFlag"
    int loadRegistryDlnaDtcpipDevCert() { int v; loadRegistryIntValue(0x73, &v); return v; }   // questionable							//0x73 || "/setting/dlna/dtcpipDevCert"
    int loadRegistryBrowserTrendEula() { int v; loadRegistryIntValue(0x74, &v); return v; }												//0x74 || "/setting/browser/trendEula"
    int loadRegistryBrowserTrendEnable() { int v; loadRegistryIntValue(0x75, &v); return v; }											//0x75 || "/setting/browser/trendEnable"
    int loadRegistryBrowserTrendLastTime() { int v; loadRegistryIntValue(0x76, &v); return v; }											//0x76 || "/setting/browser/trendLastTime"
    int loadRegistryBrowserTrendTtl() { int v; loadRegistryIntValue(0x77, &v); return v; }												//0x77 || "/setting/browser/trendTtl"
    int loadRegistryBrowserTrendRegistered() { int v; loadRegistryIntValue(0x78, &v); return v; }										//0x78 || "/setting/browser/trendRegistered"
    int loadRegistryBrowserHeapSize() { int v; loadRegistryIntValue(0x79, &v); return v; }												//0x79 || "/setting/browser/heapSize"
    int loadRegistryBrowserDebugMenu() { int v; loadRegistryIntValue(0x7A, &v); return v; }												//0x7A || "/setting/browser/debugMenu"
    int loadRegistryBrowserType() { int v; loadRegistryIntValue(0x7B, &v); return v; }													//0x7B || "/setting/browser/browserType"
    int loadRegistryWboardBaseUri(char * uri, int max_len) { return loadRegistryStringValue(0x7C, uri, max_len); }						//0x7C || "/setting/wboard/baseUri"
    int loadRegistrySmssTargetServer() { int v; loadRegistryIntValue(0x7D, &v); return v; }												//0x7D || "/setting/smss/targetServer"
    int loadRegistrySmssResultOutput() { int v; loadRegistryIntValue(0x7E, &v); return v; }												//0x7E || "/setting/smss/resultOutput"
    int loadRegistryDisplayForceEnable3D() { int v; loadRegistryIntValue(0x7F, &v); return v; }											//0x7F || "/setting/display/forceEnable3D"
    int loadRegistryDisplayScreenSize() { int v; loadRegistryIntValue(0x80, &v); return v; }											//0x80 || "/setting/display/screenSize"
    int loadRegistryDisplayDeepColor() { int v; loadRegistryIntValue(0x81, &v); return v; }												//0x81 || "/setting/display/deepColor"
};

class xsetting_ED5B559F_t
{
public:
    //int (*sub_45E35C) ?  Export_sys_io_sys_config_add_service_listener()
    //int (*sub_45E328) ?  Export_sys_io_sys_config_remove_service_listener()
    //int (*sub_45E750) ?
    //int (*sub_45E6FC) ?
    //int (*sub_45E6A8) ?
    //int (*sub_45E644) ?
    //int (*sub_45E310) ?
    //int (*sub_45E600) ?
    //int (*sub_45E5BC) ?
    //int (*sub_45E578) ?  Export_sdk_4AF81871_io_pad_DisconnectGamePad()
    //int (*sub_45E544) ?
    //int (*sub_45E510) ?
    //int (*sub_45E4AC) ?
    //int (*sub_45E448) ?
    //int (*sub_45E3F4) ?
    //int (*sub_45E3A0) ?
};

class xsetting_F48C0548_t
{
public:
    struct address_t
    {
        char addr[0x10];
    };

    struct lease_info_t
    {
        char ip[0x10];
        uint64_t time;
    };

    struct wireless_info_t
    {
        char ssid[0x20];
        char passPhrase[41];
    };

    struct net_info_t
    {
        int device;								//0x000:
        int etherMode;							//0x004:
        int authProto;							//0x008:
        char wirelessPassPhrase[0x41];			//0x00C: wepKey[0x1A] wpaKey[0x40]
        char ssid[0x20];						//0x04D: ssid[0x20]
        char pad0[3];							//0x06D
        int auth8021xType;						//0x070: int auth8021xType
        char auth8021xAuthName[0x80];			//0x074: auth8021xAuthName[0x80]
        char auth8021xAuthKey[0x80];			//0x0F4: auth8021xAuthKey[0x80]
        int howToSetupIp;						//0x174:
        char dhcpHostName[0xFF];				//0x178: dhcpHostName[0xFF]
        char authName[0x80];					//0x277: authName[0x80]
        char authKey[0x80];						//0x2F7: authKey[0x80]
        char ipAddress[0x10];					//0x377: ipAddress[0x10]
        char netmask[0x10];						//0x387: netmask[0x10]
        char defaultRoute[0x10];				//0x397: defaultRoute[0x10]
        char pad1;								//0x3A7
        int dnsFlag;							//0x3A8:
        char primaryDns[0x10];					//0x3AC:
        char secondaryDns[0x10];				//0x3BC:
        int httpProxyFlag;						//0x3CC:
        char httpProxyServer[0x100];			//0x3D0:
        short httpProxyPort;					//0x4D0:
        short pad2;								//0x4D2
        int mtu;								//0x4D4:
        int upnpFlag;							//0x4D8:
        int aossFlag;							//0x4DC:
        char aossWep64Ssid[0x20];				//0x4E0:
        char aossWep64Key[0x41];				//0x500:
        char aossWep128Ssid[0x20];				//0x541:
        char aossWep128Key[0x41];				//0x561:
        char aossWpaPskTkipSsid[0x20];			//0x5A2:
        char aossWpaPskTkipKey[0x41];			//0x5C2:
        char aossWpaPskAesSsid[0x20];			//0x603:
        char aossWpaPskAesKey[0x41];			//0x623:
    };

public:
    int(*SetSettingNet_enable)(int);
    int(*GetSettingNet_enable)(int *);
    int(*SetSettingNet_device)(int);
    int(*GetSettingNet_device)(int *);
    int(*SetSettingNet_apAutoConfig)(int);
    int(*GetSettingNet_apAutoConfig)(int *);
    int(*SetSettingNet_eapMd5)(int);
    int(*GetSettingNet_eapMd5)(int *);
    int(*SetSettingNet_howToSetupIp)(int);
    int(*GetSettingNet_howToSetupIp)(int *);
    int(*SetSettingNet_ipAddress)(address_t *);
    int(*GetSettingNet_ipAddress)(address_t *);
    int(*SetSettingNet_netmask)(address_t *);
    int(*GetSettingNet_netmask)(address_t *);
    int(*SetSettingNet_defaultRoute)(address_t *);
    int(*GetSettingNet_defaultRoute)(address_t *);
    int(*SetSettingNet_dnsFlag)(int);
    int(*GetSettingNet_dnsFlag)(int *);
    int(*SetSettingNet_primaryDns)(address_t *);
    int(*GetSettingNet_primaryDns)(address_t *);
    int(*SetSettingNet_secondaryDns)(address_t *);
    int(*GetSettingNet_secondaryDns)(address_t *);
    int(*SetSettingNet_httpProxyFlag)(int);
    int(*GetSettingNet_httpProxyFlag)(int *);

    int(*sub_44A104)(void *);     // set "/setting/net/httpProxyServer"    [0x100]
    int(*sub_449F0C)(void *);     // get "/setting/net/httpProxyServer"    [0x100]

    int(*SetSettingNet_httpProxyPort)(short);
    int(*GetSettingNet_httpProxyPort)(short *);
    int(*SetSettingNet_upnpFlag)(int);
    int(*GetSettingNet_upnpFlag)(int *);

    int(*SetNetworkConfig)(net_info_t *);            // set network config, [0x664]
    int(*GetNetworkConfig)(net_info_t *);            // get network config, [0x664]
    int(*SetDeviceNetworkConfig)(int, net_info_t *);   // set network config, [0x664], arg1(device) 0 or 2
    int(*GetDeviceNetworkConfig)(int, net_info_t *);   // get network config, [0x664], arg1(device) 0 or 2

    int(*SetLeaseIPAndTime)(int, lease_info_t *);       // arg1(device) 0 or 2
    int(*GetLeaseIPAndTime)(int, lease_info_t *);       // arg1(device) 0 or 2
    int(*SetWirelessSsidAndPassPhrase)(wireless_info_t *);  // set wirelessSsid[0x20] and wirelessPassPhrase[0x41]
    int(*GetWirelessSsidAndPassPhrase)(wireless_info_t *);  // get wirelessSsid[0x20] and wirelessPassPhrase[0x41]
};

class xsetting_FFAF9B19_t
{
public:
    //int (*sub_45DEC0) ?
    //int (*sub_45DE7C) ?
    //int (*sub_45E168) ?
    //int (*sub_45E124) ?
    //int (*sub_45E0E0) ?
    //int (*sub_45E09C) ?
    //int (*sub_45E058) ?
    //int (*sub_45E014) ?
    //int (*sub_45DFD0) ?
    //int (*sub_45DF8C) ?
    //int (*sub_45DF58) ?
    //int (*sub_45DF04) ?
};

CDECL_BEGIN
xsetting_0AF1F161_t* xsetting_0AF1F161(void); // xsettings
xsetting_154430FC_t* xsetting_154430FC(void);
xsetting_16A8A805_t* xsetting_16A8A805(void);
xsetting_1D6D60D4_t* xsetting_1D6D60D4(void);
xsetting_43F98936_t* xsetting_43F98936(void);
xsetting_4712F276_t* xsetting_4712F276(void);
xsetting_58560CA4_t* xsetting_58560CA4(void);
xsetting_5FB90B89_t* xsetting_5FB90B89(void);
xsetting_660ECC35_t* xsetting_660ECC35(void);
xsetting_69C19C7F_t* xsetting_69C19C7F(void);
xsetting_7125FEB5_t* xsetting_7125FEB5(void);
xsetting_7EDDAD29_t* xsetting_7EDDAD29(void);
xsetting_8B69F85A_t* xsetting_8B69F85A(void);
xsetting_9EE60B4E_t* xsetting_9EE60B4E(void);
xsetting_C1008335_t* xsetting_C1008335(void);
xsetting_CC56EB2D_t* xsetting_CC56EB2D(void); // xuser
xsetting_CE27E884_t* xsetting_CE27E884(void);
xsetting_D0261D72_t* xsetting_D0261D72(void); //xregistry
xsetting_ED5B559F_t* xsetting_ED5B559F(void);
xsetting_F48C0548_t* xsetting_F48C0548(void); // xnet
xsetting_FFAF9B19_t* xsetting_FFAF9B19(void);
CDECL_END

#endif // __XSETTING_HPP__