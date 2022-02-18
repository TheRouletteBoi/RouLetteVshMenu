#include "Memory.hpp"

uint32_t GetCurrentToc()
{
   uint32_t* entry_point = *reinterpret_cast<uint32_t**>(0x1001C); // ElfHeader->e_entry 
   return entry_point[1];
}

int WriteProcessMemory(uint32_t pid, void* address, const void* data, size_t size)
{
   static bool useHenSyscalls = false;

   if (!useHenSyscalls)
   {
      int canWrite = sys_dbg_write_process_memory(pid, address, data, size);
      if (canWrite == SUCCEEDED)
      {
         return canWrite;
      }
   }

   useHenSyscalls = true;
   return PS3MAPISetMemory(pid, address, data, size);
}

int ReadProcessMemory(uint32_t pid, void* address, void* data, size_t size)
{
   static bool useHenSyscalls = false;

   if (!useHenSyscalls)
   {
      int canRead = sys_dbg_read_process_memory(pid, address, data, size);
      if (canRead == SUCCEEDED)
      {
         return canRead;
      }
   }

   useHenSyscalls = true;
   return PS3MAPIGetMemory(pid, address, data, size);
}