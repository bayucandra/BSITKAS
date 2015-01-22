/* 
 * File:   absensi_panel.cpp
 * Author: bayucandra@gmail.com
 *
 * Created on January 22, 2015, 9:21 PM
 */

#include "absensi_panel.h"

AbsensiPanel::AbsensiPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
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
	
	absensi_dataViewListCtrl = new wxDataViewListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	wrapper_bSizer->Add( absensi_dataViewListCtrl, 1, wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	m_panel4 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	m_panel4->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVEBORDER ) );
	
	wxBoxSizer* footer_bSizer;
	footer_bSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText20 = new wxStaticText( m_panel4, wxID_ANY, wxT("Tampilkan Dari"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	footer_bSizer->Add( m_staticText20, 0, wxALL, 5 );
	
	m_datePicker1 = new wxDatePickerCtrl( m_panel4, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DROPDOWN );
	footer_bSizer->Add( m_datePicker1, 0, wxALL, 5 );
	
	m_staticText21 = new wxStaticText( m_panel4, wxID_ANY, wxT("s/d"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	footer_bSizer->Add( m_staticText21, 0, wxALL, 5 );
	
	m_datePicker2 = new wxDatePickerCtrl( m_panel4, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DROPDOWN );
	footer_bSizer->Add( m_datePicker2, 0, wxALL, 5 );
	
	
	footer_bSizer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText22 = new wxStaticText( m_panel4, wxID_ANY, wxT("Cari Nama"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	footer_bSizer->Add( m_staticText22, 0, wxALL, 5 );
	
	m_textCtrl14 = new wxTextCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	m_textCtrl14->SetMinSize( wxSize( 150,-1 ) );
	
	footer_bSizer->Add( m_textCtrl14, 0, wxALL|wxEXPAND, 5 );
	
	
	m_panel4->SetSizer( footer_bSizer );
	m_panel4->Layout();
	footer_bSizer->Fit( m_panel4 );
	wrapper_bSizer->Add( m_panel4, 0, wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 5 );
	
	
	this->SetSizer( wrapper_bSizer );
	this->Layout();
	wrapper_bSizer->Fit( this );
	
	// Connect Events
	tambah_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AbsensiPanel::OnTambah ), NULL, this );
	ubah_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AbsensiPanel::OnUbah ), NULL, this );
	hapus_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AbsensiPanel::OnHapus ), NULL, this );
	m_datePicker1->Connect( wxEVT_DATE_CHANGED, wxDateEventHandler( AbsensiPanel::OnFilterData ), NULL, this );
	m_datePicker2->Connect( wxEVT_DATE_CHANGED, wxDateEventHandler( AbsensiPanel::OnFilterData ), NULL, this );
	m_textCtrl14->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( AbsensiPanel::OnFilterData ), NULL, this );
}

AbsensiPanel::~AbsensiPanel()
{
	// Disconnect Events
	tambah_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AbsensiPanel::OnTambah ), NULL, this );
	ubah_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AbsensiPanel::OnUbah ), NULL, this );
	hapus_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AbsensiPanel::OnHapus ), NULL, this );
	m_datePicker1->Disconnect( wxEVT_DATE_CHANGED, wxDateEventHandler( AbsensiPanel::OnFilterData ), NULL, this );
	m_datePicker2->Disconnect( wxEVT_DATE_CHANGED, wxDateEventHandler( AbsensiPanel::OnFilterData ), NULL, this );
	m_textCtrl14->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( AbsensiPanel::OnFilterData ), NULL, this );
	
}
