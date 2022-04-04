#ifndef __VSH_TYPES_H__
#define __VSH_TYPES_H__

#include <sys/types.h> // for size_t

#define _VSH_BEGIN namespace vsh {
#define _VSH_END }

#define _PAF_BEGIN namespace paf {
#define _PAF_END }



_VSH_BEGIN
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