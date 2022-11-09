#include "Helpers.hpp"

Helpers g_Helpers;

Helpers::Helpers()
{
    m_IsHen = IsConsoleHen();
}

void Helpers::OnUpdate()
{
    // Update plugins and widgets pointers
    m_SystemPlugin = paf::View::Find("system_plugin");
    m_GamePlugin = paf::View::Find("game_plugin");
    m_GameExtPlugin = paf::View::Find("game_ext_plugin");
    m_XmbPlugin = paf::View::Find("xmb_plugin");

    m_PageAutoOffGuide = m_SystemPlugin ? m_SystemPlugin->FindWidget("page_autooff_guide") : nullptr;


    MonitorGameState();

#ifdef LAUNCHER_DEBUG
    if (g_Input.IsButtonBinds(Input::BUTTON_L1, Input::BUTTON_PAD_UP))
        TakeScreenshot();
#endif // LAUNCHER_DEBUG
}

void Helpers::MonitorGameState()
{
    //uint64_t timeNow = GetTimeNow();

    // Detect game launch 
    if (vsh::GetCooperationMode() != vsh::CooperationMode::XMB && !m_StateGameRunning)
    {
        m_StateGameRunning = true;
        m_StateGameJustLaunched = true;
        //m_GameLaunchTime = timeNow;
    }
    else if (vsh::GetCooperationMode() == vsh::CooperationMode::XMB)
        m_StateGameRunning = false;

    //if (timeNow - m_GameLaunchTime > 15 * 1000)
    //    m_StateGameJustLaunched = false;
}

void Helpers::TakeScreenshot()
{
    uint64_t timeNow = GetTimeNow();

    if ((timeNow - m_ScreenshotLastTime) < 500)
        return;

    m_ScreenshotLastTime = timeNow;

    if (vsh::GetCooperationMode() == vsh::CooperationMode::XMB)
    {
        if (!m_SystemPlugin)
            return;

        vsh::SystemPluginInterface* systemInterface = m_SystemPlugin->GetInterface<vsh::SystemPluginInterface*>(1);
        if (!systemInterface)
            return;

        std::string screenshotPath = GetCurrentDir() + "Screenshots";
        vsh::mkdir(screenshotPath.c_str(), 40777);

        time_t rawtime;
        vsh::time(&rawtime);
        tm* timeinfo = vsh::localtime(&rawtime);

        char datestr[100];
        vsh::strftime(datestr, sizeof(datestr), "%Y-%m-%d_%H-%M-%S", timeinfo);

        std::string screenshotName = screenshotPath + "/" + datestr + ".bmp";

        systemInterface->saveBMP(screenshotName.c_str());

        wchar_t buffer[130];
        vsh::swprintf(buffer, sizeof(buffer), L"Screenshot saved as: %s", screenshotName.c_str());
        vsh::ShowNavigationMessage(buffer);
    }
    else
        vsh::ShowNavigationMessage(L"Screenshots aren't supported in game");
}