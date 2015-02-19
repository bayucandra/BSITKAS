/* 
 * File:   tukin_notebook.h
 * Author: bayucandra@gmail.com
 *
 * Created on January 27, 2015, 9:06 AM
 */

#ifndef TUKIN_NOTEBOOK_H
#define	TUKIN_NOTEBOOK_H

#include "tukin_panel.h"

class TukinNotebook : public wxNotebook
{
    private:
        TukinPanel *tukin_panel;
    public:
        TukinNotebook(wxWindow *parent, wxWindowID id=wxID_ANY, const wxPoint &pos=wxDefaultPosition, const wxSize &size=wxDefaultSize, long style=wxTAB_TRAVERSAL, const wxString &name=wxPanelNameStr);
        ~TukinNotebook();
};


#endif	/* TUKIN_NOTEBOOK_H */

