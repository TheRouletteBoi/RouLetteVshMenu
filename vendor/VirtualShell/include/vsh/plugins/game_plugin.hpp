#ifndef __GAME_PLUGIN_HPP__
#define __GAME_PLUGIN_HPP__

#define _VSH_BEGIN namespace vsh {
#define _VSH_END }

_VSH_BEGIN

// Interface 1
class GamePluginInterface
{
public:
    int(*DoUnk0)(void);                                       // 0 Parameter: - set Widget "page_game_main" and activate
    int(*DoUnk1)(void *);                                     // 1 Parameter: uint8_t [0x5B8]
    int(*DoUnk2)(void *);                                     // 1 Parameter: uint8_t [0x230]
    int(*ExitGame)(int);                                      // 1 Parameter: int - (0=Exit to XMB, 3=Exit to Remote Play, 4=Focus Remote Play)
    int(*DoUnk4)(int, void *);                                // 2 Parameter: int (used for func 3), uint8_t msg?dialog_struct[0x1A0]
    int(*ExitToUpdate)(void);                                 // 0 Parameter: GameExit to system update
    int(*ReloadGame)(void);                                   // 0 Parameter:
    int(*DoUnk7)(void);                                       // 0 Parameter: - set Widget "page_game_main", pageactivate and paf_55944323 /paf_FA17FC05.
    int(*gameInfo)(void *);                                   // 1 Parameter: out:uint8_t [0x114] - (+4 = TitleID, +0x14 = Title, +0x94 = Title)
    int(*DoUnk9)(void *);                                     // 1 Parameter: out:char* [0x80]- returns Title
    int(*DoUnk10)(char *);                                    // 1 Parameter: out:uint8_t [8]
    int(*DoUnk11)(unsigned long, int);                        // 2 Parameter: uint64_t data, int (0=12,other=0x13) - EventPortSend 0x100, 0x12/0x13,data
    int(*DoUnk12)(void);                                      // 0 Parameter:
    int(*DoUnk13)(void);                                      // 0 Parameter:
    int(*DoUnk14)(void);                                      // 0 Parameter: - pad vibration related
    int(*GetExecAppType)(int *, int *);                       // GetExecAppType, 2 Parameter: int * apptype, int * extendedtype?
    int(*DoUnk16)(int *);                                     // 1 Parameter: int *
    int(*DoUnk17)(void);                                      // 0 Parameter:
    int(*DoUnk18)(int *, char *);                             // 2 Parameter: int *, char * [0x20]
    int(*DoUnk19)(int *, char *, char *);                     // 3 Parameter: int *, char * [0x20], char * [0x20]
    int(*DoUnk20)(void *);                                    // 1 Parameter: out: uint8_t [0x5B8]
    int(*DoUnk21)(void);                                      // 0 Parameter:
    int(*commerce2ExecuteStoreBrowse)(int, char *, int, int); // commerce2ExecuteStoreBrowse, 4 Parameter: int targetType, char * targetId, uint8 flags, int userdata
    int(*DoUnk23)(void *);                                    // 1 Parameter: in: uint8_t [0xA4]
    int(*DoUnk24)(void *);                                    // 1 Parameter: in: uint8_t [0xA4]
    int(*wakeupWithGameExit)(char *, int);                    // wakeupWithGameExit, 2 Parameter: char * url [0x800], int usrdata
    int(*commerce2Reboot4PrgDl)(int);                         // commerce2Reboot4PrgDl, 1 Parameter: int taskId
    int(*DoUnk27)(char *);                                    // 1 Parameter: in: char * url[0x800] - "psvp:vdss?url=%s&id=0x%016llx&spd=%lld&cid=%s&fid=%s"
    int(*DoUnk28)(void);                                      // RebootSignup?, 0 Parameter:
    int(*DoUnk29)(void *);                                    // 1 Parameter: uint8_t [0xA4]
    int(*commerce2GetOptions)(int *);                         // commerce2GetOptions, 1 Parameter: int * userdata
    int(*GetUsrdataOnGameExit)(int *);                        // GetUsrdataOnGameExit, 1 Parameter: int * game_plugin_view
    int(*GetManualPath)(char *);                              // Get MANUAL DirName, 1 Parameter: char [0x80]
    int(*DoUnk33)(void);                                      // 0 Parameter: - is music gameBgmPlayback allowed check
    int(*DoUnk34)(char *);                                    // 1 Parameter: char * [0x20]
    int(*DoUnk35)(char *);                                    // 1 Parameter: char * DirName[0x20] - tmp game lock
    int(*DoUnk36)(int, char *);                               // 2 Parameter: int * , char * - no size check
    int(*DoUnk37)(void);                                      // 0 Parameter:
    int(*DoUnk38)(unsigned long);                             // 1 Parameter: uint64_t data - event port send data1=0x100, data2=0x14, data3=input
    int(*DoUnk39)(char *);                                    // 1 Parameter: char * titleid [0x20]
    int(*DoUnk40)(char *, int *, int);                        // 3 Parameter: char * titleid [0x20], int* , MemoryContainer cid
    int(*DoUnk41)(char *, char *, int);                       // 3 Parameter: char * titleid [0x20], char * [4], MemoryContainer cid
    int(*DoUnk42)(char *, int, char *, int);                  // 4 Parameter: char * titleid, int flags , char * , int
    int(*DoUnk43)(void);                                      // 0 Parameter: 0
    int(*DoUnk44)(void);                                      // 0 Parameter: 43) with 1
    int(*initGameData)(int, int);                             // initGameData, 2 Parameter: int MemContainer(-1), int NoCalcFlag - returns Memory Container
    int(*EndGameData)(void);                                  // EndGameData, 0 Parameter:
    int(*getGameDataStat)(char *, char *, void *);            // getGameDataStat, 3 Parameter: char * DirName, char * CategoryType, uint8_t[0x1450]
    int(*updateGameData)(char *, char *, void *, void *);     // updateGameData, 4 Parameter: char * DirName, uint32_t CategoryType, void * callback, uint8_t[0x1450] (SysParam)
    int(*showErrorMsg)(int err, int, int, void *, char *tex); // showDialog, 5 Parameter: int errcode, int, int, void * callback, char * tex?
    int(*showDialog)(char *Msg, void *callback, char *tex);   // showDialog, 3 Parameter: char * ErrorMsg, void * callback, char * tex?
    int(*DoUnk51)(void);                                      // 0 Parameter: FindWidget("page_game_main") - returns Widget View
    int(*cacheInit)(void *, void *);                          // cacheInit, 2 Parameter: void * callback, uint8_t SysCacheParam[0x444] {char cacheId[0x20], char getCachePath[0x41F], void * reserved} - SysCacheMount
    int(*cacheClear)(void);                                   // cacheClear, 0 Parameter: returns GameDataStat - SysCacheClear
    int(*GetBootInfo)(void *);                                // bootInfo, 1 Parameter: uint8_t bootinfo[0x20] // also gets TitleId - GameGetBootDiscInfo
    int(*GetTitleId)(void *);                                 // GetTitleId,1 Parameter: uint8_t * titleId [0x20]
    int(*kbGetSize)(int *, int);                              // kbGetSize, 2 Parameter: int * data (=0) , int value (0,1=EventPortSend 0x10E)
    int(*SetSysVersion)(char *);                              // SetSysVersion, 1 Parameter: char * SysVersion[7] (String Version for attribute "PS3_SYSTEM_VER") - GameDataSetSystemVer
    int(*GetDiscInfo)(void *);                                // GetDiscInfo, 1 Parameter: uint8_t [0x20] (titleid? (0xA) from /dev_ps2disc/SYSTEM.CNF or /dev_bdvd/PS3_GAME/(L0x/)PARAM.SFO)
    int(*DoUnk59)(int, int, void *, int);                     // endDialog, 4 Parameter: int dialog_msg_type (0=corrupted gamedata,1=corrupted installgame,2=update completed,3=hdd full stop game) int size, void * callback, 0
    int(*SetEjectMode)(int);                                  // SetEjectMode, 1 Parameter: int mode (0=DiscGameUnregisterDiscChangeCallback,1=DiscGameRegisterDiscChangeCallback)
    int(*gameExec)(char *, char *, int, int, int, int, int);        // gameExec, 7 Parameter: char * DirName (Type=1,else ""), char * DirName (Type!=1,else ""),int Type,int Options,sys_memory_container_t MemoryContainer, ExecData, UserData
    int(*getList)(int *, int *, int *, int *, int);           // getList, 7 Parameter: int * ListBufNum, sys_addr_t * memory_allocate_from_container, int * ListNum, int * GetListNum, MemoryContainer,
    int(*DoUnk63_GetBootInfo)(int *, char *, int *);          // GetBootInfo, 3 Parameter: int * Type, char * DirName[0x20], int * ExecData
    int(*SetExecDataParam)(int *);                            // SetParam, 1 Parameter: int * ExecData - SetExitParam
    int(*GetExitInfo)(int *, int *, char *, int *, int *);    // GetExitInfo, 5 Parameter: int * status, int * Type, char * DirName, uint8_t * ExecData, uint8_t * UserData
    int(*HomePath)(char *);                                   // HomePath, 1 Parameter: char * HddGamePath (Playstation@Home "/dev_hdd0/game/NPEA00013/USRDIR")
    int(*DeleteGame)(char *, int);                            // DeleteGame, 2 Parameter: char * DirName, sys_memory_container_t MemoryContainerId
    int(*OptionPath)(char *, char *);                         // OptionPath, 2 Parameter: char * CommonPath, char * PersonalPath - GetHomeLaunchOptionPath
    int(*ExportPath)(char *);                                 // ExportPath, 1 Parameter: char * ImportPath[0x80] (GetHomeDataExportPath)
    int(*ImportPath)(char *);                                 // ImportPath, 1 Parameter: char * ExportPath[0x80] (GetHomeDataImportPath)
    int(*Open)(int, char *, int, int *);                       // Open, 4 Parameter: int Type, char * DirName, MemoryContainer cid(-1), int * SizeInfo[3] { hddFreeSizeKB, sizeKB, sysSizeKB } - GameDataCheck
    int(*BootCheck)(int *, int *, int, int *, char *);        // BootCheck, 5 Parameter: int * Type, int * Attribute, MemoryContainer cid (-1), int * SizeInfo[3] { hddFreeSizeKB, sizeKB, sysSizeKB}, char * DirName - GameBootCheck
    int(*PatchCheck)(int, int *);                              // PatchCheck, 2 Parameter: int (-1), int * SizeInfo[3] {0, 0, 0} - GamePatchCheck
    int(*Create)(void *, char *, char *, int);                // Create, 4 Parameter: uint8_t setData[0xD4] (GameSetInitParams), char * ContentInfoPath, char * GameDataPath, int Mode - GameCreateGameData
    int(*getInt)(int, int*, int);                             // getInt, 3 Parameter: int DataId, int * DataInt, int Mode - GameGetParamInt (from PARAM.SFO)
    int(*getStr)(int, char *, int, int);                      // getStr, 4 Parameter: int DataId, char * DataStr, int max_len(0x80), int Mode - GameGetParamString (from PARAM.SFO)
    int(*setInt)(int, int, int);                              // setInt, 3 Parameter: int DataId, int DataInt, int Mode - GameSetParamInt (to PARAM.SFO)
    int(*setStr)(int, char *, int);                           // setStr, 3 Parameter: int DataId, char * DataStr, int Mode - GameSetParamString (to PARAM.SFO)
    int(*Close)(char *, char *);                              // Close, 2 Parameter: char * ContentInfoPath, char * GameDataPath - GameContentPermit
    int(*DoUnk80)(int, int, char *);                          // dialog, 3 Parameter: int Type, int NeedSize, char * DirName - GameContentErrorDialog
    int(*getSizeKB)(int *);                                   // getSizeKB, 1 Parameter: int * DataInt - current size of game content (KB)
    int(*tInstall)(char *, char *, int, int);                 // tInstall, 4 Parameter: char * UsrDirPath, char * FileName, int Options, int (0) - GameThemeInstall
    int(*mtInstall)(int);                                     // mtInstall (Create tmp file), 1 Parameter: int FileSize - ("/dev_hdd0/tmp/game/theme.tmp") - GameThemeInstallFromBuffer
    int(*mtWrite)(int, void *);                               // mtWrite, 2 Parameter: int p3t_theme_size, void * buf
    int(*mtClose)(int, int);                                  // mtClose, 2 Parameter: int Status (=0 continue install, else=close), int Options
    int(*getUpPath)(char *);                                  // getUpPath, 1 Parameter: char * Path ("/dev_hdd0/game" + "/C01") - GameGetDiscContentInfoUpdatePath
    int(*getWConPath)(char *);                                // getWConPath, 1 Parameter: char * Path (HTMLDIR - creates HTMLDIR) - GameGetLocalWebContentPath
    int(*delGameData)(char *);                                // delGameData, 1 Parameter: char * DirName [0x20] - GameDeleteGameData
    int(*getDevIdList)(int *, void *);                        // getDevIdList, 2 Parameter: int * DevIdListNum, uint8_t DevIdList[0x800]
    int(*getDevInfo)(unsigned long, void *);                  // getDevInfo, 2 Parameter: uint64_t DevId, uint8_t DevInfo[0x70]
    int(*getUsbDevInfo)(unsigned long, void *);                // getUsbDevInfo, 2 Parameter: uint64_t DevId, uint8_t DevInfo[0x86]
    int(*storageMode)(void);                                  // storageMode, 0 Parameter: return int storageMode
    int(*notifyCtrl)(int);                                    // notifyCtrl, 1 Parameter: int CtrlInt( 0 = page close "page_hider" widget, 1 = create "page_hider" widget)
    int(*allreadyDisp)(void);                                 // allreadyDisp, 0 Parameter: (cellFsUnlink "/dev_hdd0/data/disp_change.dat")
    int(*pspLoad)(void *, int);                               // pspLoad, uint8_t PspSaveParam[0xA4], sys_memory_container_t MemoryContainer
    int(*pspSave)(void *, int);                               // pspSave, uint8_t PspSaveParam[0xA4], sys_memory_container_t MemoryContainer
    int(*vmcAssign)(int, char *, void *, int);                 // vmcAssign, 4 Parameter: int VmcPort (0/1), char * vmcFileName, void *callback, 0 - GameDataAssignVmc
    int(*ps1End)(int);                                        // ps1End, 1 Parameter: int Ps1EndMode (0-4) - GameDataExit
    int(*SetPadRumble)(int);                                  // SetPadRumble, 1 Parameter: int mode - (for pad id = 0)
    int(*DoUnk100)(void *, int);                              // 2 Parameter: uint8_t [0x2470] (vshcommon_34A05733("game_plugin")), int *
    int(*DoUnk101)(void);                                     // 0 Parameter: - GameExit Event ?
    int(*DoUnk102)(char *);                                   // 1 Parameter: char * sfo_file_path - (re)load? sfo
    int(*DoUnk103_DeleteGame)(char *);                        // 1 Parameter: char * dirname -> 67) "DeleteGame" delete game with memory container -1
    int(*DoUnk104)(char *);                                   // 1 Parameter: char * pkg?_filepath
};

_VSH_END

#endif // __GAME_PLUGIN_HPP__