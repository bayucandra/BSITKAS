#include "umak_notebook.h"
#include "umak_panel.cpp"

UmakNotebook::UmakNotebook(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxNotebook(parent, id, pos, size, style, name) {
    umak_panel=new UmakPanel(this);
    AddPage(umak_panel, wxT("Laporan uang makan"));
}
UmakNotebook::~UmakNotebook(){
}

