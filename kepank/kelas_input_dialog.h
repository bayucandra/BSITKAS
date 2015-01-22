/* 
 * File:   kelas_input_dialog.h
 * Author: bayucandra@gmail.com
 *
 * Created on January 13, 2015, 10:31 PM
 */

#ifndef KELAS_INPUT_DIALOG_H
#define	KELAS_INPUT_DIALOG_H

class KelasInputDialog : public wxDialog 
{
	private:
            //BEGIN BAYU==============
            char* input_mode;
            int ref_id;
            bool IsInputValid();
            //END BAYU***************
            
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
                virtual void OnReset( wxCommandEvent& event );
                //BEGIN BAYU============
                void ResetInput();
		
	
	public:
		
		KelasInputDialog( wxPanel* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,200 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~KelasInputDialog();
                
            //BEGIN BAYU============
            void InputMode(char* p_input_mode, int p_ref_id=-1);//create, update
            char* GetInputMode();//return wxString
            int GetRefId();
            void SetUpdateValue(wxString kelas, wxString keterangan, wxString tunjangan_perbulan);
};
#endif	/* KELAS_INPUT_DIALOG_H */

