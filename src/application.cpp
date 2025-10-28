#include "application.hpp"
#include "frame.hpp"
#include <wx/xrc/xmlres.h>

bool Application::OnInit()
{
    wxXmlResource::Get()->InitAllHandlers();
    InitXmlResource();

    MainFrame *frame = new MainFrame();
    frame->Show(true);
    return true;
}