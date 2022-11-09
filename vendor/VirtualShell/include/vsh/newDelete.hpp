#ifndef __NEWDELETE_HPP__
#define __NEWDELETE_HPP__

#include "sys_prx_for_user.hpp"

// Override the new/delete operator cuz the sprx ones are brokey
// not sure why i crash when using allocator exports so i use the
// sysPrxForUser ones instead

void* operator new(std::size_t size) _THROW1(_XSTD bad_alloc) // allocate or throw exception
{
    return sysPrxForUser::_sys_malloc(size);
    //return allocator::malloc(size);
}

void* operator new(std::size_t size, const _STD nothrow_t&) _THROW0() // allocate or return null pointer
{
    return sysPrxForUser::_sys_malloc(size);
    //return allocator::malloc(size);
}

void* operator new(size_t size, size_t align)
{
    return sysPrxForUser::_sys_memalign(align, size);
    //return allocator::memalign(align, size);
}

void* operator new(size_t size, size_t align, const _STD nothrow_t&) _THROW0()
{
    return sysPrxForUser::_sys_memalign(align, size);
    //return allocator::memalign(align, size);
}

void* operator new[](std::size_t size) _THROW1(_XSTD bad_alloc)	// allocate array or throw exception
{
    return sysPrxForUser::_sys_malloc(size);
    //return allocator::malloc(size);
}

void* operator new[](std::size_t size, const _STD nothrow_t&) _THROW0() // allocate array or return null pointer
{
    return sysPrxForUser::_sys_malloc(size);
    //return allocator::malloc(size);
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
    sysPrxForUser::_sys_free(mem);
    //allocator::free(mem);
}

// The rest of these deletes will be called if the correspond call to
// new throws an exception.
void operator delete(void* mem, const _STD nothrow_t&) _THROW0() // delete if nothrow new fails -- REPLACEABLE
{
    sysPrxForUser::_sys_free(mem);
    //allocator::free(mem);
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
    sysPrxForUser::_sys_free(mem);
    //allocator::free(mem);
}

void operator delete[](void* mem, const _STD nothrow_t&) _THROW0() // delete if nothrow array new fails -- REPLACEABLE
{
    sysPrxForUser::_sys_free(mem);
    //allocator::free(mem);
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

#endif // __NEWDELETE_HPP__