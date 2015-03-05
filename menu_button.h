/* 
 * File:   menu_button.h
 * Author: bayucandra@gmail.com
 *
 * Created on February 26, 2015, 10:40 PM
 */

#ifndef MENU_BUTTON_H
#define	MENU_BUTTON_H
class MenuButton : public wxButton{
    private:
        wxBitmap bitmap_active;
        wxBitmap bitmap_inactive;
    public:
        MenuButton(wxWindow *parent, const wxString &p_bg_path_active, const wxString &p_bg_path_inactive, wxWindowID id = wxID_ANY, const wxString &label=wxEmptyString, const wxPoint &pos=wxDefaultPosition, const wxSize &size=wxSize(170,-1), long style=0|wxNO_BORDER, const wxValidator &validator=wxDefaultValidator, const wxString &name=wxButtonNameStr);
        void SetActive();
        void SetInactive();
};


#endif	/* MENU_BUTTON_H */

