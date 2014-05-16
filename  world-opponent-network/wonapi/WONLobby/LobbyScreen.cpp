#include "LobbyScreen.h"

#include "LobbyContainer.h"
#include "LobbyEvent.h"
#include "LoginScreen.h"
#include "RootScreen.h"
#include "WONLobbyPrv.h"

#include "WONGUI/Window.h"

using namespace WONAPI;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void LobbyScreen::ShowWindow(bool show)
{
	Window *aWindow = GetWindow();
	if(aWindow!=NULL)
		aWindow->Show(show);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
bool LobbyScreen::IsWindowShowing()
{
	Window *aWindow = GetWindow();
	if(aWindow!=NULL)
		return aWindow->IsShowing();
	else
		return false;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
Container* LobbyScreen::GetCurScreen()
{
	if(gLobbyData.get()==NULL)
		return NULL;

	if(OnInternetScreen())
		return gLobbyData->mLobbyContainer->GetInternetScreen();
	else if(OnLanScreen())
		return gLobbyData->mLobbyContainer->GetLanScreen();
	else if(OnLoginScreen())
		return gLobbyData->mLobbyContainer->GetLoginScreen();
	else
		return NULL;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void LobbyScreen::ShowInternetScreen()
{
	if(gLobbyData.get()!=NULL)
	{
		gLobbyData->mLobbyContainer->ShowInternetScreen();
		gLobbyData->mLobbyContainer->GetInternetScreen()->BroadcastEventDown(new LobbyEvent(LobbyEvent_EnteredScreen));
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void LobbyScreen::ShowLanScreen()
{
	if(gLobbyData.get()!=NULL)
	{
		gLobbyData->mLobbyContainer->ShowLanScreen();
		gLobbyData->mLobbyContainer->GetLanScreen()->BroadcastEventDown(new LobbyEvent(LobbyEvent_EnteredScreen));
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void LobbyScreen::ShowLoginScreen()
{
	if(gLobbyData.get()!=NULL)
	{
		gLobbyData->mLobbyContainer->ShowLoginScreen();
		gLobbyData->mLobbyContainer->GetLoginScreen()->BroadcastEventDown(new LobbyEvent(LobbyEvent_EnteredScreen));
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void LobbyScreen::ShowLobbyTab()
{
	if(gLobbyData.get()!=NULL)
		gLobbyData->mLobbyContainer->GetInternetScreen()->ShowLobbyTab();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void LobbyScreen::ShowMOTD()
{
	if(gLobbyData.get()!=NULL)
		gLobbyData->mLobbyContainer->GetLoginScreen()->ShowMOTD();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void LobbyScreen::ShowCreateAccountCtrl()
{
	if(gLobbyData.get()!=NULL)
		gLobbyData->mLobbyContainer->GetLoginScreen()->ShowCreateAccountCtrl();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void LobbyScreen::ShowLostPasswordCtrl()
{
	if(gLobbyData.get()!=NULL)
		gLobbyData->mLobbyContainer->GetLoginScreen()->ShowLostPasswordCtrl();

}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void LobbyScreen::ShowLostUsernameCtrl()
{
	if(gLobbyData.get()!=NULL)
		gLobbyData->mLobbyContainer->GetLoginScreen()->ShowLostUsernameCtrl();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
bool LobbyScreen::OnInternetScreen()
{
	if(gLobbyData.get()!=NULL)
		return gLobbyData->mLobbyContainer->OnInternetScreen();
	else
		return false;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
bool LobbyScreen::OnLanScreen()
{
	if(gLobbyData.get()!=NULL)
		return gLobbyData->mLobbyContainer->OnLanScreen();
	else
		return false;
}
	
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
bool LobbyScreen::OnLoginScreen()
{
	if(gLobbyData.get()!=NULL)
		return gLobbyData->mLobbyContainer->OnLoginScreen();
	else
		return false;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
LobbyGameType LobbyScreen::GetGameScreenType()
{
	if(!gLobbyData.get()!=NULL)
		return LobbyGameType_None;

	return gLobbyData->mLobbyContainer->GetGameScreenType();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
Container* LobbyScreen::GetLobbyContainer()
{
	return gLobbyData.get()?gLobbyData->mLobbyContainer:NULL;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ColorScheme* LobbyScreen::GetColorScheme()
{
	return gLobbyData.get()?gLobbyData->mLobbyContainer->GetColorScheme():NULL;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
Window* LobbyScreen::GetWindow()
{
	return gLobbyData.get()?gLobbyData->mLobbyContainer->GetWindow():NULL;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
WindowManager* LobbyScreen::GetWindowManager()
{
	return WindowManager::GetDefaultWindowManager();
}