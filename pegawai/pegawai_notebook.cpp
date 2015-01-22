#include "pegawai_notebook.h"
#include "pegawai_panel.cpp"

PegawaiNotebook::PegawaiNotebook(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxNotebook(parent, id, pos, size, style, name) {
    pegawai_panel=new PegawaiPanel(this);
    AddPage(pegawai_panel, wxT("Pegawai"));
}
PegawaiNotebook::~PegawaiNotebook(){
}
