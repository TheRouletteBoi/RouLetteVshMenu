#ifndef __VSH_HPP__
#define __VSH_HPP__

#include <sys/memory.h>

namespace vsh
{
    CDECL_BEGIN

    // vsh virtual memory
    struct vm_info
    {
        uint32_t ea;                 // ea (0x70000000)
        size_t size;                 // size (32 MB)
        uint8_t flag;                // ?
    };

    int vsh_E932A8C0(const char* text); // reboot_show_min_version
    static int reboot_show_min_version(const char* text) { return vsh_E932A8C0(text); }

    // vsh_ED372406  // Export_vsh_update_manager_if_get_token_seed | _ZN2ss17update_manager_if14get_token_seedEyyyy	ss::update_manager_if::get_token_seed(unsigned long long, unsigned long long, unsigned long long, unsigned long long)

    // vsh_8E2AF83C  // Write EEPROM: 0x00048C18 (System Language),
    // vsh_92A609B2  // Write EEPROM: 0x00048C42 (HDD Copy Mode)
    // vsh_DDB635E1  // Write EEPROM: 0x00048C06 (FSELF Control Flag / toggles release mode)
    // vsh_ACDDC98E  // (void) return 1
    // vsh_80F5B53C  // Read EEPROM: 0x00048C07 (Product Mode flag) | _ZN2ss17update_manager_if15is_product_modeERh	ss::update_manager_if::is_product_mode(unsigned char &)
    // vsh_9C279BCF  // Read EEPROM: 0x00048C18 (System Language)

    // vsh_3473377C  // ? sys_ss_get_cache_of_flash_ext_flag

    // vsh_3231E012  // VTRMManagerIF_DecryptMaster | cellSsVtrmDecryptMaster
    // vsh_9B1FEAA3  // VTRManagerIF_Encrypt_With_Portability | cellSsVtrmEncryptWithPortability
    // vsh_A79070D5  // VTRManagerIF_Decrypt | cellSsVtrmDecrypt
    // vsh_4FD63C1D  // VTRMManagerIF_Encrypt | cellSsVtrmEncrypt
    // vsh_8B0BC111  // VTRManagerIF_Free | cellSsVtrmFree2
    // vsh_50C2962C  // VTRMManagerIF_Retrieve | cellSsVtrmRetrieve2
    // vsh_772E1A24  // VTRManagerIF_Store | cellSsVtrmStore2

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

    // vsh_1F80C608  // UpdateManagerIF_GetFixInstruction | cellSsUmGetFixInstruction
    // vsh_E836E451  // sys_get_cache_of_product_mode | cellSsUmGetCacheOfProductMode
    // vsh_DC980E61  // sys_ss_get_cache_of_flash_ext_flag | cellSsUmGetCacheOfFlashExtFlag
    // vsh_2068CBF3  // sys_ss_get_boot_device | cellSsUmGetBootDevice
    // vsh_42FEA6FB  // UpdateManagerIF_GetPackageInfo | cellSsUmGetPackageInfo
    // vsh_9121C0C6  // UpdateManagerIF_ReleaseBuffer  | cellSsUmReleaseBuffer
    // vsh_8A86B77C  // UpdateManagerrIF_AllocateBuffer | cellSsUmAllocateBuffer

    int vsh_172B05CD(uint32_t offset, uint8_t value);
    static int cellSsUmWriteEprom(uint32_t offset, uint8_t value) { return vsh_172B05CD(offset, value); }

    int vsh_2C563C92(uint32_t offset, uint8_t* value);
    static int cellSsUmReadEprom(uint32_t offset, uint8_t *value) { return vsh_2C563C92(offset, value); }

    // vsh_349F1535  // UpdateManagerIF_SetToken | cellSsUmSetToken
    // vsh_1B890AD2  // UpdateManagerIF_GetTokenSeed | cellSsUmGetTokenSeed
    // vsh_A10195F4  // UpdateManagerIF_GetStatus | cellSsUmGetStatus
    // vsh_DC2A512E  // UpdateManagerIF_GetExtractPackage | cellSsUmGetExtractPackage
    // vsh_3AE8D802  // UpdateManagerIF_InspectPackageTophalf | cellSsUmInspectPackage
    // vsh_2A91BB1D  // UpdateManagerIF_ExtractPackageTophalf | cellSsUmExtractPackage
    // vsh_E65867F4  // UpdateManagerIF_UpdatePackageTophalf | cellSsUmUpdatePackage

    // vsh_986EC8D3  // StorageManagerIF_control_bd_drive_HW_ps3_disc_auth | cellSsDrvAuthDiscPs3
    // vsh_26709B91  // StorageManagerIF_AuthenticateBDDrive | cellSsDrvAuthDrive
    // vsh_2B58A92C  // StorageManagerIF_AuthenticatePS3Game
    // vsh_4F3A5866  // StorageManagerIF_control_bd_drive_HW_ps3_disc_change | cellSsDrvAuthDiscChange
    // vsh_99A5F404  // StorageManagerIF_control_bd_drive_HW_ps3_hdd_game_auth
    // vsh_E20104BE  // StorageManagerIF_control_bd_drive_HW_ps3_disc_auth_disc_id

    // vsh_489102C6  // sys_ss_random_number_generator_2 | cellSsRngGetPseudoRandomNumber
    // vsh_CC31BBCF  // sys_ss_random_number_generator_1 | cellSsRngGetGenuineRandomNumber

    // vsh_CAA3E8E7  // SecureRTCManagerIF_GetTime | cellSsSrtcGetTime
    // vsh_196DB98B  // SecureRTCManagerIF_SetRTC  | cellSsSrtcSetRtc
    // vsh_9AF9918E  // SecureRTCManagerIF_SetTime | cellSsSrtcSetTime

    // vsh_3B4A1AC4  // AIMManagerIF_GetDeviceID | cellSsAimGetDeviceId
    // vsh_3F062337  // AIMManagerIF_GetPSCode   | cellSsAimChkregPsCode

    //int vsh_9AD2E524(u8 *open_psid[8]);  // sys_ss_get_open_psid | cellSsAimGetOpenPSID

    // vsh_C0E39B97  // cellSsAimIsDEHA (aim_manager_if_get_ps_code)
    // vsh_E35D54E3  // cellSsAimIsDEHXB2
    // vsh_E4A68606  // cellSsAimIsDEHXB
    // vsh_8F71C2DF  // cellSsAimGetDeviceType
    // vsh_145991B4  // cellSsAimIsARCADE AIMManagerIF: 0x19002 (Get Device Type)
    // vsh_1F80E287  // cellSsAimIsDEH AIMManagerIF: 0x19002 (Get Device Type)
    // vsh_8AD55D80  // cellSsAimIsDEX AIMManagerIF: 0x19002 (Get Device Type)
    // vsh_0F48562D  // cellSsAimIsCEX
    // vsh_703393A2  // sys_ss_access_control_engine
    // vsh_A51FFBF9  // (void) return 0

    // vsh_ED9E5178  // inflateInit2_
    // vsh_7D73E7CD  // inflateInit_
    // vsh_4DB8DD87  // inflateEnd
    // vsh_20215547  // inflate

    // vsh_1C68CC75  // uncompress

    void vsh_F4AD1B8A(int arg, vm_info *info);  // get virtual memory info
    static void GetVMInfo(vm_info *info) { vsh_F4AD1B8A(0, info); }

    // vsh_609635AB  // ? alloc
    // vsh_C0A2CB93  // ? alloc, if no real memory use virtual memory ?

    // vsh_63F9074F  // void, no return | _ZN3paf10HeapMemory19check_memory_boundsEv	paf::HeapMemory::check_memory_bounds(void)
    // vsh_8A9529BA  // printf detailed memory status in case of an mc error, module("memory_container.cpp") + line | _ZN3paf10HeapMemory16dump_sysmem_infoEPKcS2_i	paf::HeapMemory::dump_sysmem_info(char const*, char const*, int)
    // vsh_D477DB73  // _ZN3paf10HeapMemory8DumpInfoEi	paf::HeapMemory::DumpInfo(int)
    // vsh_5C5D84C1  // ?
    // vsh_3C186420  // _ZN3paf10HeapMemoryD1Ev	paf::HeapMemory::~HeapMemory()

    enum class MemoryContainer
    {
        Game,
        App,
        Debug,
        Foreground,
        Background
    };

    sys_memory_container_t vsh_E7C34044(MemoryContainer id);
    static sys_memory_container_t GetMemoryContainerById(MemoryContainer id) { return vsh_E7C34044(id); }

    int vsh_F399CA36(MemoryContainer id);
    static int DestroyMemoryContainerById(MemoryContainer id) { return vsh_F399CA36(id); }

    // vsh_37857F3F  // create_vsh_memory_container_by_id (int32_t id)

    // vsh_40E51FD1  // Heap_CheckMemoryBounds (void) return 0

    // vsh_55C6366A  // Heap_ReportMemoryBlocks
    // vsh_91C2E500  // Heap_QueryInfo
    // vsh_13A5BE24  // Heap_Trim
    // vsh_01DFD97E  // Heap_MemAlign
    // vsh_8F29A4A4  // Heap_Free
    // vsh_9FC0AA39  // Heap_ReAlloc
    // vsh_4CE8E544  // Heap_Alloc
    // vsh_8BC98CB9  // Heap_Destroy
    // vsh_44F4A936  // Heap_Create

    // vsh_FF0309A5  // Pool_QueryInfo
    // vsh_D68351F0  // Pool_Free
    // vsh_38EA9A58  // Pool_Alloc
    // vsh_278A6AF7  // Pool_Create
    // vsh_015910A0  // Pool_Destroy()

    // vsh_4B0523C4  // ? io_kb_ (sys_hid_manager_ioctl(port_no, 0x12, buf[1], 1))
    // vsh_B84451B2  // ? io_kb_ (sys_hid_manager_ioctl(port_no, 0xF, buf[2], 2))
    // vsh_5649626F  // ? io_kb_ (sys_hid_manager_ioctl(port_no, 0xD, buf[13], 13))

    // vsh_1EAC97C3  // cellFsUtilityNewfs 
    // vsh_233791FE  // ? -> vsh_1EAC97C3() | cellFsUtilNewfs
    // vsh_E44F29F4  // ? cellFsUtilityMount
    // vsh_FF4A1633  // ? -> vsh_E44F29F4() | cellFsUtilMount
    // vsh_9C4E9B5C  // syscall: sys_fs_sync() | cellFsUtilitySync
    // vsh_CFD2CA7D  // syscall: sys_fs_unmount(char const* mount, int32_t, int32_t 0) | cellFsUtilityUmount
    // vsh_339A7508  // syscall: sys_fs_unmount(char const* mount, int32_t, int32_t 1) | cellFsUtilityForceUmount
    // vsh_B517EC40  // ?

    // vsh_0D5CCC40  // ? syscall: sys_fs_fcntl(-1, 0x80000004, , 4)

    int vsh_1714D098(uint32_t *size);                 // sys_fs_get_mount_info_size() | cellFsUtilGetMountInfoSize
    static int cellFsUtilGetMountInfoSize(uint32_t *size) { return vsh_1714D098(size); }

    // vsh_612496AA  // syscall: sys_fs_get_mount_info(CellFsMountInformation *, u32, u32 *) | cellFsUtilGetMountInfo
    // vsh_E413CD78  // syscall: sys_fs_disk_free | cellFsUtilDf

    int vsh_1B8D4287(const char *dir);  // sys_fs_sync, Param: Device Path (e.g. /dev_hdd0) | cellFsUtilSync
    static int cellFsUtilSync(const char *dir) { return vsh_1B8D4287(dir); }

    // vsh_33ACD759  // (char const* mount, int32_t ?) -> sys_fs_unmount(char const* mount, int32_t, int32_t 0) | cellFsUtilUmount
    // vsh_53E57474  // (char const* mount, int32_t ?) -> sys_fs_unmount(char const* mount, int32_t, int32_t 1) | cellFsUtilForceUmount

    // vsh_18EF767F  // ?

    // vsh_AF44BFBF  // return string "CELL_FS_UTILITY:HDD0"

    // vsh_7C5A1812  // ?

    // vsh_8443023A  // ?

    // vsh_D42045F9  // return string "CELL_FS_UTILITY:HDD1"
    // vsh_9C6EEE24  // ?
    // vsh_D5B38646  // ?
    // vsh_71BBE625  // ?

    CDECL_END
}

#endif // __VSH_HPP__