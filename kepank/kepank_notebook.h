/* 
 * File:   kepank_window.h
 * Author: bayucandra@gmail.com
 *
 * Created on January 11, 2015, 11:38 PM
 */

#ifndef KEPANK_WINDOW_H
#define	KEPANK_WINDOW_H

#include <wx/notebook.h>
#include "kelas_panel.h"

class KepankNotebook : public wxNotebook
{
    private:
        KelasPanel* kelas_panel;
    public:
        KepankNotebook(wxWindow *parent, wxWindowID id=wxID_ANY, const wxPoint &pos=wxDefaultPosition, const wxSize &size=wxDefaultSize, long style=wxTAB_TRAVERSAL, const wxString &name=wxPanelNameStr);
        virtual ~KepankNotebook();
};

KepankNotebook::KepankNotebook(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size, long style, const wxString &name) : wxNotebook(parent,id,pos,size,style,name){
    kelas_panel=new KelasPanel(this);
    AddPage(kelas_panel,wxT("Kelas Panel"));
}
KepankNotebook::~KepankNotebook(){
}

#endif	/* KEPANK_WINDOW_H */

