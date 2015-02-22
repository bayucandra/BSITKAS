/* 
 * File:   pangkat_input_dialog.h
 * Author: bayucandra@gmail.com
 *
 * Created on January 20, 2015, 11:53 AM
 */

#ifndef PANGKAT_INPUT_DIALOG_H
#define	PANGKAT_INPUT_DIALOG_H

#include "wx/dialog.h"
class PangkatInputDialog : public wxDialog 
{
	private:
            wxString input_mode;
            int ref_id;
	
	protected:
		wxStaticText* staticText1;
		wxTextCtrl* pangkat_textCtrl;
		wxStaticText* staticText2;
		wxTextCtrl* keterangan_textCtrl;
		wxStaticText* staticText3;
		wxTextCtrl* uang_makan_textCtrl;
		wxButton* simpan_button;
		wxButton* reset_button;
		
		// Virtual event handlers, overide them in your derived class
		void OnSimpan( wxCommandEvent& event );
		void OnReset( wxCommandEvent& event );
		
	
	public:
		
		PangkatInputDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,200 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~PangkatInputDialog();
                
            //BEGIN BAYU==============
                void InputMode(wxString p_input_mode, int p_ref_id=-1);//create, update
                void ResetInput();
                void SetUpdateValue(wxString p_pangkat_golongan, wxString p_keterangan, wxString p_uang_makan);
	
};

#endif	/* PANGKAT_INPUT_DIALOG_H */

