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
#include <wx/splash.h>

#include "mysql++.h"
//#include "ssql_tpl.h"

#include "functions/general.h"
wxDateTime gjam_masuk(8,0,0,0);
wxDateTime gjam_masuk_awal(7,30,0,0);
wxDateTime gjam_pulang(16,30,0,0);
const wxString bmain_settings[]={"mysql_server","mysql_username","mysql_password","mysql_db"};
mysqlpp::Connection conn(false);

#include "BFrame.cpp"
#include "BSettingDialog.cpp"
class BApp:public wxApp{
    public:
//        BApp(){
//        }
        
        virtual bool OnInit();
    private:
//        void xmlConfig();
};


wxIMPLEMENT_APP(BApp);

bool BApp::OnInit()
{
    // Add the common image handlers
    wxImage::AddHandler( new wxPNGHandler );
    wxImage::AddHandler( new wxJPEGHandler );
    wxBitmap bitmap;
    if (bitmap.LoadFile("images/splash.png", wxBITMAP_TYPE_PNG)){
        wxSplashScreen* splash = new wxSplashScreen(bitmap, wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT, 5000, NULL, -1, wxDefaultPosition, wxDefaultSize,        wxBORDER_SIMPLE|wxSTAY_ON_TOP);
    }
    wxYield();

    //BEGIN DATABASE CONNECTION======
    bool is_mysql_configs_empty=(BgetXMLConfig(bmain_settings[0])==wxEmptyString)||
                (BgetXMLConfig(bmain_settings[1])==wxEmptyString)||
                (BgetXMLConfig(bmain_settings[2])==wxEmptyString)||
                (BgetXMLConfig(bmain_settings[3])==wxEmptyString);
    if(is_mysql_configs_empty==false){
        bool mysql_connect=conn.connect(BgetXMLConfig(bmain_settings[3]).mb_str(), BgetXMLConfig(bmain_settings[0]).mb_str(),
                BgetXMLConfig(bmain_settings[1]).mb_str(), BgetXMLConfig(bmain_settings[2]).mb_str()
        );
        if(mysql_connect==false){
            wxString mysql_error=wxString(wxT("Koneksi database gagal, pesan error:"));
            mysql_error.Append(conn.error());
            wxLogError(mysql_error);
        }else{
            //BEGIN MAIN FRAME==================

            BFrame *frame=new BFrame(NULL);
            frame->Center();
            frame->Show(true);
            SetTopWindow(frame);
            //END MAIN FRAME*******************
        }
    }else{
        wxLogError(wxT("Error: Harap periksa setting konfigurasi database."));
    }
    //END DATABASE CONNECTION*************
//    splash->Close();
    
    return true;
}
//void BApp::xmlConfig(){
//    wxString setting_dir_base(".bapps");
//    wxString setting_file_name("bcatalog_settings.conf");
//    wxString setting_file_path=wxStandardPaths::Get().GetUserConfigDir();
////#ifdef __WXMSW__
////     setting_file_path.Append("\"");
////#else
////    setting_file_path.Append("/");
////#endif
//    setting_file_path.Append(BPATH_SLASH);
//    setting_file_path.Append(setting_dir_base);//Change path to base dir
//    wxDir config_dir;
//    if(!config_dir.Exists(setting_file_path)){
//        config_dir.Make(setting_file_path);
//    }
//    
//
//    bool is_config_exist=wxFileExists(setting_file_path);
//    if(!is_config_exist){
//        wxFile setting_file(setting_file_path, wxFile::write);
//        if(setting_file.IsOpened()){
//            bool is_written=setting_file.Write("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<xs:schema xmlns:xs=\"http://www.w3.org/2001/XMLSchema\"></xs:schema>\n<settings>\n</settings>");
//            if(!is_written){
//                wxLogError(_("Error when writing configs"));
//            }
//            setting_file.Close();
//        }
//    }
//}