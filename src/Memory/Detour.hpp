#pragma once
#include <string>
#include <sys/process.h>
#include "Memory.hpp"

#define MARK_AS_EXECUTABLE __attribute__((section(".text")))

opd_s* FindExportByName(const char* module, uint32_t fnid);
opd_s* FindImportByName(const char* module, uint32_t fnid);

class Detour
{
public:
   struct HookInformation
   {
       sys_prx_module_info_t prxInfo;
       uint32_t hookBytes[4];
   };

public:
   Detour();
   Detour(uintptr_t fnAddress, uintptr_t fnCallback);
   Detour(Detour const&) = delete;
   Detour(Detour&&) = delete;
   Detour& operator=(Detour const&) = delete;
   Detour& operator=(Detour&&) = delete;
   virtual ~Detour();

   virtual void Hook(uintptr_t fnAddress, uintptr_t fnCallback, uintptr_t tocOverride = 0);
   virtual bool UnHook();

   // also works
   /*template<typename T>
   T GetOriginal() const
   {
      return T(m_TrampolineOpd);
   }*/

   template <typename R, typename... TArgs>
   R GetOriginal(TArgs... args)
   {
      R(*original)(TArgs...) = (R(*)(TArgs...))m_TrampolineOpd;
      return original(args...);
   }

private:
   /***
   * Writes an unconditional branch to the destination address that will branch to the target address.
   * @param destination Where the branch will be written to.
   * @param branchTarget The address the branch will jump to.
   * @param linked Branch is a call or a jump? aka bl or b
   * @param preserveRegister Preserve the register clobbered after loading the branch address.
   * @returns size of relocating the instruction in bytes
   */
   size_t Jump(void* destination, const void* branchTarget, bool linked, bool preserveRegister);

   /***
   * Writes both conditional and unconditional branches using the count register to the destination address that will branch to the target address.
   * @param destination Where the branch will be written to.
   * @param branchTarget The address the branch will jump to.
   * @param linked Branch is a call or a jump? aka bl or b
   * @param preserveRegister Preserve the register clobbered after loading the branch address.
   * @param branchOptions Options for determining when a branch to be followed.
   * @param conditionRegisterBit The bit of the condition register to compare.
   * @param registerIndex Register to use when loading the destination address into the count register.
   * @returns size of relocating the instruction in bytes
   */
   size_t JumpWithOptions(void* destination, const void* branchTarget, bool linked, bool preserveRegister,
      uint32_t branchOptions, uint8_t conditionRegisterBit, uint8_t registerIndex);

   /***
   * Copies and fixes relative branch instructions to a new location.
   * @param destination Where to write the new branch.
   * @param source Address to the instruction that is being relocated.
   * @returns size of relocating the instruction in bytes
   */
   size_t RelocateBranch(uint32_t* destination, uint32_t* source);

   /***
   * Copies an instruction enusuring things such as PC relative offsets are fixed.
   * @param destination Where to write the new instruction(s).
   * @param source Address to the instruction that is being copied.
   * @returns size of relocating the instruction in bytes
   */
   size_t RelocateCode(uint32_t* destination, uint32_t* source);

   /***
   * Get's size of method hook in bytes
   * @param branchTarget The address the branch will jump to.
   * @param linked Branch is a call or a jump? aka bl or b
   * @param preserveRegister Preserve the register clobbered after loading the branch address.
   * @returns size of hook in bytes
   */
   size_t GetHookSize(const void* branchTarget, bool linked, bool preserveRegister);

protected:
   const void*  m_HookTarget;                // The funtion we are pointing the hook to.
   void*        m_HookAddress;               // The function we are hooking.
   uint8_t*     m_TrampolineAddress;         // Pointer to the trampoline for this detour.
   uint32_t     m_TrampolineOpd[2];          // opd_s of the trampoline for this detour.
   uint8_t      m_OriginalInstructions[30];  // Any bytes overwritten by the hook.
   size_t       m_OriginalLength;            // The amount of bytes overwritten by the hook.

   // Shared
   MARK_AS_EXECUTABLE static uint8_t   s_TrampolineBuffer[2048];
   static size_t                       s_TrampolineSize;
};

// list of fnids https://github.com/aerosoul94/ida_gel/blob/master/src/ps3/ps3.xml
class ImportExportDetour : public Detour
{
public:
   enum HookType { Import = 0, Export = 1 };
public:
   ImportExportDetour(HookType type, const std::string& libaryName, uint32_t fnid, uintptr_t fnCallback);
   virtual ~ImportExportDetour();

   virtual void Hook(uintptr_t fnAddress, uintptr_t fnCallback, uintptr_t tocOverride = 0) override;
   virtual bool UnHook() override;

private:
   void HookByFnid(HookType type, const std::string& libaryName, uint32_t fnid, uintptr_t fnCallback);

private:
   std::string m_LibaryName;
   uint32_t m_Fnid;
};