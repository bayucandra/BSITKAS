/* 
 * File:   absensi_panel.h
 * Author: bayucandra@gmail.com
 *
 * Created on January 22, 2015, 9:01 PM
 */

#ifndef ABSENSI_PANEL_H
#define	ABSENSI_PANEL_H


//#include <wx/textctrl.h>
//#include <wx/button.h>

class AbsensiPanel : public wxPanel 
{
	private:
	
	protected:
		wxButton* tambah_button;
		wxButton* ubah_button;
		wxButton* hapus_button;
		wxDataViewListCtrl* absensi_dataViewListCtrl;
		wxPanel* m_panel4;
		wxStaticText* m_staticText20;
		wxDatePickerCtrl* m_datePicker1;
		wxStaticText* m_staticText21;
		wxDatePickerCtrl* m_datePicker2;
		wxStaticText* m_staticText22;
		wxTextCtrl* m_textCtrl14;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnTambah( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUbah( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHapus( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFilterData( wxDateEvent& event ) { event.Skip(); }
		virtual void OnFilterData( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		AbsensiPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL ); 
		~AbsensiPanel();
	
};

#endif	/* ABSENSI_PANEL_H */

