#include "absensi_notebook.h"
#include "absensi_panel.cpp"
#include "izin_panel.cpp"
#include "dinas_luar_panel.cpp"
#include "surat_tugas_panel.cpp"

AbsensiNotebook::AbsensiNotebook(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size, long style, const wxString &name) : wxNotebook(parent, id, pos, size, style, name){
    absensi_panel=new AbsensiPanel(this);
    AddPage(absensi_panel, wxT("Absensi"));
    
    izin_panel=new IzinPanel(this);
    AddPage(izin_panel, wxT("Izin"));
    
    dinas_luar_panel=new DinasLuarPanel(this);
    AddPage(dinas_luar_panel, wxT("Dinas Luar"));
    
    surat_tugas_panel=new SuratTugasPanel(this);
    AddPage(surat_tugas_panel, wxT("Surat Tugas"));
}
AbsensiNotebook::~AbsensiNotebook(){
}

