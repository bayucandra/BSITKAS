#include "pegawai_panel.h"
#include "pegawai_salin_dialog.cpp"

PegawaiPanel::PegawaiPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* wrapperSizer;
	wrapperSizer = new wxBoxSizer( wxVERTICAL );
	
	pegawai_splitter = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	pegawai_splitter->Connect( wxEVT_IDLE, wxIdleEventHandler( PegawaiPanel::pegawai_splitterOnIdle ), NULL, this );
	pegawai_splitter->SetMinimumPaneSize( 100 );
	
	pegawai_splitter->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	
	pegawai_panel = new wxPanel( pegawai_splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	pegawai_panel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INACTIVECAPTION ) );
	wxBoxSizer* pegawai_bSizer;
	pegawai_bSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* button_bSizer;
	button_bSizer = new wxBoxSizer( wxHORIZONTAL );
	
	ubah_button = new wxButton( pegawai_panel, wxID_ANY, wxT("Ubah"), wxDefaultPosition, wxDefaultSize, 0 );
	button_bSizer->Add( ubah_button, 0, wxALL, 5 );
	
	hapus_button = new wxButton( pegawai_panel, wxID_ANY, wxT("Hapus"), wxDefaultPosition, wxDefaultSize, 0 );
	button_bSizer->Add( hapus_button, 0, wxALL, 5 );
	
	
	pegawai_bSizer->Add( button_bSizer, 0, wxEXPAND, 5 );
	
	pegawai_dataViewListCtrl = new wxDataViewListCtrl( pegawai_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxDV_HORIZ_RULES|wxDV_ROW_LINES );
	pegawai_bSizer->Add( pegawai_dataViewListCtrl, 1, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	
	pegawai_panel->SetSizer( pegawai_bSizer );
	pegawai_panel->Layout();
	pegawai_bSizer->Fit( pegawai_panel );
	pegawai_data_lama_panel = new wxPanel( pegawai_splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
        pegawai_data_lama_panel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INACTIVECAPTION ) );
	wxBoxSizer* pegawai_data_lama_bSizer;
	pegawai_data_lama_bSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* button2_bSizer;
	button2_bSizer = new wxBoxSizer( wxHORIZONTAL );
	
	salin_button = new wxButton( pegawai_data_lama_panel, wxID_ANY, wxT("Salin"), wxDefaultPosition, wxDefaultSize, 0 );
	button2_bSizer->Add( salin_button, 0, wxALL, 5 );
	
	
	pegawai_data_lama_bSizer->Add( button2_bSizer, 0, wxEXPAND, 5 );
	
	pegawai_data_lama_dataViewListCtrl = new wxDataViewListCtrl( pegawai_data_lama_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxDV_HORIZ_RULES|wxDV_ROW_LINES );
	pegawai_data_lama_bSizer->Add( pegawai_data_lama_dataViewListCtrl, 1, wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	
	pegawai_data_lama_panel->SetSizer( pegawai_data_lama_bSizer );
	pegawai_data_lama_panel->Layout();
	pegawai_data_lama_bSizer->Fit( pegawai_data_lama_panel );
	pegawai_splitter->SplitHorizontally( pegawai_panel, pegawai_data_lama_panel, 0 );
	wrapperSizer->Add( pegawai_splitter, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( wrapperSizer );
	this->Layout();
	wrapperSizer->Fit( this );
	
	// Connect Events
	ubah_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PegawaiPanel::OnUbah ), NULL, this );
	hapus_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PegawaiPanel::OnHapus ), NULL, this );
	salin_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PegawaiPanel::OnSalin ), NULL, this );
        
        //BEGIN BAYU=============
        InitDataView();
}

PegawaiPanel::~PegawaiPanel()
{
	// Disconnect Events
	ubah_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PegawaiPanel::OnUbah ), NULL, this );
	hapus_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PegawaiPanel::OnHapus ), NULL, this );
	salin_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PegawaiPanel::OnSalin ), NULL, this );
	
}
void PegawaiPanel::InitDataView(){
    wxDataViewListStore* pegawai_store=new wxDataViewListStore();
    pegawai_dataViewListCtrl->AssociateModel(pegawai_store);
    pegawai_store->DecRef();
    
    pegawai_dataViewListCtrl->AppendTextColumn("idpegawai",wxDATAVIEW_CELL_ACTIVATABLE,50,wxALIGN_LEFT,wxDATAVIEW_COL_HIDDEN);
    pegawai_dataViewListCtrl->AppendTextColumn("FID",wxDATAVIEW_CELL_ACTIVATABLE,70,wxALIGN_RIGHT,wxDATAVIEW_COL_RESIZABLE);
    pegawai_dataViewListCtrl->AppendTextColumn("Nama pegawai",wxDATAVIEW_CELL_ACTIVATABLE,250,wxALIGN_LEFT,wxDATAVIEW_COL_RESIZABLE);
    pegawai_dataViewListCtrl->AppendTextColumn("NIK",wxDATAVIEW_CELL_ACTIVATABLE,200,wxALIGN_CENTER,wxDATAVIEW_COL_RESIZABLE);
    pegawai_dataViewListCtrl->AppendTextColumn("Kelas/Jabatan",wxDATAVIEW_CELL_ACTIVATABLE,90,wxALIGN_LEFT,wxDATAVIEW_COL_RESIZABLE);
    pegawai_dataViewListCtrl->AppendTextColumn("Pangkat/Golongan",wxDATAVIEW_CELL_ACTIVATABLE,150,wxALIGN_LEFT,wxDATAVIEW_COL_RESIZABLE);
    
    RefreshDataView();
    InitDataLamaView();
}
void PegawaiPanel::RefreshDataView(){
    if(conn.connected()){
        pegawai_dataViewListCtrl->DeleteAllItems();
        try{
            mysqlpp::Query qry=conn.query();
            qry<<"SELECT s.idbstaff, s.FID, s.nama, s.NIK, k.kelas, p.pangkat_golongan"
                <<" FROM bstaff s"
                    <<" LEFT JOIN bkelas k ON(s.idbkelas = k.idbkelas)"
                    <<" LEFT JOIN bpangkat_golongan p ON(s.idbpangkat_golongan = p.idbpangkat_golongan)";
            mysqlpp::StoreQueryResult res=qry.store();
            if(res){
                wxVector<wxVariant> data;
                for(size_t i=0; i<res.num_rows(); ++i){
                    data.clear();
                    data.push_back(wxString::FromUTF8(res[i]["idbstaff"]));
                    data.push_back(wxString::FromUTF8(res[i]["FID"]));
                    data.push_back(wxString::FromUTF8(res[i]["nama"]));
                    data.push_back(wxString::FromUTF8(res[i]["NIK"]));
                    data.push_back(wxString::FromUTF8(res[i]["kelas"]));
                    data.push_back(wxString::FromUTF8(res[i]["pangkat_golongan"]));
                    pegawai_dataViewListCtrl->AppendItem(data);
                }
            }else{
                wxString error_msg=wxString("Error saat query tabel pegawai: ");
                error_msg.Append(qry.error());
                wxLogError(error_msg);
            }
        }catch(mysqlpp::Exception &e){
            wxLogError(e.what());
        }
    }else{
        wxLogError("Error, Database tidak terkoneksi");
    }
}
void PegawaiPanel::InitDataLamaView(){
    wxDataViewListStore* pegawai_data_lama_store=new wxDataViewListStore();
    pegawai_data_lama_dataViewListCtrl->AssociateModel(pegawai_data_lama_store);
    pegawai_data_lama_store->DecRef();
    
    pegawai_data_lama_dataViewListCtrl->AppendTextColumn("FID",wxDATAVIEW_CELL_ACTIVATABLE,70,wxALIGN_RIGHT,wxDATAVIEW_COL_RESIZABLE);
    pegawai_data_lama_dataViewListCtrl->AppendTextColumn("Nama",wxDATAVIEW_CELL_ACTIVATABLE,250,wxALIGN_LEFT,wxDATAVIEW_COL_RESIZABLE);
    pegawai_data_lama_dataViewListCtrl->AppendTextColumn("NIK",wxDATAVIEW_CELL_ACTIVATABLE,200,wxALIGN_RIGHT,wxDATAVIEW_COL_RESIZABLE);
    RefreshDataLamaView();
}
void PegawaiPanel::RefreshDataLamaView(){
    if(conn.connected()){
        pegawai_data_lama_dataViewListCtrl->DeleteAllItems();
        try{
            mysqlpp::Query qry=conn.query();
            qry<<"SELECT so.FID, so.Nama, so.NIK"
                <<" FROM hr_staff_info so"
                    <<" LEFT JOIN bstaff sn ON(so.FID=sn.FID)"
                <<" WHERE ISNULL(sn.FID)";
            mysqlpp::StoreQueryResult res=qry.store();
            if(res){
                wxVector<wxVariant> data;
                for(size_t i=0; i<res.num_rows(); ++i){
                    data.clear();
                    data.push_back(wxString::FromUTF8(res[i]["FID"]));
                    data.push_back(wxString::FromUTF8(res[i]["Nama"]));
                    data.push_back(wxString::FromUTF8(res[i]["NIK"]));
                    pegawai_data_lama_dataViewListCtrl->AppendItem(data);
                }
            }else{
                wxString error_msg=wxString("Error saat query tabel pegawai lama: ");
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
void PegawaiPanel::OnSalin( wxCommandEvent& event ){
    if(pegawai_data_lama_dataViewListCtrl->HasSelection()){
        int selected_row=pegawai_data_lama_dataViewListCtrl->GetSelectedRow();
        pegawai_salin_dialog=new PegawaiSalinDialog(this);
        pegawai_salin_dialog->InputMode(wxString("create"));
        pegawai_salin_dialog->SalinDataLama(
            pegawai_data_lama_dataViewListCtrl->GetTextValue(selected_row,0),
            pegawai_data_lama_dataViewListCtrl->GetTextValue(selected_row,1),
            pegawai_data_lama_dataViewListCtrl->GetTextValue(selected_row,2)
        );
        pegawai_salin_dialog->ShowModal();
    }else{
        wxLogError("Harap pilih baris data lama pegawai untuk disalin.");
    }
}
void PegawaiPanel::OnUbah( wxCommandEvent& event ){
    if(pegawai_dataViewListCtrl->HasSelection()){
        int selected_row = pegawai_dataViewListCtrl->GetSelectedRow();
        wxString idbstaff=pegawai_dataViewListCtrl->GetTextValue(selected_row,0);
        pegawai_salin_dialog = new PegawaiSalinDialog(this);
        pegawai_salin_dialog->SetTitle(wxT("Ubah data pegawai"));
        pegawai_salin_dialog->InputMode("update", idbstaff);
        pegawai_salin_dialog->SetUpdateValue();
        pegawai_salin_dialog->ShowModal();
    }else{
        wxLogError("Harap pilih baris data pegawai untuk diubah");
    }
}
void PegawaiPanel::OnHapus( wxCommandEvent& event ){
    if(pegawai_dataViewListCtrl->HasSelection()){
        int selected_row=pegawai_dataViewListCtrl->GetSelectedRow();
        if(wxMessageBox(wxString("Yakin untuk menghapus data pegawai terpilih: ")<<pegawai_dataViewListCtrl->GetTextValue(selected_row, 2)<<"?",
             wxT("Konfirmasi"),
                wxICON_QUESTION | wxYES_NO, this) == wxYES
        ){
            if(conn.connected()){
                try{
                    mysqlpp::Query qry=conn.query();
                    qry<<"DELETE FROM bstaff"
                        <<" WHERE idbstaff="<<(const_cast<char*>((const char*)pegawai_dataViewListCtrl->GetTextValue(selected_row,0).mb_str()))
                        <<" LIMIT 1";
                    if(qry.execute()){
                        RefreshDataView();
                        RefreshDataLamaView();
                    }else{
                        wxString error_msg = wxString("Error, saat menghapus data: ");
                        error_msg<<qry.error();
                        wxLogError(error_msg);
                    }
                }catch(mysqlpp::Exception &e){
                    wxLogError(e.what());
                }
            }else{
                wxLogError("Error, database tidak terkoneksi.");
            }
        }
    }else{
        wxLogError("Error, harap pilih baris pegawai untuk dihapus.");
    }
}
