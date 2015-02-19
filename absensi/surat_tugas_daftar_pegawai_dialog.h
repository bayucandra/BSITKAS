/* 
 * File:   surat_tugas_daftar_pegawai_dialog.h
 * Author: bayucandra@gmail.com
 *
 * Created on January 25, 2015, 10:25 PM
 */

#ifndef SURAT_TUGAS_DAFTAR_PEGAWAI_DIALOG_H
#define	SURAT_TUGAS_DAFTAR_PEGAWAI_DIALOG_H


class SuratTugasDaftarPegawaiDialog : public wxDialog 
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
		
		SuratTugasDaftarPegawaiDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Daftar pegawai"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 450,350 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~SuratTugasDaftarPegawaiDialog();
                //BEGIN BAYU=================
                void RefreshDataView();
                //END BAYU****************
	
};

#endif	/* SURAT_TUGAS_DAFTAR_PEGAWAI_DIALOG_H */

