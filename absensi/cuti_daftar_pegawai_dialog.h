/* 
 * File:   cuti_daftar_pegawai_dialog.h
 * Author: bayucandra@gmail.com
 *
 * Created on February 24, 2015, 10:54 PM
 */

#ifndef CUTI_DAFTAR_PEGAWAI_DIALOG_H
#define	CUTI_DAFTAR_PEGAWAI_DIALOG_H

class CutiDaftarPegawaiDialog : public wxDialog 
{
	private:
            //BEGIN BAYU==================
            void InitDataView();
            void Pilih();
            //END BAYU******************
	protected:
		wxTextCtrl* cari_textCtrl;
		wxButton* cari_button;
		wxDataViewListCtrl* pegawai_dataViewListCtrl;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCari( wxCommandEvent& event );
		virtual void OnPilih( wxDataViewEvent& event );
		
	
	public:
		
		CutiDaftarPegawaiDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Daftar pegawai"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 450,350 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~CutiDaftarPegawaiDialog();
                //BEGIN BAYU=================
                void RefreshDataView();
                //END BAYU****************
	
};

#endif	/* CUTI_DAFTAR_PEGAWAI_DIALOG_H */

