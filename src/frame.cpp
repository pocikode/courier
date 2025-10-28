#include "frame.hpp"
#include <wx/xrc/xmlres.h>

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame) EVT_LISTBOX(XRCID("m_listBox1"), MainFrame::OnNavigationSelect) EVT_MENU(
    wxID_EXIT, MainFrame::OnExit
) EVT_MENU(wxID_ABOUT, MainFrame::OnAbout) wxEND_EVENT_TABLE()

    MainFrame::MainFrame()
{
    // Load the frame from XRC - this will set all properties including title,
    // size, etc.
    wxXmlResource::Get()->LoadFrame(this, nullptr, "MainFrame");

    // Initialize controls after loading from XRC
    InitializeControls();

    // Center the frame on screen
    Centre();
}

void MainFrame::InitializeControls()
{
    // Get references to controls defined in XRC
    m_splitter = XRCCTRL(*this, "topLevelSplitter", wxSplitterWindow);
    m_navigationList = XRCCTRL(*this, "m_listBox1", wxListBox);
    m_pageBook = XRCCTRL(*this, "pageBook", wxSimplebook);

    // Get panel references
    m_sidebarPanel = XRCCTRL(*this, "sidebarPanel", wxPanel);
    m_contentPanel = XRCCTRL(*this, "contentPanel", wxPanel);
    m_homePanel = XRCCTRL(*this, "homePanel", wxPanel);
    m_settingsPanel = XRCCTRL(*this, "settingsPanel", wxPanel);
    m_aboutPanel = XRCCTRL(*this, "aboutPanel", wxPanel);

    // Set initial page
    if (m_pageBook && m_navigationList)
    {
        m_pageBook->SetSelection(0);       // Start with Dashboard
        m_navigationList->SetSelection(0); // Select first item in navigation
    }

    // Ensure splitter is properly set up
    if (m_splitter)
    {
        m_splitter->SetMinimumPaneSize(200);
    }
}

void MainFrame::OnNavigationSelect(wxCommandEvent &event)
{
    if (!m_navigationList || !m_pageBook)
        return;

    int selection = m_navigationList->GetSelection();
    if (selection == wxNOT_FOUND)
        return;

    // Switch to the corresponding page
    switch (selection)
    {
    case 0: // Dashboard
        m_pageBook->SetSelection(0);
        break;
    case 1: // Settings
        m_pageBook->SetSelection(1);
        break;
    case 2: // About
        m_pageBook->SetSelection(2);
        break;
    default:
        break;
    }
}

void MainFrame::OnExit(wxCommandEvent &event)
{
    Close(true);
}

void MainFrame::OnAbout(wxCommandEvent &event)
{
    wxMessageBox(
        "SNAP Tools - A wxWidgets Application\n\n"
        "Built with wxWidgets and XRC resources.",
        "About SNAP Tools", wxOK | wxICON_INFORMATION
    );
}