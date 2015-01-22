/* 
 * File:   izin_panel.h
 * Author: bayucandra@gmail.com
 *
 * Created on January 22, 2015, 9:57 PM
 */

#ifndef IZIN_PANEL_H
#define	IZIN_PANEL_H

class IzinPanel : public wxPanel 
{
	private:
            //BEGIN BAYU=============
            void InitDataView();
            void InitDateRange();
            //END BAYU*******
	protected:
		wxButton* tambah_button;
		wxButton* ubah_button;
		wxButton* hapus_button;
		wxDataViewListCtrl* izin_dataViewListCtrl;
		wxPanel* footer_panel;
		wxStaticText* m_staticText20;
		wxDatePickerCtrl* start_datePicker;
		wxStaticText* m_staticText21;
		wxDatePickerCtrl* end_datePicker;
		wxStaticText* m_staticText22;
		wxTextCtrl* m_textCtrl14;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnTambah( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUbah( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHapus( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFilterData( wxDateEvent& event ) { event.Skip(); }
		virtual void OnFilterData( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		IzinPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL ); 
		~IzinPanel();
                //BEGIN BAYU===========
                void RefreshDataView();
                //END BAYU**************
};

#endif	/* IZIN_PANEL_H */

