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
#include <wx/listbook.h>
#include <wx/listctrl.h>
#include <wx/frame.h>

//#include "event_enum.h"
#include "BSettingDialog.h"


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
            void OnExit(wxCommandEvent& event);
            
            void OnLeftDown(wxMouseEvent& evt);
            void OnLeftUp(wxMouseEvent& evt);
            void OnMouseMove(wxMouseEvent& evt);
            
            void OnMaximizeRestore(wxCommandEvent& event);
            void OnBSettingDialog(wxCommandEvent& event);
	
	protected:
		wxStaticBitmap* m_bitmapLogo;
		wxStaticText* header_SI_staticText;
		wxStaticText* header_staticText1;
		wxBitmapButton* Minimize_bpButton;
		wxBitmapButton* Maximize_bpButton;
		wxBitmapButton* Close_bpButton;
		wxBitmapButton* Setting_bpButton;
		wxListbook* main_listbook;
	
	public:
		
		BFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 900,450 ), long style = wxFRAME_SHAPED|wxRESIZE_BORDER|wxSUNKEN_BORDER|wxTAB_TRAVERSAL );

                
		~BFrame();
        wxDECLARE_EVENT_TABLE();
	
};

//enum{
//    ID_New=1, ID_Maximize
//};

#endif //__NONAME_H__