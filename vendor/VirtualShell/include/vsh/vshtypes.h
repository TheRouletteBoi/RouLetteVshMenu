#ifndef __VSH_TYPES_H__
#define __VSH_TYPES_H__

#include <sys/types.h> // for size_t

#define _VSH_BEGIN namespace vsh {
#define _VSH_END }

#define _PAF_BEGIN namespace paf {
#define _PAF_END }



_VSH_BEGIN

// TODO(Roulette): convert all structs to classes for C++ and use CallMethod when calling functions. Insterface functions should start with a capital 'I'
/*struct download_plugin_interface;
struct download_act0_if;
struct friendim_plugin_interface;
struct game_ext_plugin_interface;
struct game_plugin_interface;
struct impose_plugin_interface;
struct nas_plugin_interface;
struct ps3_savedata_plugin_game_interface;
struct rec_plugin_interface;
struct wboard_if;
struct wboard_act0_if;
struct wboard_mod0_if;
struct webbrowser_plugin_interface;
struct webbrowser_act0_if;
struct webrender_plugin_interface;
struct webrender_act0_interface;
struct webrender_plugin_mod0;
struct xmb_plugin_xmm0;
struct xmb_plugin_xmb2;
struct xmb_plugin_mod0;
struct xsetting_0AF1F161_class;
struct xsetting_154430FC_class;
struct xsetting_16A8A805_class;
struct xsetting_1D6D60D4_class;
struct xsetting_43F98936_class;
struct xsetting_4712F276_class;
struct xsetting_58560CA4_class;
struct xsetting_5FB90B89_class;
struct xsetting_660ECC35_class;
struct xsetting_69C19C7F_class;
struct xsetting_7125FEB5_class;
struct xsetting_7EDDAD29_class;
struct xsetting_8B69F85A_class;
struct xsetting_9EE60B4E_class;
struct xsetting_C1008335_class;
struct xsetting_CC56EB2D_class;
struct xsetting_CE27E884_class;
struct xsetting_D0261D72_class;
struct xsetting_ED5B559F_class;
struct lease_info;
struct wireless_info;
struct net_info;
struct xsetting_F48C0548_class;
struct xsetting_FFAF9B19_class;*/
class vec2;
class vec3;
class vec4;


_PAF_BEGIN
class View;
class Module;
class PhHandler;
class PhWidget;
class PhPlane;
class PhText;
struct Surface;
using SurfaceRCPtr = Surface*;
_PAF_END


_VSH_END


#endif // __VSH_TYPES_H__