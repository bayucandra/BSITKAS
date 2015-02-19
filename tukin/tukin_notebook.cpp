#include "tukin_notebook.h"
#include "tukin_panel.cpp"
TukinNotebook::TukinNotebook(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxNotebook(parent, id, pos, size, style, name) {
    tukin_panel=new TukinPanel(this);
    AddPage(tukin_panel, wxT("Laporan Tukin"));
}
TukinNotebook::~TukinNotebook(){
}

