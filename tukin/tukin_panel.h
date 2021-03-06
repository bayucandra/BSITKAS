/* 
 * File:   tukin_panel.h
 * Author: bayucandra@gmail.com
 *
 * Created on January 27, 2015, 9:55 AM
 */

#ifndef TUKIN_PANEL_H
#define	TUKIN_PANEL_H

class TukinPanel : public wxPanel 
{
	private:
            //BEGIN BAYU======================
            wxString tukin_html;
            int tukin_num_col;
            void InitYear();
            void InitMonth();
            void InitCurDateCombo();
            int TotalDaySelected();
            wxString GenHtmlCutiPegawai(const wxString &p_FID, wxDateTime &p_date);
            wxString GetAlasan(wxDateTime p_date, wxString p_FID);
            wxString CheckHoliday(wxString p_date_str);
            wxString GenReport();
            wxString HeaderReport(wxString p_year, wxString p_month);
            wxHtmlEasyPrinting *b_print;
            float GetPersenPengurangan(const wxString &p_int_str);
            wxString GetRangeKeterlambatan(const wxString &p_int_str);
            wxArrayString GetCutiPegawai(const wxString &p_FID, const wxString &p_year, const wxString &p_month);
            
            //END BAYU*******************
	protected:
		wxStaticText* m_staticText41;
		wxComboBox* year_comboBox;
		wxStaticText* m_staticText42;
		wxComboBox* month_comboBox;
		wxButton* tampilkan_button;
		wxButton* cetak_button;
		wxHtmlWindow* tukin_htmlWin;
		
		// Virtual event handlers, overide them in your derived class
		void OnTampilTukin( wxCommandEvent& event );
		virtual void OnCetak( wxCommandEvent& event );
		virtual void OnPrintSeting( wxCommandEvent& event ) { event.Skip(); }
	
	public:
		
		TukinPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL ); 
		~TukinPanel();
	
};

#endif	/* TUKIN_PANEL_H */

