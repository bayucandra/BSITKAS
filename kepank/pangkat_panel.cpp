/* 
 * File:   pangkat_panel.cpp
 * Author: bayucandra@gmail.com
 *
 * Created on January 19, 2015, 8:23 PM
 */

#include "pangkat_panel.h"
#include "pangkat_input_dialog.cpp"


PangkatPanel::PangkatPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* wrapperSizer;
	wrapperSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* button_bSizer;
	button_bSizer = new wxBoxSizer( wxHORIZONTAL );
	
	tambah_button = new wxButton( this, ID_tambah_pangkat, wxT("Tambah"), wxDefaultPosition, wxDefaultSize, 0 );
	button_bSizer->Add( tambah_button, 0, wxALL, 5 );
	
	ubah_button = new wxButton( this, ID_ubah_pangkat, wxT("Ubah"), wxDefaultPosition, wxDefaultSize, 0 );
	button_bSizer->Add( ubah_button, 0, wxALL, 5 );
	
	hapus_button = new wxButton( this, ID_hapus_pangkat, wxT("Hapus"), wxDefaultPosition, wxDefaultSize, 0 );
	button_bSizer->Add( hapus_button, 0, wxALL, 5 );
	
	
	wrapperSizer->Add( button_bSizer, 0, wxEXPAND, 5 );
	
	pangkat_dataViewListCtrl = new wxDataViewListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxDV_HORIZ_RULES|wxDV_ROW_LINES );
	wrapperSizer->Add( pangkat_dataViewListCtrl, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( wrapperSizer );
	this->Layout();
	
	// Connect Events
	tambah_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PangkatPanel::OnTambahPangkat ), NULL, this );
	ubah_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PangkatPanel::OnUbahPangkat ), NULL, this );
	hapus_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PangkatPanel::OnHapusPangkat ), NULL, this );
        
        //BEGIN BAYU============
        InitDataView();
}

PangkatPanel::~PangkatPanel()
{
	// Disconnect Events
	tambah_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PangkatPanel::OnTambahPangkat ), NULL, this );
	ubah_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PangkatPanel::OnUbahPangkat ), NULL, this );
	hapus_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PangkatPanel::OnHapusPangkat ), NULL, this );
	
}

void PangkatPanel::InitDataView(){
    wxDataViewListStore* pangkat_model=new wxDataViewListStore();
    pangkat_dataViewListCtrl->AssociateModel(pangkat_model);
    pangkat_model->DecRef();
    
    wxDataViewTextRenderer *tr0= new wxDataViewTextRenderer("string", wxDATAVIEW_CELL_INERT);
    wxDataViewColumn *column0= new wxDataViewColumn("idbpangkat_golongan", tr0, 0, 50, wxALIGN_LEFT, wxDATAVIEW_COL_HIDDEN);
    pangkat_dataViewListCtrl->AppendColumn(column0);
    pangkat_dataViewListCtrl->AppendTextColumn("Pangkat / Golongan", wxDATAVIEW_CELL_ACTIVATABLE, 120, wxALIGN_LEFT, wxDATAVIEW_COL_RESIZABLE);
    pangkat_dataViewListCtrl->AppendTextColumn("Keterangan", wxDATAVIEW_CELL_ACTIVATABLE, 300, wxALIGN_LEFT, wxDATAVIEW_COL_RESIZABLE);
    pangkat_dataViewListCtrl->AppendTextColumn("Uang makan perhari", wxDATAVIEW_CELL_ACTIVATABLE, 150, wxALIGN_RIGHT, wxDATAVIEW_COL_RESIZABLE);
    pangkat_dataViewListCtrl->AppendTextColumn("Uang makan perhari RAW", wxDATAVIEW_CELL_ACTIVATABLE,50, wxALIGN_RIGHT, wxDATAVIEW_COL_HIDDEN);
    RefreshDataView();
}
void PangkatPanel::RefreshDataView(){
    if(conn.connected()){
        pangkat_dataViewListCtrl->DeleteAllItems();
        try{
            mysqlpp::Query qry=conn.query("SELECT *, CONCAT('Rp ',FORMAT(uang_makan, 0, 'id_ID'),',-') AS uang_makan_rp FROM bpangkat_golongan");
            mysqlpp::StoreQueryResult res=qry.store();
            if(res){
                wxVector<wxVariant> data;
                for(size_t i=0; i<res.num_rows(); i++){
                    data.clear();
                    data.push_back(wxString::FromUTF8(res[i]["idbpangkat_golongan"]));
                    data.push_back(wxString::FromUTF8(res[i]["pangkat_golongan"]));
                    data.push_back(wxString::FromUTF8(res[i]["keterangan"]));
                    data.push_back(wxString::FromUTF8(res[i]["uang_makan_rp"]));
                    data.push_back(wxString::FromUTF8(res[i]["uang_makan"]));
                    pangkat_dataViewListCtrl->AppendItem(data);
                }
            }else{
                wxString error=wxString("Ada error saat query database pangkat/golongan");
            }
        }catch(mysqlpp::Exception &e){
            wxLogError(e.what());
        }
    }
}
void PangkatPanel::OnTambahPangkat(wxCommandEvent& event){
    pangkat_input_dialog=new PangkatInputDialog(this);
    pangkat_input_dialog->InputMode(wxString("create"));
    pangkat_input_dialog->Center();
    pangkat_input_dialog->SetTitle("Tambah Pangkat/Golongan");
    pangkat_input_dialog->ShowModal();
}
void PangkatPanel::OnUbahPangkat( wxCommandEvent& event ){
    if(pangkat_dataViewListCtrl->HasSelection()){
        int selected_row=pangkat_dataViewListCtrl->GetSelectedRow();
        int idbpangkat_golongan=wxAtoi(pangkat_dataViewListCtrl->GetTextValue(selected_row,0));
        
        pangkat_input_dialog=new PangkatInputDialog(this);
        pangkat_input_dialog->InputMode(wxString("update"), idbpangkat_golongan);
        
        wxString title=wxString("Ubah pangkat/golongan: ");
        title.Append(pangkat_dataViewListCtrl->GetTextValue(selected_row,1));
        pangkat_input_dialog->SetTitle(title);
        pangkat_input_dialog->SetUpdateValue(pangkat_dataViewListCtrl->GetTextValue(selected_row,1),
                pangkat_dataViewListCtrl->GetTextValue(selected_row,2),
                pangkat_dataViewListCtrl->GetTextValue(selected_row,4)
        );
        
        pangkat_input_dialog->Center();
        pangkat_input_dialog->ShowModal();
    }else{
        wxLogError("Harap pilih baris pangkat untuk diubah!");
    }
}
void PangkatPanel::OnHapusPangkat( wxCommandEvent& event ){
    if(pangkat_dataViewListCtrl->HasSelection()){
        int selected_row=pangkat_dataViewListCtrl->GetSelectedRow();
        int idbpangkat_golongan=wxAtoi(pangkat_dataViewListCtrl->GetTextValue(selected_row, 0));

        if(wxMessageBox(
                wxString("Yakin untuk menghapus pangkat/golongan: ").Append(pangkat_dataViewListCtrl->GetTextValue(selected_row, 1)),
                wxT("Konfirmasi"),
                wxICON_QUESTION | wxYES_NO, this) == wxYES )
        {
            try{
                if(conn.connected()){
                    mysqlpp::Query qry=conn.query();
                    qry<<"DELETE FROM bpangkat_golongan WHERE idbpangkat_golongan="<<idbpangkat_golongan<<" LIMIT 1";
                    if(qry.execute()){
                        RefreshDataView();
                    }else{
                        wxString error_msg=wxString("Error saat menghapus data: ");
                        error_msg.Append(qry.error());
                        wxLogError(error_msg);
                    }
                }else{
                    wxLogError("Database tidak terkoneksi");
                }
            }catch(mysqlpp::Exception &e){
                wxLogError(e.what());
            }
        }
    }else{
        wxLogError("Harap pilih baris untuk dihapus!");
    }
}