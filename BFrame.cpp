///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////
#include "images/logo.xpm"
#include "BFrame.h"
#include "kepank/kepank_notebook.cpp"
#include "pegawai/pegawai_notebook.cpp"
#include "absensi/absensi_notebook.cpp"
#include "tukin/tukin_notebook.cpp"
#include "umak/umak_notebook.cpp"

///////////////////////////////////////////////////////////////////////////

BFrame::BFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 800,400 ), wxDefaultSize );
	this->SetBackgroundColour( wxColour( 244, 244, 244 ) );
	
	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* HeaderbSizer;
	HeaderbSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_bitmapLogo = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("images/logo.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	HeaderbSizer->Add( m_bitmapLogo, 0, wxLEFT|wxTOP, 15 );
	
	wxBoxSizer* HeaderCaptionSizer;
	HeaderCaptionSizer = new wxBoxSizer( wxVERTICAL );
	
	header_SI_staticText = new wxStaticText( this, wxID_ANY, wxT("SISTEM INFORMASI"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	header_SI_staticText->Wrap( -1 );
	header_SI_staticText->SetFont( wxFont( 12, 71, 90, 92, false, wxEmptyString ) );
	
	HeaderCaptionSizer->Add( header_SI_staticText, 0, wxALL, 5 );
	
	header_staticText1 = new wxStaticText( this, wxID_ANY, wxT("TUNJANGAN KINERJA APARATUR SIPIL"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	header_staticText1->Wrap( -1 );
	header_staticText1->SetFont( wxFont( 12, 71, 90, 92, false, wxEmptyString ) );
	
	HeaderCaptionSizer->Add( header_staticText1, 0, wxALL, 5 );
	
	
	HeaderbSizer->Add( HeaderCaptionSizer, 1, wxEXPAND|wxTOP, 15 );
	
	
	HeaderbSizer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* HeaderRbSizer;
	HeaderRbSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* CloseBoxbSizer;
	CloseBoxbSizer = new wxBoxSizer( wxHORIZONTAL );
	
	Minimize_bpButton = new wxBitmapButton( this, ID_Minimize, wxBitmap( wxT("images/btn_minimize.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxSize( 20,20 ), wxBU_AUTODRAW|wxNO_BORDER );
	Minimize_bpButton->SetToolTip( wxT("Minimize") );
	
	CloseBoxbSizer->Add( Minimize_bpButton, 0, wxALL, 3 );
	
	Maximize_bpButton = new wxBitmapButton( this, ID_Maximize, wxBitmap( wxT("images/btn_maximize.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxSize( 20,20 ), wxBU_AUTODRAW|wxNO_BORDER );
	Maximize_bpButton->SetToolTip( wxT("Maximize/Restore") );
	
	CloseBoxbSizer->Add( Maximize_bpButton, 0, wxALL, 3 );
	
	Close_bpButton = new wxBitmapButton( this, wxID_EXIT, wxBitmap( wxT("images/btn_close.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxSize( 20,20 ), wxBU_AUTODRAW|wxNO_BORDER );
	Close_bpButton->SetToolTip( wxT("Close") );
	
	CloseBoxbSizer->Add( Close_bpButton, 0, wxALIGN_RIGHT|wxALL, 3 );
	
	
	HeaderRbSizer->Add( CloseBoxbSizer, 1, wxALIGN_RIGHT, 5 );
	
	Setting_bpButton = new wxBitmapButton( this, ID_Setting, wxBitmap( wxT("images/btn_setting.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxSize( 32,32 ), wxBU_AUTODRAW|wxNO_BORDER );
	Setting_bpButton->SetToolTip( wxT("Settings") );
	
	HeaderRbSizer->Add( Setting_bpButton, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	
	HeaderbSizer->Add( HeaderRbSizer, 1, wxEXPAND, 5 );
	
	
	bSizerMain->Add( HeaderbSizer, 0, wxEXPAND, 1 );
	
	wxBoxSizer* BodybSizer;
	BodybSizer = new wxBoxSizer( wxHORIZONTAL );
	
	menu_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	wxBoxSizer* menu_bSizer;
	menu_bSizer = new wxBoxSizer( wxVERTICAL );
	
	menu_laporan_staticText = new wxStaticText( menu_panel, wxID_ANY, wxT("Laporan"), wxDefaultPosition, wxSize( 170,-1 ), 0 );
	menu_laporan_staticText->Wrap( -1 );
	menu_bSizer->Add( menu_laporan_staticText, 0, wxALL, 5 );
	
	menu_tukin_button = new wxButton( menu_panel, ID_menu_tukin_btn, wxT("Tunjagan Kinerja"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	menu_bSizer->Add( menu_tukin_button, 0, wxEXPAND, 0 );
	
	menu_umak_button = new wxButton( menu_panel, ID_menu_umak_btn, wxT("Uang Makan"), wxDefaultPosition, wxDefaultSize, 0 );
	menu_bSizer->Add( menu_umak_button, 0, wxEXPAND, 0 );
	
	menu_input_data_staticText = new wxStaticText( menu_panel, wxID_ANY, wxT("Data"), wxDefaultPosition, wxDefaultSize, 0 );
	menu_input_data_staticText->Wrap( -1 );
	menu_bSizer->Add( menu_input_data_staticText, 0, wxALL, 5 );
	
	menu_absensi_button = new wxButton( menu_panel, ID_menu_absensi_btn, wxT("Absensi"), wxDefaultPosition, wxDefaultSize, 0 );
	menu_bSizer->Add( menu_absensi_button, 0, wxEXPAND, 0 );
	
	menu_pegawai_button = new wxButton( menu_panel, ID_menu_pegawai_btn, wxT("Pegawai"), wxDefaultPosition, wxDefaultSize, 0 );
	menu_bSizer->Add( menu_pegawai_button, 0, wxEXPAND, 0 );
	
	menu_kepank_button = new wxButton( menu_panel, ID_menu_kepank_btn, wxT("Pangkat && Jabatan"), wxDefaultPosition, wxDefaultSize, 0 );
	menu_bSizer->Add( menu_kepank_button, 0, wxEXPAND, 0 );
	
	
	menu_panel->SetSizer( menu_bSizer );
	menu_panel->Layout();
	menu_bSizer->Fit( menu_panel );
	BodybSizer->Add( menu_panel, 0, wxEXPAND | wxALL, 5 );
	
	main_notebook = new wxSimplebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	BodybSizer->Add( main_notebook, 1, wxEXPAND | wxALL, 5 );
	
	
	bSizerMain->Add( BodybSizer, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizerMain );
	this->Layout();
	
	this->Centre( wxBOTH );
        
        this->SetIcon(wxIcon(logo_xpm));
        
        //BEGIN BAYU============
        tukin_notebook = new TukinNotebook(main_notebook);
        main_notebook->AddPage(tukin_notebook,"Tukin Notebook");
        
        umak_notebook = new UmakNotebook(main_notebook);
        main_notebook->AddPage(umak_notebook, "Uangmakan Notebook");
        
        absensi_notebook=new AbsensiNotebook(main_notebook);
        main_notebook->AddPage(absensi_notebook, "Absensi Notebook");
        
        pegawai_notebook=new PegawaiNotebook(main_notebook);
        main_notebook->AddPage(pegawai_notebook, "Pegawai Notebook");
        
        kepank_notebook=new KepankNotebook(main_notebook);
        main_notebook->AddPage( kepank_notebook, wxT("Kepank Notebook"));
        //END BAYU************
}

BFrame::~BFrame()
{
}

void BFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
void BFrame::OnLeftDown(wxMouseEvent& evt)
{
    CaptureMouse();
    wxPoint pos = ClientToScreen(evt.GetPosition());
    wxPoint origin = GetPosition();
    int dx =  pos.x - origin.x;
    int dy = pos.y - origin.y;
    m_delta = wxPoint(dx, dy);
}

void BFrame::OnLeftUp(wxMouseEvent& WXUNUSED(evt))
{
    if (HasCapture())
        ReleaseMouse();
}

void BFrame::OnMouseMove(wxMouseEvent& evt)
{
    wxPoint pt = evt.GetPosition();
    if (evt.Dragging() && evt.LeftIsDown())
    {
        wxPoint pos = ClientToScreen(pt);
        Move(wxPoint(pos.x - m_delta.x, pos.y - m_delta.y));
    }
}
void BFrame::OnMinimize(wxCommandEvent& event){
    Iconize();
}
void BFrame::OnMaximizeRestore(wxCommandEvent& event)
{
    if(this->IsMaximized()){
        this->Restore();
	Maximize_bpButton->SetToolTip( wxT("Maximize") );
    }else{
        this->Maximize();
	Maximize_bpButton->SetToolTip( wxT("Restore") );
    }
}
void BFrame::OnBSettingDialog(wxCommandEvent& event){
    BSettingDialog *setting_dialog=new BSettingDialog(this);
    setting_dialog->Center();
    setting_dialog->ShowModal();
}


void BFrame::OnMenuKepank(wxCommandEvent& event){
    int kepank_idx=main_notebook->FindPage(kepank_notebook);
    main_notebook->SetSelection(kepank_idx);
}
void BFrame::OnMenuPegawai(wxCommandEvent& event){
    int pegawai_idx=main_notebook->FindPage(pegawai_notebook);
    main_notebook->SetSelection(pegawai_idx);
}
void BFrame::OnMenuAbsensi(wxCommandEvent& event){
    int absensi_idx=main_notebook->FindPage(absensi_notebook);
    main_notebook->SetSelection(absensi_idx);
}
void BFrame::OnMenuTukin(wxCommandEvent& event){
    int tukin_idx=main_notebook->FindPage(tukin_notebook);
    main_notebook->SetSelection(tukin_idx);
}
void BFrame::OnMenuUmak(wxCommandEvent& event){
    int umak_idx=main_notebook->FindPage(umak_notebook);
    main_notebook->SetSelection(umak_idx);
}

wxBEGIN_EVENT_TABLE(BFrame,wxFrame)
    EVT_LEFT_DOWN(BFrame::OnLeftDown)
    EVT_LEFT_UP(BFrame::OnLeftUp)
    EVT_MOTION(BFrame::OnMouseMove)
        
    EVT_BUTTON(wxID_EXIT, BFrame::OnExit)
    EVT_BUTTON(ID_Minimize, BFrame::OnMinimize)
    EVT_BUTTON(ID_Maximize, BFrame::OnMaximizeRestore)
    EVT_BUTTON(ID_Setting, BFrame::OnBSettingDialog)

    EVT_BUTTON(ID_menu_tukin_btn, BFrame::OnMenuTukin)
    EVT_BUTTON(ID_menu_umak_btn, BFrame::OnMenuUmak)
    EVT_BUTTON(ID_menu_absensi_btn, BFrame::OnMenuAbsensi)
    EVT_BUTTON(ID_menu_pegawai_btn, BFrame::OnMenuPegawai)
    EVT_BUTTON(ID_menu_kepank_btn, BFrame::OnMenuKepank)
//    EVT_MENU(wxID_ABOUT, BFrame::OnAbout)
wxEND_EVENT_TABLE()