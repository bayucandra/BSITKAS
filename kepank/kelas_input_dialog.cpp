#include "kelas_input_dialog.h"
#include "kelas_panel.h"
KelasInputDialog::KelasInputDialog( wxPanel* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
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
        //BEGIN BAYU=============
        ref_id=-1;
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
void KelasInputDialog::ResetInput(){
    kelas_textCtrl->SetValue(wxEmptyString);
    keterangan_textCtrl->SetValue(wxEmptyString);
    tunjangan_perbulan_textCtrl->SetValue(wxEmptyString);
    
    kelas_textCtrl->SetFocus();
}
void KelasInputDialog::OnReset(wxCommandEvent& event){
    this->ResetInput();
}
void KelasInputDialog::OnSimpan(wxCommandEvent& event) {
    if(!IsInputValid()){
        wxLogError("Inputan tidak valid. Harap periksa ulang.");
        return;
    }
    if(conn.connected()){
        try{
            mysqlpp::Query qry=conn.query();
            if(this->GetInputMode()==wxString(wxT("create"))){
                qry<<"INSERT INTO bkelas(kelas,keterangan,tunjangan_perbulan) VALUES("
                    <<mysqlpp::quote<<(const_cast<char*>((const char*)kelas_textCtrl->GetValue().mb_str()))<<","
                    <<mysqlpp::quote<<(const_cast<char*>((const char*)keterangan_textCtrl->GetValue().mb_str()))<<","
                    <<(const_cast<char*>((const char*)tunjangan_perbulan_textCtrl->GetValue().mb_str()))
                    <<")";
            }else if(this->GetInputMode()==wxString(wxT("update"))){
                qry<<"UPDATE bkelas SET "
                    <<"kelas="<<mysqlpp::quote<<(const_cast<char*>((const char*)kelas_textCtrl->GetValue().mb_str()))<<","
                    <<"keterangan="<<mysqlpp::quote<<(const_cast<char*>((const char*)keterangan_textCtrl->GetValue().mb_str()))<<","
                    <<"tunjangan_perbulan="<<mysqlpp::quote<<(const_cast<char*>((const char*)tunjangan_perbulan_textCtrl->GetValue().mb_str()))
                    <<" WHERE idbkelas="<<ref_id
                    <<" LIMIT 1";
            }
            bool res_ins=qry.execute();
            if(!res_ins){
                wxString error_msg=wxString(wxT("Error input database: "));
                error_msg.Append(qry.error());
                wxLogError(error_msg);
            }else{
                ((KelasPanel*)GetParent())->RefreshDataView();
                if(input_mode==wxString(wxT("create"))){
                    ResetInput();
                }else if(input_mode==wxString(wxT("update"))){
                    Close();
                }
            }
        }catch(mysqlpp::Exception &e){
            wxLogMessage(e.what());
        }
    }else{
        wxLogError(wxT("Error: Database tidak terkoneksi!"));
    }
}
void KelasInputDialog::InputMode(wxString p_input_mode,int p_ref_id){
    input_mode=p_input_mode;
    if(p_input_mode==wxString("update")){
        if(p_ref_id!=-1){
            ref_id=p_ref_id;
        }else{
            wxLogError("Kesalahan pemrograman untuk parameter p_ref_id. Harap kontak administrator programmer.");
        }
    }
}
wxString KelasInputDialog::GetInputMode(){
    return input_mode;
}

int KelasInputDialog::GetRefId(){
    return ref_id;
}

void KelasInputDialog::SetUpdateValue(wxString kelas, wxString keterangan, wxString tunjangan_perbulan){
    kelas_textCtrl->SetValue(kelas);
    keterangan_textCtrl->SetValue(keterangan);
    tunjangan_perbulan_textCtrl->SetValue(tunjangan_perbulan);
}
bool KelasInputDialog::IsInputValid(){
    bool ret=true;
    if((kelas_textCtrl->GetValue()==wxEmptyString)
            ||(tunjangan_perbulan_textCtrl->GetValue()==wxEmptyString)
        )
    {
        ret=false;
    }
    return ret;
}
