///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __NONAME_H__
#define __NONAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
class MenuButton;

#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/notebook.h>
#include <wx/frame.h>
#include <wx/textctrl.h>
#include <wx/dialog.h>
#include <wx/dataview.h>
#include <wx/splitter.h>
#include <wx/statbox.h>
#include <wx/combobox.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/html/htmlwin.h>

///////////////////////////////////////////////////////////////////////////

#define ID_Minimize 1000
#define ID_Maximize 1001
#define ID_Setting 1002
#define ID_menu_tukin_btn 1003
#define ID_menu_umak_btn 1004
#define ID_menu_absensi_btn 1005
#define ID_menu_pegawai_btn 1006
#define ID_menu_kepank_btn 1007
#define ID_DLG_SETTING_save 1008
#define ID_tambah_kelas 1009
#define ID_ubah_kelas 1010
#define ID_hapus_kelas 1011
#define ID_tambah_pangkat 1012
#define ID_ubah_pangkat 1013
#define ID_hapus_pangkat 1014

///////////////////////////////////////////////////////////////////////////////
/// Class BFrame
///////////////////////////////////////////////////////////////////////////////
class BFrame : public wxFrame 
{
	private:
	
	protected:
		wxStaticBitmap* m_bitmapLogo;
		wxStaticText* header_SI_staticText;
		wxStaticText* header_staticText1;
		wxBitmapButton* Minimize_bpButton;
		wxBitmapButton* Maximize_bpButton;
		wxBitmapButton* Close_bpButton;
		wxBitmapButton* Setting_bpButton;
		wxPanel* menu_panel;
		MenuButton* menu_tukin_button;
		MenuButton* menu_umak_button;
		MenuButton* menu_absensi_button;
		MenuButton* menu_pegawai_button;
		MenuButton* menu_kepank_button;
		wxNotebook* main_notebook;
	
	public:
		
		BFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("SITKAS"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 900,550 ), long style = wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLIP_CHILDREN|wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
		
		~BFrame();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class BSettingDialog
///////////////////////////////////////////////////////////////////////////////
class BSettingDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* MySQLServer_staticText;
		wxTextCtrl* MySQLServer_textCtrl;
		wxStaticText* m_staticText9;
		wxTextCtrl* MySQLUsername_textCtrl;
		wxStaticText* m_staticText10;
		wxTextCtrl* MySQLPassword_textCtrl;
		wxStaticText* m_staticText11;
		wxTextCtrl* MySQLDBName_textCtrl;
		wxButton* Simpan_button;
	
	public:
		
		BSettingDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Setting"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,400 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~BSettingDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class KelasPanel
///////////////////////////////////////////////////////////////////////////////
class KelasPanel : public wxPanel 
{
	private:
	
	protected:
		wxButton* tambah_kelas_button;
		wxButton* ubah_kelas_button;
		wxButton* hapus_kelas_button;
		wxDataViewListCtrl* kelas_dataViewListCtrl;
	
	public:
		
		KelasPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL ); 
		~KelasPanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class KelasInputDialog
///////////////////////////////////////////////////////////////////////////////
class KelasInputDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* kelas_staticText;
		wxTextCtrl* kelas_textCtrl;
		wxStaticText* keterangan_staticText;
		wxTextCtrl* keterangan_textCtrl;
		wxStaticText* tunjangan_perbulan_staticText;
		wxTextCtrl* tunjangan_perbulan_textCtrl;
		wxButton* tambah_button;
		wxButton* reset_button;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSimpan( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnReset( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		KelasInputDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,200 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~KelasInputDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class PangkatPanel
///////////////////////////////////////////////////////////////////////////////
class PangkatPanel : public wxPanel 
{
	private:
	
	protected:
		wxButton* tambah_button;
		wxButton* ubah_button;
		wxButton* hapus_button;
		wxDataViewListCtrl* pangkat_dataViewListCtrl;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnTambahPangkat( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUbahPangkat( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHapusPangkat( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		PangkatPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL ); 
		~PangkatPanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class PangkatInputDialog
///////////////////////////////////////////////////////////////////////////////
class PangkatInputDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* staticText1;
		wxTextCtrl* pangkat_textCtrl;
		wxStaticText* staticText2;
		wxTextCtrl* keterangan_textCtrl;
		wxStaticText* staticText3;
		wxTextCtrl* uang_makan_textCtrl;
		wxButton* simpan_button;
		wxButton* reset_button;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSimpan( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnReset( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		PangkatInputDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,200 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~PangkatInputDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class PegawaiPanel
///////////////////////////////////////////////////////////////////////////////
class PegawaiPanel : public wxPanel 
{
	private:
	
	protected:
		wxSplitterWindow* pegawai_splitter;
		wxPanel* pegawai_panel;
		wxButton* ubah_button;
		wxButton* hapus_button;
		wxDataViewListCtrl* pegawai_dataViewListCtrl;
		wxPanel* pegawai_data_lama_panel;
		wxButton* salin_button;
		wxDataViewListCtrl* pegawai_data_lama_dataViewListCtrl;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnUbah( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHapus( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSalin( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		PegawaiPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL ); 
		~PegawaiPanel();
		
		void pegawai_splitterOnIdle( wxIdleEvent& )
		{
			pegawai_splitter->SetSashPosition( 0 );
			pegawai_splitter->Disconnect( wxEVT_IDLE, wxIdleEventHandler( PegawaiPanel::pegawai_splitterOnIdle ), NULL, this );
		}
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class PegawaiSalinDialog
///////////////////////////////////////////////////////////////////////////////
class PegawaiSalinDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText15;
		wxTextCtrl* FID_textCtrl;
		wxStaticText* m_staticText16;
		wxTextCtrl* Nama_textCtrl;
		wxStaticText* m_staticText17;
		wxTextCtrl* NIK_textCtrl;
		wxStaticText* m_staticText18;
		wxComboBox* kelas_comboBox;
		wxStaticText* m_staticText19;
		wxComboBox* pangkat_comboBox;
		wxButton* simpan_button;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSalin( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		PegawaiSalinDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Salin Pegawai (data lama)"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,250 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~PegawaiSalinDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class AbsensiPanel
///////////////////////////////////////////////////////////////////////////////
class AbsensiPanel : public wxPanel 
{
	private:
	
	protected:
		wxButton* tambah_button;
		wxButton* ubah_button;
		wxButton* hapus_button;
		wxDataViewListCtrl* absensi_dataViewListCtrl;
		wxPanel* footer_panel;
		wxStaticText* m_staticText20;
		wxDatePickerCtrl* start_datePicker;
		wxStaticText* m_staticText21;
		wxDatePickerCtrl* end_datePicker;
		wxStaticText* m_staticText22;
		wxTextCtrl* m_textCtrl14;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnTambah( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUbah( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHapus( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFilterData( wxDateEvent& event ) { event.Skip(); }
		virtual void OnFilterData( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		AbsensiPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL ); 
		~AbsensiPanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class LupaAbsenPanel
///////////////////////////////////////////////////////////////////////////////
class LupaAbsenPanel : public wxPanel 
{
	private:
	
	protected:
		wxButton* tambah_button;
		wxButton* ubah_button;
		wxButton* hapus_button;
		wxDataViewListCtrl* dinas_luar_dataViewListCtrl;
		wxPanel* footer_panel;
		wxStaticText* m_staticText20;
		wxDatePickerCtrl* start_datePicker;
		wxStaticText* m_staticText21;
		wxDatePickerCtrl* end_datePicker;
		wxStaticText* m_staticText22;
		wxTextCtrl* filter_nama_textCtrl;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnTambah( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUbah( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHapus( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFilterData( wxDateEvent& event ) { event.Skip(); }
		virtual void OnFilterData( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		LupaAbsenPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL ); 
		~LupaAbsenPanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class LupaAbsenDialog
///////////////////////////////////////////////////////////////////////////////
class LupaAbsenDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText26;
		wxTextCtrl* FID_textCtrl;
		wxTextCtrl* nama_textCtrl;
		wxStaticText* m_staticText27;
		wxDatePickerCtrl* tgl_datePicker;
		wxStaticText* m_staticText28;
		wxTextCtrl* keterangan_textCtrl;
		wxButton* simpan_button;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnDaftarPegawaiDialog( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnSimpan( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		LupaAbsenDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 450,180 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~LupaAbsenDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class HariLiburPanel
///////////////////////////////////////////////////////////////////////////////
class HariLiburPanel : public wxPanel 
{
	private:
	
	protected:
		wxButton* tambah_button;
		wxButton* ubah_button;
		wxButton* hapus_button;
		wxDataViewListCtrl* hari_libur_dataViewListCtrl;
		wxPanel* footer_panel;
		wxStaticText* m_staticText20;
		wxDatePickerCtrl* start_datePicker;
		wxStaticText* m_staticText21;
		wxDatePickerCtrl* end_datePicker;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnTambah( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUbah( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHapus( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFilterData( wxDateEvent& event ) { event.Skip(); }
		
	
	public:
		
		HariLiburPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL ); 
		~HariLiburPanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class HariLiburDialog
///////////////////////////////////////////////////////////////////////////////
class HariLiburDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText27;
		wxDatePickerCtrl* tgl_datePicker;
		wxStaticText* m_staticText28;
		wxTextCtrl* keterangan_textCtrl;
		wxButton* simpan_button;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSimpan( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		HariLiburDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 450,180 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~HariLiburDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class IzinPanel
///////////////////////////////////////////////////////////////////////////////
class IzinPanel : public wxPanel 
{
	private:
	
	protected:
		wxButton* tambah_button;
		wxButton* ubah_button;
		wxButton* hapus_button;
		wxDataViewListCtrl* izin_dataViewListCtrl;
		wxPanel* footer_panel;
		wxStaticText* m_staticText20;
		wxDatePickerCtrl* start_datePicker;
		wxStaticText* m_staticText21;
		wxDatePickerCtrl* end_datePicker;
		wxStaticText* m_staticText22;
		wxTextCtrl* filter_nama_textCtrl;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnTambah( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUbah( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHapus( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFilterData( wxDateEvent& event ) { event.Skip(); }
		virtual void OnFilterData( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		IzinPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL ); 
		~IzinPanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class IzinDialog
///////////////////////////////////////////////////////////////////////////////
class IzinDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText26;
		wxTextCtrl* FID_textCtrl;
		wxTextCtrl* nama_textCtrl;
		wxStaticText* m_staticText27;
		wxDatePickerCtrl* tgl_datePicker;
		wxStaticText* m_staticText28;
		wxTextCtrl* keterangan_textCtrl;
		wxButton* simpan_button;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnDaftarPegawaiDialog( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnSimpan( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		IzinDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 450,180 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~IzinDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class IzinDaftarPegawaiDialog
///////////////////////////////////////////////////////////////////////////////
class IzinDaftarPegawaiDialog : public wxDialog 
{
	private:
	
	protected:
		wxTextCtrl* cari_textCtrl;
		wxButton* cari_button;
		wxDataViewListCtrl* pegawai_dataViewListCtrl;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCari( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPilih( wxDataViewEvent& event ) { event.Skip(); }
		
	
	public:
		
		IzinDaftarPegawaiDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Daftar pegawai"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 450,350 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~IzinDaftarPegawaiDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class DinasLuarPanel
///////////////////////////////////////////////////////////////////////////////
class DinasLuarPanel : public wxPanel 
{
	private:
	
	protected:
		wxButton* tambah_button;
		wxButton* ubah_button;
		wxButton* hapus_button;
		wxDataViewListCtrl* dinas_luar_dataViewListCtrl;
		wxPanel* footer_panel;
		wxStaticText* m_staticText20;
		wxDatePickerCtrl* start_datePicker;
		wxStaticText* m_staticText21;
		wxDatePickerCtrl* end_datePicker;
		wxStaticText* m_staticText22;
		wxTextCtrl* filter_nama_textCtrl;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnTambah( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUbah( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHapus( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFilterData( wxDateEvent& event ) { event.Skip(); }
		virtual void OnFilterData( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		DinasLuarPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL ); 
		~DinasLuarPanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class DinasLuarDialog
///////////////////////////////////////////////////////////////////////////////
class DinasLuarDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText26;
		wxTextCtrl* FID_textCtrl;
		wxTextCtrl* nama_textCtrl;
		wxStaticText* m_staticText27;
		wxDatePickerCtrl* tgl_datePicker;
		wxStaticText* m_staticText28;
		wxTextCtrl* keterangan_textCtrl;
		wxButton* simpan_button;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnDaftarPegawaiDialog( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnSimpan( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		DinasLuarDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 450,180 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~DinasLuarDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class DinasLuarDaftarPegawaiDialog
///////////////////////////////////////////////////////////////////////////////
class DinasLuarDaftarPegawaiDialog : public wxDialog 
{
	private:
	
	protected:
		wxTextCtrl* cari_textCtrl;
		wxButton* cari_button;
		wxDataViewListCtrl* pegawai_dataViewListCtrl;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCari( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPilih( wxDataViewEvent& event ) { event.Skip(); }
		
	
	public:
		
		DinasLuarDaftarPegawaiDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Daftar pegawai"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 450,350 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~DinasLuarDaftarPegawaiDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class SuratTugasPanel
///////////////////////////////////////////////////////////////////////////////
class SuratTugasPanel : public wxPanel 
{
	private:
	
	protected:
		wxButton* tambah_button;
		wxButton* ubah_button;
		wxButton* hapus_button;
		wxDataViewListCtrl* surat_tugas_dataViewListCtrl;
		wxPanel* footer_panel;
		wxStaticText* m_staticText20;
		wxDatePickerCtrl* start_datePicker;
		wxStaticText* m_staticText21;
		wxDatePickerCtrl* end_datePicker;
		wxStaticText* m_staticText22;
		wxTextCtrl* filter_nama_textCtrl;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnTambah( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUbah( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHapus( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFilterData( wxDateEvent& event ) { event.Skip(); }
		virtual void OnFilterData( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		SuratTugasPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL ); 
		~SuratTugasPanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class SuratTugasDialog
///////////////////////////////////////////////////////////////////////////////
class SuratTugasDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText26;
		wxTextCtrl* FID_textCtrl;
		wxTextCtrl* nama_textCtrl;
		wxStaticText* m_staticText27;
		wxDatePickerCtrl* tgl_datePicker;
		wxStaticText* m_staticText28;
		wxTextCtrl* keterangan_textCtrl;
		wxButton* simpan_button;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnDaftarPegawaiDialog( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnSimpan( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		SuratTugasDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 450,180 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~SuratTugasDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class SuratTugasDaftarPegawaiDialog
///////////////////////////////////////////////////////////////////////////////
class SuratTugasDaftarPegawaiDialog : public wxDialog 
{
	private:
	
	protected:
		wxTextCtrl* cari_textCtrl;
		wxButton* cari_button;
		wxDataViewListCtrl* pegawai_dataViewListCtrl;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCari( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPilih( wxDataViewEvent& event ) { event.Skip(); }
		
	
	public:
		
		SuratTugasDaftarPegawaiDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Daftar pegawai"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 450,350 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~SuratTugasDaftarPegawaiDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CutiPanel
///////////////////////////////////////////////////////////////////////////////
class CutiPanel : public wxPanel 
{
	private:
	
	protected:
		wxButton* tambah_button;
		wxButton* ubah_button;
		wxButton* hapus_button;
		wxPanel* footer_panel;
		wxStaticText* m_staticText20;
		wxDatePickerCtrl* start_datePicker;
		wxStaticText* m_staticText21;
		wxDatePickerCtrl* end_datePicker;
		wxStaticText* m_staticText22;
		wxTextCtrl* filter_nama_textCtrl;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnTambah( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUbah( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHapus( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFilterData( wxDateEvent& event ) { event.Skip(); }
		virtual void OnFilterData( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxDataViewListCtrl* cuti_dataViewListCtrl;
		
		CutiPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL ); 
		~CutiPanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CutiDialog
///////////////////////////////////////////////////////////////////////////////
class CutiDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText26;
		wxTextCtrl* FID_textCtrl;
		wxTextCtrl* nama_textCtrl;
		wxStaticText* m_staticText27;
		wxDatePickerCtrl* tgl_awal_datePicker;
		wxStaticText* m_staticText67;
		wxDatePickerCtrl* tgl_akhir_datePicker;
		wxStaticText* m_staticText69;
		wxTextCtrl* idbcuti_jenis_textCtrl;
		wxTextCtrl* jenis_cuti_textCtrl;
		wxStaticText* m_staticText28;
		wxTextCtrl* keterangan_textCtrl;
		wxButton* simpan_button;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnDaftarPegawaiDialog( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnDaftarJenisCutiDialog( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnSimpan( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CutiDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 450,260 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~CutiDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CutiDaftarPegawaiDialog
///////////////////////////////////////////////////////////////////////////////
class CutiDaftarPegawaiDialog : public wxDialog 
{
	private:
	
	protected:
		wxTextCtrl* cari_textCtrl;
		wxButton* cari_button;
		wxDataViewListCtrl* pegawai_dataViewListCtrl;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCari( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPilih( wxDataViewEvent& event ) { event.Skip(); }
		
	
	public:
		
		CutiDaftarPegawaiDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Daftar pegawai"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 450,350 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~CutiDaftarPegawaiDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CutiJenisDialog
///////////////////////////////////////////////////////////////////////////////
class CutiJenisDialog : public wxDialog 
{
	private:
	
	protected:
		wxTextCtrl* cari_textCtrl;
		wxButton* cari_button;
		wxDataViewListCtrl* pegawai_dataViewListCtrl;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCari( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPilih( wxDataViewEvent& event ) { event.Skip(); }
		
	
	public:
		
		CutiJenisDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Jenis cuti"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 450,350 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~CutiJenisDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class TukinPanel
///////////////////////////////////////////////////////////////////////////////
class TukinPanel : public wxPanel 
{
	private:
	
	protected:
		wxStaticText* m_staticText41;
		wxComboBox* year_comboBox;
		wxStaticText* m_staticText42;
		wxComboBox* month_comboBox;
		wxButton* tampilkan_button;
		wxButton* cetak_button;
		wxButton* print_seting_button;
		wxHtmlWindow* tukin_htmlWin;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnTampilTukin( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCetak( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPrintSeting( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		TukinPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL ); 
		~TukinPanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class UmakPanel
///////////////////////////////////////////////////////////////////////////////
class UmakPanel : public wxPanel 
{
	private:
	
	protected:
		wxStaticText* m_staticText41;
		wxComboBox* year_comboBox;
		wxStaticText* m_staticText42;
		wxComboBox* month_comboBox;
		wxButton* tampilkan_button;
		wxButton* cetak_button;
		wxHtmlWindow* umak_htmlWin;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnTampil( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCetak( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		UmakPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL ); 
		~UmakPanel();
	
};

#endif //__NONAME_H__
