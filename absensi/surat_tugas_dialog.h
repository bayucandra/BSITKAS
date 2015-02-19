/* 
 * File:   surat_tugas_dialog.h
 * Author: bayucandra@gmail.com
 *
 * Created on January 25, 2015, 10:21 PM
 */

#ifndef SURAT_TUGAS_DIALOG_H
#define	SURAT_TUGAS_DIALOG_H
#include "surat_tugas_daftar_pegawai_dialog.h"

class SuratTugasDialog : public wxDialog 
{
	private:
            //BEGIN BAYU=============
            char* input_mode;
            int ref_id;
            wxString ref_tgl;
            
            SuratTugasDaftarPegawaiDialog *surat_tugas_daftar_pegawai_dialog;
            void ResetInput();
            //END BAYU******************
	
	protected:
		wxStaticText* m_staticText26;
		wxTextCtrl* FID_textCtrl;
		wxTextCtrl* nama_textCtrl;
		wxStaticText* m_staticText27;
		wxDatePickerCtrl* tgl_datePicker;
		wxStaticText* m_staticText28;
		wxTextCtrl* keterangan_textCtrl;
		wxButton* simpan_button;
		
		// Virtual event handlers, overide them in your derived class
		void OnDaftarPegawaiDialog( wxMouseEvent& event );
		void OnSimpan( wxCommandEvent& event );
		
	
	public:
		
		SuratTugasDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 450,180 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~SuratTugasDialog();
                //BEGIN BAYU============
                void InputMode(char* p_input_mode, int p_ref_id=-1, wxString p_ref_tgl=wxEmptyString);
                void PilihPegawai(wxString p_FID, wxString p_nama);
                void SetUpdateValue(wxString p_FID, wxString p_nama, wxString p_tgl, wxString p_keterangan);
                //END BAYU*******
	
};


#endif	/* SURAT_TUGAS_DIALOG_H */

