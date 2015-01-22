/* 
 * File:   kepank_window.h
 * Author: bayucandra@gmail.com
 *
 * Created on January 11, 2015, 11:38 PM
 */

#ifndef KEPANK_WINDOW_H
#define	KEPANK_WINDOW_H

#include "kelas_panel.h"
#include "pangkat_panel.h"

class KepankNotebook : public wxNotebook
{
    private:
        KelasPanel* kelas_panel;
        PangkatPanel* pangkat_panel;
    public:
        KepankNotebook(wxWindow *parent, wxWindowID id=wxID_ANY, const wxPoint &pos=wxDefaultPosition, const wxSize &size=wxDefaultSize, long style=wxTAB_TRAVERSAL, const wxString &name=wxPanelNameStr);
        ~KepankNotebook();
};

#endif	/* KEPANK_WINDOW_H */

