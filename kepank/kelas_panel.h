/* 
 * File:   kelas_panel.h
 * Author: bayucandra@gmail.com
 *
 * Created on January 13, 2015, 9:45 PM
 */

#ifndef KELAS_PANEL_H
#define	KELAS_PANEL_H
#include "kelas_input_dialog.h"
enum{
    ID_tambah_kelas, ID_ubah_kelas, ID_hapus_kelas
};
class KelasPanel : public wxPanel 
{
	private:
            //BEGIN BAYU============
            KelasInputDialog *kelas_input_dialog;
            void OnInputKelas(wxCommandEvent& event);
            void InitDataView();
            void OnUbahKelas(wxCommandEvent& event);
            void OnHapusKelas(wxCommandEvent& event);
            //END BAYU****************
	protected:
		wxButton* tambah_kelas_button;
		wxButton* ubah_kelas_button;
		wxButton* hapus_kelas_button;
		wxDataViewListCtrl* kelas_dataViewListCtrl;
	
	public:
		
		KelasPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL ); 
		~KelasPanel();
                
            //BEGIN BAYU============
            void RefreshDataView();
        wxDECLARE_EVENT_TABLE();
	
};

#endif	/* KELAS_PANEL_H */

