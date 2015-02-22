#include "hari_libur_panel.h"
#include "hari_libur_dialog.cpp"
HariLiburPanel::HariLiburPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* wrapper_bSizer;
	wrapper_bSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* button_bSizer;
	button_bSizer = new wxBoxSizer( wxHORIZONTAL );
	
	tambah_button = new wxButton( this, wxID_ANY, wxT("Tambah"), wxDefaultPosition, wxDefaultSize, 0 );
	button_bSizer->Add( tambah_button, 0, wxALL, 5 );
	
	ubah_button = new wxButton( this, wxID_ANY, wxT("Ubah"), wxDefaultPosition, wxDefaultSize, 0 );
	button_bSizer->Add( ubah_button, 0, wxALL, 5 );
	
	hapus_button = new wxButton( this, wxID_ANY, wxT("Hapus"), wxDefaultPosition, wxDefaultSize, 0 );
	button_bSizer->Add( hapus_button, 0, wxALL, 5 );
	
	
	wrapper_bSizer->Add( button_bSizer, 0, wxEXPAND, 5 );
	
	hari_libur_dataViewListCtrl = new wxDataViewListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	wrapper_bSizer->Add( hari_libur_dataViewListCtrl, 1, wxALL|wxEXPAND, 5 );
	
	footer_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	footer_panel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVEBORDER ) );
	
	wxBoxSizer* footer_bSizer;
	footer_bSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText20 = new wxStaticText( footer_panel, wxID_ANY, wxT("Tampilkan Dari"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	footer_bSizer->Add( m_staticText20, 0, wxALL, 5 );
	
	start_datePicker = new wxDatePickerCtrl( footer_panel, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DROPDOWN );
	footer_bSizer->Add( start_datePicker, 0, wxALL, 5 );
	
	m_staticText21 = new wxStaticText( footer_panel, wxID_ANY, wxT("s/d"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	footer_bSizer->Add( m_staticText21, 0, wxALL, 5 );
	
	end_datePicker = new wxDatePickerCtrl( footer_panel, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DROPDOWN );
	footer_bSizer->Add( end_datePicker, 0, wxALL, 5 );
	
	
	footer_bSizer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	footer_panel->SetSizer( footer_bSizer );
	footer_panel->Layout();
	footer_bSizer->Fit( footer_panel );
	wrapper_bSizer->Add( footer_panel, 0, wxEXPAND | wxALL, 5 );
	
	
	this->SetSizer( wrapper_bSizer );
	this->Layout();
	
	// Connect Events
	tambah_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HariLiburPanel::OnTambah ), NULL, this );
	ubah_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HariLiburPanel::OnUbah ), NULL, this );
	hapus_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HariLiburPanel::OnHapus ), NULL, this );
	start_datePicker->Connect( wxEVT_DATE_CHANGED, wxDateEventHandler( HariLiburPanel::OnFilterData ), NULL, this );
	end_datePicker->Connect( wxEVT_DATE_CHANGED, wxDateEventHandler( HariLiburPanel::OnFilterData ), NULL, this );
        
        //BEGIN BAYU===========================
        InitDateRange();
        InitDataView();
}

HariLiburPanel::~HariLiburPanel()
{
	// Disconnect Events
	tambah_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HariLiburPanel::OnTambah ), NULL, this );
	ubah_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HariLiburPanel::OnUbah ), NULL, this );
	hapus_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HariLiburPanel::OnHapus ), NULL, this );
	start_datePicker->Disconnect( wxEVT_DATE_CHANGED, wxDateEventHandler( HariLiburPanel::OnFilterData ), NULL, this );
	end_datePicker->Disconnect( wxEVT_DATE_CHANGED, wxDateEventHandler( HariLiburPanel::OnFilterData ), NULL, this );
	
}
void HariLiburPanel::InitDataView(){
    wxDataViewListStore* hari_libur_store = new wxDataViewListStore();
    hari_libur_dataViewListCtrl->AssociateModel(hari_libur_store);
    hari_libur_store->DecRef();
    
    hari_libur_dataViewListCtrl->AppendTextColumn("Tgl. Libur",wxDATAVIEW_CELL_ACTIVATABLE, 100, wxALIGN_CENTER, wxDATAVIEW_COL_RESIZABLE);
    hari_libur_dataViewListCtrl->AppendTextColumn("Keterangan",wxDATAVIEW_CELL_ACTIVATABLE, 300, wxALIGN_LEFT, wxDATAVIEW_COL_RESIZABLE);
    RefreshDataView();
}
void HariLiburPanel::RefreshDataView(){
    if(conn.connected()){
        hari_libur_dataViewListCtrl->DeleteAllItems();
        try{
            mysqlpp::Query qry = conn.query();
            qry<<"SELECT * FROM bhari_libur"
                <<" WHERE tgl >="
                        <<mysqlpp::quote<<(const_cast<char*>((const char*)start_datePicker->GetValue().FormatISODate().mb_str()))
                    <<" AND tgl <="
                        <<mysqlpp::quote<<(const_cast<char*>((const char*)end_datePicker->GetValue().FormatISODate().mb_str()))
                    <<" ORDER BY tgl DESC";
            mysqlpp::StoreQueryResult res=qry.store();
            if(res){
                wxVector<wxVariant> data;
                for(size_t i=0; i<res.num_rows(); ++i){
                    data.clear();
                    data.push_back(wxString::FromUTF8(res[i]["tgl"]));
                    data.push_back(wxString::FromUTF8(res[i]["keterangan"]));
                    hari_libur_dataViewListCtrl->AppendItem(data);
                }
            }else{
                wxString err_msg(wxT("Error database refresh hari libur:"));
                err_msg<<qry.error();
                wxLogError(err_msg);
            }
        }catch(mysqlpp::Exception &e){
            wxLogError(e.what());
        }
    }else{
        wxLogError(wxT("Error, database tidak terkoneksi"));
    }
}
void HariLiburPanel::InitDateRange(){
    wxDateTime date_today=wxDateTime::Today();
    
    wxDateTime first_day=wxDateTime(1,date_today.GetMonth(), date_today.GetYear());
    start_datePicker->SetValue(first_day);
    
    wxDateTime last_day=date_today;
    last_day.SetToLastMonthDay();
    end_datePicker->SetValue(last_day);
}
void HariLiburPanel::OnTambah( wxCommandEvent& event ){
    hari_libur_dialog = new HariLiburDialog(this);
    hari_libur_dialog->InputMode(wxT("create"));
    hari_libur_dialog->SetTitle("Tambah hari libur");
    hari_libur_dialog->Center();
    hari_libur_dialog->ShowModal();
}
void HariLiburPanel::OnUbah( wxCommandEvent& event ){
    if(hari_libur_dataViewListCtrl->HasSelection()){
        int selected_row = hari_libur_dataViewListCtrl->GetSelectedRow();

        hari_libur_dialog = new HariLiburDialog(this);
        hari_libur_dialog->InputMode("update", hari_libur_dataViewListCtrl->GetTextValue(selected_row,0));

        wxString title(wxT("Ubah hari libur tanggal: "));
        title<<hari_libur_dataViewListCtrl->GetTextValue(selected_row,0);
        hari_libur_dialog->SetTitle(title);

        hari_libur_dialog->SetUpdateValue(
            hari_libur_dataViewListCtrl->GetTextValue(selected_row,0),
            hari_libur_dataViewListCtrl->GetTextValue(selected_row,1)
        );

        hari_libur_dialog->Center();
        hari_libur_dialog->ShowModal();
    }else{
        wxLogError("Harap pilih baris data untuk diubah");
    }
}
void HariLiburPanel::OnHapus( wxCommandEvent& event ){
    if(hari_libur_dataViewListCtrl->HasSelection()){
        int selected_row = hari_libur_dataViewListCtrl->GetSelectedRow();
        int confirm = wxMessageBox(
                wxString("Yakin untuk menghapus data hari libur tanggal: ").Append(hari_libur_dataViewListCtrl->GetTextValue(selected_row,0)),
                wxT("Konfirmasi"),
                wxICON_QUESTION | wxYES_NO,
                this
            );
        if(confirm == wxYES){
            if(conn.connected()){
                try{
                    mysqlpp::Query qry = conn.query();
                    qry<<"DELETE FROM bhari_libur"
                            <<" WHERE tgl="
                                <<mysqlpp::quote<<(const_cast<char*>((const char*)hari_libur_dataViewListCtrl->GetTextValue(selected_row, 0).mb_str()))
                        <<" LIMIT 1";
                    if(qry.execute()){
                        RefreshDataView();
                    }else{
                        wxString err_msg = wxString("Error saat menghapus data: ");
                        err_msg.Append(qry.error());
                        wxLogError(err_msg);
                    }
                }catch(mysqlpp::Exception &e){
                    wxLogError(e.what());
                }
            }
        }
    }else{
        wxLogError("Error, harap pilih baris data untuk dihapus.");
    }
}
void HariLiburPanel::OnFilterData( wxDateEvent& event ){
    RefreshDataView();
}
