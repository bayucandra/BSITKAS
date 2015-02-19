/* 
 * File:   dinas_luar_daftar_pegawai_dialog.h
 * Author: bayucandra@gmail.com
 *
 * Created on January 25, 2015, 9:18 PM
 */

#ifndef DINAS_LUAR_DAFTAR_PEGAWAI_DIALOG_H
#define	DINAS_LUAR_DAFTAR_PEGAWAI_DIALOG_H

class DinasLuarDaftarPegawaiDialog : public wxDialog 
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
		
		DinasLuarDaftarPegawaiDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Daftar pegawai"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 450,350 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~DinasLuarDaftarPegawaiDialog();
                //BEGIN BAYU=================
                void RefreshDataView();
                //END BAYU****************
	
};

#endif	/* DINAS_LUAR_DAFTAR_PEGAWAI_DIALOG_H */

