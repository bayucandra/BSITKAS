/* 
 * File:   kelas_input_dialog.h
 * Author: bayucandra@gmail.com
 *
 * Created on January 13, 2015, 10:31 PM
 */

#ifndef KELAS_INPUT_DIALOG_H
#define	KELAS_INPUT_DIALOG_H

#include "wx/dialog.h"

class KelasInputDialog : public wxDialog 
{
	private:
            char* input_mode;
            int update_id;
	protected:
		wxStaticText* kelas_staticText;
		wxTextCtrl* kelas_textCtrl;
		wxStaticText* keterangan_staticText;
		wxTextCtrl* keterangan_textCtrl;
		wxStaticText* tunjangan_perbulan_staticText;
		wxTextCtrl* tunjangan_perbulan_textCtrl;
		wxButton* tambah_button;
		wxButton* reset_button;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSimpan( wxCommandEvent& event );
		
	
	public:
		
		KelasInputDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,200 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~KelasInputDialog();
                
        
            void InputMode(char* p_input_mode);//create, update, destroy
            char* GetInputMode();//return wxString
            void SetUpdateId(int p_update_id);
            int GetUpdateId();
};
#endif	/* KELAS_INPUT_DIALOG_H */

