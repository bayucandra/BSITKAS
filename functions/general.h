/* 
 * File:   general.h
 * Author: bayu
 *
 * Created on September 25, 2014, 1:03 PM
 */

#ifndef GENERAL_H
#define	GENERAL_H

#include <wx/file.h>
#include <wx/log.h>
#include <wx/cmdline.h>
#include <wx/filefn.h>
#include <wx/stdpaths.h>
#include <wx/dir.h>
#include <wx/xml/xml.h>
#include <wx/stringimpl.h>

#define BAPP_NAME wxString("BSITKAS")
#define BSETTING_DIR_BASE wxString(".bapps")
#define BSETTING_FILE_NAME wxString("settings.conf")
#define BSETTING_XML_ROOT_NODE wxString("settings")
#ifdef __WXMSW__
    #define BPATH_SLASH wxString("\\")
#else
    #define BPATH_SLASH wxString("/")
#endif

inline bool BinitXMLConfig(){
    //-----------------------------------
    //BEGIN CHECK AND GENERATE CONFIGS
    //------------------------------------
    wxString setting_file_path=wxStandardPaths::Get().GetUserConfigDir();
//#ifdef __WXMSW__
//     setting_file_path.Append("\"");
//#else
//    setting_file_path.Append("/");
//#endif
    setting_file_path.Append(BPATH_SLASH);
    setting_file_path.Append(BSETTING_DIR_BASE);//Change path to base dir
    wxDir config_dir;
    if(!config_dir.Exists(setting_file_path)){
        config_dir.Make(setting_file_path);
    }
    setting_file_path.Append(BPATH_SLASH);
    setting_file_path.Append(BAPP_NAME);//Change path to app name dir
    if(!config_dir.Exists(setting_file_path)){
        config_dir.Make(setting_file_path);
    }
    config_dir.Close();
    
    setting_file_path.Append(BPATH_SLASH);
    setting_file_path.Append(BSETTING_FILE_NAME);//Change path to file name of config
    bool is_config_exist=wxFileExists(setting_file_path);
    if(!is_config_exist){
        wxFile setting_file(setting_file_path, wxFile::write);
        if(setting_file.IsOpened()){
            wxString xml_content_init("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<");
            xml_content_init.Append(BSETTING_XML_ROOT_NODE);
            xml_content_init.Append(">\n");
            xml_content_init.Append("</");
            xml_content_init.Append(BSETTING_XML_ROOT_NODE);
            xml_content_init.Append(">");
            bool is_written=setting_file.Write(xml_content_init);
            if(!is_written){
                wxLogError(_("Error when writing configs"));
            }
            setting_file.Close();
        }else{
            return false;
        }
    }
    return true;

    //-----------------------------------
    //BEGIN GET CONFIG
    //------------------------------------
}
inline wxString BgetConfigPath(){
    wxString setting_file_path=wxStandardPaths::Get().GetUserConfigDir();
    setting_file_path.Append(BPATH_SLASH);
    setting_file_path.Append(BSETTING_DIR_BASE);
    setting_file_path.Append(BPATH_SLASH);
    setting_file_path.Append(BAPP_NAME);
    setting_file_path.Append(BPATH_SLASH);
    setting_file_path.Append(BSETTING_FILE_NAME);
    return setting_file_path;
}
inline wxString BgetXMLConfig(wxString p_key){
    wxString ret_str=wxEmptyString;
    if(BinitXMLConfig()){
        wxXmlDocument doc;
        if(!doc.Load(BgetConfigPath())){
            return wxEmptyString;
        }
        if(doc.GetRoot()->GetName()!=BSETTING_XML_ROOT_NODE){
            wxLogError("Root node error");
            return wxEmptyString;
        }
        wxXmlNode *record=doc.GetRoot()->GetChildren();
        while(record){
            wxXmlNode *key=record->GetChildren();
            wxXmlNode *value=key->GetNext();
            if(key->GetNodeContent()==p_key){
                wxString value_str=value->GetNodeContent();
                if(value_str!=wxEmptyString){
                    ret_str=value->GetNodeContent();
                }
                break;
            }
            record=record->GetNext();
        }
    }
    return ret_str;
}
inline bool BSetXMLConfig(wxString p_key,wxString p_value){
    if(BinitXMLConfig()){
        wxXmlDocument doc;
        if(!doc.Load(BgetConfigPath())){
            return false;
        }
        if(doc.GetRoot()->GetName()!=BSETTING_XML_ROOT_NODE){
            wxLogError("Root node error");
            return false;
        }
        wxXmlNode *record=doc.GetRoot()->GetChildren();
        bool key_exist=false;
        while(record){
            wxXmlNode *key=record->GetChildren();
            wxXmlNode *value=key->GetNext();
            if(key->GetNodeContent()==p_key){
                key_exist=true;
                if(p_value!=wxEmptyString){
                    value->GetChildren()->SetContent(p_value);
                }else{
                    doc.GetRoot()->RemoveChild(record);
                }
            }
            
            record=record->GetNext();
        }
        if(!key_exist&&(p_value!=wxEmptyString)){
            wxXmlNode *record_node=new wxXmlNode(wxXML_ELEMENT_NODE,wxString("record"));
            
            wxXmlNode *key=new wxXmlNode(wxXML_ELEMENT_NODE,wxString("key"));
                wxXmlNode *key_content=new wxXmlNode(wxXML_TEXT_NODE,wxString("key"),p_key);
                key->AddChild(key_content);
            wxXmlNode *value=new wxXmlNode(wxXML_ELEMENT_NODE,wxString("value"));
                wxXmlNode *value_content=new wxXmlNode(wxXML_TEXT_NODE,wxString("value"),p_value);
                value->AddChild(value_content);
            record_node->AddChild(key);
            record_node->AddChild(value);
            doc.GetRoot()->AddChild(record_node);
        }
        doc.Save(BgetConfigPath());
        return true;
    }
}
wxString BGetMonthName(wxString p_month_decimal){
    wxString ret_str;
    if(p_month_decimal==wxT("01")){
        ret_str=wxString("Januari");
    }else if(p_month_decimal==wxT("02")){
        ret_str=wxString("Februari");
    }else if(p_month_decimal==wxT("03")){
        ret_str=wxString("Maret");
    }else if(p_month_decimal==wxT("04")){
        ret_str=wxString("April");
    }else if(p_month_decimal==wxT("05")){
        ret_str=wxString("Mei");
    }else if(p_month_decimal==wxT("06")){
        ret_str=wxString("Juni");
    }else if(p_month_decimal==wxT("07")){
        ret_str=wxString("Juli");
    }else if(p_month_decimal==wxT("08")){
        ret_str=wxString("Agustus");
    }else if(p_month_decimal==wxT("09")){
        ret_str=wxString("September");
    }else if(p_month_decimal==wxT("10")){
        ret_str=wxString("Oktober");
    }else if(p_month_decimal==wxT("11")){
        ret_str=wxString("November");
    }else if(p_month_decimal==wxT("12")){
        ret_str=wxString("Desember");
    }
    return ret_str;
}
wxString BFloatToWxString(float p_float){
    wxString ret_str=wxEmptyString;
    wxString tmp_str=wxString::Format(wxT("%f"),p_float);
    size_t str_len=tmp_str.Len();
//    wxString(str_len);
    bool init_number=false;
    for(size_t i=str_len;i>0;i--){
        wxString cur_char=tmp_str.Mid(i-1,1);
//        wxLogMessage(cur_char);
//        wxLogMessage(wxString::Format(wxT("%i"),i));
        if(
                (cur_char!=wxString(wxT("0")))
                &&(cur_char!=wxString(wxT(".")))
            )
        {
            ret_str.Prepend(cur_char);
        }else if(init_number){
            ret_str.Prepend(cur_char);
        }
        if(!init_number){
            if(cur_char!=wxString(wxT("0"))){
                init_number=true;
            }
        }
    }
    return ret_str;
}
wxString BCurrencyFormat(wxString p_num_str, wxString p_currency_str){
    wxString ret_str;
    size_t digit_count=0;
    for(size_t i=p_num_str.Len() ; i>0 ; i--){
        digit_count++;
        ret_str.Prepend(p_num_str.Mid(i-1,1));
        if( ((digit_count%3)==0) && (digit_count<p_num_str.Len()) ){
            ret_str.Prepend(".");
        }
    }
    ret_str.Prepend(" ");
    ret_str.Prepend(p_currency_str);
    p_currency_str.Append(",-");
    return ret_str;
}
//int getArrayIndex(wxString p_str,const wxString *p_arr){
//    int idx=-1;
//    int len=WXSIZEOF(p_arr);
//    wxLogMessage(wxString::Format(wxT("%i"),len));
//    wxLogMessage(p_arr[1]);
//    for(int i=0;i<len;i++){
//        if(p_arr[i]==p_str){
//            idx=i;
//            break;
//        }
//    }
//    return idx;
//}


#endif	/* GENERAL_H */