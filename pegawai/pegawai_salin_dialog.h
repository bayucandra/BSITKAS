/* 
 * File:   pegawai_salin.h
 * Author: bayucandra@gmail.com
 *
 * Created on January 21, 2015, 9:25 PM
 */

#ifndef PEGAWAI_SALIN_H
#define	PEGAWAI_SALIN_H

#include "wx/dialog.h"
#include "wx/combobox.h"

class PegawaiSalinDialog : public wxDialog 
{
	private:
            //BEGIN BAYU===============
            wxString input_mode;
            wxString ref_id;
            void CbInitKelas();
            void CbInitPangkat();
            //END BAYU*********
	protected:
		wxStaticText* m_staticText15;
		wxTextCtrl* FID_textCtrl;
		wxStaticText* m_staticText16;
		wxTextCtrl* Nama_textCtrl;
		wxStaticText* m_staticText17;
		wxTextCtrl* NIK_textCtrl;
		wxStaticText* m_staticText18;
		wxComboBox* kelas_comboBox;
		wxStaticText* m_staticText19;
		wxComboBox* pangkat_comboBox;
		wxButton* simpan_button;
		
		// Virtual event handlers, overide them in your derived class
		void OnSimpan( wxCommandEvent& event );
		
	
	public:
		
		PegawaiSalinDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Salin Pegawai (data lama)"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,250 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~PegawaiSalinDialog();
	
            //BEGIN BAYU===========
            void SalinDataLama(wxString p_FID, wxString p_Nama, wxString p_NIK);
            void InputMode(wxString p_input_mode, wxString p_ref_id=wxEmptyString);
            void SetUpdateValue();
            //END BAYU***************
};

#endif	/* PEGAWAI_SALIN_H */

