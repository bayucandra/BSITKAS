///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "noname.h"

///////////////////////////////////////////////////////////////////////////

BFrame::BFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 800,400 ), wxDefaultSize );
	this->SetBackgroundColour( wxColour( 244, 244, 244 ) );
	
	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* HeaderbSizer;
	HeaderbSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_bitmapLogo = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("images/logo.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	HeaderbSizer->Add( m_bitmapLogo, 0, wxLEFT|wxTOP, 15 );
	
	wxBoxSizer* HeaderCaptionSizer;
	HeaderCaptionSizer = new wxBoxSizer( wxVERTICAL );
	
	header_SI_staticText = new wxStaticText( this, wxID_ANY, wxT("SISTEM INFORMASI"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	header_SI_staticText->Wrap( -1 );
	header_SI_staticText->SetFont( wxFont( 12, 71, 90, 92, false, wxEmptyString ) );
	
	HeaderCaptionSizer->Add( header_SI_staticText, 0, wxALL, 5 );
	
	header_staticText1 = new wxStaticText( this, wxID_ANY, wxT("TUNJANGAN KINERJA APARATUR SIPIL"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	header_staticText1->Wrap( -1 );
	header_staticText1->SetFont( wxFont( 12, 71, 90, 92, false, wxEmptyString ) );
	
	HeaderCaptionSizer->Add( header_staticText1, 0, wxALL, 5 );
	
	
	HeaderbSizer->Add( HeaderCaptionSizer, 1, wxEXPAND|wxTOP, 15 );
	
	
	HeaderbSizer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* HeaderRbSizer;
	HeaderRbSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* CloseBoxbSizer;
	CloseBoxbSizer = new wxBoxSizer( wxHORIZONTAL );
	
	Minimize_bpButton = new wxBitmapButton( this, ID_Minimize, wxBitmap( wxT("images/btn_minimize.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxSize( 20,20 ), wxBU_AUTODRAW|wxNO_BORDER );
	Minimize_bpButton->SetToolTip( wxT("Minimize") );
	
	CloseBoxbSizer->Add( Minimize_bpButton, 0, wxALL, 3 );
	
	Maximize_bpButton = new wxBitmapButton( this, ID_Maximize, wxBitmap( wxT("images/btn_maximize.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxSize( 20,20 ), wxBU_AUTODRAW|wxNO_BORDER );
	Maximize_bpButton->SetToolTip( wxT("Maximize / Restore") );
	
	CloseBoxbSizer->Add( Maximize_bpButton, 0, wxALL, 3 );
	
	Close_bpButton = new wxBitmapButton( this, wxID_EXIT, wxBitmap( wxT("images/btn_close.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxSize( 20,20 ), wxBU_AUTODRAW|wxNO_BORDER );
	Close_bpButton->SetToolTip( wxT("Close") );
	
	CloseBoxbSizer->Add( Close_bpButton, 0, wxALIGN_RIGHT|wxALL, 3 );
	
	
	HeaderRbSizer->Add( CloseBoxbSizer, 1, wxALIGN_RIGHT, 5 );
	
	Setting_bpButton = new wxBitmapButton( this, ID_Setting, wxBitmap( wxT("images/btn_setting.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxSize( 32,32 ), wxBU_AUTODRAW|wxNO_BORDER );
	Setting_bpButton->SetToolTip( wxT("Settings") );
	
	HeaderRbSizer->Add( Setting_bpButton, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	
	HeaderbSizer->Add( HeaderRbSizer, 1, wxEXPAND, 5 );
	
	
	bSizerMain->Add( HeaderbSizer, 0, wxEXPAND, 1 );
	
	wxBoxSizer* BodybSizer;
	BodybSizer = new wxBoxSizer( wxHORIZONTAL );
	
	menu_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	wxBoxSizer* menu_bSizer;
	menu_bSizer = new wxBoxSizer( wxVERTICAL );
	
	menu_laporan_staticText = new wxStaticText( menu_panel, wxID_ANY, wxT("Laporan"), wxDefaultPosition, wxSize( 170,-1 ), 0 );
	menu_laporan_staticText->Wrap( -1 );
	menu_bSizer->Add( menu_laporan_staticText, 0, wxALL, 5 );
	
	menu_tukin_button = new wxButton( menu_panel, ID_menu_tukin_btn, wxT("Tunjagan Kinerja"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	menu_bSizer->Add( menu_tukin_button, 0, wxEXPAND, 0 );
	
	menu_umak_button = new wxButton( menu_panel, ID_menu_umak_btn, wxT("Uang Makan"), wxDefaultPosition, wxDefaultSize, 0 );
	menu_bSizer->Add( menu_umak_button, 0, wxEXPAND, 0 );
	
	menu_input_data_staticText = new wxStaticText( menu_panel, wxID_ANY, wxT("Input Data"), wxDefaultPosition, wxDefaultSize, 0 );
	menu_input_data_staticText->Wrap( -1 );
	menu_bSizer->Add( menu_input_data_staticText, 0, wxALL, 5 );
	
	menu_pegawai_button = new wxButton( menu_panel, ID_menu_pegawai_btn, wxT("Pegawai"), wxDefaultPosition, wxDefaultSize, 0 );
	menu_bSizer->Add( menu_pegawai_button, 0, wxEXPAND, 0 );
	
	menu_kepank_button = new wxButton( menu_panel, ID_menu_kepank_btn, wxT("Kelas /Pangkat"), wxDefaultPosition, wxDefaultSize, 0 );
	menu_bSizer->Add( menu_kepank_button, 0, wxEXPAND, 0 );
	
	menu_absensi_button = new wxButton( menu_panel, ID_menu_absensi_btn, wxT("Absensi"), wxDefaultPosition, wxDefaultSize, 0 );
	menu_bSizer->Add( menu_absensi_button, 0, wxEXPAND, 0 );
	
	
	menu_panel->SetSizer( menu_bSizer );
	menu_panel->Layout();
	menu_bSizer->Fit( menu_panel );
	BodybSizer->Add( menu_panel, 0, wxEXPAND | wxALL, 5 );
	
	main_notebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	BodybSizer->Add( main_notebook, 1, wxEXPAND | wxALL, 5 );
	
	
	bSizerMain->Add( BodybSizer, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizerMain );
	this->Layout();
	
	this->Centre( wxBOTH );
}

BFrame::~BFrame()
{
}

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
}

BSettingDialog::~BSettingDialog()
{
}

KelasPanel::KelasPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* wrapperSizer;
	wrapperSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* button_bSizer;
	button_bSizer = new wxBoxSizer( wxHORIZONTAL );
	
	tambah_kelas_button = new wxButton( this, ID_tambah_kelas, wxT("Tambah"), wxDefaultPosition, wxDefaultSize, 0 );
	button_bSizer->Add( tambah_kelas_button, 0, wxALL, 5 );
	
	ubah_kelas_button = new wxButton( this, ID_ubah_kelas, wxT("Ubah"), wxDefaultPosition, wxDefaultSize, 0 );
	button_bSizer->Add( ubah_kelas_button, 0, wxALL, 5 );
	
	hapus_kelas_button = new wxButton( this, ID_hapus_kelas, wxT("Hapus"), wxDefaultPosition, wxDefaultSize, 0 );
	button_bSizer->Add( hapus_kelas_button, 0, wxALL, 5 );
	
	
	wrapperSizer->Add( button_bSizer, 0, wxEXPAND, 5 );
	
	kelas_dataViewListCtrl = new wxDataViewListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxDV_HORIZ_RULES|wxDV_ROW_LINES );
	wrapperSizer->Add( kelas_dataViewListCtrl, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( wrapperSizer );
	this->Layout();
}

KelasPanel::~KelasPanel()
{
}

KelasInputDialog::KelasInputDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* input_fgSizer;
	input_fgSizer = new wxFlexGridSizer( 0, 2, 0, 0 );
	input_fgSizer->AddGrowableCol( 1 );
	input_fgSizer->SetFlexibleDirection( wxBOTH );
	input_fgSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	kelas_staticText = new wxStaticText( this, wxID_ANY, wxT("Kelas"), wxDefaultPosition, wxDefaultSize, 0 );
	kelas_staticText->Wrap( -1 );
	input_fgSizer->Add( kelas_staticText, 0, wxALL, 5 );
	
	kelas_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	input_fgSizer->Add( kelas_textCtrl, 0, wxALL, 5 );
	
	keterangan_staticText = new wxStaticText( this, wxID_ANY, wxT("Keterangan"), wxDefaultPosition, wxDefaultSize, 0 );
	keterangan_staticText->Wrap( -1 );
	input_fgSizer->Add( keterangan_staticText, 0, wxALL, 5 );
	
	keterangan_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	input_fgSizer->Add( keterangan_textCtrl, 0, wxALL|wxEXPAND, 5 );
	
	tunjangan_perbulan_staticText = new wxStaticText( this, wxID_ANY, wxT("Tunjangan perbulan"), wxDefaultPosition, wxDefaultSize, 0 );
	tunjangan_perbulan_staticText->Wrap( -1 );
	input_fgSizer->Add( tunjangan_perbulan_staticText, 0, wxALL, 5 );
	
	tunjangan_perbulan_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), wxTE_PROCESS_ENTER|wxTE_RIGHT );
	input_fgSizer->Add( tunjangan_perbulan_textCtrl, 0, wxALL, 5 );
	
	
	input_fgSizer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* button_bSizer;
	button_bSizer = new wxBoxSizer( wxHORIZONTAL );
	
	tambah_button = new wxButton( this, wxID_ANY, wxT("Simpan"), wxDefaultPosition, wxDefaultSize, 0 );
	button_bSizer->Add( tambah_button, 0, wxALL, 5 );
	
	reset_button = new wxButton( this, wxID_ANY, wxT("Reset Input"), wxDefaultPosition, wxDefaultSize, 0 );
	button_bSizer->Add( reset_button, 0, wxALL, 5 );
	
	
	input_fgSizer->Add( button_bSizer, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( input_fgSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	kelas_textCtrl->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( KelasInputDialog::OnSimpan ), NULL, this );
	keterangan_textCtrl->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( KelasInputDialog::OnSimpan ), NULL, this );
	tunjangan_perbulan_textCtrl->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( KelasInputDialog::OnSimpan ), NULL, this );
	tambah_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( KelasInputDialog::OnSimpan ), NULL, this );
	reset_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( KelasInputDialog::OnReset ), NULL, this );
}

KelasInputDialog::~KelasInputDialog()
{
	// Disconnect Events
	kelas_textCtrl->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( KelasInputDialog::OnSimpan ), NULL, this );
	keterangan_textCtrl->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( KelasInputDialog::OnSimpan ), NULL, this );
	tunjangan_perbulan_textCtrl->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( KelasInputDialog::OnSimpan ), NULL, this );
	tambah_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( KelasInputDialog::OnSimpan ), NULL, this );
	reset_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( KelasInputDialog::OnReset ), NULL, this );
	
}

PangkatPanel::PangkatPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* wrapperSizer;
	wrapperSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* button_bSizer;
	button_bSizer = new wxBoxSizer( wxHORIZONTAL );
	
	tambah_button = new wxButton( this, ID_tambah_pangkat, wxT("Tambah"), wxDefaultPosition, wxDefaultSize, 0 );
	button_bSizer->Add( tambah_button, 0, wxALL, 5 );
	
	ubah_button = new wxButton( this, ID_ubah_pangkat, wxT("Ubah"), wxDefaultPosition, wxDefaultSize, 0 );
	button_bSizer->Add( ubah_button, 0, wxALL, 5 );
	
	hapus_button = new wxButton( this, ID_hapus_pangkat, wxT("Hapus"), wxDefaultPosition, wxDefaultSize, 0 );
	button_bSizer->Add( hapus_button, 0, wxALL, 5 );
	
	
	wrapperSizer->Add( button_bSizer, 0, wxEXPAND, 5 );
	
	pangkat_dataViewListCtrl = new wxDataViewListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxDV_HORIZ_RULES|wxDV_ROW_LINES );
	wrapperSizer->Add( pangkat_dataViewListCtrl, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( wrapperSizer );
	this->Layout();
	
	// Connect Events
	tambah_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PangkatPanel::OnTambahPangkat ), NULL, this );
	ubah_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PangkatPanel::OnUbahPangkat ), NULL, this );
	hapus_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PangkatPanel::OnHapusPangkat ), NULL, this );
}

PangkatPanel::~PangkatPanel()
{
	// Disconnect Events
	tambah_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PangkatPanel::OnTambahPangkat ), NULL, this );
	ubah_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PangkatPanel::OnUbahPangkat ), NULL, this );
	hapus_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PangkatPanel::OnHapusPangkat ), NULL, this );
	
}

PangkatInputDialog::PangkatInputDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* input_fgSizer;
	input_fgSizer = new wxFlexGridSizer( 0, 2, 0, 0 );
	input_fgSizer->AddGrowableCol( 1 );
	input_fgSizer->SetFlexibleDirection( wxBOTH );
	input_fgSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	staticText1 = new wxStaticText( this, wxID_ANY, wxT("Pangkat / Golongan"), wxDefaultPosition, wxDefaultSize, 0 );
	staticText1->Wrap( -1 );
	input_fgSizer->Add( staticText1, 0, wxALL, 5 );
	
	pangkat_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	input_fgSizer->Add( pangkat_textCtrl, 0, wxALL, 5 );
	
	staticText2 = new wxStaticText( this, wxID_ANY, wxT("Keterangan"), wxDefaultPosition, wxDefaultSize, 0 );
	staticText2->Wrap( -1 );
	input_fgSizer->Add( staticText2, 0, wxALL, 5 );
	
	keterangan_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	input_fgSizer->Add( keterangan_textCtrl, 0, wxALL|wxEXPAND, 5 );
	
	staticText3 = new wxStaticText( this, wxID_ANY, wxT("Uang makan"), wxDefaultPosition, wxDefaultSize, 0 );
	staticText3->Wrap( -1 );
	input_fgSizer->Add( staticText3, 0, wxALL, 5 );
	
	uang_makan_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), wxTE_PROCESS_ENTER|wxTE_RIGHT );
	input_fgSizer->Add( uang_makan_textCtrl, 0, wxALL, 5 );
	
	
	input_fgSizer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* button_bSizer;
	button_bSizer = new wxBoxSizer( wxHORIZONTAL );
	
	simpan_button = new wxButton( this, wxID_ANY, wxT("Simpan"), wxDefaultPosition, wxDefaultSize, 0 );
	button_bSizer->Add( simpan_button, 0, wxALL, 5 );
	
	reset_button = new wxButton( this, wxID_ANY, wxT("Reset Input"), wxDefaultPosition, wxDefaultSize, 0 );
	button_bSizer->Add( reset_button, 0, wxALL, 5 );
	
	
	input_fgSizer->Add( button_bSizer, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( input_fgSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	pangkat_textCtrl->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( PangkatInputDialog::OnSimpan ), NULL, this );
	keterangan_textCtrl->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( PangkatInputDialog::OnSimpan ), NULL, this );
	uang_makan_textCtrl->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( PangkatInputDialog::OnSimpan ), NULL, this );
	simpan_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PangkatInputDialog::OnSimpan ), NULL, this );
	reset_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PangkatInputDialog::OnReset ), NULL, this );
}

PangkatInputDialog::~PangkatInputDialog()
{
	// Disconnect Events
	pangkat_textCtrl->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( PangkatInputDialog::OnSimpan ), NULL, this );
	keterangan_textCtrl->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( PangkatInputDialog::OnSimpan ), NULL, this );
	uang_makan_textCtrl->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( PangkatInputDialog::OnSimpan ), NULL, this );
	simpan_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PangkatInputDialog::OnSimpan ), NULL, this );
	reset_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PangkatInputDialog::OnReset ), NULL, this );
	
}
