/* 
 * File:   menu_panel.h
 * Author: bayucandra@gmail.com
 *
 * Created on February 26, 2015, 9:55 PM
 */

#ifndef MENU_PANEL_H
#define	MENU_PANEL_H

class MenuPanel : public wxPanel{
    private:
        wxBitmap image;
    protected:
        // Virtual event handlers, overide them in your derived class
        virtual void OnPaint( wxPaintEvent& event );
    public:
        MenuPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL );
 
//        void paintEvent(wxPaintEvent & evt);
//        void paintNow();
// 
//        void render(wxDC& dc);
    DECLARE_EVENT_TABLE()
};

#endif	/* MENU_PANEL_H */

