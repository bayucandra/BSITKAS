/* 
 * File:   hari_libur_panel.h
 * Author: bayucandra@gmail.com
 *
 * Created on February 19, 2015, 9:11 PM
 */

#ifndef HARI_LIBUR_PANEL_H
#define	HARI_LIBUR_PANEL_H

#include "hari_libur_dialog.h"
class HariLiburPanel : public wxPanel 
{
	private:
            //BEGIN BAYU=============
            void InitDataView();
            void InitDateRange();
            HariLiburDialog* hari_libur_dialog;
            //END BAYU*******
	protected:
		wxButton* tambah_button;
		wxButton* ubah_button;
		wxButton* hapus_button;
		wxDataViewListCtrl* hari_libur_dataViewListCtrl;
		wxPanel* footer_panel;
		wxStaticText* m_staticText20;
		wxDatePickerCtrl* start_datePicker;
		wxStaticText* m_staticText21;
		wxDatePickerCtrl* end_datePicker;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnTambah( wxCommandEvent& event );
		virtual void OnUbah( wxCommandEvent& event );
		virtual void OnHapus( wxCommandEvent& event );
		virtual void OnFilterData( wxDateEvent& event );
		
	
	public:
		
		HariLiburPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL ); 
		~HariLiburPanel();
                //BEGIN BAYU======================
                void RefreshDataView();
};

#endif	/* HARI_LIBUR_PANEL_H */

