/* 
 * File:   surat_tugas_panel.h
 * Author: bayucandra@gmail.com
 *
 * Created on January 25, 2015, 10:02 PM
 */

#ifndef SURAT_TUGAS_PANEL_H
#define	SURAT_TUGAS_PANEL_H

#include "surat_tugas_dialog.h"

class SuratTugasPanel : public wxPanel 
{
	private:
            //BEGIN BAYU=============
            void InitDataView();
            void InitDateRange();
            SuratTugasDialog *surat_tugas_dialog;
            //END BAYU**************
	
	protected:
		wxButton* tambah_button;
		wxButton* ubah_button;
		wxButton* hapus_button;
		wxDataViewListCtrl* surat_tugas_dataViewListCtrl;
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
		
		SuratTugasPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL ); 
		~SuratTugasPanel();
	
                //BEGIN BAYU===========
                void RefreshDataView();
                //END BAYU**************
};

#endif	/* SURAT_TUGAS_PANEL_H */

