/* 
 * File:   pegawai_notebook.h
 * Author: bayucandra@gmail.com
 *
 * Created on January 20, 2015, 7:43 PM
 */

#ifndef PEGAWAI_NOTEBOOK_H
#define	PEGAWAI_NOTEBOOK_H

#include "pegawai_panel.h"

class PegawaiNotebook : public wxNotebook
{
    private:
        PegawaiPanel *pegawai_panel;
    public:
        PegawaiNotebook(wxWindow *parent, wxWindowID id=wxID_ANY, const wxPoint &pos=wxDefaultPosition, const wxSize &size=wxDefaultSize, long style=wxTAB_TRAVERSAL, const wxString &name=wxPanelNameStr);
        ~PegawaiNotebook();
};

#endif	/* PEGAWAI_NOTEBOOK_H */

