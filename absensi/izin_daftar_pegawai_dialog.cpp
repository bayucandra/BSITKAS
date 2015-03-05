#include "izin_daftar_pegawai_dialog.h"
#include "izin_dialog.h"

IzinDaftarPegawaiDialog::IzinDaftarPegawaiDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
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
	
	pegawai_dataViewListCtrl = new wxDataViewListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	wrapper_bSizer->Add( pegawai_dataViewListCtrl, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( wrapper_bSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	cari_textCtrl->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( IzinDaftarPegawaiDialog::OnCari ), NULL, this );
	cari_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IzinDaftarPegawaiDialog::OnCari ), NULL, this );
	this->Connect( wxID_ANY, wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED, wxDataViewEventHandler( IzinDaftarPegawaiDialog::OnPilih ) );
        //BEGIN BAYU===========
        InitDataView();
}

IzinDaftarPegawaiDialog::~IzinDaftarPegawaiDialog()
{
	// Disconnect Events
	cari_textCtrl->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( IzinDaftarPegawaiDialog::OnCari ), NULL, this );
	cari_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IzinDaftarPegawaiDialog::OnCari ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED, wxDataViewEventHandler( IzinDaftarPegawaiDialog::OnPilih ) );
	
}

void IzinDaftarPegawaiDialog::InitDataView(){
    wxDataViewListStore* pegawai_store=new wxDataViewListStore();
    pegawai_dataViewListCtrl->AssociateModel(pegawai_store);
    pegawai_store->DecRef();
    
    pegawai_dataViewListCtrl->AppendTextColumn("idpegawai",wxDATAVIEW_CELL_ACTIVATABLE,50,wxALIGN_LEFT,wxDATAVIEW_COL_HIDDEN);
    pegawai_dataViewListCtrl->AppendTextColumn("FID",wxDATAVIEW_CELL_ACTIVATABLE,70,wxALIGN_RIGHT,wxDATAVIEW_COL_RESIZABLE);
    pegawai_dataViewListCtrl->AppendTextColumn("Nama pegawai",wxDATAVIEW_CELL_ACTIVATABLE,250,wxALIGN_LEFT,wxDATAVIEW_COL_RESIZABLE);
    pegawai_dataViewListCtrl->AppendTextColumn("NIP",wxDATAVIEW_CELL_ACTIVATABLE,200,wxALIGN_CENTER,wxDATAVIEW_COL_RESIZABLE);
    pegawai_dataViewListCtrl->AppendTextColumn("Kelas/Jabatan",wxDATAVIEW_CELL_ACTIVATABLE,90,wxALIGN_LEFT,wxDATAVIEW_COL_RESIZABLE);
    pegawai_dataViewListCtrl->AppendTextColumn("Pangkat/Golongan",wxDATAVIEW_CELL_ACTIVATABLE,150,wxALIGN_LEFT,wxDATAVIEW_COL_RESIZABLE);
    
    RefreshDataView();
}
void IzinDaftarPegawaiDialog::OnCari( wxCommandEvent& event ){
    RefreshDataView();
}
void IzinDaftarPegawaiDialog::RefreshDataView(){
    if(conn.connected()){
        pegawai_dataViewListCtrl->DeleteAllItems();
        try{
            mysqlpp::Query qry=conn.query();
            qry<<"SELECT s.idbstaff, s.FID, s.nama, s.NIK, k.kelas, CONCAT(p.keterangan, ' (', p.pangkat_golongan, ')') AS pangkat_golongan"
                <<" FROM bstaff s"
                    <<" LEFT JOIN bkelas k ON(s.idbkelas = k.idbkelas)"
                    <<" LEFT JOIN bpangkat_golongan p ON(s.idbpangkat_golongan = p.idbpangkat_golongan)";
            if(cari_textCtrl->GetValue()!=wxEmptyString){
                qry<<" WHERE s.nama LIKE "
                    <<"'%%"
                    <<mysqlpp::escape<<(const_cast<char*>((const char*)cari_textCtrl->GetValue().mb_str()))
                    <<"%%'";
            }
            qry<<" ORDER BY s.nama ASC";
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
        wxLogError("Error, database tidak terkoneksi.");
    }
}
void IzinDaftarPegawaiDialog::OnPilih( wxDataViewEvent& event ){
    Pilih();
}
void IzinDaftarPegawaiDialog::Pilih(){
    if(pegawai_dataViewListCtrl->HasSelection()){
        int selected_row=pegawai_dataViewListCtrl->GetSelectedRow();
        ((IzinDialog*)GetParent())->PilihPegawai(
                pegawai_dataViewListCtrl->GetTextValue(selected_row, 1),
                pegawai_dataViewListCtrl->GetTextValue(selected_row, 2)
            );
        Close();
    }
}
