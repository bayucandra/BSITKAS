#include "tukin_panel.h"

TukinPanel::TukinPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
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
	
	tukin_htmlWin = new wxHtmlWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO|wxSTATIC_BORDER );
	bSizer47->Add( tukin_htmlWin, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer47 );
	this->Layout();
	bSizer47->Fit( this );
	
	// Connect Events
	tampilkan_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TukinPanel::OnTampilTukin ), NULL, this );
        
        //BEGIN BAYU=============
        tukin_htmlWin->SetPage("<html><head><title>Init</title></head><body><br><br><br><center><img src=\"images/logo_report.png\"></center></body></html>");
        InitYear();
        InitMonth();
        InitCurDateCombo();
}

TukinPanel::~TukinPanel()
{
	// Disconnect Events
	tampilkan_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TukinPanel::OnTampilTukin ), NULL, this );
	
}

void TukinPanel::InitCurDateCombo(){
    wxDateTime date_today=wxDateTime::Today();
    wxString year=date_today.Format("%Y");
    wxString month=date_today.Format("%m");
    
    year_comboBox->SetValue(year);
    month_comboBox->SetValue(month);
}
void TukinPanel::InitYear(){
    int year_start=2010;
    for(int i=0; i<30; i++){
        year_comboBox->Append(wxString::Format(wxT("%i"),year_start));
        year_start++;
    }
}
void TukinPanel::InitMonth(){
    for(int i=0;i<12;i++){
        int month_no=i+1;
        wxString month_no_str=wxString::Format(wxT("%i"),month_no);
        if(i<9){
            month_no_str.Prepend(wxT("0"));
        }
        month_comboBox->Append(month_no_str);
    }
}
wxString TukinPanel::GetAlasan(wxDateTime p_date, wxString p_FID){
    wxString ret_str=wxEmptyString;
    wxString date_str=p_date.Format("%Y-%m-%d");
    char* date_char=(const_cast<char*>((const char*)date_str.mb_str()));
    char* FID=(const_cast<char*>((const char*)p_FID.mb_str()));
    bool is_izin=false;
    bool is_dinas_luar=false;
    bool is_surat_tugas=false;
    if(conn.connected()){
        //BEGIN CHECK IZIN=================
        try{
            mysqlpp::Query qry_izin=conn.query();
            qry_izin<<"SELECT * FROM bizin"
                <<" WHERE tgl="<<mysqlpp::quote<<date_char
                    <<" AND FID="<<FID;
            mysqlpp::StoreQueryResult res_izin=qry_izin.store();
            if(res_izin){
                if(res_izin.num_rows()==1){
                    is_izin=true;
                }
            }else{
                wxString err_msg(wxT("Error query bizin:"));
                err_msg<<qry_izin.error();
                wxLogError(err_msg);
            }
        }catch(mysqlpp::Exception &e){
            wxLogError(e.what());
        }
        //END CHECK IZIN********************
        //BEGIN CHECK DINAS LUAR============
        try{
            mysqlpp::Query qry_dinas_luar=conn.query();
            qry_dinas_luar<<"SELECT * FROM bdinas_luar"
                <<" WHERE tgl="<<mysqlpp::quote<<date_char
                    <<" AND FID="<<FID;
            mysqlpp::StoreQueryResult res_dinas_luar=qry_dinas_luar.store();
            if(res_dinas_luar){
                if(res_dinas_luar.num_rows()==1){
                    is_dinas_luar=true;
                }
            }else{
                wxString err_msg(wxT("Error query bdinas_luar:"));
                err_msg<<qry_dinas_luar.error();
                wxLogError(err_msg);
            }
        }catch(mysqlpp::Exception &e){
            wxLogError(e.what());
        }
        //END CHECK DINAS LUAR****************
        //BEGIN CHECK SURAT TUGAS============
        try{
            mysqlpp::Query qry_surat_tugas=conn.query();
            qry_surat_tugas<<"SELECT * FROM bsurat_tugas"
                <<" WHERE tgl="<<mysqlpp::quote<<date_char
                    <<" AND FID="<<FID;
            mysqlpp::StoreQueryResult res_surat_tugas=qry_surat_tugas.store();
            if(res_surat_tugas){
                if(res_surat_tugas.num_rows()==1){
                    is_surat_tugas=true;
                }
            }else{
                wxString err_msg(wxT("Error query bsurat_tugas:"));
                err_msg<<qry_surat_tugas.error();
                wxLogError(err_msg);
            }
        }catch(mysqlpp::Exception &e){
            wxLogError(e.what());
        }
        //END CHECK SURAT TUGAS****************
    }else{
        wxLogError(wxT("Error, database tidak terkoneksi!!!"));
    }
    if(
        (is_izin&&is_dinas_luar)
        ||(is_izin&&is_surat_tugas)
        ||(is_dinas_luar&&is_surat_tugas)
    ){
        wxString error_str(wxT("Error, duplikasi tanggal yang sama untuk: "));
        if(is_izin){error_str.Append("Izin, ");}
        if(is_dinas_luar){error_str.Append("Dinas luar");}
        if(is_surat_tugas){error_str.Append("Surat tugas");}
        error_str<<"(Tgl:"<<p_date.Format("%d/%m/%Y")<<")";
        ret_str=error_str;
    }else{
        if(is_izin){ret_str=wxString("Izin");}
        if(is_dinas_luar){ret_str=wxString("Dinas luar");}
        if(is_surat_tugas){ret_str=wxString("Surat tugas");}
    }
    return ret_str;
}
wxString TukinPanel::CheckHoliday(wxString p_date_str){
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
wxString TukinPanel::GenTukin(){
    wxString ret_html;
    if((year_comboBox->GetValue()!=wxEmptyString)&&(month_comboBox->GetValue()!=wxEmptyString)){
        ret_html.Append("<html><head><title>Tukin view</title></head><body>");
            if(conn.connected()){
                try{
                    mysqlpp::Query qry_staff=conn.query();
                    qry_staff<<"SELECT bs.FID, bs.nama, bs.NIK, bk.kelas, bk.tunjangan_perbulan,"
                            <<"CONCAT('Rp ',FORMAT(bk.tunjangan_perbulan,0,'id_ID'),',-') AS tunjangan_perbulan_rp,"
                            <<"CONCAT(bpg.pangkat_golongan,' - ',bpg.keterangan) AS pangkat,"
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
                            wxString tunjangan_perbulan_str=wxString::FromUTF8(res_staff[i]["tunjangan_perbulan"]);
                            
                            ret_html.Append(HeaderTukin(year_comboBox->GetValue(),month_comboBox->GetValue()));
                                ret_html<<"<div align=\"right\">"
                                    <<"<table width=\"400\" cellspacing=\"0\">"
                                        <<"<tr>"
                                            <<"<td width=\"120\">Nama</td>:<td></td><td>"
                                                <<wxString::FromUTF8(res_staff[i]["nama"])
                                            <<"</td>"
                                        <<"</tr>"
                                        <<"<tr>"
                                            <<"<td>NIP</td>:<td></td><td>"
                                                <<wxString::FromUTF8(res_staff[i]["NIK"])
                                            <<"</td>"
                                        <<"</tr>"
                                        <<"<tr>"
                                            <<"<td>Golongan/Jabatan</td>:<td></td><td>"
                                                <<wxString::FromUTF8(res_staff[i]["pangkat"])
                                            <<"</td>"
                                        <<"</tr>"
                                        <<"<tr>"
                                            <<"<td>Kelas jabatan</td>:<td></td><td>"
                                                <<wxString::FromUTF8(res_staff[i]["kelas"])
                                            <<"</td>"
                                        <<"</tr>"
                                        <<"<tr>"
                                            <<"<td>Tunjangan</td>:<td></td><td>"
                                                <<wxString::FromUTF8(res_staff[i]["tunjangan_perbulan_rp"])
                                            <<"</td>"
                                        <<"</tr>"
                                    <<"</table>"
                                <<"</div>";
                            //BEGIN TABLE REPORT========================
                            ret_html<<"<table border=\"1\" cellspacing=\"0\">";
                            ret_html<<"<tr>"
                                    <<"<td colspan=\"1\" rowspan=\"2\">Tgl.</td>"
                                    <<"<td colspan=\"1\" rowspan=\"2\">Jam Masuk</td>"
                                    <<"<td colspan=\"1\" rowspan=\"2\">Jam Pulang</td>"
                                    <<"<td colspan=\"4\" align=\"center\">Status Absensi (dalam menit)</td>"
                                    <<"<td colspan=\"2\" align=\"center\">Total Keterlambatan (dalam menit)</td>"
                                    <<"<td colspan=\"1\" rowspan=\"2\" width=\"150\">Alasan absensi</td>"
                                    <<"<td colspan=\"2\" align=\"center\">Pengurangan</td>"
                                <<"</tr>"
                                <<"<tr>"
                                    <<"<td width=\"70\" align=\"center\">Masuk cepat</td>"
                                    <<"<td width=\"70\" align=\"center\">Masuk terlambat</td>"
                                    <<"<td width=\"70\" align=\"center\">Pulang cepat</td><td width=\"70\">Pulang Terlambat</td>"
                                    
                                    <<"<td width=\"70\" align=\"center\"><font color=\"#FF0000\">Masuk terlambat</font></td>"
                                    <<"<td width=\"70\" align=\"center\"><font color=\"#FF0000\">Pulang cepat</font></td>"
                                    
                                    <<"<td width=\"120\">Rincian</td>"
                                    <<"<td width=\"50\">Total</td>"
                                <<"</tr>"
                                ;
//                            ret_html.Append(report_header);
                            float total_persentasi_potongan=0;
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
                                ret_html<<"<td>"
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
                                        ret_html<<"<td colspan=\"11\" align=\"center\"><font color=\"#444444\">"
                                                <<nama_hari
                                            <<"</font></td>";
                                        continue;
                                    }
                                    //END WEEKEND HOLIDAY************
                                    //BEGIN CUSTOM/NATIONAL HOLIDAY==================
                                    wxString check_holiday=CheckHoliday(date_attendance_str);
                                    if(check_holiday!=wxEmptyString){
                                        ret_html<<"<td colspan=\"11\" align=\"center\"><font color=\"#444444\">"
                                                <<check_holiday
                                            <<"</font></td>";
                                        continue;
                                    }
                                    //BEGIN CUSTOM/NATIONAL HOLIDAY************
                                //END SKIPPING IF HOLIDAY***************
                                //BEGIN JAM MASUK=================
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
                                //BEGIN MASUK AWAL=====================================
                                wxString jam_masuk_awal_str="-";
                                wxTimeSpan jam_masuk_awal_span;
                                wxDateTime jam_masuk_awal_time;
                                if(jam_masuk_str!="-"){
                                    jam_masuk_awal_span=jam_masuk_time.Subtract(gjam_masuk_awal);
                                    if(jam_masuk_awal_span.GetMinutes()<=0){
                                        wxString tmp_jam_masuk_awal_str(wxT("00:30:00"));
                                        jam_masuk_awal_time.ParseTime(tmp_jam_masuk_awal_str);
                                        jam_masuk_awal_str=wxString::Format(wxT("%i"),jam_masuk_awal_time.GetMinute());
                                    }
                                }
                                ret_html<<"<td align=\"center\">"
                                        <<jam_masuk_awal_str
                                    <<"</td>";
                                //END MASUK AWAL**************************
                                //BEGIN MASUK TERLAMBAT========================
                                wxString jam_masuk_terlambat_str="-";
                                wxTimeSpan jam_masuk_terlambat_span;
                                wxDateTime jam_masuk_terlambat_time;
                                if(jam_masuk_str!="-"){
                                    jam_masuk_terlambat_span=jam_masuk_time.Subtract(gjam_masuk);
                                    if(jam_masuk_terlambat_span.GetMinutes()>0){
                                        jam_masuk_terlambat_str=wxString::Format(wxT("%i"),jam_masuk_terlambat_span.GetMinutes());
                                    }
                                }
                                ret_html<<"<td align=\"center\">"
                                        <<jam_masuk_terlambat_str
                                    <<"</td>";
                                //END MASUK TERLAMBAT**********************
                                //BEGIN PULANG CEPAT======================
                                wxString jam_pulang_cepat_str="-";
                                wxTimeSpan jam_pulang_cepat_span;
                                wxDateTime jam_pulang_cepat_time;
                                if(jam_pulang_str!="-"){
                                    jam_pulang_cepat_span=gjam_pulang.Subtract(jam_pulang_time);
                                    if(jam_pulang_cepat_span.GetMinutes()>0){
                                        jam_pulang_cepat_str=wxString::Format(wxT("%i"),jam_pulang_cepat_span.GetMinutes());
                                    }
                                }
                                ret_html<<"<td align=\"center\">"
                                        <<jam_pulang_cepat_str
                                    <<"</td>";
                                //END PULANG CEPAT***********
                                //BEGIN PULANG TERLAMBAT==============
                                wxString jam_pulang_terlambat_str="-";
                                wxTimeSpan jam_pulang_terlambat_span;
                                wxDateTime jam_pulang_terlambat_time;
                                if(jam_pulang_str!="-"){
                                    jam_pulang_terlambat_span=jam_pulang_time.Subtract(gjam_pulang);
                                    if(jam_pulang_terlambat_span.GetMinutes()>0){
                                        jam_pulang_terlambat_str=wxString::Format(wxT("%i"),jam_pulang_terlambat_span.GetMinutes());
                                    }
                                }
                                ret_html<<"<td align=\"center\">"
                                        <<jam_pulang_terlambat_str
                                    <<"</td>";
                                //END PULANG TERLAMBAT****************
                                //BEGIN JAM MASUK KURANG============
                                wxString jam_masuk_kurang_str="-";
                                if(jam_masuk_terlambat_str!="-"){
                                    int jam_masuk_kurang_int=wxAtoi(jam_masuk_terlambat_str);
                                    int jam_pulang_lebih_int=0;
                                    if(jam_pulang_terlambat_str!="-"){
                                        jam_pulang_lebih_int=wxAtoi(jam_pulang_terlambat_str);
                                    }
                                    if(jam_masuk_kurang_int>jam_pulang_lebih_int){
                                        int total_jam_masuk_kurang=jam_masuk_kurang_int-jam_pulang_lebih_int;
                                        jam_masuk_kurang_str=wxString::Format(wxT("%i"),total_jam_masuk_kurang);
                                    }
                                }
                                ret_html<<"<td align=\"center\">"
                                        <<jam_masuk_kurang_str
                                    <<"</td>";
                                //END JAM MASUK KURANG***************
                                //BEGIN JAM PULANG KURANG=====================
                                wxString jam_pulang_kurang_str="-";
                                if(jam_pulang_cepat_str!="-"){
                                    int jam_pulang_kurang_int=wxAtoi(jam_pulang_cepat_str);
                                    int jam_masuk_lebih_int=0;
                                    if(jam_masuk_awal_str!="-"){
                                        jam_masuk_lebih_int=wxAtoi(jam_masuk_awal_str);
                                    }
                                    if(jam_masuk_lebih_int<jam_pulang_kurang_int){
                                        int total_jam_pulang_kurang=jam_pulang_kurang_int-jam_masuk_lebih_int;
                                        jam_pulang_kurang_str=wxString::Format(wxT("%i"),total_jam_pulang_kurang);
                                    }
                                }
                                ret_html<<"<td align=\"center\">"
                                        <<jam_pulang_kurang_str
                                    <<"</td>";
                                //END JAM PULANG KURANG*****************
                                //BEGIN ALASAN ABSENSI==============
                                wxString alasan_absensi_str("-");
                                wxString tmp_alasan_absensi_str=GetAlasan(date_attendance, FID);
                                if(tmp_alasan_absensi_str!=wxEmptyString){
                                    alasan_absensi_str=tmp_alasan_absensi_str;
                                }
                                ret_html<<"<td align=\"left\">"
                                        <<alasan_absensi_str
                                    <<"</td>";
                                //END ALASAN ABSENSI********************
                                //BEGIN RINCIAN PENGURANGAN TUNJANGAN=================
                                float total_pengurangan=0.0;
                                wxString rincian_pengurangan_str="-";
                                wxString tmp_rincian_pengurangan_str=wxEmptyString;
                                if(alasan_absensi_str==wxString("-")){
                                    if(jam_masuk_kurang_str!="-"){
                                        total_pengurangan=total_pengurangan+0.5;
                                        tmp_rincian_pengurangan_str<<"-Masuk terlambat=0.5%<br>";
                                    }
                                    if(jam_pulang_kurang_str!="-"){
                                        total_pengurangan=total_pengurangan+0.5;
                                        tmp_rincian_pengurangan_str<<"-Pulang cepat=0.5%<br>";
                                    }
                                    if(
                                            (jam_masuk_str == wxString("-"))
                                            &&(jam_pulang_str == wxString("-"))
                                    ){//TANPA KETERANGAN=========
                                        total_pengurangan=total_pengurangan+3;
                                        tmp_rincian_pengurangan_str<<"-Tanpa keterangan=3%<br>";
                                    }
                                }else if(alasan_absensi_str==wxString("Izin")){
                                    total_pengurangan=total_pengurangan+1.5;
                                    tmp_rincian_pengurangan_str<<"-Izin=1.5%<br>";
                                }
                                if(tmp_rincian_pengurangan_str!=wxEmptyString){
                                    tmp_rincian_pengurangan_str=tmp_rincian_pengurangan_str.Mid(0,tmp_rincian_pengurangan_str.Len()-4);
                                    rincian_pengurangan_str=tmp_rincian_pengurangan_str;
                                }
                                ret_html<<"<td align=\"left\">"
                                        <<rincian_pengurangan_str
                                    <<"</td>";
                                //END RINCIAN PENGURANGAN TUNJANGAN***************
                                //BEGIN TOTAL PENGURANGAN====================
                                wxString total_pengurangan_str(wxT("-"));
                                if(total_pengurangan>0){
                                    total_pengurangan_str=BFloatToWxString(total_pengurangan);
                                    total_pengurangan_str<<"% ";
                                }
                                ret_html<<"<td align=\"right\">"
                                        <<total_pengurangan_str
                                    <<"</td>";
                                total_persentasi_potongan=total_persentasi_potongan+total_pengurangan;
                                //END TOTAL PENGURANGAN***************
                                ret_html<<"</tr>";//CLOSE TR LINE**********************************************************************************
                            }
                            //BEGIN SUMARY TABLE======================
                            double tunjangan_perbulan_double;
                            float tunjangan_perbulan;
                            tunjangan_perbulan_str.ToDouble(&tunjangan_perbulan_double);
                            tunjangan_perbulan=static_cast<float>(tunjangan_perbulan_double);
                            float total_rupiah_potongan = tunjangan_perbulan*total_persentasi_potongan/100;
                            float total_tunjangan_diterima = tunjangan_perbulan - total_rupiah_potongan;
                            ret_html
                                <<"<tr height=\"5\" bgcolor=\"#000000\" border=\"0\"><td colspan=\"12\"></td></tr>"
                                <<"<tr>"
                                    <<"<td colspan=\"9\" align=\"right\"><font size=\"+1\"><b>Total persentasi potongan</b></font></td>"
                                    <<"<td colspan=\"3\" align=\"left\"><font size=\"+1\"><b>"
                                        <<BFloatToWxString(total_persentasi_potongan)
                                    <<"%</b></font></td>"
                                <<"</tr>"
                                <<"<tr>"
                                    <<"<td colspan=\"9\" align=\"right\"><font size=\"+1\"><b>Total rupiah potongan</b></font></td>"
                                    <<"<td colspan=\"3\" align=\"left\">"
                                        <<"<span style=\"font-size:9pt;\">"<<BCurrencyFormat(BFloatToWxString(tunjangan_perbulan),wxString("Rp"))
                                            <<" x "<<BFloatToWxString(total_persentasi_potongan)<<"</span>"
                                        <<"% <br><b><font size=\"+1\">= "<<BCurrencyFormat(BFloatToWxString(total_rupiah_potongan),wxString("Rp"))
                                    <<"</b></font></td>"
                                <<"</tr>"
                                <<"<tr>"
                                    <<"<td colspan=\"9\" align=\"right\"><font size=\"+1\"><b>Total Tunjangan diterima</b></font></td>"
                                    <<"<td colspan=\"3\" align=\"left\">"
                                        <<BCurrencyFormat(BFloatToWxString(tunjangan_perbulan),wxString("Rp"))
                                            <<" - "<<BCurrencyFormat(BFloatToWxString(total_rupiah_potongan),wxString("Rp"))
                                        <<" <br><font size=\"+1\"><b>= "<<BCurrencyFormat(BFloatToWxString(total_tunjangan_diterima),wxString("Rp"))
                                    <<"</b></font></td>"
                                <<"</tr>";
                            //END SUMARY TABLE***********
                            ret_html<<"</table>";
                            //END TABLE REPORT========================
                            
                            ret_html.Append("<div style=\"page-break-before:always\"></div>");
                        }
                    }else{
                        wxString error_msg=wxString("Error saat query database pegawai: ");
                        error_msg.Append(qry_staff.error());
                        wxLogError(error_msg);
                    }

                }catch(mysqlpp::Exception &e){
                    wxLogError(e.what());
                }
            }else{
                wxLogError("Error, database tidak terkoneksi.");
            }
        ret_html.Append("</body></html>");
    }else{
        wxLogError("Error, Harap pilih tahun dan bulan.");
    }
    return ret_html;
}

void TukinPanel::OnTampilTukin( wxCommandEvent& event ){
    tukin_htmlWin->SetPage(GenTukin());
}
wxString TukinPanel::HeaderTukin(wxString p_year, wxString p_month){
    wxString ret_html;
//    wxString str_date_selected=p_year;
//    str_date_selected.Append("-"); str_date_selected.Append(p_month);
//    str_date_selected.Append("-"); str_date_selected.Append("01");
//    wxDateTime date_selected=wxDateTime::ParseFormat(str_date_selected, "%Y-%m-%d");
    
    ret_html.Append("<table>");
        ret_html.Append("<tr>");
            ret_html.Append("<td><img src=\"images/logo_report.png\" alt=\"Report logo\"></td>");
            ret_html.Append("<td><font face=\"arial,helvetica, sans-serif, sans\" size=\"+1\"><b>Kantor Pertanahan Kabupaten Jepara</b></font>");
                ret_html.Append("<br><font face=\"arial,helvetica, sans-serif, sans\" size=\"+1\">Tunjangan kinerja pegawai</font>");
                ret_html.Append("<br><font face=\"arial,helvetica, sans-serif, sans\" size=\"+1\">");
                    ret_html.Append("Bulan: ");
                    ret_html.Append(BGetMonthName(p_month));
                    ret_html.Append(", Tahun: ");
                    ret_html.Append(p_year);
                ret_html.Append("</font>");
            ret_html.Append("</td>");
        ret_html.Append("</tr>");
    ret_html.Append("</table>");
    return ret_html;
}
int TukinPanel::TotalDaySelected(){
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
