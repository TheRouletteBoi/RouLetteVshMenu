#pragma once
#include <vsh/vshmain.h>
#include <vsh/vshcommon.h>
#include <vsh/pafView.h>
#include <vsh/explore_plugin.h>
#include <vsh/game_plugin.h>
#include <sys/timer.h>
#include <sys/ppu_thread.h>
#include <string>


class CFindActiveGame
{
public:
   struct GameName
   {
      std::string titleId;
      std::string titleName;
   };

   enum class PatchedMenu
   {
      None,

      // GTAV
      Terrorizer,
   };

public:
   static void GameProcessThread(uint64_t arg);

   void Initialize();
   void ShutDown();
   bool LoadMenu(PatchedMenu menuId);
   uint32_t GetRunningGameProcessId();

private:
   void SetRunningGameProcessId(uint32_t pid);
   void GetGameName(char outTitleId[16], char outTitleName[64]);
   bool IsGameGTAV(const std::string& titleId);
   bool IsGameRDR(const std::string& titleId);
   bool IsGameMinecraft(const std::string& titleId);
   bool IsGameMW2(const std::string& titleId);
   bool IsGameMW3(const std::string& titleId);
   bool IsGameBO1(const std::string& titleId);
   bool IsGameBO2(const std::string& titleId);
   bool IsGameBO3(const std::string& titleId);
   bool IsGameAW(const std::string& titleId);
   bool IsGameCodGhosts(const std::string& titleId);
   void WhileInGame(uint32_t pid, const char* titleId, const char* titleName);

public:
   PatchedMenu m_MenuToLoad = PatchedMenu::None;

private:
   sys_ppu_thread_t m_GameProcessPpuThreadId = SYS_PPU_THREAD_ID_INVALID;
   bool hasGameInitialized{};
   bool gameProcessThreadRunning{};
   uint32_t m_CurrentGamePid{};
};

extern CFindActiveGame g_FindActiveGame;