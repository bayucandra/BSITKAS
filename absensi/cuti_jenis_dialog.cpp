#include "cuti_jenis_dialog.h"
#include "cuti_dialog.h"
CutiJenisDialog::CutiJenisDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* wrapper_bSizer;
	wrapper_bSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* cari_bSizer;
	cari_bSizer = new wxBoxSizer( wxHORIZONTAL );
	
	cari_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	cari_bSizer->Add( cari_textCtrl, 1, wxALL|wxEXPAND, 5 );
	
	cari_button = new wxButton( this, wxID_ANY, wxT("Cari"), wxDefaultPosition, wxDefaultSize, 0 );
	cari_bSizer->Add( cari_button, 0, wxALL, 5 );
	
	
	wrapper_bSizer->Add( cari_bSizer, 0, wxEXPAND, 5 );
	
	cuti_jenis_dataViewListCtrl = new wxDataViewListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	wrapper_bSizer->Add( cuti_jenis_dataViewListCtrl, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( wrapper_bSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	cari_textCtrl->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( CutiJenisDialog::OnCari ), NULL, this );
	cari_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CutiJenisDialog::OnCari ), NULL, this );
	this->Connect( wxID_ANY, wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED, wxDataViewEventHandler( CutiJenisDialog::OnPilih ) );
        //BEGIN BAYU===========
        InitDataView();
}

CutiJenisDialog::~CutiJenisDialog()
{
	// Disconnect Events
	cari_textCtrl->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( CutiJenisDialog::OnCari ), NULL, this );
	cari_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CutiJenisDialog::OnCari ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED, wxDataViewEventHandler( CutiJenisDialog::OnPilih ) );
	
}

void CutiJenisDialog::InitDataView(){
    wxDataViewListStore* pegawai_store=new wxDataViewListStore();
    cuti_jenis_dataViewListCtrl->AssociateModel(pegawai_store);
    pegawai_store->DecRef();
    
    cuti_jenis_dataViewListCtrl->AppendTextColumn("idbcuti_jenis",wxDATAVIEW_CELL_ACTIVATABLE,50,wxALIGN_LEFT,wxDATAVIEW_COL_HIDDEN);
    cuti_jenis_dataViewListCtrl->AppendTextColumn("Jenis Cuti",wxDATAVIEW_CELL_ACTIVATABLE,300,wxALIGN_LEFT,wxDATAVIEW_COL_RESIZABLE);
    cuti_jenis_dataViewListCtrl->AppendTextColumn("persentasi_tunjangan",wxDATAVIEW_CELL_ACTIVATABLE,50,wxALIGN_LEFT,wxDATAVIEW_COL_HIDDEN);
    
    RefreshDataView();
}
void CutiJenisDialog::OnCari( wxCommandEvent& event ){
    RefreshDataView();
}
void CutiJenisDialog::RefreshDataView(){
    if(conn.connected()){
        cuti_jenis_dataViewListCtrl->DeleteAllItems();
        try{
            mysqlpp::Query qry=conn.query();
            qry<<"SELECT *"
                <<" FROM bcuti_jenis";
            if(cari_textCtrl->GetValue()!=wxEmptyString){
                qry<<" WHERE jenis LIKE "
                    <<"'%%"
                    <<mysqlpp::escape<<(const_cast<char*>((const char*)cari_textCtrl->GetValue().mb_str()))
                    <<"%%'";
            }
            mysqlpp::StoreQueryResult res=qry.store();
            if(res){
                wxVector<wxVariant> data;
                for(size_t i=0; i<res.num_rows(); ++i){
                    data.clear();
                    data.push_back(wxString::FromUTF8(res[i]["idbcuti_jenis"]));
                    data.push_back(wxString::FromUTF8(res[i]["jenis"]));
                    data.push_back(wxString::FromUTF8(res[i]["persentasi_tunjangan"]));
                    cuti_jenis_dataViewListCtrl->AppendItem(data);
                }
            }else{
                wxString error_msg=wxString("Error saat query tabel cuti: ");
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
void CutiJenisDialog::OnPilih( wxDataViewEvent& event ){
    Pilih();
}
void CutiJenisDialog::Pilih(){
    if(cuti_jenis_dataViewListCtrl->HasSelection()){
        int selected_row=cuti_jenis_dataViewListCtrl->GetSelectedRow();
        ((CutiDialog*)GetParent())->PilihJenisCuti(
                cuti_jenis_dataViewListCtrl->GetTextValue(selected_row, 0),
                cuti_jenis_dataViewListCtrl->GetTextValue(selected_row, 1)
            );
        Close();
    }
}
