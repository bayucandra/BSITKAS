/* 
 * File:   pangkat_panel.h
 * Author: bayucandra@gmail.com
 *
 * Created on January 19, 2015, 7:52 PM
 */

#ifndef PANGKAT_PANEL_H
#define	PANGKAT_PANEL_H

#include "wx/panel.h"
#include "wx/dataview.h"
#include "pangkat_input_dialog.h"
enum{
    ID_tambah_pangkat, ID_ubah_pangkat, ID_hapus_pangkat
};

class PangkatPanel : public wxPanel 
{
	private:
            //BEGIN BAYU============
            PangkatInputDialog* pangkat_input_dialog;
            void InitDataView();
            //END BAYU****************
	
	protected:
		wxButton* tambah_button;
		wxButton* ubah_button;
		wxButton* hapus_button;
		wxDataViewListCtrl* pangkat_dataViewListCtrl;
		
		// Virtual event handlers, overide them in your derived class
		void OnTambahPangkat( wxCommandEvent& event );
		void OnUbahPangkat( wxCommandEvent& event );
		void OnHapusPangkat( wxCommandEvent& event );
                
		
	
	public:
		
		PangkatPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL ); 
		~PangkatPanel();
            //BEGIN BAYU=============
            void RefreshDataView();
};

#endif	/* PANGKAT_PANEL_H */

