/* 
 * File:   absensi_dialog.h
 * Author: bayucandra@gmail.com
 *
 * Created on January 23, 2015, 7:15 PM
 */

#ifndef ABSENSI_DIALOG_H
#define	ABSENSI_DIALOG_H
#include "izin_daftar_pegawai_dialog.h"

class IzinDialog : public wxDialog 
{
	private:
            //BEGIN BAYU=============
            wxString input_mode;
            int ref_id;
            wxString ref_tgl;
            
            IzinDaftarPegawaiDialog *izin_daftar_pegawai_dialog;
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
		
		IzinDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 450,180 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~IzinDialog();
                //BEGIN BAYU============
                void InputMode(wxString p_input_mode, int p_ref_id=-1, wxString p_ref_tgl=wxEmptyString);
                void PilihPegawai(wxString p_FID, wxString p_nama);
                void SetUpdateValue(wxString p_FID, wxString p_nama, wxString p_tgl, wxString p_keterangan);
                //END BAYU*******
	
};

#endif	/* ABSENSI_DIALOG_H */

