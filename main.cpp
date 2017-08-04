// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "MainFrame.h"
class MyApp : public wxApp {
public:
  virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit() {
  using namespace vlc;
  MainFrame *frame =
      new MainFrame("Easy Notepad", wxPoint(50, 50), wxSize(600, 600));
  frame->Show(true);
  return true;
}
