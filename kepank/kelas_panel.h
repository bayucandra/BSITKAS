/* 
 * File:   kelas_panel.h
 * Author: bayucandra@gmail.com
 *
 * Created on January 13, 2015, 9:45 PM
 */

#ifndef KELAS_PANEL_H
#define	KELAS_PANEL_H
#include "wx/panel.h"
#include <wx/dataview.h>
#include "kelas_input_dialog.h"
enum{
    ID_tambah_kelas
};
class KelasPanel : public wxPanel 
{
	private:
            KelasInputDialog *kelas_input_dialog;
            void OnTambahKelas(wxCommandEvent& event);
	protected:
		wxButton* tambah_kelas_button;
		wxDataViewListCtrl* m_dataViewListCtrl1;
	
	public:
		
		KelasPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL ); 
		~KelasPanel();
        wxDECLARE_EVENT_TABLE();
	
};
wxBEGIN_EVENT_TABLE(KelasPanel, wxPanel)
    EVT_BUTTON(ID_tambah_kelas, KelasPanel::OnTambahKelas)
wxEND_EVENT_TABLE()
KelasPanel::KelasPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* wrapperSizer;
	wrapperSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* button_bSizer;
	button_bSizer = new wxBoxSizer( wxHORIZONTAL );
	
	tambah_kelas_button = new wxButton( this, ID_tambah_kelas, wxT("Tambah Kelas"), wxDefaultPosition, wxDefaultSize, 0 );
	button_bSizer->Add( tambah_kelas_button, 0, wxALL, 5 );
	
	
	wrapperSizer->Add( button_bSizer, 0, wxEXPAND, 5 );
	
	m_dataViewListCtrl1 = new wxDataViewListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	wrapperSizer->Add( m_dataViewListCtrl1, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( wrapperSizer );
	this->Layout();
}

KelasPanel::~KelasPanel()
{
}

void KelasPanel::OnTambahKelas(wxCommandEvent& event){
    kelas_input_dialog=new KelasInputDialog(this);
    kelas_input_dialog->Center();
    kelas_input_dialog->SetTitle(wxT("Tambah Kelas"));
    kelas_input_dialog->ShowModal();
}

#endif	/* KELAS_PANEL_H */

