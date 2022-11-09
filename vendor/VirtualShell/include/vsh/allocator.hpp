#ifndef __ALLOCATOR_HPP__
#define __ALLOCATOR_HPP__

#include <yvals.h> // for _CSTD
#include <xstddef> // for _THROW1
#include <new> // for nothrow_t

#define _VSH_BEGIN namespace vsh {
#define _VSH_END }

_VSH_BEGIN
CDECL_BEGIN

// allocator_045E124A  // _ZdaPv operator delete[](void *)
// allocator_0871FFB0  // mspace_malloc_usable_size
// allocator_2356EF16  // _ZnajRKSt9nothrow_t operator new[](uint, std::nothrow_t const&)
// allocator_58B43627  // ?

void* allocator_6137D196(size_t alignment, size_t size);  // memalign()
static void* memalign(size_t alignment, size_t size) { return allocator_6137D196(alignment, size); }

// allocator_679E8CAF  // ?
// allocator_6997B837  // ?

void *allocator_759E0635(size_t size);  // malloc()
static void* malloc(size_t size) { return allocator_759E0635(size); }

void allocator_77A602DD(void *ptr);  // free()
static void free(void* ptr) { allocator_77A602DD(ptr); }

// allocator_799473AE  // ?
// allocator_79EADF05  // malloc_usable_size
// allocator_83B2CC6F  // _Znwj operator new(uint)
// allocator_96BC2578  // _Znajj operator new[](uint, uint)
// allocator_97C02090  // ?

void *allocator_A72A7595(size_t nitems, size_t size);  // calloc()
static void* calloc(size_t nitems, size_t size) { return allocator_A72A7595(nitems, size); }

// allocator_A830FDD8  // ?
// allocator_AD382A99  // _ZdlPvRKSt9nothrow_t operator delete(void *, std::nothrow_t const&)
// allocator_BB712718  // _ZnwjRKSt9nothrow_t operator new(uint, std::nothrow_t  const&)
// allocator_D2B978F5  // ?
// allocator_D84B3689  // _ZdlPv operator delete(void *)
// allocator_E27B3C01  // ?
// allocator_ED3DA02B  // _Znwjj operator new(uint, uint)
// allocator_F58E83A5  // _Znaj  operator new[](uint)

void *allocator_F7A14A22(void *ptr, size_t size);  // realloc()
static void* realloc(void* ptr, size_t size) { return allocator_F7A14A22(ptr, size); }

CDECL_END
_VSH_END

#endif // __ALLOCATOR_HPP__