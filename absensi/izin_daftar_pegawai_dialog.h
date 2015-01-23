/* 
 * File:   izin_daftar_pegawai_dialog.h
 * Author: bayucandra@gmail.com
 *
 * Created on January 23, 2015, 8:30 PM
 */

#ifndef IZIN_DAFTAR_PEGAWAI_DIALOG_H
#define	IZIN_DAFTAR_PEGAWAI_DIALOG_H

class IzinDaftarPegawaiDialog : public wxDialog 
{
	private:
	
	protected:
		wxTextCtrl* m_textCtrl21;
		wxButton* cari_button;
		wxDataViewListCtrl* m_dataViewListCtrl7;
		wxButton* pilih_button;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCari( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPilih( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		IzinDaftarPegawaiDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Daftar pegawai"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 400,300 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~IzinDaftarPegawaiDialog();
	
};

#endif	/* IZIN_DAFTAR_PEGAWAI_DIALOG_H */

