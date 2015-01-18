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
#include "kelas_input_dialog.cpp"
enum{
    ID_tambah_kelas, ID_ubah_kelas, ID_hapus_kelas
};
class KelasPanel : public wxPanel 
{
	private:
            KelasInputDialog *kelas_input_dialog;
            void OnTambahKelas(wxCommandEvent& event);
	protected:
		wxButton* tambah_kelas_button;
		wxButton* ubah_kelas_button;
		wxButton* hapus_kelas_button;
		wxDataViewListCtrl* kelas_dataViewListCtrl;
	
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
	
	ubah_kelas_button = new wxButton( this, ID_ubah_kelas, wxT("Ubah Kelas"), wxDefaultPosition, wxDefaultSize, 0 );
	button_bSizer->Add( ubah_kelas_button, 0, wxALL, 5 );
	
	hapus_kelas_button = new wxButton( this, ID_hapus_kelas, wxT("Hapus Kelas"), wxDefaultPosition, wxDefaultSize, 0 );
	button_bSizer->Add( hapus_kelas_button, 0, wxALL, 5 );
	
	wrapperSizer->Add( button_bSizer, 0, wxEXPAND, 5 );
	
	kelas_dataViewListCtrl = new wxDataViewListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
        wxDataViewListStore* kelas_model=new wxDataViewListStore();
        kelas_dataViewListCtrl->AssociateModel(kelas_model);
        kelas_model->DecRef();
        kelas_dataViewListCtrl->AppendTextColumn("Row Id");
        wxVector<wxVariant> data;
        for(unsigned int i=0;i<10;i++){
            data.clear();
            data.push_back(wxString::Format("row %d",i));
            kelas_dataViewListCtrl->AppendItem(data);
        }
        
	wrapperSizer->Add( kelas_dataViewListCtrl, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( wrapperSizer );
	this->Layout();
}

KelasPanel::~KelasPanel()
{
}

void KelasPanel::OnTambahKelas(wxCommandEvent& event){
    kelas_input_dialog=new KelasInputDialog(this);
    kelas_input_dialog->InputMode("create");
    kelas_input_dialog->Center();
    kelas_input_dialog->SetTitle(wxT("Tambah Kelas"));
    kelas_input_dialog->ShowModal();
}

#endif	/* KELAS_PANEL_H */

