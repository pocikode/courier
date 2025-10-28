#ifndef APPLICATION_H
#define APPLICATION_H

#include <wx/wx.h>

extern void InitXmlResource();

class Application : public wxApp
{
  public:
    bool OnInit() override;
};

#endif // !APPLICATION_H