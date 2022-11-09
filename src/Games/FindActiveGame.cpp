#include "FindActiveGame.hpp"
#include "GTAV.hpp"
#include "Minecraft.hpp"
#include "CODBO1.hpp"
#include "CODBO2.hpp"
#include "CODBO3.hpp"
#include "CODMW2.hpp"
#include "CODMW3.hpp"
#include "CODGhost.hpp"
#include "CODAdvanceWarfare.hpp"


FindActiveGame g_FindActiveGame;

FindActiveGame::FindActiveGame()
{
   sys_ppu_thread_create(&m_GameProcessPpuThreadId, GameProcessThread, 0, 1109, 0x8000, SYS_PPU_THREAD_CREATE_JOINABLE, "RouLetteGameProcess");
}

void FindActiveGame::Initialize()
{

}

void FindActiveGame::ShutDown()
{
   if (m_GameProcessPpuThreadId != SYS_PPU_THREAD_ID_INVALID)
   {
      m_GameProcessThreadRunning = false;

      // Prevent unload too fast (give time to other threads to finish)
      sys_ppu_thread_yield();
      sys_timer_sleep(1);

      uint64_t exitCode;
      sys_ppu_thread_join(m_GameProcessPpuThreadId, &exitCode);
   }
}

uint32_t FindActiveGame::GetRunningGameProcessId()
{
   return m_CurrentGamePid;
}

void FindActiveGame::SetRunningGameProcessId(uint32_t pid)
{
   m_CurrentGamePid = pid;
}

void FindActiveGame::GetGameName(char outTitleId[16], char outTitleName[64])
{
   paf::View* gamePlugin = paf::View::Find("game_plugin");
   if (!gamePlugin)
      return;

   vsh::GamePluginInterface* gameInterface = gamePlugin->GetInterface<vsh::GamePluginInterface*>(1);
   if (!gameInterface)
      return;

   char _gameInfo[0x120]{};
   gameInterface->gameInfo(_gameInfo);
   vsh::snprintf(outTitleId, 10, "%s", _gameInfo + 0x04);
   vsh::snprintf(outTitleName, 63, "%s", _gameInfo + 0x14);
}

bool FindActiveGame::IsGameGTAV(const std::string& titleId)
{
   if (titleId == "BLES01807" || titleId == "BLUS31156" || titleId == "BLJM61019"
      || titleId == "NPEB01283" || titleId == "NPUB31154")
      return true;

   return false;
}

bool FindActiveGame::IsGameRDR(const std::string& titleId)
{
   if (titleId == "BLES01294" || titleId == "BLUS30418" || titleId == "BLES01179" || titleId == "BLES00680"
      || titleId == "BLJM60265" || titleId == "NPEB00833" || titleId == "NPUB30638")
      return true;

   return false;
}

bool FindActiveGame::IsGameMinecraft(const std::string& titleId)
{
    if (titleId == "BLES01976" || titleId == "BLUS31426" || titleId == "NPUB31419" || titleId == "NPEB01899"
        || titleId == "NPJB00549")
        return true;

    return false;
}

bool FindActiveGame::IsGameCodBO1(const std::string& titleId)
{
    if (titleId == "BLUS30591" || titleId == "BLUS30625" || titleId == "BLUS30638" || titleId == "BLES01031"
        || titleId == "BLES01032" || titleId == "BLES01033" || titleId == "NPUB30584" || titleId == "NPEB00758"
        || titleId == "NPEB00760" || titleId == "NPEB00756" || titleId == "NPEB00757" || titleId == "NPEB00759"
        || titleId == "BLJM60286" || titleId == "BLJM60287")
        return true;

    return false;
}

bool FindActiveGame::IsGameCodBO2(const std::string& titleId)
{
    if (titleId == "BLUS31011" || titleId == "BLUS41005" || titleId == "BLUS31141" || titleId == "BLUS31140"
        || titleId == "BLES01717" || titleId == "BLES01718" || titleId == "BLES01719" || titleId == "BLES01720"
        || titleId == "NPUB31054" || titleId == "NPEB01206" || titleId == "NPEB01205" || titleId == "NPEB01204"
        || titleId == "BLJM60548")
        return true;

    return false;
}

bool FindActiveGame::IsGameCodBO3(const std::string& titleId)
{
    if (titleId == "BCJS35003" || titleId == "BLES02166" || titleId == "BLES02168" || titleId == "BLUS31527"
        || titleId == "NPEB02266" || titleId == "NPEB02268" || titleId == "NPJA00135" || titleId == "NPUB31665")
        return true;

    return false;
}

bool FindActiveGame::IsGameCodMW2(const std::string& titleId)
{
    if (titleId == "BLUS30450" || titleId == "BLUS30377" || titleId == "BLUS30337" || titleId == "BLUS30429"
        || titleId == "BLES00683" || titleId == "BLES00691" || titleId == "BLES00690" || titleId == "BLES00686"
        || titleId == "BLES00685" || titleId == "BLES00684" || titleId == "BLES00687" || titleId == "NPEB00731"
        || titleId == "BLJM61006" || titleId == "BLJM60191")
        return true;

    return false;
}

bool FindActiveGame::IsGameCodMW3(const std::string& titleId)
{
    if (titleId == "BLUS30838" || titleId == "BLUS30887" || titleId == "BLES01428" || titleId == "BLES01433"
        || titleId == "BLES01429" || titleId == "BLES01431" || titleId == "BLES01432" || titleId == "BLES01430"
        || titleId == "BLES01434" || titleId == "NPUB30787" || titleId == "NPUB30788" || titleId == "NPEB00964"
        || titleId == "NPEB00965" || titleId == "NPEB00966" || titleId == "NPEB00967" || titleId == "NPEB00968"
        || titleId == "NPEB00977" || titleId == "NPEB00978" || titleId == "BLJM60404" || titleId == "BLJM60422")
        return true;

    return false;
}

bool FindActiveGame::IsGameCodGhost(const std::string& titleId)
{
    if (titleId == "BLUS31270" || titleId == "BLES01948" || titleId == "BLES01945" || titleId == "NPEB01832"
        || titleId == "NPEB01835" || titleId == "NPUB31301" || titleId == "NPJB00527" || titleId == "NPJB00528"
        || titleId == "BLJM61126" || titleId == "BLJM61125")
        return true;

    return false;
}

bool FindActiveGame::IsGameCodAW(const std::string& titleId)
{
    if (titleId == "BLUS31466" || titleId == "BLES02077" || titleId == "BLES02078" || titleId == "BLES02079"
        || titleId == "NPEB02087" || titleId == "NPEB02092" || titleId == "NPEB02088" || titleId == "NPUB31553"
        || titleId == "BLJM61227" || titleId == "BLJM61228")
        return true;

    return false;
}

void FindActiveGame::WhileInGame(uint32_t pid, const char* titleId, const char* titleName)
{
   if (IsGameGTAV(titleId))
   {
      if (!m_HasGameInitialized)
      {
         GTAV::Initialize();
         m_HasGameInitialized = true;
      }

      //GTAV::OnUpdate();
   }
   else if (IsGameMinecraft(titleId))
   {
       if (!m_HasGameInitialized)
       {
           Minecraft::Initialize();
           m_HasGameInitialized = true;
       }
   }
   else if (IsGameCodBO1(titleId))
   {
      if (!m_HasGameInitialized)
      {
         CODBO1::Initialize();
         m_HasGameInitialized = true;
      }
   }
   else if (IsGameCodBO2(titleId))
   {
      if (!m_HasGameInitialized)
      {
         CODBO2::Initialize();
         m_HasGameInitialized = true;
      }
   }
   else if (IsGameCodBO3(titleId))
   {
      if (!m_HasGameInitialized)
      {
         CODBO3::Initialize();
         m_HasGameInitialized = true;
      }
   }
   else if (IsGameCodMW2(titleId))
   {
      if (!m_HasGameInitialized)
      {
         CODMW2::Initialize();
         m_HasGameInitialized = true;
      }
   }
   else if (IsGameCodMW3(titleId))
   {
      if (!m_HasGameInitialized)
      {
         CODMW3::Initialize();
         m_HasGameInitialized = true;
      }
   }
   else if (IsGameCodGhost(titleId))
   {
      if (!m_HasGameInitialized)
      {
         CODGhost::Initialize();
         m_HasGameInitialized = true;
      }
   }
   else if (IsGameCodAW(titleId))
   {
      if (!m_HasGameInitialized)
      {
         CODAW::Initialize();
         m_HasGameInitialized = true;
      }
   }

}

bool FindActiveGame::LoadMenu(PatchedMenu menuId)
{
   if (m_MenuToLoad != PatchedMenu::None && vsh::GetCooperationMode() == vsh::CooperationMode::Game)
   {
      vsh::ShowNavigationMessage(L"\uF46B You can not change menu while in game \uF46B");
      return false;
   }

   m_MenuToLoad = menuId;
   return true;
}

void FindActiveGame::GameProcessThread(uint64_t arg)
{
   g_FindActiveGame.m_GameProcessThreadRunning = true;
   uint32_t gameProcessID = 0;
   while (g_FindActiveGame.m_GameProcessThreadRunning)
   {
      gameProcessID = vsh::GetGameProcessId();

      if (gameProcessID != 0)
      {
         for (int x = 0; x < (10 * 100); x++) // 10 second delay
         {
            sys_timer_usleep(10000);
            sys_ppu_thread_yield();
         }

         g_FindActiveGame.SetRunningGameProcessId(gameProcessID);
         if (g_FindActiveGame.GetRunningGameProcessId())
         {
            char gameTitleId[16]{};
            char gameTitleName[64]{};
            g_FindActiveGame.GetGameName(gameTitleId, gameTitleName);
            g_FindActiveGame.WhileInGame(g_FindActiveGame.GetRunningGameProcessId(), gameTitleId, gameTitleName);
         }
      }
      else
      {
         // disconnect from game process
         if (g_FindActiveGame.GetRunningGameProcessId())
         {
            g_FindActiveGame.SetRunningGameProcessId(0);
            g_FindActiveGame.m_MenuToLoad = PatchedMenu::None;
            g_FindActiveGame.m_HasGameInitialized = false;
         }
      }

      // Good Bye CPU! Smallest sleep because we need to execute the patches as fast as possible 
      sys_timer_usleep(1668);
      sys_ppu_thread_yield();
   }

   sys_ppu_thread_exit(0);
}