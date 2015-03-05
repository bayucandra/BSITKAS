/* 
 * File:   cuti_jenis_dialog.h
 * Author: bayucandra@gmail.com
 *
 * Created on February 25, 2015, 5:39 AM
 */

#ifndef CUTI_JENIS_DIALOG_H
#define	CUTI_JENIS_DIALOG_H

class CutiJenisDialog : public wxDialog 
{
	private:
            //BEGIN BAYU==================
            void InitDataView();
            void Pilih();
            //END BAYU********************
	
	protected:
		wxTextCtrl* cari_textCtrl;
		wxButton* cari_button;
		wxDataViewListCtrl* cuti_jenis_dataViewListCtrl;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCari( wxCommandEvent& event );
		virtual void OnPilih( wxDataViewEvent& event );
		
	
	public:
		
		CutiJenisDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Jenis cuti"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 450,350 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~CutiJenisDialog();
                //BEGIN BAYU=================
                void RefreshDataView();
                //END BAYU****************
	
};

#endif	/* CUTI_JENIS_DIALOG_H */

