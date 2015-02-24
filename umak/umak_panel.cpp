#include "umak_panel.h"
UmakPanel::UmakPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer47;
	bSizer47 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Periode") ), wxHORIZONTAL );
	
	m_staticText41 = new wxStaticText( this, wxID_ANY, wxT("Tahun:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText41->Wrap( -1 );
	m_staticText41->SetFont( wxFont( 10, 70, 90, 90, false, wxEmptyString ) );
	
	sbSizer3->Add( m_staticText41, 0, wxLEFT|wxTOP, 8 );
	
	year_comboBox = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 120,-1 ), 0, NULL, wxCB_READONLY ); 
	sbSizer3->Add( year_comboBox, 0, wxALL, 5 );
	
	m_staticText42 = new wxStaticText( this, wxID_ANY, wxT("Bulan:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText42->Wrap( -1 );
	m_staticText42->SetFont( wxFont( 10, 70, 90, 90, false, wxEmptyString ) );
	
	sbSizer3->Add( m_staticText42, 0, wxLEFT|wxTOP, 8 );
	
	month_comboBox = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 70,-1 ), 0, NULL, wxCB_READONLY ); 
	sbSizer3->Add( month_comboBox, 0, wxALL, 5 );
	
	tampilkan_button = new wxButton( this, wxID_ANY, wxT("Tampilkan"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer3->Add( tampilkan_button, 0, wxALL, 5 );
	
	cetak_button = new wxButton( this, wxID_ANY, wxT("Cetak PDF"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer3->Add( cetak_button, 0, wxALL, 5 );
	
	
	bSizer47->Add( sbSizer3, 0, wxEXPAND, 5 );
	
	umak_htmlWin = new wxHtmlWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO|wxSTATIC_BORDER );
	bSizer47->Add( umak_htmlWin, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer47 );
	this->Layout();
	bSizer47->Fit( this );
	
	// Connect Events
	tampilkan_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UmakPanel::OnTampil ), NULL, this );
	cetak_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UmakPanel::OnCetak ), NULL, this );
        
        //BEGIN BAYU======================
        umak_html=wxEmptyString;
        
        b_print = new wxHtmlEasyPrinting(wxT("Cetak Tukin"), this);
        b_print->SetFooter(wxString("halaman @PAGENUM@ dari @PAGESCNT@"),wxPAGE_ALL);
        wxPageSetupDialogData* b_page_setup_data=b_print->GetPageSetupData();
        b_page_setup_data->SetMarginBottomRight(wxPoint(10,15));
        b_page_setup_data->SetMarginTopLeft(wxPoint(10,20));
        
        wxPrintData *b_print_data=b_print->GetPrintData();
        b_print_data->SetPaperId(wxPAPER_A4);
        b_print_data->SetOrientation(wxPORTRAIT);
        
        wxString init_html;
        init_html<<"<html><head><title>Init</title></head><body>"
                <<"<br><br><br><center><img src=\"images/logo_report.png\"></center>"
                <<"<h3 align=\"center\">Preview laporan uang makan</h3>"
            <<"</body></html>";
        umak_htmlWin->SetPage(init_html);
        InitYear();
        InitMonth();
        InitCurDateCombo();
}

UmakPanel::~UmakPanel()
{
	// Disconnect Events
	tampilkan_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UmakPanel::OnTampil ), NULL, this );
	cetak_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UmakPanel::OnCetak ), NULL, this );
	
}
void UmakPanel::InitYear(){
    int year_start=2010;
    for(int i=0; i<30; i++){
        year_comboBox->Append(wxString::Format(wxT("%i"),year_start));
        year_start++;
    }
}
void UmakPanel::InitMonth(){
    for(int i=0;i<12;i++){
        int month_no=i+1;
        wxString month_no_str=wxString::Format(wxT("%i"),month_no);
        if(i<9){
            month_no_str.Prepend(wxT("0"));
        }
        month_comboBox->Append(month_no_str);
    }
}
void UmakPanel::InitCurDateCombo(){
    wxDateTime date_today=wxDateTime::Today();
    wxString year=date_today.Format("%Y");
    wxString month=date_today.Format("%m");
    
    year_comboBox->SetValue(year);
    month_comboBox->SetValue(month);
}
int UmakPanel::TotalDaySelected(){
    wxString str_date_selected=year_comboBox->GetValue();
    str_date_selected.Append("-");
    str_date_selected.Append(month_comboBox->GetValue());
    str_date_selected.Append(wxT("-01"));

    wxDateTime date_last_day;
    bool parsed=date_last_day.ParseFormat(str_date_selected, "%Y-%m-%d");
    if(!parsed){
        wxLogError("Error, terjadi masalah saat penghitungan tanggal");
        return -1;
    }
    date_last_day.SetToLastMonthDay();
    int total_day=date_last_day.GetDay();
    return total_day;
}
wxString UmakPanel::GenReport(){
    wxString ret_html;
    if((year_comboBox->GetValue()!=wxEmptyString)&&(month_comboBox->GetValue()!=wxEmptyString)){
        ret_html<<"<html><head><title>Uang makan report</title></head><body>";
            if(conn.connected()){
                try{
                    mysqlpp::Query qry_staff=conn.query();
                    qry_staff<<"SELECT bs.FID, bs.nama, bs.NIK, CONCAT(bk.keterangan,' (',bk.kelas,')') AS kelas,"
                            <<"pangkat_golongan AS pangkat,"
                            <<"bpg.uang_makan, CONCAT('Rp ', FORMAT(bpg.uang_makan,0,'id_ID'),',-') AS uang_makan_rp"
                        <<" FROM bstaff bs"
                            " lEFT JOIN bkelas bk ON(bs.idbkelas = bk.idbkelas)"
                            " LEFT JOIN bpangkat_golongan bpg ON( bs.idbpangkat_golongan = bpg.idbpangkat_golongan)";
                    mysqlpp::StoreQueryResult res_staff=qry_staff.store();
                    if(res_staff){
                        for(size_t i=0; i<res_staff.num_rows(); ++i){
                            wxString FID=wxString::FromUTF8(res_staff[i]["FID"]);
                            wxString nama=wxString::FromUTF8(res_staff[i]["nama"]);
                            wxString NIK=wxString::FromUTF8(res_staff[i]["NIK"]);
                            wxString uang_makan_rp_str=wxString::FromUTF8(res_staff[i]["uang_makan_rp"]);
                            int uang_makan=wxAtoi(wxString::FromUTF8(res_staff[i]["uang_makan"]));
                            
                            ret_html.Append(HeaderReport(year_comboBox->GetValue(),month_comboBox->GetValue()));
                                ret_html<<"<div align=\"right\">"
                                    <<"<table width=\"400\" cellspacing=\"0\" cellpadding=\"1\">"
                                        <<"<tr>"
                                            <<"<td width=\"120\">Nama</td><td>:</td><td>"
                                                <<wxString::FromUTF8(res_staff[i]["nama"])
                                            <<"</td>"
                                        <<"</tr>"
                                        <<"<tr>"
                                            <<"<td>NIP</td><td>:</td><td>"
                                                <<wxString::FromUTF8(res_staff[i]["NIK"])
                                            <<"</td>"
                                        <<"</tr>"
                                        <<"<tr>"
                                            <<"<td>Jabatan</td><td>:</td><td>"
                                                <<wxString::FromUTF8(res_staff[i]["pangkat"])
                                            <<"</td>"
                                        <<"</tr>"
                                        <<"<tr>"
                                            <<"<td>Pangkat / Gol</td><td>:</td><td>"
                                                <<wxString::FromUTF8(res_staff[i]["kelas"])
                                            <<"</td>"
                                        <<"</tr>"
                                        <<"<tr>"
                                            <<"<td>Tunjangan harian:</td><td>:</td><td>"
                                                <<uang_makan_rp_str
                                            <<"</td>"
                                        <<"</tr>"
                                    <<"</table>"
                                <<"</div>";
                            //BEGIN TABLE REPORT========================
                            ret_html<<"<table border=\"1\" cellspacing=\"0\" style=\"border-collapse:collapse;\">";
                            ret_html<<"<tr bgcolor=\"#e0e0e0\">"
                                    <<"<td width=\"50\" align=\"center\">Tgl.</td>"
                                    <<"<td width=\"150\" align=\"center\">Jam Masuk</td>"
                                    <<"<td width=\"150\" align=\"center\">Jam Pulang</td>"
                                    <<"<td width=\"200\" align=\"center\">Tunjangan Harian</td>"
                                <<"</tr>";
                            //BEGIN LOOPING DAYS IN A SELECTED MONTH============================
                            int total_tunjangan=0;
                            int total_days=0;
                            for(int i=0; i<TotalDaySelected(); i++){
                                wxString date_attendance_str(year_comboBox->GetValue());
                                date_attendance_str.Append("-");
                                date_attendance_str.Append(month_comboBox->GetValue());
                                date_attendance_str.Append("-");
                                int day_attendance_num=i+1;
                                wxString day_attendance_str=wxString::Format("%i",day_attendance_num);
                                if(day_attendance_num<10){
                                    day_attendance_str.Prepend("0");
                                }
                                ret_html<<"<tr>";//OPEN TR LINE========
                                date_attendance_str.Append(day_attendance_str);
                                wxDateTime date_attendance;
                                date_attendance.ParseFormat(date_attendance_str, "%Y-%m-%d");
                                //BEGIN TANGGAL==================
                                ret_html<<"<td align=\"center\">"
                                        <<day_attendance_str
                                    <<"</td>";
                                //END TANGGAL********************
                                //BEGIN SKIPPING IF HOLIDAY===========================
                                    wxString day_name=date_attendance.Format(wxT("%A"));
                                    wxString nama_hari;
                                    if(day_name == wxString(wxT("Saturday"))){
                                        nama_hari = wxString(wxT("Sabtu"));
                                    }else if(day_name == wxString(wxT("Sunday"))){
                                        nama_hari = wxString(wxT("Minggu"));
                                    }
                                    //BEGIN WEEKEND HOLIDAY==============
                                    if(nama_hari != wxEmptyString){
                                        ret_html<<"<td colspan=\"3\" align=\"center\"><font color=\"#444444\">"
                                                <<nama_hari
                                            <<"</font></td>";
                                        continue;
                                    }
                                    //END WEEKEND HOLIDAY************
                                    //BEGIN CUSTOM/NATIONAL HOLIDAY==================
                                    wxString check_holiday=CheckHoliday(date_attendance_str);
                                    if(check_holiday!=wxEmptyString){
                                        ret_html<<"<td colspan=\"3\" align=\"center\"><font color=\"#444444\">"
                                                <<check_holiday
                                            <<"</font></td>";
                                        continue;
                                    }
                                    //BEGIN CUSTOM/NATIONAL HOLIDAY************
                                //END SKIPPING IF HOLIDAY***************//BEGIN JAM MASUK=================
                                mysqlpp::Query qry_jam_masuk=conn.query();
                                qry_jam_masuk<<"SELECT tl.Jam_Log AS jam_masuk"
                                    <<" FROM ta_log tl"
                                    <<" WHERE tl.Fid="<<(const_cast<char*>((const char*)FID.mb_str()))
                                        <<" AND tl.Tanggal_Log="
                                            <<mysqlpp::quote<<(const_cast<char*>((const char*)date_attendance.Format("%d/%m/%Y").mb_str()))
                                        <<" AND ISNULL(tl.user_input)"
                                    <<" ORDER BY TIME(tl.Jam_Log) ASC"
                                    <<" LIMIT 1";
                                mysqlpp::StoreQueryResult res_jam_masuk=qry_jam_masuk.store();
                                wxString jam_masuk_str="-";
                                wxDateTime jam_masuk_time;
                                if(res_jam_masuk){
                                    if(res_jam_masuk.num_rows()==1){
                                        wxString tmp_jam_masuk=wxString::FromUTF8(res_jam_masuk[0]["jam_masuk"]);
                                        jam_masuk_time.ParseTime(tmp_jam_masuk);
                                        jam_masuk_str=jam_masuk_time.FormatTime();
                                    }
                                }else{
                                    wxLogError(qry_jam_masuk.error());
                                }
                                ret_html<<"<td align=\"center\">"
                                        <<jam_masuk_str
                                    <<"</td>";
                                //END JAM MASUK***************************
                                //BEGIN JAM PULANG=================
                                mysqlpp::Query qry_jam_pulang=conn.query();
                                qry_jam_pulang<<"SELECT tl.Jam_Log AS jam_pulang"
                                    <<" FROM ta_log tl"
                                    <<" WHERE tl.Fid="<<(const_cast<char*>((const char*)FID.mb_str()))
                                        <<" AND tl.Tanggal_Log="
                                            <<mysqlpp::quote<<(const_cast<char*>((const char*)date_attendance.Format("%d/%m/%Y").mb_str()))
                                        <<" AND ISNULL(tl.user_input)"
                                    <<" ORDER BY TIME(tl.Jam_Log) DESC"
                                    <<" LIMIT 1";
                                mysqlpp::StoreQueryResult res_jam_pulang=qry_jam_pulang.store();
                                wxString jam_pulang_str="-";
                                wxDateTime jam_pulang_time;
                                if(res_jam_pulang){
                                    if(res_jam_pulang.num_rows()==1){
                                        wxString tmp_jam_pulang_str=wxString::FromUTF8(res_jam_pulang[0]["jam_pulang"]);
                                        if(tmp_jam_pulang_str!=jam_masuk_str){//IF IT SAME, IT IS MEAN ONLY HAVE 1 TIME REGISTERED
                                            jam_pulang_time.ParseTime(tmp_jam_pulang_str);
                                            jam_pulang_str=jam_pulang_time.FormatTime();
                                        }
                                    }
                                }else{
                                    wxLogError(qry_jam_pulang.error());
                                }
                                ret_html<<"<td align=\"center\">"
                                        <<jam_pulang_str
                                    <<"</td>";
                                //END JAM PULANG***************************
                                //BEGIN TUNJANGAN HARIAN=======================
                                wxString tunjangan_harian("-");
                                if((jam_masuk_str != wxString("-"))
                                    ||(jam_pulang_str != wxString("-"))
                                ){
                                    total_days++;
                                    total_tunjangan = total_tunjangan + uang_makan;
                                    tunjangan_harian = uang_makan_rp_str;
                                }
                                ret_html<<"<td align=\"center\">"
                                        <<tunjangan_harian
                                    <<"</td>";
                                //END TUNJANGAN HARIAN***************
                                ret_html<<"</tr>";//CLOSE TR TAG***************************************************
                            }
                            //END LOOPING DAYS IN A SELECTED MONTH**********************
                            //BEGIN SUMMARY ROW======================
                            wxString total_tunjangan_str=wxString::Format(wxT("%i"),total_tunjangan);
                            ret_html
                                <<"<tr height=\"3\" bgcolor=\"#000000\" border=\"0\"><td colspan=\"12\"></td></tr>"
                                <<"<tr>"
                                    <<"<td colspan=\"3\" align=\"right\"><font size=\"+1\"><b>Total tunjangan ( "
                                        <<wxString::Format(wxT("%i"),total_days)<<" hari kerja )</b></font></td>"
                                    <<"<td><font size=\"+1\"><b>"<<BCurrencyFormat(total_tunjangan_str,wxString("Rp"))<<"</b></font></td>"
                                <<"</tr>";
                            //END SUMARRY ROW*****************
                            ret_html<<"</table>";
                            //END TABLE REPORT************************
                            
                            ret_html<<"<div style=\"page-break-before:always\"></div>";
                        }
                    }else{
                        wxString error_msg = wxString("Error saat query database pegawai: ");
                        error_msg.Append(qry_staff.error());
                        wxLogError(error_msg);
                    }
                }catch(mysqlpp::Exception &e){
                    wxLogError(e.what());
                }
            }else{
                wxLogError("Error, database tidak terkoneksi.");
            }
        ret_html<<"</body></html>";
    }else{
        wxLogError("Error, harap pilih tahun dan bulan.");
    }
    return ret_html;
}
void UmakPanel::OnTampil( wxCommandEvent& event ){
    umak_html = GenReport();
    umak_htmlWin->SetPage(umak_html);
}
void UmakPanel::OnCetak( wxCommandEvent& event ){
    if(umak_html == wxEmptyString){
        umak_html = GenReport();
    }
    b_print->PreviewText(umak_html);
}
wxString UmakPanel::HeaderReport(wxString p_year, wxString p_month){
    wxString ret_html;
    
    ret_html<<"<table>"
            <<"<tr>"
                <<"<td><img src=\"images/logo_report.png\" alt=\"Report logo\"></td>"
                <<"<td><font face=\"arial,helvetica, sans-serif, sans\" size=\"+1\"><b>Kantor Pertanahan Kabupaten Jepara</b></font>"
                    <<"<br><font face=\"arial,helvetica, sans-serif, sans\" size=\"+1\">Tunjangan Harian</font>"
                    <<"<br><font face=\"arial,helvetica, sans-serif, sans\" size=\"+1\">"
                        <<"Bulan: "
                        <<BGetMonthName(p_month)
                        <<", Tahun: "
                        <<p_year
                    <<"</font>"
                <<"</td>"
            <<"</tr>"
        <<"</table>";
    return ret_html;
}
wxString UmakPanel::CheckHoliday(wxString p_date_str){
    wxString ret_str(wxEmptyString);
    if(conn.connected()){
        mysqlpp::Query qry=conn.query();
        qry<<"SELECT * FROM bhari_libur"
            <<" WHERE tgl="<<mysqlpp::quote<<(const_cast<char*>((const char*)p_date_str.mb_str()));
        mysqlpp::StoreQueryResult res=qry.store();
        if(res){
            if(res.num_rows()==1){
                ret_str=wxString::FromUTF8(res[0]["keterangan"]);
            }
        }else{
            wxString err_msg(wxT("Error query database:CheckHoliday->"));
            err_msg<<qry.error();
            wxLogError(err_msg);
        }
    }else{
        wxLogError("Error, database tidak terkoneksi.");
    }
    return ret_str;
}
