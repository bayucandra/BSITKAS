/* 
 * File:   kepank_window.h
 * Author: IT
 *
 * Created on January 11, 2015, 11:38 PM
 */

#ifndef KEPANK_WINDOW_H
#define	KEPANK_WINDOW_H

#include "wx/mdi.h"

class KepankWindow : public wxMDIChildFrame
{
    public:
        KepankWindow(wxMDIParentFrame *parent);
        virtual ~KepankWindow();
};

KepankWindow::KepankWindow(wxMDIParentFrame *parent):wxMDIChildFrame(parent,wxID_ANY,wxString("Kelas dan Pangkat pegawai")){
    Maximize();
}
KepankWindow::~KepankWindow(){
}

#endif	/* KEPANK_WINDOW_H */

