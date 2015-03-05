/* 
 * File:   cuti_panel.h
 * Author: bayucandra@gmail.com
 *
 * Created on February 24, 2015, 9:52 PM
 */

#ifndef CUTI_PANEL_H
#define	CUTI_PANEL_H

#include "cuti_dialog.h"
class CutiPanel : public wxPanel 
{
	private:
            //BEGIN BAYU============
            void InitDateRange();
            void InitDataView();
            CutiDialog *cuti_dialog;
            //END BAYU************
	protected:
		wxButton* tambah_button;
		wxButton* ubah_button;
		wxButton* hapus_button;
		wxPanel* footer_panel;
		wxStaticText* m_staticText20;
		wxDatePickerCtrl* start_datePicker;
		wxStaticText* m_staticText21;
		wxDatePickerCtrl* end_datePicker;
		wxStaticText* m_staticText22;
		wxTextCtrl* filter_nama_textCtrl;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnTambah( wxCommandEvent& event );
		virtual void OnUbah( wxCommandEvent& event );
		virtual void OnHapus( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFilterData( wxDateEvent& event );
		virtual void OnFilterData( wxCommandEvent& event );
		
	
	public:
		
		CutiPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL ); 
		~CutiPanel();
                //BEGIN BAYU===============
                void RefreshDataView();
		wxDataViewListCtrl* cuti_dataViewListCtrl;
                //END BAYU************************
	
};

#endif	/* CUTI_PANEL_H */

