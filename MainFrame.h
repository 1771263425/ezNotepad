#ifndef MAINFRAME_H
#define MAINFRAME_H
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
namespace vlc {

class MainFrame : public wxFrame {
public:
  MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

private:
  wxTextCtrl textCtrl;
  wxString filename;
  void OnNew(wxCommandEvent &event);
  void OnExit(wxCommandEvent &event);
  void OnAbout(wxCommandEvent &event);
  void OnOpen(wxCommandEvent &event);
  void OnSave(wxCommandEvent &event);
  void OnSaveAs(wxCommandEvent &event);
  void doSave(wxString &filename);
  wxDECLARE_EVENT_TABLE();
};
enum { ID_New = 1, ID_Save, ID_Open, ID_SaveAs };
}

#endif // MAINFRAME_H
