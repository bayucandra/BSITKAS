#include "izin_panel.h"

IzinPanel::IzinPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
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
	
	izin_dataViewListCtrl = new wxDataViewListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxDV_HORIZ_RULES|wxDV_ROW_LINES );
	wrapper_bSizer->Add( izin_dataViewListCtrl, 1, wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
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
	
	m_textCtrl14 = new wxTextCtrl( footer_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	m_textCtrl14->SetMinSize( wxSize( 150,-1 ) );
	
	footer_bSizer->Add( m_textCtrl14, 0, wxALL|wxEXPAND, 5 );
	
	
	footer_panel->SetSizer( footer_bSizer );
	footer_panel->Layout();
	footer_bSizer->Fit( footer_panel );
	wrapper_bSizer->Add( footer_panel, 0, wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 5 );
	
	
	this->SetSizer( wrapper_bSizer );
	this->Layout();
	wrapper_bSizer->Fit( this );
	
	// Connect Events
	tambah_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IzinPanel::OnTambah ), NULL, this );
	ubah_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IzinPanel::OnUbah ), NULL, this );
	hapus_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IzinPanel::OnHapus ), NULL, this );
	start_datePicker->Connect( wxEVT_DATE_CHANGED, wxDateEventHandler( IzinPanel::OnFilterData ), NULL, this );
	end_datePicker->Connect( wxEVT_DATE_CHANGED, wxDateEventHandler( IzinPanel::OnFilterData ), NULL, this );
	m_textCtrl14->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( IzinPanel::OnFilterData ), NULL, this );
        
        //BEGIN BAYU================
        InitDataView();
        InitDateRange();
}

IzinPanel::~IzinPanel()
{
	// Disconnect Events
	tambah_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IzinPanel::OnTambah ), NULL, this );
	ubah_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IzinPanel::OnUbah ), NULL, this );
	hapus_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IzinPanel::OnHapus ), NULL, this );
	start_datePicker->Disconnect( wxEVT_DATE_CHANGED, wxDateEventHandler( IzinPanel::OnFilterData ), NULL, this );
	end_datePicker->Disconnect( wxEVT_DATE_CHANGED, wxDateEventHandler( IzinPanel::OnFilterData ), NULL, this );
	m_textCtrl14->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( IzinPanel::OnFilterData ), NULL, this );
	
}
void IzinPanel::InitDataView(){
    wxDataViewListStore* izin_store=new wxDataViewListStore();
    izin_dataViewListCtrl->AssociateModel(izin_store);
    izin_store->DecRef();
    
    izin_dataViewListCtrl->AppendTextColumn("Nama",wxDATAVIEW_CELL_ACTIVATABLE, 150, wxALIGN_LEFT, wxDATAVIEW_COL_RESIZABLE);
    izin_dataViewListCtrl->AppendTextColumn("NIK",wxDATAVIEW_CELL_ACTIVATABLE, 130, wxALIGN_CENTER, wxDATAVIEW_COL_RESIZABLE);
    izin_dataViewListCtrl->AppendTextColumn("Tgl. Izin",wxDATAVIEW_CELL_ACTIVATABLE, 100, wxALIGN_CENTER, wxDATAVIEW_COL_RESIZABLE);
    izin_dataViewListCtrl->AppendTextColumn("Keterangan",wxDATAVIEW_CELL_ACTIVATABLE, 250, wxALIGN_LEFT, wxDATAVIEW_COL_RESIZABLE);
    RefreshDataView();
}
void IzinPanel::RefreshDataView(){
    if(conn.connected()){
        try{
            mysqlpp::Query qry=conn.query();
            qry<<"SELECT bs.nama, bs.NIK, bi.*"
                <<" FROM bizin bi"
                <<" LEFT JOIN bstaff bs ON(bi.FID=bs.FID)";
            mysqlpp::StoreQueryResult res=qry.store();
            if(res){
                wxVector<wxVariant> data;
                for(size_t i=0; i<res.num_rows(); ++i){
                    data.clear();
                    data.push_back(wxString::FromUTF8(res[i]["nama"]));
                    data.push_back(wxString::FromUTF8(res[i]["NIK"]));
                    data.push_back(wxString::FromUTF8(res[i]["tgl"]));
                    data.push_back(wxString::FromUTF8(res[i]["keterangan"]));
                    izin_dataViewListCtrl->AppendItem(data);
                }
            }else{
                wxString error_msg=wxString("Error saat query database izin: ");
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
void IzinPanel::InitDateRange(){
    wxDateTime date_today=wxDateTime::Today();
    
    wxDateTime last_month_day=wxDateTime::;
    end_datePicker->SetValue(last_month_day);
}
