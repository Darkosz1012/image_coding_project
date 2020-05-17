///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/gauge.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class frame_main
///////////////////////////////////////////////////////////////////////////////
class frame_main : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText1;
		wxStaticText* m_staticText2;
		wxStaticText* m_staticText3;
		wxButton* button_encode_A;
		wxButton* button_decode_A;
		wxButton* button_encode_B;
		wxButton* button_decode_B;
		wxButton* button_encode_AB;
		wxButton* button_decode_AB;

		// Virtual event handlers, overide them in your derived class
		virtual void button_encode_A_OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void button_decode_A_OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void button_encode_B_OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void button_decode_B_OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void button_encode_AB_OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void button_decode_AB_OnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		frame_main( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Menu główne"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 381,365 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~frame_main();

};

///////////////////////////////////////////////////////////////////////////////
/// Class frame_encode_A
///////////////////////////////////////////////////////////////////////////////
class frame_encode_A : public wxFrame
{
	private:

	protected:
		wxButton* button_load_input;
		wxPanel* panel_input_image;
		wxButton* button_encode;
		wxGauge* gauge_progress;
		wxStaticText* text_info;
		wxButton* button_save_output;
		wxPanel* panel_output_image;
		wxButton* button_return;

		// Virtual event handlers, overide them in your derived class
		virtual void frame_encode_A_OnUpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void button_load_input_OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void button_encode_OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void button_save_output_OnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		frame_encode_A( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Koduj metodą steganograficzną"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1177,369 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~frame_encode_A();

};

///////////////////////////////////////////////////////////////////////////////
/// Class frame_decode_A
///////////////////////////////////////////////////////////////////////////////
class frame_decode_A : public wxFrame
{
	private:

	protected:
		wxButton* button_load_input;
		wxPanel* panel_input_image;
		wxButton* button_decode;
		wxGauge* gauge_progress;
		wxStaticText* text_info;
		wxButton* button_save_output;
		wxPanel* panel_output_image;
		wxButton* button_return;

		// Virtual event handlers, overide them in your derived class
		virtual void frame_encode_A_OnUpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void button_load_input_OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void button_encode_OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void button_save_output_OnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		frame_decode_A( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Dekoduj metodą steganograficzną"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1177,369 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~frame_decode_A();

};

