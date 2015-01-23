#include "izin_dialog.h"
#include "izin_daftar_pegawai_dialog.cpp"

IzinDialog::IzinDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* wrapper_bSizer;
	wrapper_bSizer = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer6->AddGrowableCol( 1 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText26 = new wxStaticText( this, wxID_ANY, wxT("Pegawai"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	fgSizer6->Add( m_staticText26, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxHORIZONTAL );
	
	FID_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxTE_READONLY );
	FID_textCtrl->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	
	bSizer30->Add( FID_textCtrl, 0, wxALL, 5 );
	
	nama_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	nama_textCtrl->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	
	bSizer30->Add( nama_textCtrl, 1, wxALL|wxEXPAND, 5 );
	
	
	fgSizer6->Add( bSizer30, 1, wxEXPAND, 5 );
	
	m_staticText27 = new wxStaticText( this, wxID_ANY, wxT("Tanggal"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText27->Wrap( -1 );
	fgSizer6->Add( m_staticText27, 0, wxALL, 5 );
	
	tgl_datePicker = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxSize( 100,-1 ), wxDP_DROPDOWN );
	fgSizer6->Add( tgl_datePicker, 0, wxALL, 5 );
	
	m_staticText28 = new wxStaticText( this, wxID_ANY, wxT("Keterangan"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText28->Wrap( -1 );
	fgSizer6->Add( m_staticText28, 0, wxALL, 5 );
	
	m_textCtrl20 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer6->Add( m_textCtrl20, 0, wxALL|wxEXPAND, 5 );
	
	
	wrapper_bSizer->Add( fgSizer6, 1, wxEXPAND, 5 );
	
	simpan_button = new wxButton( this, wxID_ANY, wxT("Simpan"), wxDefaultPosition, wxDefaultSize, 0 );
	wrapper_bSizer->Add( simpan_button, 0, wxALIGN_RIGHT|wxBOTTOM|wxRIGHT, 5 );
	
	
	this->SetSizer( wrapper_bSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	FID_textCtrl->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( IzinDialog::OnDaftarPegawaiDialog ), NULL, this );
	nama_textCtrl->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( IzinDialog::OnDaftarPegawaiDialog ), NULL, this );
	simpan_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IzinDialog::OnSimpan ), NULL, this );
}

IzinDialog::~IzinDialog()
{
	// Disconnect Events
	FID_textCtrl->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( IzinDialog::OnDaftarPegawaiDialog ), NULL, this );
	nama_textCtrl->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( IzinDialog::OnDaftarPegawaiDialog ), NULL, this );
	simpan_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IzinDialog::OnSimpan ), NULL, this );
	
}

void IzinDialog::InputMode(char* p_input_mode, int p_ref_id){
    input_mode=p_input_mode;
    if(p_input_mode=="update"){
        if(p_ref_id!=-1){
            ref_id=p_ref_id;
        }else{
            wxLogError("Kesalahan pemrograman untuk parameter p_ref_id. Harap kontak administrator programmer.");
        }
    }
}
void IzinDialog::OnDaftarPegawaiDialog( wxMouseEvent& event ){
    izin_daftar_pegawai_dialog=new IzinDaftarPegawaiDialog(this);
    izin_daftar_pegawai_dialog->Center();
    izin_daftar_pegawai_dialog->ShowModal();
}
