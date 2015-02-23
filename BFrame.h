///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __BFRAME_H__
#define __BFRAME_H__

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
#include <wx/tglbtn.h>
#include <wx/statbox.h>
#include <wx/scrolwin.h>
#include <wx/splitter.h>
#include <wx/frame.h>
#include <wx/simplebook.h>
#include "wx/dataview.h"
#include "wx/notebook.h"
#include "wx/panel.h"
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include "wx/dialog.h"
#include <wx/html/htmlwin.h>
#include <wx/html/htmprint.h>

//#include "event_enum.h"
#include "BSettingDialog.h"
#include "kepank/kepank_notebook.h"
#include "pegawai/pegawai_notebook.h"
#include "absensi/absensi_notebook.h"
#include "tukin/tukin_notebook.h"

enum{
    ID_Minimize, ID_Maximize, ID_Setting, 
    ID_menu_tukin_btn, ID_menu_umak_btn, ID_menu_pegawai_btn, ID_menu_kepank_btn, ID_menu_absensi_btn
};
///////////////////////////////////////////////////////////////////////////
//
//#define ID_Minimize 1000
//#define ID_Maximize 1001
//#define ID_Setting 1002

///////////////////////////////////////////////////////////////////////////////
/// Class BFrame
///////////////////////////////////////////////////////////////////////////////
class BFrame : public wxFrame 
{
	private:
            wxPoint m_delta;
            
            void OnLeftDown(wxMouseEvent& evt);
            void OnLeftUp(wxMouseEvent& evt);
            void OnMouseMove(wxMouseEvent& evt);
            
            void OnMinimize(wxCommandEvent& event);
            void OnMaximizeRestore(wxCommandEvent& event);
            void OnExit(wxCommandEvent& event);
            
            void OnBSettingDialog(wxCommandEvent& event);
            
            void OnMenuTukin(wxCommandEvent& event);
            void OnMenuAbsensi(wxCommandEvent& event);
            void OnMenuPegawai(wxCommandEvent& event);
            void OnMenuKepank(wxCommandEvent& event);
	
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
		wxButton* menu_absensi_button;
		wxButton* menu_pegawai_button;
		wxButton* menu_kepank_button;
		wxSimplebook* main_notebook;
                //BEGIN BAYU===========
                TukinNotebook* tukin_notebook;
                AbsensiNotebook* absensi_notebook;
                PegawaiNotebook* pegawai_notebook;
                KepankNotebook* kepank_notebook;
                //END BAYU**************
	
	public:
		
		BFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 900,450 ), long style = wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLIP_CHILDREN|wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
		
		~BFrame();
        wxDECLARE_EVENT_TABLE();
	
};

//enum{
//    ID_New=1, ID_Maximize
//};

#endif //__NONAME_H__
