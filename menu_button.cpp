#include "menu_button.h"
MenuButton::MenuButton(wxWindow *parent, const wxString &p_bg_path_active, const wxString &p_bg_path_inactive, wxWindowID id, const wxString &label, const wxPoint &pos, const wxSize &size, long style, const wxValidator &validator, const wxString &name) : wxButton(parent, id, label, pos, size, style, validator, name){
    bitmap_active = wxBitmap(p_bg_path_active, wxBITMAP_TYPE_ANY);
    bitmap_inactive = wxBitmap(p_bg_path_inactive, wxBITMAP_TYPE_ANY);
    
    SetInactive();
}
void MenuButton::SetActive(){
    SetBitmap(bitmap_active);
}
void MenuButton::SetInactive(){
    SetBitmap(bitmap_inactive);
}
