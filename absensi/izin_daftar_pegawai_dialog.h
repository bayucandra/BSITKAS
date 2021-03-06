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
            //BEGIN BAYU==================
            void InitDataView();
            //END BAYU******************
	protected:
		wxTextCtrl* cari_textCtrl;
		wxButton* cari_button;
		wxDataViewListCtrl* pegawai_dataViewListCtrl;
		
		// Virtual event handlers, overide them in your derived class
		void OnCari( wxCommandEvent& event );
		void OnPilih( wxDataViewEvent& event );
                void Pilih();
		
	
	public:
		
		IzinDaftarPegawaiDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Daftar pegawai"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 450,350 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~IzinDaftarPegawaiDialog();
                //BEGIN BAYU=================
                void RefreshDataView();
                //END BAYU****************
	
};

#endif	/* IZIN_DAFTAR_PEGAWAI_DIALOG_H */

