#pragma once

#include "Settings.h"
#include "Shortcut.h"

namespace Launcher
{
	class Application;

	namespace LauncherEventIDs
	{
		enum LauncherEventID
		{
			First = wxID_HIGHEST + 1,
			Exit = First,
			Help,
			Redraw,
			Refresh,
			Update,
			Add,
			Last = Add,
		};
	}

	class TrayIcon : public wxTaskBarIcon
	{
	public:
		TrayIcon( Application* application );
		virtual ~TrayIcon();

		void Initialize();    
		void Cleanup();

		bool IsMenuShowing() const { return m_IsMenuShowing; }
		void BeginBusy();
		void EndBusy();

	protected:
		void OnTrayIconClick( wxTaskBarIconEvent& evt );
		void OnMenuExit( wxCommandEvent& evt );
		void OnMenuHelp( wxCommandEvent& evt );
		void OnMenuRedraw( wxCommandEvent& evt );
		void OnMenuRefresh( wxCommandEvent& evt );
		void OnMenuShortcut( wxCommandEvent& evt );
		void OnMenuAdd( wxCommandEvent& evt );

	private:
		void Refresh( bool reload );
		void DetectAndSetIcon( Shortcut& shortcut, wxMenuItem* shortcutMenuItem );
		void CreateProjectsMenu( wxMenu* parentMenu );

	private:
		Application* m_Application;
		V_Settings m_Settings;
		M_Shortcut m_ProjectShortcuts;
		wxMenu* m_Menu;
		int m_BusyCount;
		bool m_IsMenuShowing;
	};
}
