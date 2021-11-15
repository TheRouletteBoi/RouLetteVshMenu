#include "DetourHook.hpp"

#define ADDRESS_HIGHER(X) ( ( X >> 16 ) & 0xFFFF )
#define ADDRESS_LOWER(X)  ( X & 0xFFFF )

#define POWERPC_INSTRUCTION_LENGTH 4

/*Opcodes*/
#define POWERPC_BRANCH             0x48000000
#define POWERPC_BRANCH_CONDITIONAL 0x40000000

/*Takes Human based syntax numbers and returns approbate bits ie. bcctr 20, 0*/
#define POWERPC_BRANCH_OPTION_SET(X)      ( X << 21 ) 
#define POWERPC_CONDITION_REGISTER_SET(X) ( X << 16 )

/*Takes powerpc bits and converts to human based syntax*/
#define POWERPC_BRANCH_OPTION_GET(X)      ( X >> 21 )
#define POWERPC_CONDITION_REGISTER_GET(X) ( X >> 16 )

const uint32_t jumpASMPreserve[] = {
   0x9161FFD0, // stw %r11, -0x30(%r1)
   0x3D600000, // lis %r11, 0
   0x616B0000, // ori %r11, %r11, 0
   0x7D6903A6, // mtctr %r11
   0x8161FFD0, // lwz %r11, -0x30(%r1)
   0x4C800420  // bcctr (Used For PatchInJumpEx bcctr 20, 0 == bctr)
};

const uint32_t jumpASMNoPreserve[] = { /*Don't always have enough space to preserve registers*/
   0x3D600000, // lis %r11, Destination@h
   0x616B0000, // ori %r11, %r11, Destination@l
   0x7D6903A6, // mtctr %r11
   0x4C800420  // bcctr (Used For PatchInJumpEx bcctr 20, 0 == bctr)
};

uint8_t DetourHook::stubs[]{};
size_t DetourHook::stubOffset = 0;

DetourHook::DetourHook(uint32_t fnAddress, uintptr_t fnCallback, bool preserveRegisters, uint32_t tocOverride) 
   : stubAddress(nullptr), hookAddress(0), originalLength(0), stubIndex(0)
{
   memset(stubOpd, 0, sizeof(stubOpd));
   memset(originalInstructions, 0, sizeof(originalInstructions));

   Hook(fnAddress, fnCallback, preserveRegisters);
}

DetourHook::~DetourHook()
{
   UnHook();
}

void* DetourHook::Hook(uint32_t fnAddress, uintptr_t fnCallback, bool preserveRegisters, uint32_t tocOverride)
{
   stubIndex = 0;
   stubAddress = &stubs[stubOffset];

   size_t hookInstructionCount = preserveRegisters ? ARRAYSIZE(jumpASMPreserve) : ARRAYSIZE(jumpASMNoPreserve);

   for (int i = 0; i < hookInstructionCount; ++i)
   {
      uint32_t instructionAddress = (fnAddress + (i * POWERPC_INSTRUCTION_LENGTH));

      RelocateCode(instructionAddress, preserveRegisters);
   }

   size_t hookByteLength = preserveRegisters ? sizeof(jumpASMPreserve) : sizeof(jumpASMNoPreserve);

   uint32_t afterJumpAddress = static_cast<uint32_t>(fnAddress + hookByteLength);

   Jump(reinterpret_cast<uint32_t>(&stubAddress[stubIndex]), afterJumpAddress, false, preserveRegisters);

   Jump(fnAddress, *reinterpret_cast<uintptr_t*>(fnCallback), false, preserveRegisters);

   // gotta add on the size of the last jump back to the start of the original function
   stubOffset += stubIndex + hookByteLength;

   stubOpd[0] = reinterpret_cast<uint32_t>(stubAddress);
   stubOpd[1] = tocOverride != 0 ? tocOverride : GetCurrentToc();

   return (void*)stubAddress;
}

void DetourHook::UnHook()
{
   if (originalLength)
   {
      WriteProcessMemory(sys_process_getpid(), (void*)hookAddress, originalInstructions, originalLength);

      originalLength = 0;
   }
}

void DetourHook::RelocateBranch(uint32_t instructionAddress, bool preserveRegisters)
{
   uint32_t instructionOpcode = *(uint32_t*)instructionAddress;
   uint32_t currentStubPos = (uint32_t)&stubAddress[stubIndex];

   if (instructionOpcode & 0x2) /*BA BLA*/
   {
      WriteProcessMemory(sys_process_getpid(), (void*)currentStubPos, &instructionOpcode, sizeof(instructionOpcode));
      stubIndex += POWERPC_INSTRUCTION_LENGTH;
   }
   else
   {
      intptr_t branchOffset = instructionOpcode & 0x03FFFFFC;

      if (branchOffset & (1 << 25)) // If The MSB Is Set Make It Negative
         branchOffset |= ~0x03FFFFFF;

      intptr_t originalAddress = (intptr_t)(instructionAddress + branchOffset);

      Jump(currentStubPos, originalAddress, instructionOpcode & 1, preserveRegisters);

      size_t hookSize = preserveRegisters ? sizeof(jumpASMPreserve) : sizeof(jumpASMNoPreserve);

      stubIndex += hookSize;
   }
}

void DetourHook::RelocateBranchConditional(uint32_t instructionAddress, bool preserveRegisters)
{
   uint32_t instructionOpcode = *(uint32_t*)instructionAddress;
   uint32_t currentStubPos = (uint32_t)&stubAddress[stubIndex];

   if (instructionOpcode & 0x2) /*Conditional Absolute*/
   {
      WriteProcessMemory(sys_process_getpid(), (void*)currentStubPos, &instructionOpcode, sizeof(instructionOpcode));
      stubIndex += POWERPC_INSTRUCTION_LENGTH;
   }
   else
   {
      uint32_t branchOptions = instructionOpcode & 0x03E00000;
      uint32_t conditionRegister = instructionOpcode & 0x001F0000;

      intptr_t branchOffset = instructionOpcode & 0x0000FFFC;

      if (branchOffset & (1 << 15)) // If The MSB Is Set Make It Negative
         branchOffset |= ~0x0000FFFF;

      intptr_t originalAddress = (intptr_t)(instructionAddress + branchOffset);

      JumpWithOptions(currentStubPos, originalAddress, POWERPC_BRANCH_OPTION_GET(branchOptions), POWERPC_CONDITION_REGISTER_GET(conditionRegister), instructionOpcode & 1, preserveRegisters);

      size_t hookSize = preserveRegisters ? sizeof(jumpASMPreserve) : sizeof(jumpASMNoPreserve);

      stubIndex += hookSize;
   }
}

void DetourHook::RelocateCode(uint32_t instructionAddress, bool preserveRegisters)
{
   uint32_t instructionOpcode = *(uint32_t*)instructionAddress;
   uint32_t currentStubPos = (uint32_t)&stubAddress[stubIndex];

   switch (instructionOpcode & 0xFC000000)
   {
   case POWERPC_BRANCH: /*B BL BA BLA*/
      RelocateBranch(instructionAddress, preserveRegisters);
      break;

   case POWERPC_BRANCH_CONDITIONAL: /*BEQ BNE BLT BGE */
      RelocateBranchConditional(instructionAddress, preserveRegisters);
      break;

   default:
      WriteProcessMemory(sys_process_getpid(), (void*)currentStubPos, &instructionOpcode, sizeof(instructionOpcode));
      stubIndex += POWERPC_INSTRUCTION_LENGTH;
      break;
   }
}

void DetourHook::JumpWithOptions(uint32_t fnAddress, uintptr_t fnCallback, uint32_t branchOptions, uint32_t conditionRegister, bool linked, bool preserveRegisters)
{
   branchOptions &= 0x1F; // Options only takes 5 bits
   conditionRegister &= 0x1F;

   if (preserveRegisters)
   {
      uint32_t instructions[ARRAYSIZE(jumpASMPreserve)];

      WriteProcessMemory(sys_process_getpid(), instructions, jumpASMPreserve, sizeof(jumpASMPreserve));

      instructions[1] |= ADDRESS_HIGHER(fnCallback);
      instructions[2] |= ADDRESS_LOWER(fnCallback);
      instructions[5] |= POWERPC_BRANCH_OPTION_SET(branchOptions) | POWERPC_CONDITION_REGISTER_SET(conditionRegister) | (uint32_t)linked;

      WriteProcessMemory(sys_process_getpid(), (void*)originalInstructions, (void*)fnAddress, sizeof(jumpASMPreserve));
      WriteProcessMemory(sys_process_getpid(), (void*)fnAddress, instructions, sizeof(instructions));

      originalLength = sizeof(jumpASMPreserve);
   }
   else
   {
      uint32_t instructions[ARRAYSIZE(jumpASMNoPreserve)];

      WriteProcessMemory(sys_process_getpid(), instructions, jumpASMNoPreserve, sizeof(jumpASMNoPreserve));

      instructions[0] |= ADDRESS_HIGHER(fnCallback);
      instructions[1] |= ADDRESS_LOWER(fnCallback);
      instructions[3] |= POWERPC_BRANCH_OPTION_SET(branchOptions) | POWERPC_CONDITION_REGISTER_SET(conditionRegister) | (uint32_t)linked;

      WriteProcessMemory(sys_process_getpid(), (void*)originalInstructions, (void*)fnAddress, sizeof(jumpASMNoPreserve));
      WriteProcessMemory(sys_process_getpid(), (void*)fnAddress, instructions, sizeof(instructions));

      originalLength = sizeof(jumpASMNoPreserve);
   }

   hookAddress = fnAddress;
}

void DetourHook::Jump(uint32_t fnAddress, uintptr_t fnCallback, bool linked, bool preserveRegisters)
{
   JumpWithOptions(fnAddress, fnCallback, 20, 0, linked, preserveRegisters);
}







ImportExportHook::ImportExportHook(HookType type, const std::string& libaryName,
   uint32_t fnid, uintptr_t fnCallback, bool preserveRegisters)
   : /*DetourHook(0x00000000, fnCallback, preserveRegisters, tocOverride), */libaryName(libaryName), fnid(fnid)
{
   HookByFnid(type, libaryName, fnid, fnCallback, preserveRegisters);
}

ImportExportHook::~ImportExportHook()
{
   UnHook();
}

void* ImportExportHook::Hook(uint32_t fnAddress, uintptr_t fnCallback, bool preserveRegisters, uint32_t tocOverride)
{
   // not implemented
   return nullptr;
}

void ImportExportHook::UnHook()
{
   // not implemented
}

void* ImportExportHook::HookByFnid(HookType type, const std::string& libaryName, uint32_t fnid, uintptr_t fnCallback, bool preserveRegisters)
{
   opd_s* fnOpd = nullptr;

   switch (type)
   {
      case HookType::Import:
      {
         fnOpd = FindImportByName(libaryName.c_str(), fnid);
         break;
      }
      case HookType::Export:
      {
         fnOpd = FindExportByName(libaryName.c_str(), fnid);
         break;
      }
   }

   if (fnOpd == nullptr)
      return nullptr;

   return DetourHook::Hook(fnOpd->func, fnCallback, preserveRegisters, fnOpd->toc);
}

opd_s* ImportExportHook::FindExportByName(const char* module, std::uint32_t fnid)
{
   uint32_t* segment15 = *reinterpret_cast<uint32_t**>(0x1008C); // 0x1008C or 0x10094
   uint32_t exportAdressTable = segment15[0x261];
   exportStub_s* exportStub = reinterpret_cast<exportStub_s*>(exportAdressTable);

   while (exportStub->ssize == 0x1C00)
   {
      if (!strcmp(module, exportStub->name))
      {
         for (int16_t i = 0; i < exportStub->exports; i++)
         {
            if (exportStub->fnid[i] == fnid)
            {
               return exportStub->stub[i];
            }
         }
      }
      exportStub++;
   }

   return nullptr;
}

opd_s* ImportExportHook::FindImportByName(const char* module, uint32_t fnid)
{
   uint32_t* segment15 = *reinterpret_cast<uint32_t**>(0x1008C); // 0x1008C or 0x10094
   uint32_t exportAdressTable = segment15[0x261];
   importStub_s* importStub = reinterpret_cast<importStub_s*>(exportAdressTable);

   while (importStub->ssize == 0x2C00)
   {
      if (!strcmp(module, importStub->name))
      {
         for (int16_t i = 0; i < importStub->imports; i++)
         {
            if (importStub->fnid[i] == fnid)
            {
               return importStub->stub[i];
            }
         }
      }
      importStub++;
   }

   return nullptr;
}