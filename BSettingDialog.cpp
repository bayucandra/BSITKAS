///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "BSettingDialog.h"

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
	
	
	SettingWrapperbSizer->Add( SettingfgSizer, 1, wxALL|wxEXPAND, 10 );
	
	Simpan_button = new wxButton( this, ID_DLG_SETTING_SAVE, wxT("Simpan"), wxDefaultPosition, wxDefaultSize, 0 );
	SettingWrapperbSizer->Add( Simpan_button, 0, wxALIGN_RIGHT|wxBOTTOM|wxRIGHT, 10 );
	
	
	this->SetSizer( SettingWrapperbSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
}

BSettingDialog::~BSettingDialog()
{
}
