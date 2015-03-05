#include "cuti_dialog.h"
#include "cuti_panel.h"
#include "cuti_daftar_pegawai_dialog.cpp"
#include "cuti_jenis_dialog.cpp"

CutiDialog::CutiDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
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
	
	m_staticText27 = new wxStaticText( this, wxID_ANY, wxT("Tgl. Awal"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText27->Wrap( -1 );
	fgSizer6->Add( m_staticText27, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer72;
	bSizer72 = new wxBoxSizer( wxHORIZONTAL );
	
	tgl_awal_datePicker = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxSize( 100,-1 ), wxDP_DROPDOWN );
	bSizer72->Add( tgl_awal_datePicker, 0, wxALL, 5 );
	
	m_staticText67 = new wxStaticText( this, wxID_ANY, wxT("Tgl. Akhir"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText67->Wrap( -1 );
	bSizer72->Add( m_staticText67, 0, wxALL, 5 );
	
	tgl_akhir_datePicker = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxSize( 100,-1 ), wxDP_DROPDOWN );
	bSizer72->Add( tgl_akhir_datePicker, 0, wxALL, 5 );
	
	
	fgSizer6->Add( bSizer72, 1, wxEXPAND, 5 );
	
	m_staticText69 = new wxStaticText( this, wxID_ANY, wxT("Jenis cuti"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText69->Wrap( -1 );
	fgSizer6->Add( m_staticText69, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer77;
	bSizer77 = new wxBoxSizer( wxHORIZONTAL );
	
	idbcuti_jenis_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_READONLY );
	idbcuti_jenis_textCtrl->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	
	bSizer77->Add( idbcuti_jenis_textCtrl, 0, wxALL, 5 );
	
	jenis_cuti_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,50 ), wxTE_READONLY|wxTE_WORDWRAP );
	jenis_cuti_textCtrl->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	
	bSizer77->Add( jenis_cuti_textCtrl, 1, wxALL|wxEXPAND, 5 );
	
	
	fgSizer6->Add( bSizer77, 1, wxEXPAND, 5 );
	
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
	FID_textCtrl->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( CutiDialog::OnDaftarPegawaiDialog ), NULL, this );
	nama_textCtrl->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( CutiDialog::OnDaftarPegawaiDialog ), NULL, this );
	idbcuti_jenis_textCtrl->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( CutiDialog::OnDaftarJenisCutiDialog ), NULL, this );
	jenis_cuti_textCtrl->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( CutiDialog::OnDaftarJenisCutiDialog ), NULL, this );
	keterangan_textCtrl->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( CutiDialog::OnSimpan ), NULL, this );
	simpan_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CutiDialog::OnSimpan ), NULL, this );

        //BEGIN BAYU===========================
        tgl_awal_datePicker->SetValue(wxDateTime::Today());
        tgl_akhir_datePicker->SetValue(wxDateTime::Today());
}

CutiDialog::~CutiDialog()
{
	// Disconnect Events
	FID_textCtrl->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( CutiDialog::OnDaftarPegawaiDialog ), NULL, this );
	nama_textCtrl->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( CutiDialog::OnDaftarPegawaiDialog ), NULL, this );
	idbcuti_jenis_textCtrl->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( CutiDialog::OnDaftarJenisCutiDialog ), NULL, this );
	jenis_cuti_textCtrl->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( CutiDialog::OnDaftarJenisCutiDialog ), NULL, this );
	keterangan_textCtrl->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( CutiDialog::OnSimpan ), NULL, this );
	simpan_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CutiDialog::OnSimpan ), NULL, this );
}
void CutiDialog::OnDaftarPegawaiDialog( wxMouseEvent& event ){
    cuti_daftar_pegawai_dialog=new CutiDaftarPegawaiDialog(this);
    cuti_daftar_pegawai_dialog->Center();
    cuti_daftar_pegawai_dialog->ShowModal();
}
void CutiDialog::OnDaftarJenisCutiDialog( wxMouseEvent& event ){
    cuti_jenis_dialog = new CutiJenisDialog(this);
    cuti_jenis_dialog->Center();
    cuti_jenis_dialog->ShowModal();
}
void CutiDialog::OnSimpan( wxCommandEvent& event ){
    if(
        (FID_textCtrl->GetValue() != wxEmptyString)
        &&(idbcuti_jenis_textCtrl->GetValue() != wxEmptyString)
    ){
        if(conn.connected()){
            try{
                mysqlpp::Query qry=conn.query();
                if(input_mode == wxString("create")){
                    qry<<"INSERT INTO bcuti_pegawai (FID, idbcuti_jenis, tgl_awal, tgl_akhir, keterangan) VALUES("
                            <<(const_cast<char*>((const char*)FID_textCtrl->GetValue().mb_str()))<<","
                            <<(const_cast<char*>((const char*)idbcuti_jenis_textCtrl->GetValue().mb_str()))<<","
                            <<mysqlpp::quote<<(const_cast<char*>((const char*)tgl_awal_datePicker->GetValue().FormatISODate().mb_str()))<<","
                            <<mysqlpp::quote<<(const_cast<char*>((const char*)tgl_akhir_datePicker->GetValue().FormatISODate().mb_str()))<<","
                            <<mysqlpp::quote<<(const_cast<char*>((const char*)keterangan_textCtrl->GetValue().mb_str()))
                        <<")";
                }else if(input_mode == wxString("update")){
                    qry<<"UPDATE bcuti_pegawai SET"
                            <<" FID="<<(const_cast<char*>((const char*)FID_textCtrl->GetValue().mb_str()))<<","
                            <<" idbcuti_jenis="<<(const_cast<char*>((const char*)idbcuti_jenis_textCtrl->GetValue().mb_str()))<<","
                            <<" tgl_awal="
                                <<mysqlpp::quote<<(const_cast<char*>((const char*)tgl_awal_datePicker->GetValue().FormatISODate().mb_str()))<<","
                            <<" tgl_akhir="<<mysqlpp::quote
                                <<(const_cast<char*>((const char*)tgl_akhir_datePicker->GetValue().FormatISODate().mb_str()))<<","
                            <<" keterangan="<<mysqlpp::quote<<(const_cast<char*>((const char*)keterangan_textCtrl->GetValue().mb_str()))
                        <<" WHERE FID ="<<(const_cast<char*>((const char*)ref_id_str.mb_str()))
                            <<" AND tgl_awal="<<mysqlpp::quote<<(const_cast<char*>((const char*)ref_tgl_awal_str.mb_str()))
                            <<" AND tgl_akhir="<<mysqlpp::quote<<(const_cast<char*>((const char*)ref_tgl_akhir_str.mb_str()))
                        <<" LIMIT 1";
                }
                bool res=qry.execute();
                if(res){
                    ((CutiPanel*)GetParent())->RefreshDataView();
                    if(input_mode == wxString("create")){
                        ResetInput();
                    }else if(input_mode == wxString("update")){
                        Close();
                    }
                }else{
                    wxString err_msg("Error saat tambah/ubah data cuti pegawai: ");
                    err_msg<<qry.error();
                    wxLogError(err_msg);
                }
            }catch(mysqlpp::Exception &e){
                wxLogError(e.what());
            }
        }else{
            wxLogError("Error, database tidak terkoneksi.");
        }
    }else{
        if(FID_textCtrl->GetValue() == wxEmptyString){ wxLogError("Error, harap mengisi data pegawai"); }
        if(idbcuti_jenis_textCtrl->GetValue() == wxEmptyString){ wxLogError("Error, harap mengisi data jenis cuti"); }
    }
}
void CutiDialog::PilihPegawai(wxString p_FID, wxString p_nama){
    FID_textCtrl->SetValue(p_FID);
    nama_textCtrl->SetValue(p_nama);
}
void CutiDialog::PilihJenisCuti(wxString p_idbcuti_jenis, wxString p_jenis_cuti){
    idbcuti_jenis_textCtrl->SetValue(p_idbcuti_jenis);
    jenis_cuti_textCtrl->SetValue(p_jenis_cuti);
}
void CutiDialog::InputMode(const wxString &p_input_mode, const wxString &p_ref_id, const wxString &p_ref_tgl_awal_str
            , const wxString &p_ref_tgl_akhir_str)
{
    input_mode=p_input_mode;
    if(p_input_mode==wxString("update")){
        if( (p_ref_id!=wxEmptyString) && (p_ref_tgl_awal_str!=wxEmptyString) && (p_ref_tgl_akhir_str!=wxEmptyString) ){
            ref_id_str = p_ref_id;
            ref_tgl_awal_str = p_ref_tgl_awal_str;
            ref_tgl_akhir_str = p_ref_tgl_akhir_str;
        }else{
            wxLogError("Kesalahan pemrograman untuk parameter-parameter. Harap kontak administrator programmer.");
        }
    }
}
void CutiDialog::ResetInput(){
    FID_textCtrl->SetValue(wxEmptyString);
    nama_textCtrl->SetValue(wxEmptyString);
    tgl_awal_datePicker->SetValue(wxDateTime::Today());
    tgl_akhir_datePicker->SetValue(wxDateTime::Today());
    idbcuti_jenis_textCtrl->SetValue(wxEmptyString);
    jenis_cuti_textCtrl->SetValue(wxEmptyString);
    keterangan_textCtrl->SetValue(wxEmptyString);
}
void CutiDialog::SetUpdateValue(){
    wxDataViewListCtrl *cuti_dataViewListCtrl=((CutiPanel*)GetParent())->cuti_dataViewListCtrl;
   
    int selected_row = cuti_dataViewListCtrl->GetSelectedRow();
    FID_textCtrl->SetValue(cuti_dataViewListCtrl->GetTextValue(selected_row, 0));
    nama_textCtrl->SetValue(cuti_dataViewListCtrl->GetTextValue(selected_row, 2));
    wxDateTime sel_tgl_awal; sel_tgl_awal.ParseISODate(cuti_dataViewListCtrl->GetTextValue(selected_row, 4));
    wxDateTime sel_tgl_akhir; sel_tgl_akhir.ParseISODate(cuti_dataViewListCtrl->GetTextValue(selected_row, 5));
    tgl_awal_datePicker->SetValue(sel_tgl_awal);
    tgl_akhir_datePicker->SetValue(sel_tgl_akhir);
    idbcuti_jenis_textCtrl->SetValue(cuti_dataViewListCtrl->GetTextValue(selected_row, 1));
    jenis_cuti_textCtrl->SetValue(cuti_dataViewListCtrl->GetTextValue(selected_row, 6));
    keterangan_textCtrl->SetValue(cuti_dataViewListCtrl->GetTextValue(selected_row, 7));
}
