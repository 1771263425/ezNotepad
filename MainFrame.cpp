#include "MainFrame.h"
#include <fstream>
#include <iostream>
namespace vlc {
wxBEGIN_EVENT_TABLE(MainFrame, wxFrame) EVT_MENU(ID_New, MainFrame::OnNew)
    EVT_MENU(ID_Open, MainFrame::OnOpen) EVT_MENU(ID_Save, MainFrame::OnSave)
        EVT_MENU(wxID_EXIT, MainFrame::OnExit)
            EVT_MENU(ID_SaveAs, MainFrame::OnSaveAs)
                EVT_MENU(wxID_ABOUT, MainFrame::OnAbout) wxEND_EVENT_TABLE()

                    MainFrame::MainFrame(const wxString &title,
                                         const wxPoint &pos, const wxSize &size)
    : wxFrame(NULL, wxID_ANY, title, pos, size),
      textCtrl(this, -1, "", wxPoint(0, 0), wxSize(100, 100), wxTE_MULTILINE) {
  wxMenu *menuFile = new wxMenu;
  menuFile->Append(ID_New, "&New \tCtrl-N",
                   "Help string shown in status bar for this menu item");
  menuFile->Append(ID_Open, "Open \tCtrl-O");
  menuFile->Append(ID_Save, "Save \tCtrl-S");
  menuFile->Append(ID_SaveAs, "Save As ");
  menuFile->AppendSeparator();
  menuFile->Append(wxID_EXIT);
  wxMenu *menuHelp = new wxMenu;
  menuHelp->Append(wxID_ABOUT);
  wxMenuBar *menuBar = new wxMenuBar;
  menuBar->Append(menuFile, "&File");
  menuBar->Append(menuHelp, "&Help");
  SetMenuBar(menuBar);
  // CreateStatusBar();
  // SetStatusText("Welcome to use this app!");
}

void MainFrame::OnExit(wxCommandEvent &event) { Close(true); }
void MainFrame::OnAbout(wxCommandEvent &event) {
  wxMessageBox("This is a text editor like notepad", "About Easy Notepad",
               wxOK | wxICON_INFORMATION);
}
void MainFrame::OnNew(wxCommandEvent &event) {
  filename.Clear();
  textCtrl.Clear();
}
void MainFrame::OnOpen(wxCommandEvent &event) {
  filename = wxFileSelector("Choose a file to open", "", "", "",
                            "text files (*.txt)|*.txt|log files (*.log)|*.log");
  // std::cout << "file name" << filename << std::endl;
  if (filename.IsEmpty())
    return;
  std::fstream fs(filename.ToStdString(), std::fstream::in);
  if (!fs.good()) {
    wxLogMessage("error occurs when opening the file!");
    return;
  }
  textCtrl.Clear();
  while (!fs.eof()) {
    std::string str;
    std::getline(fs, str);
    //   std::cout << "get line" << str << std::endl;
    textCtrl << str << "\n";
  }
  fs.close();
}
void MainFrame::doSave(wxString &filename) {
  std::fstream fs(filename.ToStdString(), std::fstream::out);
  if (!fs.good()) {
    wxLogMessage("error occurs when opening the file!");
    return;
  }
  fs.close();
  if (!textCtrl.SaveFile(filename))
    wxLogMessage("save file failed!");
}

void MainFrame::OnSave(wxCommandEvent &event) {
  if (filename.IsEmpty()) {
    // choose a file
    OnSaveAs(event);
  } else {
    doSave(filename);
  }
}

void MainFrame::OnSaveAs(wxCommandEvent &event) {
  filename = wxFileSelector("Save As", "", "", "",
                            "text files (*.txt)|*.txt|log files (*.log)|*.log");
  if (filename.IsEmpty())
    return;
  doSave(filename);
}
}
