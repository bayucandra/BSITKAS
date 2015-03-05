#include "menu_panel.h"
MenuPanel::MenuPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
    
}
void MenuPanel::OnPaint(wxPaintEvent& event){
      //Create a temporary (stack-allocated) wxPaintDC object
      wxPaintDC paintDC(this);   
            
      //Draw Background image
      paintDC.DrawBitmap(wxBitmap(wxImage("images/menu_bg.png")),0,0);
}
wxBEGIN_EVENT_TABLE(MenuPanel, wxPanel)
    EVT_PAINT(MenuPanel::OnPaint)
wxEND_EVENT_TABLE()
