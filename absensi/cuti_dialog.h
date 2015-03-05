/* 
 * File:   cuti_dialog.h
 * Author: bayucandra@gmail.com
 *
 * Created on February 24, 2015, 10:30 PM
 */

#ifndef CUTI_DIALOG_H
#define	CUTI_DIALOG_H

#include "cuti_daftar_pegawai_dialog.h"
#include "cuti_jenis_dialog.h"

class CutiDialog : public wxDialog 
{
	private:
            //BEGIN BAYU==============
            wxString input_mode;
            wxString ref_id_str;
            wxString ref_tgl_awal_str;
            wxString ref_tgl_akhir_str;
//            wxString ref_tahun_str;
//            wxString ref_bulan_str;
            
            CutiDaftarPegawaiDialog *cuti_daftar_pegawai_dialog;
            CutiJenisDialog *cuti_jenis_dialog;
            void ResetInput();
            //END BAYU***************
	protected:
		wxStaticText* m_staticText26;
		wxTextCtrl* FID_textCtrl;
		wxTextCtrl* nama_textCtrl;
		wxStaticText* m_staticText27;
		wxDatePickerCtrl* tgl_awal_datePicker;
		wxStaticText* m_staticText67;
		wxDatePickerCtrl* tgl_akhir_datePicker;
		wxStaticText* m_staticText69;
		wxTextCtrl* idbcuti_jenis_textCtrl;
		wxTextCtrl* jenis_cuti_textCtrl;
		wxStaticText* m_staticText28;
		wxTextCtrl* keterangan_textCtrl;
		wxButton* simpan_button;
                
		// Virtual event handlers, overide them in your derived class
		virtual void OnDaftarPegawaiDialog( wxMouseEvent& event );
		virtual void OnDaftarJenisCutiDialog( wxMouseEvent& event );
		virtual void OnSimpan( wxCommandEvent& event );
		
	
	public:
		
		CutiDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 450,260 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~CutiDialog();
                //BEGIN BAYU=================
                void InputMode(const wxString &p_input_mode, const wxString &p_ref_id=wxEmptyString, const wxString &p_ref_tgl_awal_str=wxEmptyString
                    , const wxString &p_ref_tgl_akhir_str=wxEmptyString);
                void PilihPegawai(wxString p_FID, wxString p_nama);
                void PilihJenisCuti(wxString p_idbcuti_jenis, wxString p_jenis_cuti);
                void SetUpdateValue();
                //END BAYU***************
	
};

#endif	/* CUTI_DIALOG_H */

