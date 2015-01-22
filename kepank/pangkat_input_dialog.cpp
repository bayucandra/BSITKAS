/* 
 * File:   pangkat_input_dialog.cpp
 * Author: bayucandra@gmail.com
 *
 * Created on January 20, 2015, 12:07 PM
 */

#include "pangkat_input_dialog.h"
#include "pangkat_panel.h"
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
void PangkatInputDialog::InputMode(char* p_input_mode, int p_ref_id){
    input_mode=p_input_mode;
    if(p_input_mode=="update"){
        if(p_ref_id!=-1){
            ref_id=p_ref_id;
        }else{
            wxLogError("Kesalahan pemrograman untuk parameter p_ref_id. Harap kontak administrator programmer.");
        }
    }
}
void PangkatInputDialog::OnSimpan( wxCommandEvent& event ){
    if(conn.connected()){
        try{
            mysqlpp::Query qry=conn.query();
            if(input_mode=="create"){
                qry<<"INSERT INTO bpangkat_golongan(pangkat_golongan, keterangan, uang_makan)VALUES("
                    <<mysqlpp::quote<<(const_cast<char*>((const char*)pangkat_textCtrl->GetValue().mb_str()))<<","
                    <<mysqlpp::quote<<(const_cast<char*>((const char*)keterangan_textCtrl->GetValue().mb_str()))<<","
                    <<mysqlpp::quote<<(const_cast<char*>((const char*)uang_makan_textCtrl->GetValue().mb_str()))
                    <<")";
            }else if(input_mode=="update"){
                qry<<"UPDATE bpangkat_golongan SET "
                    <<"pangkat_golongan="<<mysqlpp::quote<<(const_cast<char*>((const char*)pangkat_textCtrl->GetValue().mb_str()))<<","
                    <<"keterangan="<<mysqlpp::quote<<(const_cast<char*>((const char*)keterangan_textCtrl->GetValue().mb_str()))<<","
                    <<"uang_makan="<<mysqlpp::quote<<(const_cast<char*>((const char*)uang_makan_textCtrl->GetValue().mb_str()))
                    <<" WHERE idbpangkat_golongan="<<ref_id
                    <<" LIMIT 1";
            }
            bool res_ins=qry.execute();
            if(!res_ins){
                wxString error_msg=wxString("Error input database: ");
                error_msg.Append(qry.error());
                wxLogError(error_msg);
            }else{
                ((PangkatPanel*)GetParent())->RefreshDataView();
                if(input_mode=="create"){
                    ResetInput();
                }else if(input_mode=="update"){
                    Close();
                }
            }
        }catch(mysqlpp::Exception &e){
            wxLogError(e.what());
        }
    }else{
        wxLogError("Error, database tidak terkoneksi");
    }
}
void PangkatInputDialog::ResetInput(){
    pangkat_textCtrl->SetValue(wxEmptyString);
    keterangan_textCtrl->SetValue(wxEmptyString);
    uang_makan_textCtrl->SetValue(wxEmptyString);
    
    pangkat_textCtrl->SetFocus();
}
void PangkatInputDialog::SetUpdateValue(wxString p_pangkat_golongan, wxString p_keterangan, wxString p_uang_makan){
    pangkat_textCtrl->SetValue(p_pangkat_golongan);
    keterangan_textCtrl->SetValue(p_keterangan);
    uang_makan_textCtrl->SetValue(p_uang_makan);
}
void PangkatInputDialog::OnReset( wxCommandEvent& event ){
    pangkat_textCtrl->SetValue(wxEmptyString);
    keterangan_textCtrl->SetValue(wxEmptyString);
    uang_makan_textCtrl->SetValue(wxEmptyString);
}

