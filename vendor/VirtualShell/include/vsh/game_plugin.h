// Mysis game_plugin.h v0.1
// 3141card (C style version)
#ifndef __GAME_PLUGIN_H__
#define __GAME_PLUGIN_H__
#include "vshtypes.h"

_VSH_BEGIN

typedef struct game_plugin_interface_t
{
	int32_t (*DoUnk0)(void);                                       // 0 Parameter: - set Widget "page_game_main" and activate
	int32_t (*DoUnk1)(void *);                                     // 1 Parameter: uint8_t [0x5B8]
	int32_t (*DoUnk2)(void *);                                     // 1 Parameter: uint8_t [0x230]
	int32_t (*DoUnk3)(int);                                        // 1 Parameter: int - 3 = "CB" Category
	int32_t (*DoUnk4)(int, void *);                                // 2 Parameter: int (used for func 3), uint8_t msg?dialog_struct[0x1A0]
	int32_t (*DoUnk5)(void);                                       // 0 Parameter:
	int32_t (*DoUnk6)(void);                                       // 0 Parameter:
	int32_t (*DoUnk7)(void);                                       // 0 Parameter: - set Widget "page_game_main", pageactivate and paf_55944323 /paf_FA17FC05.
	int32_t (*gameInfo)(void *);                                   // 1 Parameter: out:uint8_t [0x114] - (+4 = TitleID, +0x14 = Title, +0x94 = Title)
	int32_t (*DoUnk9)(void *);                                     // 1 Parameter: out:char* [0x80]- returns Title
	int32_t (*DoUnk10)(char *);                                    // 1 Parameter: out:uint8_t [8]
	int32_t (*DoUnk11)(unsigned long, int);                        // 2 Parameter: uint64_t data, int (0=12,other=0x13) - EventPortSend 0x100, 0x12/0x13,data
	int32_t (*DoUnk12)(void);                                      // 0 Parameter:
	int32_t (*DoUnk13)(void);                                      // 0 Parameter:
	int32_t (*DoUnk14)(void);                                      // 0 Parameter: - pad vibration related
	int32_t (*GetExecAppType)(int *, int *);                       // GetExecAppType, 2 Parameter: int * apptype, int * extendedtype?
	int32_t (*DoUnk16)(int *);                                     // 1 Parameter: int *
	int32_t (*DoUnk17)(void);                                      // 0 Parameter:
	int32_t (*DoUnk18)(int *, char *);                             // 2 Parameter: int *, char * [0x20]
	int32_t (*DoUnk19)(int *, char *, char *);                     // 3 Parameter: int *, char * [0x20], char * [0x20]
	int32_t (*DoUnk20)(void *);                                    // 1 Parameter: out: uint8_t [0x5B8]
	int32_t (*DoUnk21)(void);                                      // 0 Parameter:
	int32_t (*commerce2ExecuteStoreBrowse)(int, char *, int, int); // commerce2ExecuteStoreBrowse, 4 Parameter: int targetType, char * targetId, uint8 flags, int userdata
	int32_t (*DoUnk23)(void *);                                    // 1 Parameter: in: uint8_t [0xA4]
	int32_t (*DoUnk24)(void *);                                    // 1 Parameter: in: uint8_t [0xA4]
	int32_t (*wakeupWithGameExit)(char *, int);                    // wakeupWithGameExit, 2 Parameter: char * url [0x800], int usrdata
	int32_t (*commerce2Reboot4PrgDl)(int);                         // commerce2Reboot4PrgDl, 1 Parameter: int taskId
	int32_t (*DoUnk27)(char *);                                    // 1 Parameter: in: char * url[0x800] - "psvp:vdss?url=%s&id=0x%016llx&spd=%lld&cid=%s&fid=%s"
	int32_t (*DoUnk28)(void);                                      // RebootSignup?, 0 Parameter:
	int32_t (*DoUnk29)(void *);                                    // 1 Parameter: uint8_t [0xA4]
	int32_t (*commerce2GetOptions)(int *);                         // commerce2GetOptions, 1 Parameter: int * userdata
	int32_t (*GetUsrdataOnGameExit)(int *);                        // GetUsrdataOnGameExit, 1 Parameter: int * game_plugin_view
	int32_t (*GetManualPath)(char *);                              // Get MANUAL DirName, 1 Parameter: char [0x80]
	int32_t (*DoUnk33)(void);                                      // 0 Parameter: - is music gameBgmPlayback allowed check
	int32_t (*DoUnk34)(char *);                                    // 1 Parameter: char * [0x20]
	int32_t (*DoUnk35)(char *);                                    // 1 Parameter: char * DirName[0x20] - tmp game lock
	int32_t (*DoUnk36)(int, char *);                               // 2 Parameter: int * , char * - no size check
	int32_t (*DoUnk37)(void);                                      // 0 Parameter:
	int32_t (*DoUnk38)(unsigned long);                             // 1 Parameter: uint64_t data - event port send data1=0x100, data2=0x14, data3=input
	int32_t (*DoUnk39)(char *);                                    // 1 Parameter: char * titleid [0x20]
	int32_t (*DoUnk40)(char *, int *, int);                        // 3 Parameter: char * titleid [0x20], int* , MemoryContainer cid
	int32_t (*DoUnk41)(char *, char *, int);                       // 3 Parameter: char * titleid [0x20], char * [4], MemoryContainer cid
	int32_t (*DoUnk42)(char *, int, char *, int);                  // 4 Parameter: char * titleid, int flags , char * , int
	int32_t (*DoUnk43)(void);                                      // 0 Parameter: 0
	int32_t (*DoUnk44)(void);                                      // 0 Parameter: 43) with 1
	int32_t (*initGameData)(int, int);                             // initGameData, 2 Parameter: int MemContainer(-1), int NoCalcFlag - returns Memory Container
	int32_t (*EndGameData)(void);                                  // EndGameData, 0 Parameter:
	int32_t (*getGameDataStat)(char *, char *, void *);            // getGameDataStat, 3 Parameter: char * DirName, char * CategoryType, uint8_t[0x1450]
	int32_t (*updateGameData)(char *, char *, void *, void *);     // updateGameData, 4 Parameter: char * DirName, uint32_t CategoryType, void * callback, uint8_t[0x1450] (SysParam)
	int32_t (*DoUnk49)(int, int, int, void *, char *);             // showDialog, 5 Parameter: int errcode, int, int, void * callback, char * tex?
	int32_t (*DoUnk50)(void);                                      // showDialog, 3 Parameter: char * ErrorMsg, void * callback, char * tex?
	int32_t (*DoUnk51)(void);                                      // 0 Parameter: FindWidget("page_game_main") - returns Widget View
	int32_t (*cacheInit)(void *, void *);                          // cacheInit, 2 Parameter: void * callback, uint8_t SysCacheParam[0x444] {char cacheId[0x20], char getCachePath[0x41F], void * reserved} - SysCacheMount
	int32_t (*cacheClear)(void);                                   // cacheClear, 0 Parameter: returns GameDataStat - SysCacheClear
	int32_t (*GetBootInfo)(void *);                                // bootInfo, 1 Parameter: uint8_t bootinfo[0x20] // also gets TitleId - GameGetBootDiscInfo
	int32_t (*GetTitleId)(void *);                                 // GetTitleId,1 Parameter: uint8_t * titleId [0x20]
	int32_t (*kbGetSize)(int *, int);                              // kbGetSize, 2 Parameter: int * data (=0) , int value (0,1=EventPortSend 0x10E)
	int32_t (*SetSysVersion)(char *);                              // SetSysVersion, 1 Parameter: char * SysVersion[7] (String Version for attribute "PS3_SYSTEM_VER") - GameDataSetSystemVer
	int32_t (*GetDiscInfo)(void *);                                // GetDiscInfo, 1 Parameter: uint8_t [0x20] (titleid? (0xA) from /dev_ps2disc/SYSTEM.CNF or /dev_bdvd/PS3_GAME/(L0x/)PARAM.SFO)
	int32_t (*DoUnk59)(int, int, void *, int);                     // endDialog, 4 Parameter: int dialog_msg_type (0=corrupted gamedata,1=corrupted installgame,2=update completed,3=hdd full stop game) int size, void * callback, 0
	int32_t (*SetEjectMode)(int);                                  // SetEjectMode, 1 Parameter: int mode (0=DiscGameUnregisterDiscChangeCallback,1=DiscGameRegisterDiscChangeCallback)
	int32_t (*gameExec)(char *,char *,int,int,int,int,int);        // gameExec, 7 Parameter: char * DirName (Type=1,else ""), char * DirName (Type!=1,else ""),int Type,int Options,sys_memory_container_t MemoryContainer, ExecData, UserData
	int32_t (*getList)(int *, int *, int *, int *, int);           // getList, 7 Parameter: int * ListBufNum, sys_addr_t * memory_allocate_from_container, int * ListNum, int * GetListNum, MemoryContainer,
	int32_t (*DoUnk63_GetBootInfo)(int *, char *, int *);          // GetBootInfo, 3 Parameter: int * Type, char * DirName[0x20], int * ExecData
	int32_t (*SetExecDataParam)(int *);                            // SetParam, 1 Parameter: int * ExecData - SetExitParam
	int32_t (*GetExitInfo)(int *, int *, char *, int *, int *);    // GetExitInfo, 5 Parameter: int * status, int * Type, char * DirName, uint8_t * ExecData, uint8_t * UserData
	int32_t (*HomePath)(char *);                                   // HomePath, 1 Parameter: char * HddGamePath (Playstation@Home "/dev_hdd0/game/NPEA00013/USRDIR")
	int32_t (*DeleteGame)(char *, int);                            // DeleteGame, 2 Parameter: char * DirName, sys_memory_container_t MemoryContainerId
	int32_t (*OptionPath)(char *, char *);                         // OptionPath, 2 Parameter: char * CommonPath, char * PersonalPath - GetHomeLaunchOptionPath
	int32_t (*ExportPath)(char *);                                 // ExportPath, 1 Parameter: char * ImportPath[0x80] (GetHomeDataExportPath)
	int32_t (*ImportPath)(char *);                                 // ImportPath, 1 Parameter: char * ExportPath[0x80] (GetHomeDataImportPath)
	int32_t (*Open)(int,char *, int, int *);                       // Open, 4 Parameter: int Type, char * DirName, MemoryContainer cid(-1), int * SizeInfo[3] { hddFreeSizeKB, sizeKB, sysSizeKB } - GameDataCheck
	int32_t (*BootCheck)(int *, int *, int, int *, char *);        // BootCheck, 5 Parameter: int * Type, int * Attribute, MemoryContainer cid (-1), int * SizeInfo[3] { hddFreeSizeKB, sizeKB, sysSizeKB}, char * DirName - GameBootCheck
	int32_t (*PatchCheck)(int,int *);                              // PatchCheck, 2 Parameter: int (-1), int * SizeInfo[3] {0, 0, 0} - GamePatchCheck
	int32_t (*Create)(void *, char *, char *, int);                // Create, 4 Parameter: uint8_t setData[0xD4] (GameSetInitParams), char * ContentInfoPath, char * GameDataPath, int Mode - GameCreateGameData
	int32_t (*getInt)(int, int*, int);                             // getInt, 3 Parameter: int DataId, int * DataInt, int Mode - GameGetParamInt (from PARAM.SFO)
	int32_t (*getStr)(int, char *, int, int);                      // getStr, 4 Parameter: int DataId, char * DataStr, int max_len(0x80), int Mode - GameGetParamString (from PARAM.SFO)
	int32_t (*setInt)(int, int, int);                              // setInt, 3 Parameter: int DataId, int DataInt, int Mode - GameSetParamInt (to PARAM.SFO)
	int32_t (*setStr)(int, char *, int);                           // setStr, 3 Parameter: int DataId, char * DataStr, int Mode - GameSetParamString (to PARAM.SFO)
	int32_t (*Close)(char *, char *);                              // Close, 2 Parameter: char * ContentInfoPath, char * GameDataPath - GameContentPermit
	int32_t (*DoUnk80)(int, int, char *);                          // dialog, 3 Parameter: int Type, int NeedSize, char * DirName - GameContentErrorDialog
	int32_t (*getSizeKB)(int *);                                   // getSizeKB, 1 Parameter: int * DataInt - current size of game content (KB)
	int32_t (*tInstall)(char *, char *, int, int);                 // tInstall, 4 Parameter: char * UsrDirPath, char * FileName, int Options, int (0) - GameThemeInstall
	int32_t (*mtInstall)(int);                                     // mtInstall (Create tmp file), 1 Parameter: int FileSize - ("/dev_hdd0/tmp/game/theme.tmp") - GameThemeInstallFromBuffer
	int32_t (*mtWrite)(int, void *);                               // mtWrite, 2 Parameter: int p3t_theme_size, void * buf
	int32_t (*mtClose)(int, int);                                  // mtClose, 2 Parameter: int Status (=0 continue install, else=close), int Options
	int32_t (*getUpPath)(char *);                                  // getUpPath, 1 Parameter: char * Path ("/dev_hdd0/game" + "/C01") - GameGetDiscContentInfoUpdatePath
	int32_t (*getWConPath)(char *);                                // getWConPath, 1 Parameter: char * Path (HTMLDIR - creates HTMLDIR) - GameGetLocalWebContentPath
	int32_t (*delGameData)(char *);                                // delGameData, 1 Parameter: char * DirName [0x20] - GameDeleteGameData
	int32_t (*getDevIdList)(int *, void *);                        // getDevIdList, 2 Parameter: int * DevIdListNum, uint8_t DevIdList[0x800]
	int32_t (*getDevInfo)(unsigned long, void *);                  // getDevInfo, 2 Parameter: uint64_t DevId, uint8_t DevInfo[0x70]
	int32_t (*getUsbDevInfo)(unsigned long,void *);                // getUsbDevInfo, 2 Parameter: uint64_t DevId, uint8_t DevInfo[0x86]
	int32_t (*storageMode)(void);                                  // storageMode, 0 Parameter: return int storageMode
	int32_t (*notifyCtrl)(int);                                    // notifyCtrl, 1 Parameter: int CtrlInt( 0 = page close "page_hider" widget, 1 = create "page_hider" widget)
	int32_t (*allreadyDisp)(void);                                 // allreadyDisp, 0 Parameter: (cellFsUnlink "/dev_hdd0/data/disp_change.dat")
	int32_t (*pspLoad)(void *, int);                               // pspLoad, uint8_t PspSaveParam[0xA4], sys_memory_container_t MemoryContainer
	int32_t (*pspSave)(void *, int);                               // pspSave, uint8_t PspSaveParam[0xA4], sys_memory_container_t MemoryContainer
	int32_t (*vmcAssign)(int,char *, void *, int);                 // vmcAssign, 4 Parameter: int VmcPort (0/1), char * vmcFileName, void *callback, 0 - GameDataAssignVmc
	int32_t (*ps1End)(int);                                        // ps1End, 1 Parameter: int Ps1EndMode (0-4) - GameDataExit
	int32_t (*SetPadRumble)(int);                                  // SetPadRumble, 1 Parameter: int mode - (for pad id = 0)
	int32_t (*DoUnk100)(void *, int);                              // 2 Parameter: uint8_t [0x2470] (vshcommon_34A05733("game_plugin")), int *
	int32_t (*DoUnk101)(void);                                     // 0 Parameter: - GameExit Event ?
	int32_t (*DoUnk102)(char *);                                   // 1 Parameter: char * sfo_file_path - (re)load? sfo
	int32_t (*DoUnk103_DeleteGame)(char *);                        // 1 Parameter: char * dirname -> 67) "DeleteGame" delete game with memory container -1
	int32_t (*DoUnk104)(char *);                                   // 1 Parameter: char * pkg?_filepath
} game_plugin_interface;


_VSH_END

#endif // __GAME_PLUGIN_H__