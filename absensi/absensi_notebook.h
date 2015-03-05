/* 
 * File:   absensi_notebook.h
 * Author: bayucandra@gmail.com
 *
 * Created on January 22, 2015, 8:51 PM
 */

#ifndef ABSENSI_NOTEBOOK_H
#define	ABSENSI_NOTEBOOK_H

//#include "absensi_panel.h"
#include "hari_libur_panel.h"
#include "izin_panel.h"
#include "dinas_luar_panel.h"
#include "surat_tugas_panel.h"
#include "cuti_panel.h"

class AbsensiNotebook : public wxNotebook
{
    private:
//        AbsensiPanel *absensi_panel;
        HariLiburPanel *hari_libur_panel;
        IzinPanel *izin_panel;
        DinasLuarPanel *dinas_luar_panel;
        SuratTugasPanel *surat_tugas_panel;
        CutiPanel *cuti_panel;
        
    public:
        AbsensiNotebook(wxWindow *parent, wxWindowID id=wxID_ANY, const wxPoint &pos=wxDefaultPosition, const wxSize &size=wxDefaultSize, long style=wxTAB_TRAVERSAL, const wxString &name=wxPanelNameStr);
        ~AbsensiNotebook();
};

#endif	/* ABSENSI_NOTEBOOK_H */

