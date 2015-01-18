/* 
 * File:   BSettingDialog.h
 * Author: IT
 *
 * Created on January 10, 2015, 6:22 AM
 */

#ifndef BSETTINGDIALOG_H
#define	BSETTINGDIALOG_H
///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

//#define ID_DLG_SETTING_SAVE 1000

///////////////////////////////////////////////////////////////////////////////
/// Class BSettingDialog
///////////////////////////////////////////////////////////////////////////////
class BSettingDialog : public wxDialog 
{
	private:
            void OnSave(wxCommandEvent& event);
            void BInitConfigs();
	protected:
		wxStaticText* MySQLServer_staticText;
		wxTextCtrl* MySQLServer_textCtrl;
		wxStaticText* m_staticText9;
		wxTextCtrl* MySQLUsername_textCtrl;
		wxStaticText* m_staticText10;
		wxTextCtrl* MySQLPassword_textCtrl;
		wxStaticText* m_staticText11;
		wxTextCtrl* MySQLDBName_textCtrl;
		wxButton* Simpan_button;
	
	public:
		
		BSettingDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Setting"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,400 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~BSettingDialog();

        wxDECLARE_EVENT_TABLE();
};


#endif	/* BSETTINGDIALOG_H */

