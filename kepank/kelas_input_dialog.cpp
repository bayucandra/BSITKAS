/* 
 * File:   kelas_input_dialog.cpp
 * Author: bayucandra@gmail.com
 *
 * Created on January 17, 2015, 7:23 PM
 */
#include "kelas_input_dialog.h"

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
        
        update_id=-1;
}

KelasInputDialog::~KelasInputDialog()
{
	// Disconnect Events
	kelas_textCtrl->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( KelasInputDialog::OnSimpan ), NULL, this );
	keterangan_textCtrl->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( KelasInputDialog::OnSimpan ), NULL, this );
	tunjangan_perbulan_textCtrl->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( KelasInputDialog::OnSimpan ), NULL, this );
	
}
void KelasInputDialog::OnSimpan(wxCommandEvent& event) {
    if(conn.connected()){
        bkelas row;
        mysqlpp::Query qry=conn.query();
        if(this->GetInputMode()=="insert"){
            bkelas row(NULL, (const_cast<char*>((const char*)kelas_textCtrl->GetValue().mb_str())),
                (const_cast<char*>((const char*)keterangan_textCtrl->GetValue().mb_str())),
                wxAtoi(tunjangan_perbulan_textCtrl->GetValue()));
            qry.insert(row);
            
        }else if(this->GetInputMode()=="update"){
            bkelas row(this->GetUpdateId(), (const_cast<char*>((const char*)kelas_textCtrl->GetValue().mb_str())),
                (const_cast<char*>((const char*)keterangan_textCtrl->GetValue().mb_str())),
                wxAtoi(tunjangan_perbulan_textCtrl->GetValue()));
        }
        bool res_ins=qry.execute();
        if(!res_ins){
            wxString error_msg=wxString(wxT("Error input database: "));
            error_msg.Append(qry.error());
            wxLogError(error_msg);
        }
    }else{
        wxLogError(wxT("Error: Database tidak terkoneksi!"));
    }
}
void KelasInputDialog::InputMode(char* p_input_mode){
    input_mode=p_input_mode;
    if(p_input_mode=="update"){
        update_id=-1;
    }
}
char* KelasInputDialog::GetInputMode(){
    return input_mode;
}

void KelasInputDialog::SetUpdateId(int p_update_id){
    update_id=p_update_id;
}
int KelasInputDialog::GetUpdateId(){
    return update_id;
}
