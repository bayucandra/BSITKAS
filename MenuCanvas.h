/* 
 * File:   MenuCanvas.h
 * Author: IT
 *
 * Created on January 11, 2015, 9:05 PM
 */

#ifndef MENUCANVAS_H
#define	MENUCANVAS_H

#include "wx/custombgwin.h"
#include "wx/dcbuffer.h"

class MyCanvas : public wxCustomBackgroundWindow<wxScrolledWindow>
{
public:
    MyCanvas(wxScrolledWindow *parent);


    void EraseBgInPaint(bool erase) { m_eraseBgInPaint = erase; Refresh(); }

private:
    void OnPaint( wxPaintEvent &event );
    void OnEraseBackground( wxEraseEvent &event );

    void DoPaint(wxDC& dc);

    wxBitmap    m_bitmap;


    // use background bitmap?
    bool m_useBgBmp;

    // erase background in OnPaint()?
    bool m_eraseBgInPaint;


    wxDECLARE_EVENT_TABLE();
};
wxBEGIN_EVENT_TABLE(MyCanvas, wxScrolledWindow)
    EVT_PAINT(MyCanvas::OnPaint)
//    EVT_ERASE_BACKGROUND(MyCanvas::OnEraseBackground)
wxEND_EVENT_TABLE()

MyCanvas::MyCanvas(wxScrolledWindow *parent)
{
    Create(parent, wxID_ANY);

    m_useBgBmp = true;
    m_eraseBgInPaint = false;

//    SetScrollbars( 10, 10, 40, 100, 0, 0 );

//    m_bitmap = wxBitmap( wxICON(sample) );
    m_bitmap = wxBitmap( wxT("images/logo.png"), wxBITMAP_TYPE_ANY );
    SetBackgroundBitmap(m_bitmap);
    Refresh();
//
//    new wxStaticBitmap( this, wxID_ANY, m_bitmap, wxPoint(80,20) );
//
//    new wxStaticText(this, wxID_ANY,
//                     "Left bitmap is a wxStaticBitmap,\n"
//                     "right one drawn directly",
//                     wxPoint(150, 20));
//
//    new ControlWithTransparency(this, wxPoint(65, 125), wxSize(350, 22));
//
//    SetFocusIgnoringChildren();
//    SetBackgroundColour(*wxCYAN);
}

void MyCanvas::DoPaint(wxDC& dc)
{
    PrepareDC(dc);

    dc.DrawBitmap( m_bitmap, 20, 120, true );

    dc.SetTextForeground(*wxRED);
    dc.DrawText("This text is drawn from OnPaint", 165, 65);
}

void MyCanvas::OnPaint( wxPaintEvent &WXUNUSED(event) )
{

        wxPaintDC dc(this);
        DoPaint(dc);
}

void MyCanvas::OnEraseBackground( wxEraseEvent& event )
{
    // We must not erase the background ourselves if we asked wxPanel to erase
    // it using a background bitmap.
    if ( m_useBgBmp )
    {
        event.Skip();
        return;
    }

    wxASSERT_MSG
    (
        GetBackgroundStyle() == wxBG_STYLE_ERASE,
        "shouldn't be called unless background style is \"erase\""
    );

    wxDC& dc = *event.GetDC();
    dc.SetPen(*wxGREEN_PEN);

    // clear any junk currently displayed
    dc.Clear();

    PrepareDC( dc );

    const wxSize size = GetVirtualSize();
    for ( int x = 0; x < size.x; x += 15 )
    {
        dc.DrawLine(x, 0, x, size.y);
    }

    for ( int y = 0; y < size.y; y += 15 )
    {
        dc.DrawLine(0, y, size.x, y);
    }

    dc.SetTextForeground(*wxRED);
    dc.SetBackgroundMode(wxSOLID);
    dc.DrawText("This text is drawn from OnEraseBackground", 60, 160);
}

#endif	/* MENUCANVAS_H */

