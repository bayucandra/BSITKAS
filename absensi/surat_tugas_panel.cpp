#include "surat_tugas_panel.h"
#include "surat_tugas_dialog.cpp"

SuratTugasPanel::SuratTugasPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
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
	
	surat_tugas_dataViewListCtrl = new wxDataViewListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxDV_HORIZ_RULES|wxDV_ROW_LINES );
	wrapper_bSizer->Add( surat_tugas_dataViewListCtrl, 1, wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
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
	
	m_staticText22 = new wxStaticText( footer_panel, wxID_ANY, wxT("Cari Nama"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	footer_bSizer->Add( m_staticText22, 0, wxALL, 5 );
	
	filter_nama_textCtrl = new wxTextCtrl( footer_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	filter_nama_textCtrl->SetMinSize( wxSize( 150,-1 ) );
	
	footer_bSizer->Add( filter_nama_textCtrl, 0, wxALL|wxEXPAND, 5 );
	
	
	footer_panel->SetSizer( footer_bSizer );
	footer_panel->Layout();
	footer_bSizer->Fit( footer_panel );
	wrapper_bSizer->Add( footer_panel, 0, wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 5 );
	
	
	this->SetSizer( wrapper_bSizer );
	this->Layout();
	wrapper_bSizer->Fit( this );
	
	// Connect Events
	tambah_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SuratTugasPanel::OnTambah ), NULL, this );
	ubah_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SuratTugasPanel::OnUbah ), NULL, this );
	hapus_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SuratTugasPanel::OnHapus ), NULL, this );
	start_datePicker->Connect( wxEVT_DATE_CHANGED, wxDateEventHandler( SuratTugasPanel::OnFilterData ), NULL, this );
	end_datePicker->Connect( wxEVT_DATE_CHANGED, wxDateEventHandler( SuratTugasPanel::OnFilterData ), NULL, this );
	filter_nama_textCtrl->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SuratTugasPanel::OnFilterData ), NULL, this );
        
        //BEGIN BAYU=============
        InitDateRange();
        InitDataView();
        //END BAYU****************
}

SuratTugasPanel::~SuratTugasPanel()
{
	// Disconnect Events
	tambah_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SuratTugasPanel::OnTambah ), NULL, this );
	ubah_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SuratTugasPanel::OnUbah ), NULL, this );
	hapus_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SuratTugasPanel::OnHapus ), NULL, this );
	start_datePicker->Disconnect( wxEVT_DATE_CHANGED, wxDateEventHandler( SuratTugasPanel::OnFilterData ), NULL, this );
	end_datePicker->Disconnect( wxEVT_DATE_CHANGED, wxDateEventHandler( SuratTugasPanel::OnFilterData ), NULL, this );
	filter_nama_textCtrl->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SuratTugasPanel::OnFilterData ), NULL, this );
	
}

void SuratTugasPanel::InitDateRange(){
    wxDateTime date_today=wxDateTime::Today();
    
    wxDateTime first_day=wxDateTime(1,date_today.GetMonth(), date_today.GetYear());
    start_datePicker->SetValue(first_day);
    
    wxDateTime last_day=date_today;
    last_day.SetToLastMonthDay();
    end_datePicker->SetValue(last_day);
}
void SuratTugasPanel::InitDataView(){
    wxDataViewListStore* surat_tugas_store=new wxDataViewListStore();
    surat_tugas_dataViewListCtrl->AssociateModel(surat_tugas_store);
    surat_tugas_store->DecRef();
    
    surat_tugas_dataViewListCtrl->AppendTextColumn("FID",wxDATAVIEW_CELL_ACTIVATABLE, 50, wxALIGN_LEFT, wxDATAVIEW_COL_HIDDEN);
    surat_tugas_dataViewListCtrl->AppendTextColumn("Nama",wxDATAVIEW_CELL_ACTIVATABLE, 150, wxALIGN_LEFT, wxDATAVIEW_COL_RESIZABLE);
    surat_tugas_dataViewListCtrl->AppendTextColumn("NIP",wxDATAVIEW_CELL_ACTIVATABLE, 130, wxALIGN_CENTER, wxDATAVIEW_COL_RESIZABLE);
    surat_tugas_dataViewListCtrl->AppendTextColumn("Tgl. Tugas",wxDATAVIEW_CELL_ACTIVATABLE, 100, wxALIGN_CENTER, wxDATAVIEW_COL_RESIZABLE);
    surat_tugas_dataViewListCtrl->AppendTextColumn("Keterangan",wxDATAVIEW_CELL_ACTIVATABLE, 250, wxALIGN_LEFT, wxDATAVIEW_COL_RESIZABLE);
    RefreshDataView();
}
void SuratTugasPanel::RefreshDataView(){
    if(conn.connected()){
        surat_tugas_dataViewListCtrl->DeleteAllItems();
        try{
            mysqlpp::Query qry=conn.query();
            qry<<"SELECT bs.FID, bs.nama, bs.NIK, bst.*"
                <<" FROM bsurat_tugas bst"
                <<" LEFT JOIN bstaff bs ON(bst.FID=bs.FID)"
                <<" WHERE bst.tgl >="
                        <<mysqlpp::quote<<(const_cast<char*>((const char*)start_datePicker->GetValue().FormatISODate().mb_str()))
                    <<" AND bst.tgl <="
                        <<mysqlpp::quote<<(const_cast<char*>((const char*)end_datePicker->GetValue().FormatISODate().mb_str()))
                    <<" AND bs.nama lIKE "
                        <<"'%%"
                        <<mysqlpp::escape<<(const_cast<char*>((const char*)filter_nama_textCtrl->GetValue().mb_str()))
                        <<"%%'"
                <<" ORDER BY bst.tgl DESC";
            mysqlpp::StoreQueryResult res=qry.store();
            if(res){
                wxVector<wxVariant> data;
                for(size_t i=0; i<res.num_rows(); ++i){
                    data.clear();
                    data.push_back(wxString::FromUTF8(res[i]["FID"]));
                    data.push_back(wxString::FromUTF8(res[i]["nama"]));
                    data.push_back(wxString::FromUTF8(res[i]["NIK"]));
                    data.push_back(wxString::FromUTF8(res[i]["tgl"]));
                    data.push_back(wxString::FromUTF8(res[i]["keterangan"]));
                    surat_tugas_dataViewListCtrl->AppendItem(data);
                }
            }else{
                wxString error_msg=wxString("Error saat query database surat tugas: ");
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
void SuratTugasPanel::OnHapus( wxCommandEvent& event ){
    if(surat_tugas_dataViewListCtrl->HasSelection()){
        int selected_row=surat_tugas_dataViewListCtrl->GetSelectedRow();
        if(wxMessageBox(wxString("Yakin untuk menghapus data: ").Append(surat_tugas_dataViewListCtrl->GetTextValue(selected_row, 1)),
            wxT("Konfirmasi"),
            wxICON_QUESTION | wxYES_NO, this) == wxYES)
        {
            if(conn.connected()){
                try{
                    mysqlpp::Query qry=conn.query();
                    qry<<"DELETE FROM bsurat_tugas"
                        <<" WHERE FID="<<(const_cast<char*>((const char*)surat_tugas_dataViewListCtrl->GetTextValue(selected_row, 0).mb_str()))
                            <<" AND tgl="<<mysqlpp::quote<<(const_cast<char*>((const char*)surat_tugas_dataViewListCtrl->GetTextValue(selected_row, 3).mb_str()))
                        <<" LIMIT 1";
                    if(qry.execute()){
                        RefreshDataView();
                    }else{
                        wxString error_msg=wxString("Error saat menghapus data: ");
                        error_msg.Append(qry.error());
                        wxLogError(error_msg);
                    }
                }catch(mysqlpp::Exception &e){
                    wxLogError(e.what());
                }
            }else{
                wxLogError("Database tidak terkoneksi");
            }
        }
    }else{
        wxLogError("Harap pilih baris untuk dihapus.");
    }
}
void SuratTugasPanel::OnFilterData( wxDateEvent& event ){
    RefreshDataView();
}
void SuratTugasPanel::OnFilterData( wxCommandEvent& event ){
    RefreshDataView();
}
void SuratTugasPanel::OnTambah( wxCommandEvent& event ){
    surat_tugas_dialog=new SuratTugasDialog(this);
    surat_tugas_dialog->InputMode(wxString("create"));
    surat_tugas_dialog->SetTitle("Tambah surat tugas");
    surat_tugas_dialog->Center();
    surat_tugas_dialog->ShowModal();
}
void SuratTugasPanel::OnUbah(wxCommandEvent& event){
    if(surat_tugas_dataViewListCtrl->HasSelection()){
        int selected_row=surat_tugas_dataViewListCtrl->GetSelectedRow();
        int FID=wxAtoi(surat_tugas_dataViewListCtrl->GetTextValue(selected_row,0));
        wxString tgl=surat_tugas_dataViewListCtrl->GetTextValue(selected_row,3);
        surat_tugas_dialog=new SuratTugasDialog(this);

        surat_tugas_dialog->InputMode(wxString("update"),FID,tgl);
        
        wxString title=wxString("Ubah surat tugas: ");
        title.Append(surat_tugas_dataViewListCtrl->GetTextValue(selected_row,1));
        surat_tugas_dialog->SetTitle(title);
        
        surat_tugas_dialog->SetUpdateValue(
                surat_tugas_dataViewListCtrl->GetTextValue(selected_row,0),
                surat_tugas_dataViewListCtrl->GetTextValue(selected_row,1),
                surat_tugas_dataViewListCtrl->GetTextValue(selected_row,3),
                surat_tugas_dataViewListCtrl->GetTextValue(selected_row,4)
            );
        surat_tugas_dialog->Center();
        surat_tugas_dialog->ShowModal();
    }else{
        wxLogError("Harap pilih baris untuk diubah!");
    }
}
