///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "BSettingDialog.h"
#include "functions/general.h"

///////////////////////////////////////////////////////////////////////////

BSettingDialog::BSettingDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* SettingWrapperbSizer;
	SettingWrapperbSizer = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* SettingfgSizer;
	SettingfgSizer = new wxFlexGridSizer( 0, 2, 0, 0 );
	SettingfgSizer->AddGrowableCol( 1 );
	SettingfgSizer->SetFlexibleDirection( wxBOTH );
	SettingfgSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	MySQLServer_staticText = new wxStaticText( this, wxID_ANY, wxT("Server"), wxDefaultPosition, wxDefaultSize, 0 );
	MySQLServer_staticText->Wrap( -1 );
	SettingfgSizer->Add( MySQLServer_staticText, 1, wxALL, 5 );
	
	MySQLServer_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 300,-1 ), 0 );
	SettingfgSizer->Add( MySQLServer_textCtrl, 1, wxALL, 5 );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("Username"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	SettingfgSizer->Add( m_staticText9, 0, wxALL, 5 );
	
	MySQLUsername_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	SettingfgSizer->Add( MySQLUsername_textCtrl, 0, wxALL, 5 );
	
	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("Password"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	SettingfgSizer->Add( m_staticText10, 0, wxALL, 5 );
	
	MySQLPassword_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), wxTE_PASSWORD );
	SettingfgSizer->Add( MySQLPassword_textCtrl, 0, wxALL, 5 );
	
	m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("DB Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	SettingfgSizer->Add( m_staticText11, 0, wxALL, 5 );
	
	MySQLDBName_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 250,-1 ), 0 );
	SettingfgSizer->Add( MySQLDBName_textCtrl, 0, wxALL, 5 );
	
	
	SettingWrapperbSizer->Add( SettingfgSizer, 1, wxALL|wxEXPAND, 10 );
	
	Simpan_button = new wxButton( this, ID_DLG_SETTING_save, wxT("Simpan"), wxDefaultPosition, wxDefaultSize, 0 );
	SettingWrapperbSizer->Add( Simpan_button, 0, wxALIGN_RIGHT|wxBOTTOM|wxRIGHT, 10 );
	
	
	this->SetSizer( SettingWrapperbSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
        
        this->BInitConfigs();
}
void BSettingDialog::BInitConfigs(){
        //BEGIN GETTING XML CONFIG SAVED==============
        MySQLServer_textCtrl->SetValue(BgetXMLConfig(bmain_settings[0]));
        MySQLUsername_textCtrl->SetValue(BgetXMLConfig(bmain_settings[1]));
        MySQLPassword_textCtrl->SetValue(BgetXMLConfig(bmain_settings[2]));
        MySQLDBName_textCtrl->SetValue(BgetXMLConfig(bmain_settings[3]));
        //END GETTING XML CONFIG SAVED==============
}
void BSettingDialog::OnSave(wxCommandEvent& event){
    bool setting_save=BSetXMLConfig(bmain_settings[0],MySQLServer_textCtrl->GetValue())&&
        BSetXMLConfig(bmain_settings[1],MySQLUsername_textCtrl->GetValue())&&
        BSetXMLConfig(bmain_settings[2],MySQLPassword_textCtrl->GetValue())&&
        BSetXMLConfig(bmain_settings[3],MySQLDBName_textCtrl->GetValue());
    if(setting_save){
        wxLogMessage(wxT("Setting telah disimpan"));
        this->Close();
    }else{
        wxLogError(wxT("Setting gagal disimpan"));
    }
}

BSettingDialog::~BSettingDialog()
{
}
wxBEGIN_EVENT_TABLE(BSettingDialog,wxDialog)
    EVT_BUTTON(ID_DLG_SETTING_save, BSettingDialog::OnSave)
//    EVT_MENU(wxID_ABOUT, BFrame::OnAbout)
wxEND_EVENT_TABLE()
