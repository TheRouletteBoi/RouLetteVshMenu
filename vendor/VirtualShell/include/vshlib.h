
#ifndef __VSHLIB_H__
#define __VSHLIB_H__


/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <dirent.h>
#include <wchar.h>
#include <cell/codec/pngdec.h>
#include <cell/gcm.h>
#include <cell/font.h>
#include <cell/l10n.h>
#include <cell/pad.h>
#include <sys/poll.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netex/net.h>
#include <netex/sockinfo.h>
#include <netex/udpp2p.h>
#include <netinet/in.h>
#include <netex/ns.h>
#include <netex/ifctl.h>
#include <sys/time.h>
#include <sys/select.h>
#include <time.h>
#include <sys/sys_time.h>
#include <sys/mempool.h>
#include <sys/ppu_thread.h>
#include <sys/spu_utility.h>
#include <sys/spu_image.h>
#include <sys/synchronization.h>
#include <sys/memory.h>
#include <sys/interrupt.h>
#include <sys/process.h>
#include <sys/spinlock.h>
#include <sys/random_number.h>
*/





#include "vsh/allocator.h"
#include "vsh/download_plugin.h"
#include "vsh/esecron.h"
#include "vsh/explore_plugin.h"
#include "vsh/friendim_plugin.h"
#include "vsh/game_ext_plugin.h"
#include "vsh/game_plugin.h"
#include "vsh/impose_plugin.h"
#include "vsh/libcrashdump_system.h"
#include "vsh/mms_db.h"
#include "vsh/nas_plugin.h"
#include "vsh/netctl_main.h"
#include "vsh/paf.h"
#include "vsh/pngdec_ppuonly.h"
#include "vsh/prx_debug.h"
#include "vsh/ps3_savedata_plugin.h"
#include "vsh/rec_plugin.h"
#include "vsh/sdk.h"
#include "vsh/vsh.h"
#include "vsh/vshcommon.h"
#include "vsh/vshmain.h"
#include "vsh/vshnet.h"
#include "vsh/stdc.h"
#include "vsh/sys_io.h"
#include "vsh/sys_net.h"
#include "vsh/sys_prx_for_user.h"
#include "vsh/system_plugin.h"
#include "vsh/task.h"
#include "vsh/wboard_plugin.h"
#include "vsh/webbrowser_plugin.h"
#include "vsh/webrender_plugin.h"
#include "vsh/x3.h"
#include "vsh/xmb_plugin.h"
#include "vsh/xregistry.h"
#include "vsh/xsetting.h"
#endif // __VSHLIB_H__