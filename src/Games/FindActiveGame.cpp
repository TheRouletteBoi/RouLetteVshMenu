#include "FindActiveGame.hpp"
#include "GTAV.hpp"

CFindActiveGame g_FindActiveGame;

void CFindActiveGame::Initialize()
{
   sys_ppu_thread_create(&m_GameProcessPpuThreadId, GameProcessThread, 0, 1109, 2048, SYS_PPU_THREAD_CREATE_JOINABLE, "RouLetteGameProcess");
}

void CFindActiveGame::ShutDown()
{
   if (m_GameProcessPpuThreadId != SYS_PPU_THREAD_ID_INVALID)
   {
      gameProcessThreadRunning = false;

      // Prevent unload too fast (give time to other threads to finish)
      sys_ppu_thread_yield();
      sys_timer_sleep(1);

      uint64_t exitCode;
      sys_ppu_thread_join(m_GameProcessPpuThreadId, &exitCode);
   }
}

uint32_t CFindActiveGame::GetRunningGameProcessId()
{
   return m_CurrentGamePid;
}

void CFindActiveGame::SetRunningGameProcessId(uint32_t pid)
{
   m_CurrentGamePid = pid;
}

void CFindActiveGame::GetGameName(GameName& name)
{
   vsh::paf::View* gamePlugin = vsh::paf::View::Find("game_plugin");
   if (!gamePlugin)
      return;

   vsh::game_plugin_interface* game_interface = gamePlugin->GetInterface<vsh::game_plugin_interface*>(1);
   if (!game_interface)
      return;

   char _gameInfo[0x120]{};
   game_interface->gameInfo(_gameInfo);
   vsh::snprintf(&name.titleId[0], 10, "%s", _gameInfo + 0x04);
   vsh::snprintf(&name.titleName[0], 63, "%s", _gameInfo + 0x14);
}

bool CFindActiveGame::IsGameGTAV(const std::string& titleId)
{
   if (titleId == "BLES01807" || titleId == "BLUS31156" || titleId == "BLJM61019"
      || titleId == "NPEB01283" || titleId == "NPUB31154")
      return true;

   return false;
}

bool CFindActiveGame::IsGameRDR(const std::string& titleId)
{
   if (titleId == "BLES01294" || titleId == "BLUS30418" || titleId == "BLES01179" || titleId == "BLES00680"
      || titleId == "BLJM60265" || titleId == "NPEB00833" || titleId == "NPUB30638")
      return true;

   return false;
}

bool CFindActiveGame::IsGameMinecraft(const std::string& titleId)
{
   if (titleId == "BLES01976" || titleId == "NPUB31419" || titleId == "NPEB01899")
      return true;

   return false;
}

bool CFindActiveGame::IsGameMW2(const std::string& titleId)
{
   if (titleId == "BLES00683" || titleId == "BLUS30377" || titleId == "NPEB00731")
      return true;

   return false;
}

bool CFindActiveGame::IsGameMW3(const std::string& titleId)
{
   if (titleId == "BLES01428" || titleId == "BLUS30838" || titleId == "NPUB30787")
      return true;

   return false;
}

bool CFindActiveGame::IsGameBO1(const std::string& titleId)
{
   if (titleId == "BLUS30591" || titleId == "BLES01031" || titleId == "BLES01032" || titleId == "BLES01033"
      || titleId == "NPUB30584")
      return true;

   return false;
}

bool CFindActiveGame::IsGameBO2(const std::string& titleId)
{
   if (titleId == "BLUS31011" || titleId == "BLES01717" || titleId == "BLES01718" || titleId == "BLES01719"
      || titleId == "BLES01720" || titleId == "NPUB31054" || titleId == "NPEP00183" || titleId == "NPEB02266")
      return true;

   return false;
}

bool CFindActiveGame::IsGameBO3(const std::string& titleId)
{
   if (titleId == "NPEB02266" || titleId == "BLES02166")
      return true;

   return false;
}

bool IsGameCodGhosts(const std::string& titleId)
{
   return false;
}

bool CFindActiveGame::IsGameAW(const std::string& titleId)
{
   if (titleId == "BLUS31466" || titleId == "BLES02077" || titleId == "BLES02078" || titleId == "NPEP00266")
      return true;

   return false;
}

void CFindActiveGame::WhileInGame(uint32_t pid, const std::string& titleId, const std::string& titleName)
{
   if (IsGameGTAV(titleId)) // doesn't seem to work wtf???
   {
      vsh::printf("we are in gtav\n");
      if (!hasGameInitialized)
      {
         GTAV::Initialize();
         hasGameInitialized = true;
      }

      //GTAV::Update();
   }
}

bool CFindActiveGame::LoadMenu(PatchedMenu menuId)
{
   if (m_MenuToLoad != PatchedMenu::None && vsh::GetCooperationMode() == vsh::eCooperationMode::GameMode)
   {
      vsh::ShowButtonNavigationMessage(L"\uF46B You can not change menu while in game \uF46B");
      return false;
   }

   m_MenuToLoad = menuId;
   return true;
}

void CFindActiveGame::GameProcessThread(uint64_t arg)
{
   g_FindActiveGame.gameProcessThreadRunning = true;
   uint32_t gameProcessID = 0;
   while (g_FindActiveGame.gameProcessThreadRunning)
   {
      gameProcessID = vsh::GetGameProcessID();

      if (gameProcessID != 0)
      {
         g_FindActiveGame.SetRunningGameProcessId(gameProcessID);
         if (g_FindActiveGame.GetRunningGameProcessId())
         {
            CFindActiveGame::GameName name;
            g_FindActiveGame.GetGameName(name);
            g_FindActiveGame.WhileInGame(g_FindActiveGame.GetRunningGameProcessId(), name.titleId, name.titleName);
         }
      }
      else
      {
         // disconnect from game process
         if (g_FindActiveGame.GetRunningGameProcessId())
         {
            g_FindActiveGame.SetRunningGameProcessId(0);
            g_FindActiveGame.m_MenuToLoad = PatchedMenu::None;
            g_FindActiveGame.hasGameInitialized = false;
         }
      }

      // Good Bye CPU! Smallest sleep because we need to execute the patches as fast as possible 
      sys_timer_usleep(1668);
   }


   sys_ppu_thread_exit(0);
}