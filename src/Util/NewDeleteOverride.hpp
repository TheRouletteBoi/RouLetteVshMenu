#pragma once
#include <yvals.h> // for _CSTD
#include <xstddef> // for _THROW1
#include <new> // for nothrow_t
#include <vsh/allocator.h>

void* operator new(std::size_t size) _THROW1(_XSTD bad_alloc) // allocate or throw exception
{
   return malloc(size);
}

void* operator new(std::size_t size, const _STD nothrow_t&) _THROW0() // allocate or return null pointer
{
   return malloc(size);
}

void* operator new(size_t size, size_t align)
{
   return memalign(align, size);
}

void* operator new(size_t size, size_t align, const _STD nothrow_t&) _THROW0()
{
   return memalign(align, size);
}

void* operator new[](std::size_t size) _THROW1(_XSTD bad_alloc)	// allocate array or throw exception
{
   return malloc(size);
}

void* operator new[](std::size_t size, const _STD nothrow_t&) _THROW0() // allocate array or return null pointer
{
   return malloc(size);
}

void* operator new[](size_t size, size_t align)
{
   return operator new(size, align);
}

void* operator new[](size_t size, size_t align, const _STD nothrow_t&) _THROW0()
{
   return operator new(size, align);
}

void operator delete(void* mem) _THROW0()  // delete allocated storage
{
   free(mem);
}

// The rest of these deletes will be called if the correspond call to
// new throws an exception.
void operator delete(void* mem, const _STD nothrow_t&) _THROW0() // delete if nothrow new fails -- REPLACEABLE
{
   free(mem);
}

void operator delete(void* ptr, void* prt2)
{
   return operator delete(ptr);
}

void operator delete(void* ptr, size_t align)
{
   return operator delete(ptr);
}

void operator delete(void* ptr, size_t align, const _STD nothrow_t&) _THROW0()
{
   return operator delete(ptr);
}

void operator delete(void* ptr, size_t align, void* prt2)
{
   return operator delete(ptr);
}

void operator delete[](void* mem) _THROW0() // delete allocated array
{
   free(mem);
}

void operator delete[](void* mem, const _STD nothrow_t&) _THROW0() // delete if nothrow array new fails -- REPLACEABLE
{
   free(mem);
}

void operator delete[](void* ptr, void* prt2)
{
   return operator delete(ptr, prt2);
}

void operator delete[](void* ptr, size_t align)
{
   return operator delete(ptr, align);
}

void operator delete[](void* ptr, size_t align, const _STD nothrow_t&) _THROW0()
{
   return operator delete(ptr, align);
}

void operator delete[](void* ptr, size_t align, void* prt2)
{
   return operator delete(ptr, align);
}