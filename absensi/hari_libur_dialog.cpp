#include "hari_libur_dialog.h"
#include "hari_libur_panel.h"
HariLiburDialog::HariLiburDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* wrapper_bSizer;
	wrapper_bSizer = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer6->AddGrowableCol( 1 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText27 = new wxStaticText( this, wxID_ANY, wxT("Tanggal Libur"), wxDefaultPosition, wxDefaultSize, 0 );
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
	keterangan_textCtrl->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( HariLiburDialog::OnSimpan ), NULL, this );
	simpan_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HariLiburDialog::OnSimpan ), NULL, this );
}

HariLiburDialog::~HariLiburDialog()
{
	// Disconnect Events
	keterangan_textCtrl->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( HariLiburDialog::OnSimpan ), NULL, this );
	simpan_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HariLiburDialog::OnSimpan ), NULL, this );
	
}
void HariLiburDialog::InputMode(wxString p_input_mode, wxString p_ref_tgl){
    input_mode = p_input_mode;
    if(p_input_mode == wxString(wxT("update"))){
        if(p_ref_tgl != wxEmptyString){
            ref_tgl = p_ref_tgl;
        }else{
            wxLogError(wxT("Kesalahan pemrograman untuk parameter p_ref_tgl. Harap kontak administrator programmer."));
        }
    }
}
void HariLiburDialog::OnSimpan( wxCommandEvent& event ){
    //BEGIN VALIDATION=============
    if(keterangan_textCtrl->GetValue() == wxEmptyString){
        wxLogError("Error, Harap isi keterangan!");
        return;
    }
    //END VALIDATION**********
    if(conn.connected()){
        try{
            mysqlpp::Query qry=conn.query();
            if(input_mode==wxString(wxT("create"))){
                qry<<"INSERT INTO bhari_libur(tgl, keterangan) VALUES("
                        <<mysqlpp::quote<<(const_cast<char*>((const char*)tgl_datePicker->GetValue().FormatISODate().mb_str()))<<","
                        <<mysqlpp::quote<<(const_cast<char*>((const char*)keterangan_textCtrl->GetValue().mb_str()))
                    <<")";
            }else if(input_mode == wxString(wxT("update"))){
                qry<<"UPDATE bhari_libur SET"
                    <<" tgl="<<mysqlpp::quote<<(const_cast<char*>((const char*)tgl_datePicker->GetValue().FormatISODate().mb_str()))<<","
                    <<" keterangan="<<mysqlpp::quote<<(const_cast<char*>((const char*)keterangan_textCtrl->GetValue().mb_str()))
                    <<" WHERE tgl="<<mysqlpp::quote<<(const_cast<char*>((const char*)ref_tgl.mb_str()))
                    <<" LIMIT 1";
            }
            bool res=qry.execute();
            if(res){
                ((HariLiburPanel*)GetParent())->RefreshDataView();
                if(input_mode == wxString(wxT("create"))){
                    ResetInput();
                }else if(input_mode == wxString(wxT("update"))){
                    Close();
                }
            }else{
                wxString err_msg(wxT("Error saat input data hari libur:"));
                err_msg<<qry.error();
                wxLogError(err_msg);
            }
        }catch(mysqlpp::Exception &e){
            wxLogError(e.what());
        }
    }else{
        wxLogError(wxT("Error, database tidak terkoneksi."));
    }
}
void HariLiburDialog::ResetInput(){
    tgl_datePicker->SetValue(wxDateTime::Today());
    keterangan_textCtrl->SetValue(wxEmptyString);
}
void HariLiburDialog::SetUpdateValue(wxString p_tgl, wxString p_keterangan){
    wxDateTime tgl_value = wxDateTime();
    tgl_value.ParseISODate(p_tgl);
    tgl_datePicker->SetValue(tgl_value);
    
    keterangan_textCtrl->SetValue(p_keterangan);
}
