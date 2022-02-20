#pragma once
#include <string>
#include <sys/process.h>
#include "Memory.hpp"

#define MARK_AS_EXECUTABLE __attribute__((section(".text")))
#define ARRAYSIZE(a) (sizeof(a) / sizeof(*(a)))

class DetourHook
{
public:
   DetourHook() = default;
   DetourHook(uint32_t fnAddress, uintptr_t fnCallback, bool preserveRegisters = true, uint32_t tocOverride = 0);
   DetourHook(DetourHook const&) = delete;
   DetourHook(DetourHook&&) = delete;
   DetourHook& operator=(DetourHook const&) = delete;
   DetourHook& operator=(DetourHook&&) = delete;
   virtual ~DetourHook();

   virtual void* Hook(uint32_t fnAddress, uintptr_t fnCallback, bool preserveRegisters = true, uint32_t tocOverride = 0);
   virtual void UnHook();

   template <typename R, typename... TArgs>
   R GetOriginal(TArgs... args)
   {
      R(*original)(TArgs...) = (R(*)(TArgs...))stubOpd;
      return original(args...);
   }

private:
   void RelocateBranch(uint32_t instructionAddress, bool preserveRegisters);
   void RelocateBranchConditional(uint32_t instructionAddress, bool preserveRegisters);
   void RelocateCode(uint32_t instructionAddress, bool preserveRegisters);
   void JumpWithOptions(uint32_t fnAddress, uintptr_t fnCallback, uint32_t branchOptions, uint32_t conditionRegister, bool linked, bool preserveRegisters);
   void Jump(uint32_t fnAddress, uintptr_t fnCallback, bool linked, bool preserveRegisters);

protected:
   uint8_t* stubAddress;
   uint32_t stubOpd[2];
   uint8_t originalInstructions[30];
   uint32_t hookAddress;
   size_t originalLength;
   size_t stubIndex;

   MARK_AS_EXECUTABLE static uint8_t stubs[1024];
   static size_t stubOffset;
};

// list of fnids https://github.com/aerosoul94/ida_gel/blob/master/src/ps3/ps3.xml
class ImportExportHook : public DetourHook
{
public:
   enum HookType { Import = 0, Export = 1 };
public:
   ImportExportHook(HookType type, const std::string& libaryName,
      uint32_t fnid, uintptr_t fnCallback, bool preserveRegisters = true);
   virtual ~ImportExportHook();

   virtual void* Hook(uint32_t fnAddress, uintptr_t fnCallback, bool preserveRegisters = true, uint32_t tocOverride = 0) override;
   virtual void UnHook() override;

   static opd_s* FindExportByName(const char* module, uint32_t fnid);
   static opd_s* FindImportByName(const char* module, uint32_t fnid);

private:
   void* HookByFnid(HookType type, const std::string& libaryName, uint32_t fnid, uintptr_t fnCallback, bool preserveRegisters = true);

private:
   std::string libaryName;
   uint32_t fnid;
};