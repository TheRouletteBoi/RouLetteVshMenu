#ifndef __SYS_IO_HPP__
#define __SYS_IO_HPP__

#include <cell/pad.h>
#include <cell/keyboard.h>
#include <cell/mouse.h>

namespace sys_io
{
    CDECL_BEGIN

    //sys_io_8E06D13B  // ?
    //sys_io_662BB2AD  // ?
    //sys_io_5F81900C  // sys_config_unregister_service
    //sys_io_78F058A2  // sys_config_register_service
    //sys_io_F5D9D571  // sys_config_remove_service_listener
    //sys_io_6AE10596  // sys_config_add_service_listener
    //sys_io_6D367953  // sys_config_stop
    //sys_io_068FCBC6  // sys_config_start


    // Pad
    //sys_io_E5E139DD  // ? cellPad...

    int sys_io_8A00F264(uint32_t port_no, CellPadPeriphData *data);
    static int cellPadPeriphGetData(uint32_t port_no, CellPadPeriphData *data) { return sys_io_8A00F264(port_no, data); }

    int sys_io_4CC9B68D(CellPadPeriphInfo *info);
    static int cellPadPeriphGetInfo(CellPadPeriphInfo *info) { return sys_io_4CC9B68D(info); }

    int sys_io_578E3C98(uint32_t port_no, uint32_t mode);
    static int cellPadSetPortSetting(uint32_t port_no, uint32_t mode) { return sys_io_578E3C98(port_no, mode); }

    int sys_io_A703A51D(CellPadInfo2 *info);
    static int cellPadGetInfo2(CellPadInfo2 *info) { return sys_io_A703A51D(info); }

    int sys_io_F65544EE(uint32_t port_no, CellPadActParam *param);
    static int cellPadSetActDirect(uint32_t port_no, CellPadActParam *param) { return sys_io_F65544EE(port_no, param); }

    int sys_io_6BC09C61(uint32_t port_no, uint32_t *device_type, CellPadData *data);
    static int cellPadGetDataExtra(uint32_t port_no, uint32_t *device_type, CellPadData *data) { return sys_io_6BC09C61(port_no, device_type, data); }

    int sys_io_3733EA3C(uint32_t port_no, uint32_t *device_type, CellPadData *data);  // ? cellPad...           // base ptr
    //sys_io_DBF4C59C  // ? cellPad...
    //sys_io_10DA8DCC  // ? cellPad...
    //sys_io_5C016E79  // ? cellPad...

    int sys_io_8B8231E5(int32_t handle);
    static int cellPadLddGetPortNo(int32_t handle) { return sys_io_8B8231E5(handle); }

    //sys_io_73BB2D74  // ? cellPad...

    int sys_io_20A97BA2(void);
    static int cellPadLddRegisterController() { return sys_io_20A97BA2(); }

    int sys_io_BAFD6409(int32_t handle, CellPadData *data);
    static int cellPadLddDataInsert(int32_t handle, CellPadData *data) { return sys_io_BAFD6409(handle, data); }

    int sys_io_E442FAA8(int32_t handle);
    static int cellPadLddUnregisterController(int32_t handle) { return sys_io_E442FAA8(handle); }

    //sys_io_7009B738  // ? cellPad...

    int sys_io_78200559(uint32_t port_no);
    static int cellPadInfoSensorMode(uint32_t port_no) { return sys_io_78200559(port_no); }

    int sys_io_BE5BE3BA(uint32_t port_no, uint32_t mode);
    static int cellPadSetSensorMode(uint32_t port_no, uint32_t mode) { return sys_io_BE5BE3BA(port_no, mode); }

    int sys_io_0E2DFAAD(uint32_t port_no);
    static int cellPadInfoPressMode(uint32_t port_no) { return sys_io_0E2DFAAD(port_no); }


    int sys_io_F83F8182(uint32_t port_no, uint32_t mode);
    static int cellPadSetPressMode(uint32_t port_no, uint32_t mode) { return sys_io_F83F8182(port_no, mode); }

    //int32_t sys_io_13ED2BA4(void);  // ? cellPad...

    int sys_io_8B72CDA1(uint32_t port_no, CellPadData *data);
    static int cellPadGetData(uint32_t port_no, CellPadData *data) { return sys_io_8B72CDA1(port_no, data); }

    int sys_io_3F797DFF(uint32_t port_no, CellPadData *data);
    static int cellPadGetRawData(uint32_t port_no, CellPadData *data) { return sys_io_3F797DFF(port_no, data); }
    
    typedef struct CellPadInfo // not sure why but it's missing from my pad_codes.h
    {
        uint32_t max_connect;
        uint32_t now_connect;
        uint32_t system_info;
        uint16_t vendor_id[CELL_MAX_PADS];
        uint16_t product_id[CELL_MAX_PADS];
        uint8_t status[CELL_MAX_PADS];
    } CellPadInfo;

    int sys_io_3AAAD464(CellPadInfo *info);
    static int cellPadGetInfo(CellPadInfo *info) { return sys_io_3AAAD464(info); }

    int sys_io_0D5F2C14(uint32_t port_no);
    static int cellPadClearBuf(uint32_t port_no) { return sys_io_0D5F2C14(port_no); }

    int sys_io_4D9B75D5(void);
    static int cellPadEnd() { return sys_io_4D9B75D5(); }

    int sys_io_1CF98800(uint32_t max_connect);
    static int cellPadInit(uint32_t max_connect) { return sys_io_1CF98800(max_connect); }


    // Keyboard
    int sys_io_1F71ECBE(uint32_t port_no, CellKbConfig *config);
    static int cellKbGetConfiguration(uint32_t port_no, CellKbConfig *config) { return sys_io_1F71ECBE(port_no, config); }

    int sys_io_3F72C56E(uint32_t port_no, uint8_t led);
    static int cellKbSetLEDStatus(uint32_t port_no, uint8_t led) { return sys_io_3F72C56E(port_no, led); }

    int sys_io_DEEFDFA7(uint32_t port_no, uint32_t mode); 
    static int cellKbSetReadMode(uint32_t port_no, uint32_t mode) { return sys_io_DEEFDFA7(port_no, mode); }

    int sys_io_A5F85E4D(uint32_t port_no, uint32_t type);  
    static int cellKbSetCodeType(uint32_t port_no, uint32_t type) { return sys_io_A5F85E4D(port_no, type); }

    int sys_io_4AB1FA77(uint32_t arrange, uint32_t mkey, uint32_t led, uint16_t rawcode);  
    static int cellKbCnvRawCode(uint32_t arrange, uint32_t mkey, uint32_t led, uint16_t rawcode) { return sys_io_4AB1FA77(arrange, mkey, led, rawcode); }

    int sys_io_FF0A21B7(uint32_t port_no, CellKbData * data);  
    static int cellKbRead(uint32_t port_no, CellKbData * data) { return sys_io_FF0A21B7(port_no, data); }

    int sys_io_2F1774D5(CellKbInfo *info);  
    static int cellKbGetInfo(CellKbInfo *info) { return sys_io_2F1774D5(info); }

    int sys_io_2073B7F6(uint32_t port_no);  
    static int cellKbClearBuf(uint32_t port_no) { return sys_io_2073B7F6(port_no); }

    int sys_io_BFCE3285(void);
    static int cellKbEnd(void) { return sys_io_BFCE3285(); }

    int sys_io_433F6EC0(uint32_t max_connect);
    static int cellKbInit(uint32_t max_connect) { return sys_io_433F6EC0(max_connect); }


    // Mouse
    //int32_t sys_io_CCC785DF(void);  // ? cellMouse...

    int sys_io_2D16DA4F(uint32_t port_no, uint32_t mode);
    static int cellMouseSetTabletMode(uint32_t port_no, uint32_t mode) { return sys_io_2D16DA4F(port_no, mode); }

    int sys_io_4D0B3B1F(uint32_t port_no, CellMouseInfoTablet *info);  
    static int cellMouseInfoTabletMode(uint32_t port_no, CellMouseInfoTablet *info) { return sys_io_4D0B3B1F(port_no, info); }

    int sys_io_21A62E9B(uint32_t port_no, CellMouseTabletDataList *data);  
    static int cellMouseGetTabletDataList(uint32_t port_no, CellMouseTabletDataList *data) { return sys_io_21A62E9B(port_no, data); }

    int sys_io_6BD131F0(uint32_t port_no, CellMouseDataList *data);  
    static int cellMouseGetDataList(uint32_t port_no, CellMouseDataList *data) { return sys_io_6BD131F0(port_no, data); }

    int sys_io_3138E632(uint32_t port_no, CellMouseData *data);  
    static int cellMouseGetData(uint32_t port_no, CellMouseData *data) { return sys_io_3138E632(port_no, data); }

    int sys_io_A328CC35(uint32_t port_no, CellMouseRawData *data);  
    static int cellMouseGetRawData(uint32_t port_no, CellMouseRawData *data) { return sys_io_A328CC35(port_no, data); }

    int sys_io_5BAF30FB(CellMouseInfo *info);  
    static int cellMouseGetInfo(CellMouseInfo *info) { return sys_io_5BAF30FB(info); }

    int sys_io_3EF66B95(uint32_t port_no);  
    static int cellMouseClearBuf(uint32_t port_no) { return sys_io_3EF66B95(port_no); }

    int sys_io_E10183CE(void);  
    static int cellMouseEnd(void) { return sys_io_E10183CE(); }

    int sys_io_C9030138(uint32_t max_connect);  
    static int cellMouseInit(uint32_t max_connect) { return sys_io_C9030138(max_connect); }

    CDECL_END
}

#endif // __SYS_IO_HPP__