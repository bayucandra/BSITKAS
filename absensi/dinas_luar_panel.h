/* 
 * File:   dinas_luar_panel.h
 * Author: bayucandra@gmail.com
 *
 * Created on January 25, 2015, 8:23 PM
 */

#ifndef DINAS_LUAR_PANEL_H
#define	DINAS_LUAR_PANEL_H

#include "dinas_luar_dialog.h"

class DinasLuarPanel : public wxPanel 
{
	private:
            //BEGIN BAYU=============
            void InitDataView();
            void InitDateRange();
            DinasLuarDialog *dinas_luar_dialog;
            //END BAYU**************
	
	protected:
		wxButton* tambah_button;
		wxButton* ubah_button;
		wxButton* hapus_button;
		wxDataViewListCtrl* dinas_luar_dataViewListCtrl;
		wxPanel* footer_panel;
		wxStaticText* m_staticText20;
		wxDatePickerCtrl* start_datePicker;
		wxStaticText* m_staticText21;
		wxDatePickerCtrl* end_datePicker;
		wxStaticText* m_staticText22;
		wxTextCtrl* filter_nama_textCtrl;
		
		// Virtual event handlers, overide them in your derived class
		void OnTambah( wxCommandEvent& event );
		void OnUbah( wxCommandEvent& event );
		void OnHapus( wxCommandEvent& event );
		virtual void OnFilterData( wxDateEvent& event );
		virtual void OnFilterData( wxCommandEvent& event );
		
	
	public:
		
		DinasLuarPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL ); 
		~DinasLuarPanel();
	
                //BEGIN BAYU===========
                void RefreshDataView();
                //END BAYU**************
};

#endif	/* DINAS_LUAR_PANEL_H */

