#include "izin_daftar_pegawai_dialog.h"


IzinDaftarPegawaiDialog::IzinDaftarPegawaiDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* cari_bSizer;
	cari_bSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_textCtrl21 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	cari_bSizer->Add( m_textCtrl21, 1, wxALL|wxEXPAND, 5 );
	
	cari_button = new wxButton( this, wxID_ANY, wxT("Cari"), wxDefaultPosition, wxDefaultSize, 0 );
	cari_bSizer->Add( cari_button, 0, wxALL, 5 );
	
	
	bSizer31->Add( cari_bSizer, 0, wxEXPAND, 5 );
	
	m_dataViewListCtrl7 = new wxDataViewListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( m_dataViewListCtrl7, 1, wxALL|wxEXPAND, 5 );
	
	pilih_button = new wxButton( this, wxID_ANY, wxT("Pilih"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( pilih_button, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	
	this->SetSizer( bSizer31 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	cari_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IzinDaftarPegawaiDialog::OnCari ), NULL, this );
	pilih_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IzinDaftarPegawaiDialog::OnPilih ), NULL, this );
}

IzinDaftarPegawaiDialog::~IzinDaftarPegawaiDialog()
{
	// Disconnect Events
	cari_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IzinDaftarPegawaiDialog::OnCari ), NULL, this );
	pilih_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IzinDaftarPegawaiDialog::OnPilih ), NULL, this );
	
}
