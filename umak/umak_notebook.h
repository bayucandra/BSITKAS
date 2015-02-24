/* 
 * File:   umak_notebook.h
 * Author: bayucandra@gmail.com
 *
 * Created on February 24, 2015, 6:11 AM
 */

#ifndef UMAK_NOTEBOOK_H
#define	UMAK_NOTEBOOK_H
#include "umak_panel.h"

class UmakNotebook : public wxNotebook
{
    private:
        UmakPanel *umak_panel;
    public:
        UmakNotebook(wxWindow *parent, wxWindowID id=wxID_ANY, const wxPoint &pos=wxDefaultPosition, const wxSize &size=wxDefaultSize, long style=wxTAB_TRAVERSAL, const wxString &name=wxPanelNameStr);
        ~UmakNotebook();
};

#endif	/* UMAK_NOTEBOOK_H */

