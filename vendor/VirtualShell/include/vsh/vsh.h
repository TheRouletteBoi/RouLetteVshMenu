#ifndef __VSH_H__
#define __VSH_H__
#include "vshtypes.h"


_VSH_BEGIN
CDECL_BEGIN

// vsh vm
typedef struct _vsh_vm_info {
	uint32_t ea;                 // ea (0x70000000)
	size_t size;                 // size (32 MB)
	uint8_t flag;                // ?
} vsh_vm_info;



int vsh_E932A8C0(const char *text); // reboot_show_min_version
#define reboot_show_min_version vsh_E932A8C0

// vsh_ED372406  // Export_vsh_update_manager_if_get_token_seed

// vsh_8E2AF83C  // Write EEPROM: 0x00048C18 (System Language),
// vsh_92A609B2  // Write EEPROM: 0x00048C42 (HDD Copy Mode)
// vsh_DDB635E1  // Write EEPROM: 0x00048C06 (FSELF Control Flag / toggles release mode)
// vsh_ACDDC98E  // (void) return 1
// vsh_80F5B53C  // Read EEPROM: 0x00048C07 (Product Mode flag)
// vsh_9C279BCF  // Read EEPROM: 0x00048C18 (System Language)

// vsh_3473377C  // ? sys_ss_get_cache_of_flash_ext_flag

// vsh_3231E012  // VTRMManagerIF_DecryptMaster
// vsh_9B1FEAA3  // VTRManagerIF_Encrypt_With_Portability
// vsh_A79070D5  // VTRManagerIF_Decrypt
// vsh_4FD63C1D  // VTRMManagerIF_Encrypt
// vsh_8B0BC111  // VTRManagerIF_Free
// vsh_50C2962C  // VTRMManagerIF_Retrieve
// vsh_772E1A24  // VTRManagerIF_Store

// vsh_5A351A0A  // GamesaveStorageManagerIF_0x13
// vsh_CBF8BC6E  // GamesaveStorageManagerIF_0x04
// vsh_7CB16AA0  // GamesaveStorageManagerIF_0x12
// vsh_C13930A7  // GamesaveStorageManagerIF_0x12 (r6 = 3)
// vsh_C85E47B8  // GamesaveStorageManagerIF_0x12 (r5 = 0x42, r6 = 3)
// vsh_535A7222  // GamesaveStorageManagerIF_0x02
// vsh_6D840716  // GamesaveStorageManagerIF_0x0F
// vsh_93A6A450  // GamesaveStorageManagerIF_0x0E
// vsh_8C4215ED  // GamesaveStorageManagerIF_0x0D
// vsh_6B65C37C  // GamesaveStorageManagerIF_0x0C
// vsh_38565603  // GamesaveStorageManagerIF_0x0B
// vsh_3065B3C3  // GamesaveStorageManagerIF_0x08
// vsh_FE92A9D8  // GamesaveStorageManagerIF_0x07
// vsh_A21246C2  // GamesaveStorageManagerIF_0x06
// vsh_47FB5A92  // GamesaveStorageManagerIF_0x05

// vsh_1F80C608  // UpdateManagerIF_GetFixInstruction
// vsh_E836E451  // sys_get_cache_of_product_mode
// vsh_DC980E61  // sys_ss_get_cache_of_flash_ext_flag
// vsh_2068CBF3  // sys_ss_get_boot_device
// vsh_42FEA6FB  // UpdateManagerIF_GetPackageInfo
// vsh_9121C0C6  // UpdateManagerIF_ReleaseBuffer
// vsh_8A86B77C  // UpdateManagerrIF_AllocateBuffer

int vsh_172B05CD(uint32_t offset, uint8_t value);  // UpdateManagerIF_WriteEEPROM()
#define UpdateManagerIF_WriteEEPROM vsh_172B05CD

int vsh_2C563C92(uint32_t offset, uint8_t *value);  // UpdateManagerIF_ReadEEPROM()
#define UpdateManagerIF_ReadEEPROM vsh_2C563C92

// vsh_349F1535  // UpdateManagerIF_SetToken
// vsh_1B890AD2  // UpdateManagerIF_GetTokenSeed
// vsh_A10195F4  // UpdateManagerIF_GetStatus
// vsh_DC2A512E  // UpdateManagerIF_GetExtractPackage
// vsh_3AE8D802  // UpdateManagerIF_InspectPackageTophalf
// vsh_2A91BB1D  // UpdateManagerIF_ExtractPackageTophalf
// vsh_E65867F4  // UpdateManagerIF_UpdatePackageTophalf

// vsh_986EC8D3  // StorageManagerIF_control_bd_drive_HW_ps3_disc_auth
// vsh_26709B91  // StorageManagerIF_AuthenticateBDDrive
// vsh_2B58A92C  // StorageManagerIF_AuthenticatePS3Game
// vsh_4F3A5866  // StorageManagerIF_control_bd_drive_HW_ps3_disc_change
// vsh_99A5F404  // StorageManagerIF_control_bd_drive_HW_ps3_hdd_game_auth
// vsh_E20104BE  // StorageManagerIF_control_bd_drive_HW_ps3_disc_auth_disc_id

// vsh_489102C6  // sys_ss_random_number_generator_2
// vsh_CC31BBCF  // sys_ss_random_number_generator_1

// vsh_CAA3E8E7  // SecureRTCManagerIF_GetTime
// vsh_196DB98B  // SecureRTCManagerIF_SetRTC
// vsh_9AF9918E  // SecureRTCManagerIF_SetTime

// https://www.psdevwiki.com/ps3/AIM_Manager

int vsh_3B4A1AC4(uint8_t *idps);  // AIMManagerIF_GetDeviceID
static int cellSsAimGetDeviceId(uint8_t out[0x10]) { return vsh_3B4A1AC4(out); }

int vsh_3F062337(uint8_t *ps_code);  // AIMManagerIF_GetPSCode
static int cellSsAimGetPsCode(uint8_t out[0x8]) { return vsh_3F062337(out); }

int vsh_9AD2E524(uint8_t *open_psid);  // sys_ss_get_open_psid
static int cellSsAimGetOpenPSID(uint8_t out[0x10]) { return vsh_9AD2E524(out); }

// vsh_C0E39B97  // ? (aim_manager_if_get_ps_code)
// vsh_E35D54E3  // ?
// vsh_E4A68606  // ?

int vsh_8F71C2DF(uint8_t* type); // ?
static int cellSsAimGetDeviceType(uint8_t out[0x10]) { return vsh_8F71C2DF(out); }

// vsh_145991B4  // AIMManagerIF: 0x19002 (Get Device Type)
// vsh_1F80E287  // AIMManagerIF: 0x19002 (Get Device Type)
// vsh_8AD55D80  // AIMManagerIF: 0x19002 (Get Device Type)
// vsh_0F48562D  // ?
// vsh_703393A2  // sys_ss_access_control_engine
// vsh_A51FFBF9  // (void) return 0

// vsh_ED9E5178  // ?
// vsh_7D73E7CD  // ?
// vsh_4DB8DD87  // ?

// vsh_20215547  // ?

// vsh_1C68CC75  // ?

void vsh_F4AD1B8A(int32_t arg, vsh_vm_info *info);  // get virtual memory info
#define vsh_get_vm_info(info) vsh_F4AD1B8A(0, info)

// vsh_609635AB  // ? alloc
// vsh_C0A2CB93  // ? alloc, if no real memory use virtual memory ?

// vsh_63F9074F  // void, no return
// vsh_8A9529BA  // printf detailed memory status in case of an mc error, module("memory_container.cpp") + line
// vsh_D477DB73  // ?
// vsh_5C5D84C1  // ?
// vsh_3C186420  // ?

int32_t vsh_E7C34044(int32_t mc_id);	             // vsh_memory_container_by_id()
#define vsh_memory_container_by_id vsh_E7C34044

int32_t vsh_F399CA36(int32_t mc_id);              // destroy_vsh_memory_container_by_id()
#define destroy_vsh_memory_container_by_id vsh_F399CA36

// vsh_37857F3F  // create_vsh_memory_container_by_id (int32_t id)

// vsh_40E51FD1  // (void) return 0

// vsh_55C6366A  // ?
// vsh_91C2E500  // ?
// vsh_13A5BE24  // ?
// vsh_01DFD97E  // ?
// vsh_8F29A4A4  // ?
// vsh_9FC0AA39  // ?
// vsh_4CE8E544  // ?
// vsh_8BC98CB9  // ?
// vsh_44F4A936  // ?

// vsh_FF0309A5  // ?
// vsh_D68351F0  // ?
// vsh_38EA9A58  // ?
// vsh_278A6AF7  // ?
// vsh_015910A0  // ? Pool_Destroy()

// vsh_4B0523C4  // ? io_kb_ (sys_hid_manager_ioctl(port_no, 0x12, buf[1], 1))
// vsh_B84451B2  // ? io_kb_ (sys_hid_manager_ioctl(port_no, 0xF, buf[2], 2))
// vsh_5649626F  // ? io_kb_ (sys_hid_manager_ioctl(port_no, 0xD, buf[13], 13))

// vsh_1EAC97C3  // ?
// vsh_233791FE  // ? -> vsh_1EAC97C3()
// vsh_E44F29F4  // ?
// vsh_FF4A1633  // ? -> vsh_E44F29F4()
// vsh_9C4E9B5C  // syscall: sys_fs_sync()
// vsh_CFD2CA7D  // syscall: sys_fs_unmount(char const* mount, int32_t, int32_t 0)
// vsh_339A7508  // syscall: sys_fs_unmount(char const* mount, int32_t, int32_t 1)
// vsh_B517EC40  // ?

// vsh_0D5CCC40  // ? syscall: sys_fs_fcntl(-1, 0x80000004, , 4)

int vsh_1714D098(uint32_t *size);                 // sys_fs_get_mount_info_size()
#define sys_fs_get_mount_info_size vsh_1714D098

// vsh_612496AA  // syscall: sys_fs_get_mount_info(CellFsMountInformation *, u32, u32 *)
// vsh_E413CD78  // syscall: sys_fs_disk_free

int vsh_1B8D4287(const char *dir);  // sys_fs_sync, Param: Device Path (e.g. /dev_hdd0)
#define sys_fs_sync vsh_1B8D4287

// vsh_33ACD759  // (char const* mount, int32_t ?) -> sys_fs_unmount(char const* mount, int32_t, int32_t 0)
// vsh_53E57474  // (char const* mount, int32_t ?) -> sys_fs_unmount(char const* mount, int32_t, int32_t 1)

// vsh_18EF767F  // ?

// vsh_AF44BFBF  // return string "CELL_FS_UTILITY:HDD0"

// vsh_7C5A1812  // ?

// vsh_8443023A  // ?

// vsh_D42045F9  // return string "CELL_FS_UTILITY:HDD1"
// vsh_9C6EEE24  // ?
// vsh_D5B38646  // ?
// vsh_71BBE625  // ?


CDECL_END
_VSH_END

#endif // __VSH_H__
