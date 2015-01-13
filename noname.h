///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __NONAME_H__
#define __NONAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/notebook.h>
#include <wx/frame.h>
#include <wx/textctrl.h>
#include <wx/dialog.h>
#include <wx/dataview.h>
#include <wx/valtext.h>

///////////////////////////////////////////////////////////////////////////

#define ID_Minimize 1000
#define ID_Maximize 1001
#define ID_Setting 1002
#define ID_menu_tukin_btn 1003
#define ID_menu_umak_btn 1004
#define ID_menu_pegawai_btn 1005
#define ID_menu_kepank_btn 1006
#define ID_menu_absensi_btn 1007
#define ID_DLG_SETTING_save 1008

///////////////////////////////////////////////////////////////////////////////
/// Class BFrame
///////////////////////////////////////////////////////////////////////////////
class BFrame : public wxFrame 
{
	private:
	
	protected:
		wxStaticBitmap* m_bitmapLogo;
		wxStaticText* header_SI_staticText;
		wxStaticText* header_staticText1;
		wxBitmapButton* Minimize_bpButton;
		wxBitmapButton* Maximize_bpButton;
		wxBitmapButton* Close_bpButton;
		wxBitmapButton* Setting_bpButton;
		wxPanel* menu_panel;
		wxStaticText* menu_laporan_staticText;
		wxButton* menu_tukin_button;
		wxButton* menu_umak_button;
		wxStaticText* menu_input_data_staticText;
		wxButton* menu_pegawai_button;
		wxButton* menu_kepank_button;
		wxButton* menu_absensi_button;
		wxNotebook* main_notebook;
	
	public:
		
		BFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 900,450 ), long style = wxCAPTION|wxRESIZE_BORDER|wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
		
		~BFrame();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class BSettingDialog
///////////////////////////////////////////////////////////////////////////////
class BSettingDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* MySQLServer_staticText;
		wxTextCtrl* MySQLServer_textCtrl;
		wxButton* Simpan_button;
	
	public:
		
		BSettingDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Setting"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,400 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~BSettingDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class KelasPanel
///////////////////////////////////////////////////////////////////////////////
class KelasPanel : public wxPanel 
{
	private:
	
	protected:
		wxButton* tambah_kelas_button;
		wxDataViewListCtrl* m_dataViewListCtrl1;
	
	public:
		
		KelasPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL ); 
		~KelasPanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class KelasInputDialog
///////////////////////////////////////////////////////////////////////////////
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
		
		KelasInputDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,-1 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~KelasInputDialog();
	
};

#endif //__NONAME_H__
