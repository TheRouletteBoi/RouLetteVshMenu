#ifndef __SYS_IO_H__
#define __SYS_IO_H__
#include "vshtypes.h"


_VSH_BEGIN
CDECL_BEGIN

//sys_io_8E06D13B  // ?
//sys_io_662BB2AD  // ?
//sys_io_5F81900C  // sys_config_unregister_service
//sys_io_78F058A2  // sys_config_register_service
//sys_io_F5D9D571  // sys_config_remove_service_listener
//sys_io_6AE10596  // sys_config_add_service_listener
//sys_io_6D367953  // sys_config_stop
//sys_io_068FCBC6  // sys_config_start

//sys_io_E5E139DD  // ? cellPad...

int32_t sys_io_8A00F264(uint32_t port_no, CellPadPeriphData *data);  // cellPadPeriphGetData()
#define PadPeriphGetData sys_io_8A00F264

int32_t sys_io_4CC9B68D(CellPadPeriphInfo *info);  // cellPadPeriphGetInfo()
#define PadPeriphGetInfo sys_io_4CC9B68D

int32_t sys_io_578E3C98(uint32_t port_no, uint32_t mode);  // cellPadSetPortSetting()
#define PadSetPortSetting sys_io_578E3C98

int32_t sys_io_A703A51D(CellPadInfo2 *info);  // cellPadGetInfo2()
#define PadGetInfo2 sys_io_A703A51D

int32_t sys_io_F65544EE(uint32_t port_no, CellPadActParam *param);  // cellPadSetActDirect()
#define PadSetActDirect sys_io_F65544EE

int32_t sys_io_6BC09C61(uint32_t port_no, uint32_t *device_type, CellPadData *data);  // cellPadGetDataExtra()
#define PadGetDataExtra sys_io_6BC09C61

int32_t sys_io_3733EA3C(void);  // ? cellPad...           // base ptr
//sys_io_DBF4C59C  // ? cellPad...
//sys_io_10DA8DCC  // ? cellPad...
//sys_io_5C016E79  // ? cellPad...

int32_t sys_io_8B8231E5(int32_t handle);  // cellPadLddGetPortNo()
#define PadLddGetPortNo sys_io_8B8231E5

//sys_io_73BB2D74  // ? cellPad...

int32_t sys_io_20A97BA2(void);  // cellPadLddRegisterController()
#define PadLddRegisterController sys_io_20A97BA2

int32_t sys_io_BAFD6409(int32_t handle, CellPadData *data);  // cellPadLddDataInsert()
#define PadLddDataInsert sys_io_BAFD6409

int32_t sys_io_E442FAA8(int32_t handle);  // cellPadLddUnregisterController()
#define PadLddUnregisterController sys_io_E442FAA8

//sys_io_7009B738  // ? cellPad...
//sys_io_78200559  // cellPadInfoSensorMode


int32_t sys_io_BE5BE3BA(void);  // cellPadSetSensorMode
int32_t sys_io_0E2DFAAD(void);  // cellPadInfoPressMode
int32_t sys_io_F83F8182(void);  // cellPadSetPressMode
//int32_t sys_io_13ED2BA4(void);  // ? cellPad...
int32_t sys_io_8B72CDA1(void);  // cellPadGetData
int32_t sys_io_3F797DFF(void);  // cellPadGetRawData
int32_t sys_io_3AAAD464(void);  // cellPadGetInfo
int32_t sys_io_0D5F2C14(void);  // cellPadClearBuf

int32_t sys_io_4D9B75D5(void);  // cellPadEnd()
#define PadEnd sys_io_4D9B75D5

int32_t sys_io_1CF98800(uint32_t max_connect);  // cellPadInit()
#define PadInit sys_io_1CF98800

int32_t sys_io_1F71ECBE(void);  // cellKbGetConfiguration
int32_t sys_io_3F72C56E(void);  // cellKbSetLEDStatus
int32_t sys_io_DEEFDFA7(void);  // cellKbSetReadMode
int32_t sys_io_A5F85E4D(void);  // cellKbSetCodeType
int32_t sys_io_4AB1FA77(void);  // cellKbCnvRawCode
int32_t sys_io_FF0A21B7(void);  // cellKbRead
int32_t sys_io_2F1774D5(void);  // cellKbGetInfo
int32_t sys_io_2073B7F6(void);  // cellKbClearBuf
int32_t sys_io_BFCE3285(void);  // cellKbEnd
int32_t sys_io_433F6EC0(void);  // cellKbInit


//int32_t sys_io_CCC785DF(void);  // ? cellMouse...
int32_t sys_io_2D16DA4F(void);  // cellMouseSetTabletMode
int32_t sys_io_4D0B3B1F(void);  // cellMouseInfoTabletMode
int32_t sys_io_21A62E9B(void);  // cellMouseGetTabletDataList
int32_t sys_io_6BD131F0(void);  // cellMouseGetDataList
int32_t sys_io_3138E632(void);  // cellMouseGetData
int32_t sys_io_A328CC35(void);  // cellMouseGetRawData
int32_t sys_io_5BAF30FB(void);  // cellMouseGetInfo
int32_t sys_io_3EF66B95(void);  // cellMouseClearBuf
int32_t sys_io_E10183CE(void);  // cellMouseEnd
int32_t sys_io_C9030138(void);  // cellMouseInit


CDECL_END
_VSH_END

#endif // __SYS_IO_H__ 