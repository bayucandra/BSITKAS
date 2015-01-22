/* 
 * File:   kelas_panel.cpp
 * Author: bayucandra@gmail.com
 *
 * Created on January 18, 2015, 2:56 PM
 */

#include "kelas_panel.h"
#include "kelas_input_dialog.cpp"

wxBEGIN_EVENT_TABLE(KelasPanel, wxPanel)
    EVT_BUTTON(ID_tambah_kelas, KelasPanel::OnInputKelas)
    EVT_BUTTON(ID_ubah_kelas, KelasPanel::OnUbahKelas)
    EVT_BUTTON(ID_hapus_kelas, KelasPanel::OnHapusKelas)
wxEND_EVENT_TABLE()
KelasPanel::KelasPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* wrapperSizer;
	wrapperSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* button_bSizer;
	button_bSizer = new wxBoxSizer( wxHORIZONTAL );
	
	tambah_kelas_button = new wxButton( this, ID_tambah_kelas, wxT("Tambah"), wxDefaultPosition, wxDefaultSize, 0 );
	button_bSizer->Add( tambah_kelas_button, 0, wxALL, 5 );
	
	ubah_kelas_button = new wxButton( this, ID_ubah_kelas, wxT("Ubah"), wxDefaultPosition, wxDefaultSize, 0 );
	button_bSizer->Add( ubah_kelas_button, 0, wxALL, 5 );
	
	hapus_kelas_button = new wxButton( this, ID_hapus_kelas, wxT("Hapus"), wxDefaultPosition, wxDefaultSize, 0 );
	button_bSizer->Add( hapus_kelas_button, 0, wxALL, 5 );
	
	wrapperSizer->Add( button_bSizer, 0, wxEXPAND, 5 );
	
	kelas_dataViewListCtrl = new wxDataViewListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxDV_HORIZ_RULES|wxDV_ROW_LINES );

	wrapperSizer->Add( kelas_dataViewListCtrl, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( wrapperSizer );
	this->Layout();
        //BEGIN BAYU======
        InitDataView();
}

KelasPanel::~KelasPanel()
{
}

void KelasPanel::InitDataView(){
    wxDataViewListStore* kelas_store=new wxDataViewListStore();
    kelas_dataViewListCtrl->AssociateModel(kelas_store);
    kelas_store->DecRef();

//    wxDataViewTextRenderer *tr0 = new wxDataViewTextRenderer( "string", wxDATAVIEW_CELL_INERT );
//    wxDataViewColumn *column0 = new wxDataViewColumn( "idbkelas", tr0, 0, 50, wxALIGN_LEFT, wxDATAVIEW_COL_HIDDEN );
    kelas_dataViewListCtrl->AppendTextColumn("idbkelas",wxDATAVIEW_CELL_ACTIVATABLE,50,wxALIGN_LEFT,wxDATAVIEW_COL_HIDDEN);
    kelas_dataViewListCtrl->AppendTextColumn("Kelas",wxDATAVIEW_CELL_ACTIVATABLE,100,wxALIGN_LEFT,wxDATAVIEW_COL_RESIZABLE);
    kelas_dataViewListCtrl->AppendTextColumn("Keterangan",wxDATAVIEW_CELL_ACTIVATABLE,300,wxALIGN_LEFT,wxDATAVIEW_COL_RESIZABLE);
    kelas_dataViewListCtrl->AppendTextColumn("Tunjangan perbulan",wxDATAVIEW_CELL_ACTIVATABLE,150,wxALIGN_RIGHT,wxDATAVIEW_COL_RESIZABLE);
    kelas_dataViewListCtrl->AppendTextColumn("Tunjangan perbulan RAW",wxDATAVIEW_CELL_ACTIVATABLE,150,wxALIGN_RIGHT,wxDATAVIEW_COL_HIDDEN);
    RefreshDataView();
//    wxVector<wxVariant> data;
//    for(unsigned int i=0;i<10;i++){
//        data.clear();
//        data.push_back(wxString::Format("row %d",i));
//        kelas_dataViewListCtrl->AppendItem(data);
//    }
}
void KelasPanel::RefreshDataView(){
    if(conn.connected()){
        kelas_dataViewListCtrl->DeleteAllItems();
        try{
            mysqlpp::Query qry=conn.query("SELECT *, CONCAT('Rp ',FORMAT(tunjangan_perbulan,0,'id_ID'),',-') AS tunjangan_perbulan_rp FROM bkelas");
            mysqlpp::StoreQueryResult res=qry.store();
            if(res){
                wxVector<wxVariant> data;
                for(size_t i=0; i< res.num_rows(); ++i){
                    data.clear();
                    data.push_back(wxString::FromUTF8(res[i]["idbkelas"]));
                    data.push_back(wxString::FromUTF8(res[i]["kelas"]));
                    data.push_back(wxString::FromUTF8(res[i]["keterangan"]));
                    data.push_back(wxString::FromUTF8(res[i]["tunjangan_perbulan_rp"]));
                    data.push_back(wxString::FromUTF8(res[i]["tunjangan_perbulan"]));
                    kelas_dataViewListCtrl->AppendItem(data);
                }
            }else{
                wxString error_msg=wxString("Error sata query tabel 'kelas': ");
                error_msg.Append(qry.error());
                wxLogError(error_msg);
            }
        }catch(mysqlpp::Exception &e){
            wxLogError(e.what());
        }
    }else{
        wxLogError("MySQL server tidak terkoneksi");
    }
}
void KelasPanel::OnInputKelas(wxCommandEvent& event){
    kelas_input_dialog=new KelasInputDialog(this);
    kelas_input_dialog->InputMode("create");
    kelas_input_dialog->Center();
    kelas_input_dialog->SetTitle(wxT("Tambah Kelas"));
    kelas_input_dialog->ShowModal();
}
void KelasPanel::OnUbahKelas(wxCommandEvent& event){
    if(kelas_dataViewListCtrl->HasSelection()){
        int selected_row=kelas_dataViewListCtrl->GetSelectedRow();
        int idbkelas=wxAtoi(kelas_dataViewListCtrl->GetTextValue(selected_row,0));
        kelas_input_dialog=new KelasInputDialog(this);
        kelas_input_dialog->InputMode("update", idbkelas);
        
        wxString title=wxString("Ubah kelas: ");
        title.Append(kelas_dataViewListCtrl->GetTextValue(selected_row,1));
        kelas_input_dialog->SetTitle(title);
        kelas_input_dialog->SetUpdateValue(kelas_dataViewListCtrl->GetTextValue(selected_row,1),
                kelas_dataViewListCtrl->GetTextValue(selected_row,2),
                kelas_dataViewListCtrl->GetTextValue(selected_row,4)
            );
        
        kelas_input_dialog->Center();
        kelas_input_dialog->ShowModal();
        
    }else{
        wxLogError("Harap pilih baris untuk diubah!");
    }
}
void KelasPanel::OnHapusKelas(wxCommandEvent& event){
    if(kelas_dataViewListCtrl->HasSelection()){
        int selected_row=kelas_dataViewListCtrl->GetSelectedRow();
        int idbkelas=wxAtoi(kelas_dataViewListCtrl->GetTextValue(selected_row,0));
        if(wxMessageBox(
            wxString("Yakin untuk menghapus pangkat/golongan: ").Append(kelas_dataViewListCtrl->GetTextValue(selected_row, 1)),
            wxT("Konfirmasi"),
            wxICON_QUESTION | wxYES_NO, this) == wxYES )
        {
            try{
                if(conn.connected()){
                    mysqlpp::Query qry=conn.query();
                    qry<<"DELETE FROM bkelas WHERE idbkelas="<<idbkelas<<" LIMIT 1";
                    if(qry.execute()){
                        RefreshDataView();
                    }else{
                        wxString error_msg=wxString("Error saat menghapus data:");
                        error_msg.Append(qry.error());
                        wxLogError(error_msg);
                    }
                }else{
                    wxLogError("Error, database tidak terkoneksi");
                }
            }catch(mysqlpp::Exception &e){
                wxLogError(e.what());
            }
        }
    }else{
        wxLogError("Harap pilih kelas untuk dihapus.");
    }
}