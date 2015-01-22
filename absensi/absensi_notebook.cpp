#include "absensi_notebook.h"
#include "absensi_panel.cpp"
#include "izin_panel.cpp"

AbsensiNotebook::AbsensiNotebook(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size, long style, const wxString &name) : wxNotebook(parent, id, pos, size, style, name){
    absensi_panel=new AbsensiPanel(this);
    AddPage(absensi_panel, wxT("Absensi"));
    
    izin_panel=new IzinPanel(this);
    AddPage(izin_panel, wxT("Izin"));
}
AbsensiNotebook::~AbsensiNotebook(){
}

