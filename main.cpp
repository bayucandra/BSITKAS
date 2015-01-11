/* 
 * File:   main.cpp
 * Author: bayucandra@gmail.com
 *
 * Created on January 6, 2015, 5:32 PM
 */

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <wx/intl.h>

#include "functions/general.h"
#include "event_enum.h"
const wxString bmain_settings[]={"mysql_server"};

#include "BFrame.cpp"
#include "BSettingDialog.cpp"
class BApp:public wxApp{
    public:
        BApp(){
        }
        
        virtual bool OnInit();
    private:
        void xmlConfig();
};


wxIMPLEMENT_APP(BApp);

bool BApp::OnInit()
{
    // Add the common image handlers
    wxImage::AddHandler( new wxPNGHandler );
    wxImage::AddHandler( new wxJPEGHandler );

    if(BgetXMLConfig(bmain_settings[0])==wxEmptyString){
        BSetXMLConfig(bmain_settings[0],wxString("127.0.0.1"));
    }
    
    BFrame *frame=new BFrame(NULL);
    frame->Center();
    frame->Show(true);
    return true;
}
void BApp::xmlConfig(){
    wxString setting_dir_base(".bapps");
    wxString setting_file_name("bcatalog_settings.conf");
    wxString setting_file_path=wxStandardPaths::Get().GetUserConfigDir();
//#ifdef __WXMSW__
//     setting_file_path.Append("\"");
//#else
//    setting_file_path.Append("/");
//#endif
    setting_file_path.Append(BPATH_SLASH);
    setting_file_path.Append(setting_dir_base);//Change path to base dir
    wxDir config_dir;
    if(!config_dir.Exists(setting_file_path)){
        config_dir.Make(setting_file_path);
    }
    

    bool is_config_exist=wxFileExists(setting_file_path);
    if(!is_config_exist){
        wxFile setting_file(setting_file_path, wxFile::write);
        if(setting_file.IsOpened()){
            bool is_written=setting_file.Write("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<xs:schema xmlns:xs=\"http://www.w3.org/2001/XMLSchema\"></xs:schema>\n<settings>\n</settings>");
            if(!is_written){
                wxLogError(_("Error when writing configs"));
            }
            setting_file.Close();
        }
    }
}