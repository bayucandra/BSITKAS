/* 
 * File:   umak_panel.h
 * Author: bayucandra@gmail.com
 *
 * Created on February 24, 2015, 6:42 AM
 */

#ifndef UMAK_PANEL_H
#define	UMAK_PANEL_H

class UmakPanel : public wxPanel 
{
	private:
            //BEGIN BAYU================
            wxString umak_html;
            void InitYear();
            void InitMonth();
            void InitCurDateCombo();
            int TotalDaySelected();
            wxString GenReport();
            wxString HeaderReport(wxString p_year, wxString p_month);
            wxString CheckHoliday(wxString p_date_str);
            wxHtmlEasyPrinting *b_print;
            //END BAYU**********************
	protected:
		wxStaticText* m_staticText41;
		wxComboBox* year_comboBox;
		wxStaticText* m_staticText42;
		wxComboBox* month_comboBox;
		wxButton* tampilkan_button;
		wxButton* cetak_button;
		wxHtmlWindow* umak_htmlWin;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnTampil( wxCommandEvent& event );
		virtual void OnCetak( wxCommandEvent& event );
		
	
	public:
		
		UmakPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL ); 
		~UmakPanel();
	
};

#endif	/* UMAK_PANEL_H */

