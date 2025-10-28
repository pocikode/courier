#ifndef FRAME_H
#define FRAME_H

#include <wx/listbox.h>
#include <wx/simplebook.h>
#include <wx/splitter.h>
#include <wx/wx.h>

enum
{
    ID_Hello = 1,
    ID_NAVIGATION_LIST = 1000
};

class MainFrame : public wxFrame
{
  public:
    MainFrame();

  private:
    // Event handlers
    void OnNavigationSelect(wxCommandEvent &event);
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);

    // UI Controls (retrieved from XRC)
    wxSplitterWindow *m_splitter;
    wxListBox *m_navigationList;
    wxSimplebook *m_pageBook;

    // Panels
    wxPanel *m_sidebarPanel;
    wxPanel *m_contentPanel;
    wxPanel *m_homePanel;
    wxPanel *m_settingsPanel;
    wxPanel *m_aboutPanel;

    // Initialize controls from XRC
    void InitializeControls();

    wxDECLARE_EVENT_TABLE();
};

#endif // !FRAME_H