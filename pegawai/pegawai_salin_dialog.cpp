#include "pegawai_salin_dialog.h"
#include "pegawai_panel.h"

PegawaiSalinDialog::PegawaiSalinDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* input_bSizer;
	input_bSizer = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Data pegawai") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer5;
	fgSizer5 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer5->AddGrowableCol( 1 );
	fgSizer5->SetFlexibleDirection( wxBOTH );
	fgSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText15 = new wxStaticText( this, wxID_ANY, wxT("FID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	fgSizer5->Add( m_staticText15, 0, wxALL, 5 );
	
	FID_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 90,-1 ), 0 );
	FID_textCtrl->Enable( false );
	
	fgSizer5->Add( FID_textCtrl, 0, wxALL, 5 );
	
	m_staticText16 = new wxStaticText( this, wxID_ANY, wxT("Nama"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	fgSizer5->Add( m_staticText16, 0, wxALL, 5 );
	
	Nama_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	Nama_textCtrl->Enable( false );
	
	fgSizer5->Add( Nama_textCtrl, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText17 = new wxStaticText( this, wxID_ANY, wxT("NIK"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	fgSizer5->Add( m_staticText17, 0, wxALL, 5 );
	
	NIK_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	NIK_textCtrl->Enable( false );
	
	fgSizer5->Add( NIK_textCtrl, 0, wxALL|wxEXPAND, 5 );
	
	
	sbSizer1->Add( fgSizer5, 1, wxEXPAND, 5 );
	
	
	input_bSizer->Add( sbSizer1, 5, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Kelas - Pangkat") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText18 = new wxStaticText( this, wxID_ANY, wxT("Kelas"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	fgSizer6->Add( m_staticText18, 0, wxALL, 5 );
	
	kelas_comboBox = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), 0, NULL,
                wxCB_READONLY|wxCB_SORT ); 
	fgSizer6->Add( kelas_comboBox, 0, wxALL, 5 );
	
	m_staticText19 = new wxStaticText( this, wxID_ANY, wxT("Pangkat"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	fgSizer6->Add( m_staticText19, 0, wxALL, 5 );
	
	pangkat_comboBox = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), 0, NULL,
                wxCB_READONLY|wxCB_SORT ); 
	fgSizer6->Add( pangkat_comboBox, 0, wxALL, 5 );
	
	
	sbSizer2->Add( fgSizer6, 1, wxEXPAND, 5 );
	
	
	input_bSizer->Add( sbSizer2, 4, wxEXPAND, 5 );
	
	
	bSizer23->Add( input_bSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* button_bSizer;
	button_bSizer = new wxBoxSizer( wxVERTICAL );
	
	simpan_button = new wxButton( this, wxID_ANY, wxT("Salin"), wxDefaultPosition, wxDefaultSize, 0 );
	button_bSizer->Add( simpan_button, 0, wxALL, 15 );
	
	
	bSizer23->Add( button_bSizer, 1, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer23 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	simpan_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PegawaiSalinDialog::OnSimpan ), NULL, this );
        
        //BEGIN BAYU====================
        CbInitKelas();
        CbInitPangkat();
}

PegawaiSalinDialog::~PegawaiSalinDialog()
{
	// Disconnect Events
	simpan_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PegawaiSalinDialog::OnSimpan ), NULL, this );
	
}

void PegawaiSalinDialog::SalinDataLama(wxString p_FID, wxString p_Nama, wxString p_NIK){
    FID_textCtrl->SetValue(p_FID);
    Nama_textCtrl->SetValue(p_Nama);
    NIK_textCtrl->SetValue(p_NIK);
}
void PegawaiSalinDialog::CbInitKelas(){
    if(conn.connected()){
        try{
            mysqlpp::Query qry=conn.query();
            qry<<"SELECT kelas FROM bkelas ORDER BY kelas ASC";
            mysqlpp::StoreQueryResult res=qry.store();
//            kelas_comboBox->Append(wxString("N/A"));
            if(res){
                for(size_t i=0; i<res.num_rows(); ++i){
                    kelas_comboBox->Append(wxString::FromUTF8(res[i]["kelas"]));
                }
            }else{
                wxString error_msg=wxString("Salin pegawai => Error, saat query database kelas.");
                error_msg.Append(qry.error());
                wxLogError(error_msg);
            }
        }catch(mysqlpp::Exception &e){
            wxLogError(e.what());
        }
    }else{
        wxLogError("Error, database tidak terkoneksi.");
    }
}
void PegawaiSalinDialog::CbInitPangkat(){
    if(conn.connected()){
        try{
            mysqlpp::Query qry=conn.query();
            qry<<"SELECT pangkat_golongan FROM bpangkat_golongan ORDER BY pangkat_golongan ASC";
            mysqlpp::StoreQueryResult res=qry.store();
            if(res){
                for(size_t i=0; i<res.num_rows(); ++i){
                    pangkat_comboBox->Append(wxString::FromUTF8(res[i]["pangkat_golongan"]));
                }
            }else{
                wxString error_msg=wxString("Salin pegawai => Error, saat query database pangkat");
                error_msg.Append(qry.error());
                wxLogError(error_msg);
            }
        }catch(mysqlpp::Exception &e){
            wxLogError(e.what());
        }
    }else{
        wxLogError("Error, database tidak terkoneksi.");
    }
}
void PegawaiSalinDialog::OnSimpan( wxCommandEvent &event ){
    if((kelas_comboBox->GetValue()!=wxEmptyString)&&
        (pangkat_comboBox->GetValue()!=wxEmptyString)){
        if(conn.connected()){
            try{
                mysqlpp::Query qry=conn.query();
                if(input_mode == wxString("create")){
                    qry<<"INSERT INTO bstaff(FID, nama, NIK, idbkelas, idbpangkat_golongan) VALUES("
                        <<mysqlpp::quote<<(const_cast<char*>((const char*)FID_textCtrl->GetValue().mb_str()))<<","
                        <<mysqlpp::quote<<(const_cast<char*>((const char*)Nama_textCtrl->GetValue().mb_str()))<<","
                        <<mysqlpp::quote<<(const_cast<char*>((const char*)NIK_textCtrl->GetValue().mb_str()))<<","
                        <<"(SELECT idbkelas FROM bkelas WHERE kelas="
                            <<mysqlpp::quote<<(const_cast<char*>((const char*)kelas_comboBox->GetValue().mb_str()))
                            <<" LIMIT 1)"<<","
                        <<"(SELECT idbpangkat_golongan FROM bpangkat_golongan WHERE pangkat_golongan="
                            <<mysqlpp::quote<<(const_cast<char*>((const char*)pangkat_comboBox->GetValue().mb_str()))
                            <<" LIMIT 1)"
                        <<")";
                }else if(input_mode == wxString("update")){
                    qry<<"UPDATE bstaff SET"
                            <<" idbkelas="
                                <<"(SELECT idbkelas FROM bkelas WHERE kelas="
                                    <<mysqlpp::quote<<(const_cast<char*>((const char*)kelas_comboBox->GetValue().mb_str()))
                                    <<" LIMIT 1)"<<","
                            <<" idbpangkat_golongan="
                                <<"(SELECT idbpangkat_golongan FROM bpangkat_golongan WHERE pangkat_golongan="
                                    <<mysqlpp::quote<<(const_cast<char*>((const char*)pangkat_comboBox->GetValue().mb_str()))
                                    <<" LIMIT 1)"
                        <<" WHERE idbstaff="<<(const_cast<char*>((const char*)ref_id.mb_str()))
                        <<" LIMIT 1";
                }
                bool res_ins=qry.execute();
                if(res_ins){
                    ((PegawaiPanel*)GetParent())->RefreshDataView();
                    ((PegawaiPanel*)GetParent())->RefreshDataLamaView();
                    Close();
                }else{
                    wxString error_msg=wxString("Error input data Pegawai: ");
                    error_msg.Append(qry.error());
                    wxLogError(error_msg);
                    wxLogError(wxString(qry.str()));
                }
            }catch(mysqlpp::Exception &e){
                wxLogError(e.what());
            }
        }else{
            wxLogError("Error, database tidak terkoneksi.");
        }
    }else{
        wxLogError("Harap mengisi input Kelas dan input Pangkat");
    }
}

void PegawaiSalinDialog::InputMode(wxString p_input_mode, wxString p_ref_id){
    input_mode=p_input_mode;
    if(p_input_mode==wxString("update")){
        if(p_ref_id != wxEmptyString){
            ref_id=p_ref_id;
        }else{
            wxLogError("Kesalahan pemrograman untuk parameter p_ref_id. Harap kontak administrator programmer.");
        }
    }
}
void PegawaiSalinDialog::SetUpdateValue(){
    simpan_button->SetLabel("Ubah");
    wxDataViewListCtrl *pegawai_dataViewListCtrl=((PegawaiPanel*)GetParent())->GetPengawaiDataView();
//    wxLogMessage(pegawai_dataViewListCtrl->GetTextValue(1,1));
    int selected_row = pegawai_dataViewListCtrl->GetSelectedRow();
    FID_textCtrl->SetValue(pegawai_dataViewListCtrl->GetTextValue(selected_row, 1));
    Nama_textCtrl->SetValue(pegawai_dataViewListCtrl->GetTextValue(selected_row, 2));
    NIK_textCtrl->SetValue(pegawai_dataViewListCtrl->GetTextValue(selected_row, 3));
    kelas_comboBox->SetValue(pegawai_dataViewListCtrl->GetTextValue(selected_row, 4));
    pangkat_comboBox->SetValue(pegawai_dataViewListCtrl->GetTextValue(selected_row, 5));
}
