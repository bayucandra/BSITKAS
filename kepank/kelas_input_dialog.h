/* 
 * File:   kelas_input_dialog.h
 * Author: bayucandra@gmail.com
 *
 * Created on January 13, 2015, 10:31 PM
 */

#ifndef KELAS_INPUT_DIALOG_H
#define	KELAS_INPUT_DIALOG_H

#include "wx/dialog.h"

class KelasInputDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* kelas_staticText;
		wxTextCtrl* kelas_textCtrl;
		wxStaticText* keterangan_staticText;
		wxTextCtrl* keterangan_textCtrl;
		wxStaticText* tunjangan_perbulan_staticText;
		wxTextCtrl* tunjangan_perbulan_textCtrl;
		wxButton* tambah_button;
		wxButton* reset_button;
	
	public:
		
		KelasInputDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,200 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~KelasInputDialog();
	
};


KelasInputDialog::KelasInputDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* input_fgSizer;
	input_fgSizer = new wxFlexGridSizer( 0, 2, 0, 0 );
	input_fgSizer->AddGrowableCol( 1 );
	input_fgSizer->SetFlexibleDirection( wxBOTH );
	input_fgSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	kelas_staticText = new wxStaticText( this, wxID_ANY, wxT("Kelas"), wxDefaultPosition, wxDefaultSize, 0 );
	kelas_staticText->Wrap( -1 );
	input_fgSizer->Add( kelas_staticText, 0, wxALL, 5 );
	
	kelas_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	input_fgSizer->Add( kelas_textCtrl, 0, wxALL, 5 );
	
	keterangan_staticText = new wxStaticText( this, wxID_ANY, wxT("Keterangan"), wxDefaultPosition, wxDefaultSize, 0 );
	keterangan_staticText->Wrap( -1 );
	input_fgSizer->Add( keterangan_staticText, 0, wxALL, 5 );
	
	keterangan_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	input_fgSizer->Add( keterangan_textCtrl, 0, wxALL|wxEXPAND, 5 );
	
	tunjangan_perbulan_staticText = new wxStaticText( this, wxID_ANY, wxT("Tunjangan perbulan"), wxDefaultPosition, wxDefaultSize, 0);
	tunjangan_perbulan_staticText->Wrap( -1 );
	input_fgSizer->Add( tunjangan_perbulan_staticText, 0, wxALL, 5 );
	
	tunjangan_perbulan_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 250,-1 ), wxTE_RIGHT, wxTextValidator(wxFILTER_NUMERIC) );
	input_fgSizer->Add( tunjangan_perbulan_textCtrl, 0, wxALL, 5 );
	
	
	input_fgSizer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* button_bSizer;
	button_bSizer = new wxBoxSizer( wxHORIZONTAL );
	
	tambah_button = new wxButton( this, wxID_ANY, wxT("Simpan"), wxDefaultPosition, wxDefaultSize, 0 );
	button_bSizer->Add( tambah_button, 0, wxALL, 5 );
	
	reset_button = new wxButton( this, wxID_ANY, wxT("Reset Input"), wxDefaultPosition, wxDefaultSize, 0 );
	button_bSizer->Add( reset_button, 0, wxALL, 5 );
	
	
	input_fgSizer->Add( button_bSizer, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( input_fgSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
}

KelasInputDialog::~KelasInputDialog()
{
}

#endif	/* KELAS_INPUT_DIALOG_H */

