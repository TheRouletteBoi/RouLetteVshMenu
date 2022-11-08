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
   enum class PatchedMenu
   {
      None,

      // GTAV
      GTAVLexicon,
      GTAVSerendipity,
      GTAVTerrorizer,
      GTAVDebugPayload,

      // Minecraft
      MinecraftModcraftV4,

      // COD Black Ops 1
      BO1Paradox,
      BO1Fusion,

      // COD Black Ops 2
      BO2Kebab,
      BO2Paradox,
      BO2Sprxio,
      BO2Destiny,

      // COD Black Ops 3
      BO3Fatality,

      // COD Modern Warfare 2
      MW2Paradox,
      MW2Reborn,

      // COD Modern Warfare 3
      MW3Paradox,
      MW3Phantom,
      MW3ProjectMemories,

      // COD Ghost
      GhostParadox,
      GhostEternity,

      // COD Advance warfare
      AWParadox,
      AWFury,
   };

public:
   CFindActiveGame();
   ~CFindActiveGame() noexcept = default;

   static void GameProcessThread(uint64_t arg);
   void Initialize();
   void ShutDown();
   bool LoadMenu(PatchedMenu menuId);
   uint32_t GetRunningGameProcessId();
   void GetGameName(char outTitleId[16], char outTitleName[64]);

private:
   void SetRunningGameProcessId(uint32_t pid);
   bool IsGameGTAV(const std::string& titleId);
   bool IsGameRDR(const std::string& titleId);
   bool IsGameMinecraft(const std::string& titleId);
   bool IsGameBO1(const std::string& titleId);
   bool IsGameBO2(const std::string& titleId);
   bool IsGameBO3(const std::string& titleId);
   bool IsGameMW2(const std::string& titleId);
   bool IsGameMW3(const std::string& titleId);
   bool IsGameCodGhost(const std::string& titleId);
   bool IsGameAW(const std::string& titleId);
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