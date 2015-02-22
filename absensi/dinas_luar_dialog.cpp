#include "dinas_luar_dialog.h"
#include "dinas_luar_daftar_pegawai_dialog.cpp"
#include "dinas_luar_panel.h"
DinasLuarDialog::DinasLuarDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
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
	
	keterangan_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	fgSizer6->Add( keterangan_textCtrl, 0, wxALL|wxEXPAND, 5 );
	
	
	wrapper_bSizer->Add( fgSizer6, 1, wxEXPAND, 5 );
	
	simpan_button = new wxButton( this, wxID_ANY, wxT("Simpan"), wxDefaultPosition, wxDefaultSize, 0 );
	wrapper_bSizer->Add( simpan_button, 0, wxALIGN_RIGHT|wxBOTTOM|wxRIGHT, 5 );
	
	
	this->SetSizer( wrapper_bSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	FID_textCtrl->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( DinasLuarDialog::OnDaftarPegawaiDialog ), NULL, this );
	nama_textCtrl->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( DinasLuarDialog::OnDaftarPegawaiDialog ), NULL, this );
        keterangan_textCtrl->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( DinasLuarDialog::OnSimpan ), NULL, this );
	simpan_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DinasLuarDialog::OnSimpan ), NULL, this );
}

DinasLuarDialog::~DinasLuarDialog()
{
	// Disconnect Events
	FID_textCtrl->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( DinasLuarDialog::OnDaftarPegawaiDialog ), NULL, this );
	nama_textCtrl->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( DinasLuarDialog::OnDaftarPegawaiDialog ), NULL, this );
        keterangan_textCtrl->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( DinasLuarDialog::OnSimpan ), NULL, this );
	simpan_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DinasLuarDialog::OnSimpan ), NULL, this );
	
}

void DinasLuarDialog::InputMode(wxString p_input_mode, int p_ref_id, wxString p_ref_tgl){
    input_mode=p_input_mode;
    if(p_input_mode==wxString("update")){
        if((p_ref_id!=-1)&&(p_ref_tgl!=wxEmptyString)){
            ref_id=p_ref_id;
            ref_tgl=p_ref_tgl;
        }else{
            wxLogError("Kesalahan pemrograman untuk parameter p_ref_id atau p_ref_tgl. Harap kontak administrator programmer.");
        }
    }
}
void DinasLuarDialog::OnDaftarPegawaiDialog( wxMouseEvent& event ){
    dinas_luar_daftar_pegawai_dialog=new DinasLuarDaftarPegawaiDialog(this);
    dinas_luar_daftar_pegawai_dialog->Center();
    dinas_luar_daftar_pegawai_dialog->ShowModal();
}
void DinasLuarDialog::PilihPegawai(wxString p_FID, wxString p_nama){
    FID_textCtrl->SetValue(p_FID);
    nama_textCtrl->SetValue(p_nama);
}
void DinasLuarDialog::OnSimpan( wxCommandEvent& event ){
    if(FID_textCtrl->GetValue()!=wxEmptyString){
        if(conn.connected()){
            try{
                mysqlpp::Query qry=conn.query();
                if(input_mode==wxString("create")){
                    qry<<"INSERT INTO bdinas_luar(FID, tgl, keterangan) VALUES("
                            <<mysqlpp::quote<<(const_cast<char*>((const char*)FID_textCtrl->GetValue().mb_str()))<<","
                            <<mysqlpp::quote<<(const_cast<char*>((const char*)tgl_datePicker->GetValue().FormatISODate().mb_str()))<<","
                            <<mysqlpp::quote<<(const_cast<char*>((const char*)keterangan_textCtrl->GetValue().mb_str()))
                        <<")";
                }else if(input_mode==wxString("update")){
                    qry<<"UPDATE bdinas_luar SET "
                        <<"FID="<<mysqlpp::quote<<(const_cast<char*>((const char*)FID_textCtrl->GetValue().mb_str()))<<","
                        <<"tgl="<<mysqlpp::quote<<(const_cast<char*>((const char*)tgl_datePicker->GetValue().FormatISODate().mb_str()))<<","
                        <<"keterangan="<<mysqlpp::quote<<(const_cast<char*>((const char*)keterangan_textCtrl->GetValue().mb_str()))
                        <<" WHERE FID="<<ref_id
                            <<" AND tgl="<<mysqlpp::quote<<(const_cast<char*>((const char*)ref_tgl.mb_str()))
                        <<" LIMIT 1";
                }
                bool res=qry.execute();
                if(res){
                    ((DinasLuarPanel*)GetParent())->RefreshDataView();
                    if(input_mode==wxString("create")){
                        ResetInput();
                    }else if(input_mode==wxString("update")){
                        Close();
                    }
                }else{
                    wxString error_msg=wxString("Error saat input data dinas luar: ");
                    error_msg.Append(qry.error());
                    wxLogError(error_msg);
                }
            }catch(mysqlpp::Exception &e){
                wxLogError(e.what());
            }
        }else{
            wxLogError("Error, database tidak terkoneksi.");
        }
    }else{
        wxLogError("Harap mengisi input pegawai!");
    }
}
void DinasLuarDialog::ResetInput(){
    FID_textCtrl->SetValue(wxEmptyString);
    nama_textCtrl->SetValue(wxEmptyString);
    tgl_datePicker->SetValue(wxDateTime::Today());
    keterangan_textCtrl->SetValue(wxEmptyString);
}
void DinasLuarDialog::SetUpdateValue(wxString p_FID, wxString p_nama, wxString p_tgl, wxString p_keterangan){
    FID_textCtrl->SetValue(p_FID);
    nama_textCtrl->SetValue(p_nama);
    
    wxDateTime tgl_value=wxDateTime();
    tgl_value.ParseISODate(p_tgl);
    tgl_datePicker->SetValue(tgl_value);
    
    keterangan_textCtrl->SetValue(p_keterangan);
}
