#ifndef __PAF_MODULE_H__
#define __PAF_MODULE_H__
#include "vshtypes.h"
#include "paf.h"
#include <sys/sys_types.h>

_VSH_BEGIN
_PAF_BEGIN

class Module
{
public:
   Module(const char* path, int r5 = 0, int r6 = 0, sys_memory_container_t* memContainer = nullptr)
   {
      paf_CF068D31(this, path, r5, r6, memContainer);
   }

   ~Module()
   {
      paf_2F5CEE6D(this);
   }

   int SetInterface(int interfaceId, void* interfaceStruct)
   {
      return Module_SetInterface(this, interfaceId, interfaceStruct);
   }

   template<typename R>
   R GetInterface(int interfaceId) const
   {
      return (R)paf_B9152E15(this, interfaceId);
   }

private: // Data - size: 0x4
   struct // Data - size: 0x34
   {
      std::string path;
      char __padding_0x1C[0x18];
   } *moduleData;
};

_PAF_END
_VSH_END

#endif // __PAF_MODULE_H__