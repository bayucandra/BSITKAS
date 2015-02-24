/* 
 * File:   kepank_notebook.cpp
 * Author: bayucandra@gmail.com
 *
 * Created on January 19, 2015, 8:27 PM
 */

#include "kepank_notebook.h"
#include "kelas_panel.cpp"
#include "pangkat_panel.cpp"

KepankNotebook::KepankNotebook(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size, long style, const wxString &name) : wxNotebook(parent,id,pos,size,style,name){
    kelas_panel=new KelasPanel(this);
    AddPage(kelas_panel,wxT("Kelas/Gol"));
    
    pangkat_panel=new PangkatPanel(this);
    AddPage(pangkat_panel,wxT("Pangkat/Jabatan"));
}
KepankNotebook::~KepankNotebook(){
}
