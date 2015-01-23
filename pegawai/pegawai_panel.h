/* 
 * File:   pegawai_panel.h
 * Author: bayucandra@gmail.com
 *
 * Created on January 20, 2015, 8:45 PM
 */

#ifndef PEGAWAI_PANEL_H
#define	PEGAWAI_PANEL_H

#include "wx/panel.h"
#include "pegawai_salin_dialog.h"
class PegawaiPanel : public wxPanel 
{
	private:
            //BEGIN BAYU===========
            void InitDataView();
            void InitDataLamaView();
            PegawaiSalinDialog *pegawai_salin_dialog;
            //END BAYU**************
	protected:
		wxSplitterWindow* pegawai_splitter;
		wxPanel* pegawai_panel;
		wxButton* tambah_button;
		wxButton* ubah_button;
		wxButton* hapus_button;
		wxDataViewListCtrl* pegawai_dataViewListCtrl;
		wxPanel* pegawai_data_lama_panel;
		wxButton* salin_button;
		wxDataViewListCtrl* pegawai_data_lama_dataViewListCtrl;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnTambah( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUbah( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHapus( wxCommandEvent& event ) { event.Skip(); }
		void OnSalin( wxCommandEvent& event );
		
	
	public:
		
		PegawaiPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition,
                        const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL ); 
		~PegawaiPanel();
		
		void pegawai_splitterOnIdle( wxIdleEvent& )
		{
			pegawai_splitter->SetSashPosition( 0 );
			pegawai_splitter->Disconnect( wxEVT_IDLE, wxIdleEventHandler( PegawaiPanel::pegawai_splitterOnIdle ), NULL, this );
		}
                //BEGIN BAYU==============
                void RefreshDataView();
                void RefreshDataLamaView();
                //END BAYU********************
	
};

#endif	/* PEGAWAI_PANEL_H */
