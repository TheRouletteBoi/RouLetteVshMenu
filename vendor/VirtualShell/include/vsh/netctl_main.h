#ifndef __NETCTL_MAIN_H__
#define __NETCTL_MAIN_H__
#include "vshtypes.h"


_VSH_BEGIN
CDECL_BEGIN

int32_t netctl_main_1237870F(uint32_t *, uint32_t *);  // ? get...  ret: a(0x00000001) b(0x00000000)

int32_t netctl_main_13CD17FB(void);  // ? finalize ?

// int32_t netctl_main_218CFBD3  // ? init, 3 params

// netctl_main_23C35ECE  // ? set..., arg1: int(1, 2 or 3)(net emulationType ?), arg2: u8 *buf[0x200]

int32_t netctl_main_2DCA4721(uint32_t *);  // ? get..., arg1: int *   ret: a(0x00000003)

// netctl_main_352EFDDF  // ? (void), before sys_net_finalize_network()

int32_t netctl_main_35A1C363(uint32_t *);  // ? set..., arg1: int *

// netctl_main_367EFAA8  // ?
// netctl_main_38479255  // ? set...

int32_t netctl_main_3A5CB886(uint32_t *);  // ?

// netctl_main_442F0E40  // ?
// netctl_main_4B1EE41D(void);  // ?
// netctl_main_4E4B734D  // ?
// netctl_main_5101A052(void);  // ?
// netctl_main_55D2047A(uint32_t *);  // ? set

// netctl_main_5AB91391  // ?

// netctl_main_5D1D7803  // ?
// netctl_main_5ED42691  // ?
// netctl_main_61E363B0(void);  // ?
// netctl_main_6F2521E0  // ?
// netctl_main_6F2D52F1  // ?
// netctl_main_8DA844E1  // ?
// netctl_main_953F1E14  // ?
// netctl_main_974E50F6  // ?

int32_t netctl_main_9A528B81(int32_t size, const char *ip);  // get ip addr of interface "eth0"

// netctl_main_A111D8FB  // ?
// netctl_main_B7618526  // ?
// netctl_main_C67D3DB3  // ?

int32_t netctl_main_EC73B49D(int32_t *arg1);  // ? get...

// netctl_main_ECD37366  // ?
// netctl_main_FA020C41  // ?

CDECL_END
_VSH_END

#endif // __NETCTL_MAIN_H__
