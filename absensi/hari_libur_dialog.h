/* 
 * File:   hari_libur_dialog.h
 * Author: bayucandra@gmail.com
 *
 * Created on February 19, 2015, 9:40 PM
 */

#ifndef HARI_LIBUR_DIALOG_H
#define	HARI_LIBUR_DIALOG_H

class HariLiburDialog : public wxDialog 
{
	private:
            //BEGIN BAYU================
            wxString input_mode;
            wxString ref_tgl;
            
            void ResetInput();
            //END BAYU******************
	protected:
		wxStaticText* m_staticText27;
		wxDatePickerCtrl* tgl_datePicker;
		wxStaticText* m_staticText28;
		wxTextCtrl* keterangan_textCtrl;
		wxButton* simpan_button;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSimpan( wxCommandEvent& event );
		
	
	public:
		
		HariLiburDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 450,180 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~HariLiburDialog();
                //BEGIN BAYU==============
                void InputMode(wxString p_input_mode, wxString p_ref_tgl=wxEmptyString);
                void SetUpdateValue(wxString p_tgl, wxString p_keterangan);
                //END BAYU***************
	
};

#endif	/* HARI_LIBUR_DIALOG_H */

