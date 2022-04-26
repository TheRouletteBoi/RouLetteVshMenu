#ifndef __ALLOCATOR_H__
#define __ALLOCATOR_H__
#include "vshtypes.h"


_VSH_BEGIN
CDECL_BEGIN

// allocator_045E124A  // _ZdaPv operator delete[](void *)
// allocator_0871FFB0  // mspace_malloc_usable_size 
// allocator_2356EF16  // _ZnajRKSt9nothrow_t operator new[](uint, std::nothrow_t const&)
void* allocator_58B43627(size_t size);  // sce_paf_private_heapmemory

void* allocator_6137D196(size_t alignment, size_t size);  // memalign()
static void* memalign(size_t alignment, size_t size) { return allocator_6137D196(alignment, size); }

void* allocator_679E8CAF(void* ptr, size_t size);  // sce_paf_private_realloc

void allocator_6997B837(void* ptr);  // sce_paf_private_free
static void sce_paf_private_free(void* ptr) { allocator_6997B837(ptr); }

void* allocator_759E0635(size_t size);  // malloc()
static void* malloc(size_t size) { return allocator_759E0635(size); }

void allocator_77A602DD(void* ptr);  // free()
static void free(void* ptr) { allocator_77A602DD(ptr); }

void* allocator_799473AE(size_t alignment, size_t size);  // sce_paf_private_memalign
static void* sce_paf_private_memalign(size_t alignment, size_t size) { return allocator_799473AE(alignment, size); }

// allocator_79EADF05  // malloc_usable_size
// allocator_83B2CC6F  // _Znwj operator new(uint)
// allocator_96BC2578  // _Znajj operator new[](uint, uint)
void allocator_97C02090();  // sce_paf_private_dump_heap_info

void* allocator_A72A7595(size_t nitems, size_t size);  // calloc()
static void* calloc(size_t nitems, size_t size) { return allocator_A72A7595(nitems, size); }

void* allocator_A830FDD8(size_t size);  // sce_paf_private_calloc

// allocator_AD382A99  // _ZdlPvRKSt9nothrow_t operator delete(void *, std::nothrow_t const&)
// allocator_BB712718  // _ZnwjRKSt9nothrow_t operator new(uint, std::nothrow_t  const&)

void allocator_D2B978F5();  // sce_paf_private_report_memblk

// allocator_D84B3689  // _ZdlPv operator delete(void *)

void* allocator_E27B3C01(size_t size);  // sce_paf_private_malloc
static void* sce_paf_private_malloc(size_t size) { return allocator_E27B3C01(size); }

// allocator_ED3DA02B  // _Znwjj operator new(uint, uint)
// allocator_F58E83A5  // _Znaj  operator new[](uint)

void* allocator_F7A14A22(void* ptr, size_t size);  // realloc()
static void* realloc(void* ptr, size_t size) { return allocator_F7A14A22(ptr, size); }


CDECL_END
_VSH_END

#endif // __ALLOCATOR_H__
