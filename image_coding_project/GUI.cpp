///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

frame_main::frame_main( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Witamy!"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	m_staticText1->SetFont( wxFont( 18, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer1->Add( m_staticText1, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Wybierz jedną z opcji, by przejść dalej."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	m_staticText2->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );

	bSizer1->Add( m_staticText2, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Autorzy: Dariusz Biela, Dawid Chara, Jakub Perlak "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer1->Add( m_staticText3, 0, wxALIGN_CENTER|wxALL, 5 );

	button_encode_A = new wxButton( this, wxID_ANY, wxT("Koduj metodą steganograficzną"), wxDefaultPosition, wxSize( 260,-1 ), 0 );
	bSizer1->Add( button_encode_A, 0, wxALIGN_CENTER|wxALL, 5 );

	button_decode_A = new wxButton( this, wxID_ANY, wxT("Dekoduj metodą steganograficzną"), wxDefaultPosition, wxSize( 260,-1 ), 0 );
	bSizer1->Add( button_decode_A, 0, wxALIGN_CENTER|wxALL, 5 );

	button_encode_B = new wxButton( this, wxID_ANY, wxT("Koduj metodą kryptograficzną"), wxDefaultPosition, wxSize( 260,-1 ), 0 );
	bSizer1->Add( button_encode_B, 0, wxALIGN_CENTER|wxALL, 5 );

	button_decode_B = new wxButton( this, wxID_ANY, wxT("Dekoduj metodą kryptograficzną"), wxDefaultPosition, wxSize( 260,-1 ), 0 );
	bSizer1->Add( button_decode_B, 0, wxALIGN_CENTER|wxALL, 5 );

	button_encode_AB = new wxButton( this, wxID_ANY, wxT("Koduj obiema metodami"), wxDefaultPosition, wxSize( 260,-1 ), 0 );
	bSizer1->Add( button_encode_AB, 0, wxALIGN_CENTER|wxALL, 5 );

	button_decode_AB = new wxButton( this, wxID_ANY, wxT("Dekoduj obiema metodami"), wxDefaultPosition, wxSize( 260,-1 ), 0 );
	bSizer1->Add( button_decode_AB, 0, wxALIGN_CENTER|wxALL, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	button_encode_A->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_main::button_encode_A_OnButtonClick ), NULL, this );
	button_decode_A->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_main::button_decode_A_OnButtonClick ), NULL, this );
	button_encode_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_main::button_encode_B_OnButtonClick ), NULL, this );
	button_decode_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_main::button_decode_B_OnButtonClick ), NULL, this );
	button_encode_AB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_main::button_encode_AB_OnButtonClick ), NULL, this );
	button_decode_AB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_main::button_decode_AB_OnButtonClick ), NULL, this );
}

frame_main::~frame_main()
{
	// Disconnect Events
	button_encode_A->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_main::button_encode_A_OnButtonClick ), NULL, this );
	button_decode_A->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_main::button_decode_A_OnButtonClick ), NULL, this );
	button_encode_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_main::button_encode_B_OnButtonClick ), NULL, this );
	button_decode_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_main::button_decode_B_OnButtonClick ), NULL, this );
	button_encode_AB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_main::button_encode_AB_OnButtonClick ), NULL, this );
	button_decode_AB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_main::button_decode_AB_OnButtonClick ), NULL, this );

}

frame_encode_A::frame_encode_A( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	button_load_input = new wxButton( this, wxID_ANY, wxT("Wczytaj zdjęcie "), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( button_load_input, 0, wxALIGN_CENTER|wxALL, 5 );

	panel_input_image = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	panel_input_image->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	panel_input_image->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	bSizer3->Add( panel_input_image, 1, wxEXPAND | wxALL, 5 );


	bSizer22->Add( bSizer3, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	button_encode = new wxButton( this, wxID_ANY, wxT("Zakoduj obraz"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( button_encode, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	gauge_progress = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	gauge_progress->SetValue( 0 );
	bSizer6->Add( gauge_progress, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	text_info = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxBORDER_SIMPLE|wxVSCROLL );
	text_info->Wrap( -1 );
	text_info->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );

	bSizer6->Add( text_info, 1, wxALL|wxEXPAND, 5 );


	bSizer22->Add( bSizer6, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	button_save_output = new wxButton( this, wxID_ANY, wxT("Zapisz zakodowane zdjęcie"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( button_save_output, 0, wxALIGN_CENTER|wxALL, 5 );

	panel_output_image = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	panel_output_image->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	panel_output_image->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	bSizer4->Add( panel_output_image, 1, wxEXPAND | wxALL, 5 );


	bSizer22->Add( bSizer4, 1, wxEXPAND, 5 );


	bSizer2->Add( bSizer22, 1, wxEXPAND, 5 );

	button_return = new wxButton( this, wxID_ANY, wxT("Powrót"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( button_return, 0, wxALL, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( frame_encode_A::frame_encode_A_OnUpdateUI ) );
	button_load_input->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_encode_A::button_load_input_OnButtonClick ), NULL, this );
	button_encode->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_encode_A::button_encode_OnButtonClick ), NULL, this );
	button_save_output->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_encode_A::button_save_output_OnButtonClick ), NULL, this );
	button_return->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_encode_A::button_return_OnButtonClick ), NULL, this );
}

frame_encode_A::~frame_encode_A()
{
	// Disconnect Events
	this->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( frame_encode_A::frame_encode_A_OnUpdateUI ) );
	button_load_input->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_encode_A::button_load_input_OnButtonClick ), NULL, this );
	button_encode->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_encode_A::button_encode_OnButtonClick ), NULL, this );
	button_save_output->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_encode_A::button_save_output_OnButtonClick ), NULL, this );
	button_return->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_encode_A::button_return_OnButtonClick ), NULL, this );

}

frame_decode_A::frame_decode_A( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	button_load_input = new wxButton( this, wxID_ANY, wxT("Wczytaj zdjęcie "), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( button_load_input, 0, wxALIGN_CENTER|wxALL, 5 );

	panel_input_image = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	panel_input_image->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	panel_input_image->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	bSizer3->Add( panel_input_image, 1, wxEXPAND | wxALL, 5 );


	bSizer23->Add( bSizer3, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	button_decode = new wxButton( this, wxID_ANY, wxT("Odkoduj obraz"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( button_decode, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	gauge_progress = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	gauge_progress->SetValue( 0 );
	bSizer6->Add( gauge_progress, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	text_info = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxBORDER_SIMPLE|wxVSCROLL );
	text_info->Wrap( -1 );
	text_info->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );

	bSizer6->Add( text_info, 1, wxALL|wxEXPAND, 5 );


	bSizer23->Add( bSizer6, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	button_save_output = new wxButton( this, wxID_ANY, wxT("Zapisz odkodowane zdjęcie"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( button_save_output, 0, wxALIGN_CENTER|wxALL, 5 );

	panel_output_image = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	panel_output_image->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	panel_output_image->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	bSizer4->Add( panel_output_image, 1, wxEXPAND | wxALL, 5 );


	bSizer23->Add( bSizer4, 1, wxEXPAND, 5 );


	bSizer2->Add( bSizer23, 1, wxEXPAND, 5 );

	button_return = new wxButton( this, wxID_ANY, wxT("Powrót"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( button_return, 0, wxALL, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( frame_decode_A::frame_encode_A_OnUpdateUI ) );
	button_load_input->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_decode_A::button_load_input_OnButtonClick ), NULL, this );
	button_decode->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_decode_A::button_encode_OnButtonClick ), NULL, this );
	button_save_output->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_decode_A::button_save_output_OnButtonClick ), NULL, this );
	button_return->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_decode_A::button_return_OnButtonClick ), NULL, this );
}

frame_decode_A::~frame_decode_A()
{
	// Disconnect Events
	this->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( frame_decode_A::frame_encode_A_OnUpdateUI ) );
	button_load_input->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_decode_A::button_load_input_OnButtonClick ), NULL, this );
	button_decode->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_decode_A::button_encode_OnButtonClick ), NULL, this );
	button_save_output->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_decode_A::button_save_output_OnButtonClick ), NULL, this );
	button_return->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_decode_A::button_return_OnButtonClick ), NULL, this );

}

frame_encode_B::frame_encode_B( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	button_load_input = new wxButton( this, wxID_ANY, wxT("Wczytaj zdjęcie "), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( button_load_input, 0, wxALIGN_CENTER|wxALL, 5 );

	panel_input_image = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	panel_input_image->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	panel_input_image->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	bSizer3->Add( panel_input_image, 1, wxEXPAND | wxALL, 5 );


	bSizer22->Add( bSizer3, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	button_encode = new wxButton( this, wxID_ANY, wxT("Zakoduj obraz"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( button_encode, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	gauge_progress = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	gauge_progress->SetValue( 0 );
	bSizer6->Add( gauge_progress, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	text_info = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxBORDER_SIMPLE|wxVSCROLL );
	text_info->Wrap( -1 );
	text_info->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );

	bSizer6->Add( text_info, 1, wxALL|wxEXPAND, 5 );


	bSizer22->Add( bSizer6, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	button_save_output1 = new wxButton( this, wxID_ANY, wxT("Zapisz pierwsze zakodowane zdjęcie"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( button_save_output1, 0, wxALIGN_CENTER|wxALL, 5 );

	panel_output_image1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	panel_output_image1->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	panel_output_image1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	bSizer4->Add( panel_output_image1, 1, wxEXPAND | wxALL, 5 );


	bSizer22->Add( bSizer4, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxVERTICAL );

	button_save_output2 = new wxButton( this, wxID_ANY, wxT("Zapisz drugie zakodowane zdjęcie"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer41->Add( button_save_output2, 0, wxALIGN_CENTER|wxALL, 5 );

	panel_output_image2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	panel_output_image2->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	panel_output_image2->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	bSizer41->Add( panel_output_image2, 1, wxEXPAND | wxALL, 5 );


	bSizer22->Add( bSizer41, 1, wxEXPAND, 5 );


	bSizer2->Add( bSizer22, 1, wxEXPAND, 5 );

	button_return = new wxButton( this, wxID_ANY, wxT("Powrót"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( button_return, 0, wxALL, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( frame_encode_B::frame_encode_A_OnUpdateUI ) );
	button_load_input->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_encode_B::button_load_input_OnButtonClick ), NULL, this );
	button_encode->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_encode_B::button_encode_OnButtonClick ), NULL, this );
	button_save_output1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_encode_B::button_save_output1_OnButtonClick ), NULL, this );
	button_save_output2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_encode_B::button_save_output2_OnButtonClick ), NULL, this );
	button_return->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_encode_B::button_return_OnButtonClick ), NULL, this );
}

frame_encode_B::~frame_encode_B()
{
	// Disconnect Events
	this->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( frame_encode_B::frame_encode_A_OnUpdateUI ) );
	button_load_input->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_encode_B::button_load_input_OnButtonClick ), NULL, this );
	button_encode->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_encode_B::button_encode_OnButtonClick ), NULL, this );
	button_save_output1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_encode_B::button_save_output1_OnButtonClick ), NULL, this );
	button_save_output2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_encode_B::button_save_output2_OnButtonClick ), NULL, this );
	button_return->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_encode_B::button_return_OnButtonClick ), NULL, this );

}

frame_decode_B::frame_decode_B( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxVERTICAL );

	button_load_input1 = new wxButton( this, wxID_ANY, wxT("Wczytaj pierwsze zdjęcie "), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( button_load_input1, 0, wxALIGN_CENTER|wxALL, 5 );

	panel_input_image1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	panel_input_image1->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	panel_input_image1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	bSizer31->Add( panel_input_image1, 1, wxEXPAND | wxALL, 5 );


	bSizer23->Add( bSizer31, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	button_load_input2 = new wxButton( this, wxID_ANY, wxT("Wczytaj drugie zdjęcie "), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( button_load_input2, 0, wxALIGN_CENTER|wxALL, 5 );

	panel_input_image2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	panel_input_image2->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	panel_input_image2->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	bSizer3->Add( panel_input_image2, 1, wxEXPAND | wxALL, 5 );


	bSizer23->Add( bSizer3, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	button_decode = new wxButton( this, wxID_ANY, wxT("Odkoduj obraz"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( button_decode, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	gauge_progress = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	gauge_progress->SetValue( 0 );
	bSizer6->Add( gauge_progress, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	text_info = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxBORDER_SIMPLE|wxVSCROLL );
	text_info->Wrap( -1 );
	text_info->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );

	bSizer6->Add( text_info, 1, wxALL|wxEXPAND, 5 );


	bSizer23->Add( bSizer6, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	button_save_output = new wxButton( this, wxID_ANY, wxT("Zapisz odkodowane zdjęcie"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( button_save_output, 0, wxALIGN_CENTER|wxALL, 5 );

	panel_output_image = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	panel_output_image->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	panel_output_image->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	bSizer4->Add( panel_output_image, 1, wxEXPAND | wxALL, 5 );


	bSizer23->Add( bSizer4, 1, wxEXPAND, 5 );


	bSizer2->Add( bSizer23, 1, wxEXPAND, 5 );

	button_return = new wxButton( this, wxID_ANY, wxT("Powrót"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( button_return, 0, wxALL, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( frame_decode_B::frame_encode_A_OnUpdateUI ) );
	button_load_input1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_decode_B::button_load_input1_OnButtonClick ), NULL, this );
	button_load_input2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_decode_B::button_load_input2_OnButtonClick ), NULL, this );
	button_decode->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_decode_B::button_encode_OnButtonClick ), NULL, this );
	button_save_output->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_decode_B::button_save_output_OnButtonClick ), NULL, this );
	button_return->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_decode_B::button_return_OnButtonClick ), NULL, this );
}

frame_decode_B::~frame_decode_B()
{
	// Disconnect Events
	this->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( frame_decode_B::frame_encode_A_OnUpdateUI ) );
	button_load_input1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_decode_B::button_load_input1_OnButtonClick ), NULL, this );
	button_load_input2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_decode_B::button_load_input2_OnButtonClick ), NULL, this );
	button_decode->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_decode_B::button_encode_OnButtonClick ), NULL, this );
	button_save_output->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_decode_B::button_save_output_OnButtonClick ), NULL, this );
	button_return->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_decode_B::button_return_OnButtonClick ), NULL, this );

}

frame_encode_AB::frame_encode_AB( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	button_load_input = new wxButton( this, wxID_ANY, wxT("Wczytaj zdjęcie "), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( button_load_input, 0, wxALIGN_CENTER|wxALL, 5 );

	panel_input_image = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	panel_input_image->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	panel_input_image->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	bSizer3->Add( panel_input_image, 1, wxEXPAND | wxALL, 5 );


	bSizer22->Add( bSizer3, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	button_encode = new wxButton( this, wxID_ANY, wxT("Zakoduj obraz"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( button_encode, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	gauge_progress = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	gauge_progress->SetValue( 0 );
	bSizer6->Add( gauge_progress, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	text_info = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxBORDER_SIMPLE|wxVSCROLL );
	text_info->Wrap( -1 );
	text_info->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );

	bSizer6->Add( text_info, 1, wxALL|wxEXPAND, 5 );


	bSizer22->Add( bSizer6, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	button_save_output1 = new wxButton( this, wxID_ANY, wxT("Zapisz pierwsze zakodowane zdjęcie"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( button_save_output1, 0, wxALIGN_CENTER|wxALL, 5 );

	panel_output_image1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	panel_output_image1->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	panel_output_image1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	bSizer4->Add( panel_output_image1, 1, wxEXPAND | wxALL, 5 );


	bSizer22->Add( bSizer4, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxVERTICAL );

	button_save_output2 = new wxButton( this, wxID_ANY, wxT("Zapisz drugie zakodowane zdjęcie"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer41->Add( button_save_output2, 0, wxALIGN_CENTER|wxALL, 5 );

	panel_output_image2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	panel_output_image2->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	panel_output_image2->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	bSizer41->Add( panel_output_image2, 1, wxEXPAND | wxALL, 5 );


	bSizer22->Add( bSizer41, 1, wxEXPAND, 5 );


	bSizer2->Add( bSizer22, 1, wxEXPAND, 5 );

	button_return = new wxButton( this, wxID_ANY, wxT("Powrót"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( button_return, 0, wxALL, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( frame_encode_AB::frame_encode_A_OnUpdateUI ) );
	button_load_input->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_encode_AB::button_load_input_OnButtonClick ), NULL, this );
	button_encode->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_encode_AB::button_encode_OnButtonClick ), NULL, this );
	button_save_output1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_encode_AB::button_save_output1_OnButtonClick ), NULL, this );
	button_save_output2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_encode_AB::button_save_output2_OnButtonClick ), NULL, this );
	button_return->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_encode_AB::button_return_OnButtonClick ), NULL, this );
}

frame_encode_AB::~frame_encode_AB()
{
	// Disconnect Events
	this->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( frame_encode_AB::frame_encode_A_OnUpdateUI ) );
	button_load_input->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_encode_AB::button_load_input_OnButtonClick ), NULL, this );
	button_encode->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_encode_AB::button_encode_OnButtonClick ), NULL, this );
	button_save_output1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_encode_AB::button_save_output1_OnButtonClick ), NULL, this );
	button_save_output2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_encode_AB::button_save_output2_OnButtonClick ), NULL, this );
	button_return->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_encode_AB::button_return_OnButtonClick ), NULL, this );

}

frame_decode_AB::frame_decode_AB( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxVERTICAL );

	button_load_input1 = new wxButton( this, wxID_ANY, wxT("Wczytaj pierwsze zdjęcie "), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( button_load_input1, 0, wxALIGN_CENTER|wxALL, 5 );

	panel_input_image1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	panel_input_image1->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	panel_input_image1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	bSizer31->Add( panel_input_image1, 1, wxEXPAND | wxALL, 5 );


	bSizer23->Add( bSizer31, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	button_load_input2 = new wxButton( this, wxID_ANY, wxT("Wczytaj drugie zdjęcie "), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( button_load_input2, 0, wxALIGN_CENTER|wxALL, 5 );

	panel_input_image2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	panel_input_image2->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	panel_input_image2->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	bSizer3->Add( panel_input_image2, 1, wxEXPAND | wxALL, 5 );


	bSizer23->Add( bSizer3, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	button_decode = new wxButton( this, wxID_ANY, wxT("Odkoduj obraz"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( button_decode, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	gauge_progress = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	gauge_progress->SetValue( 0 );
	bSizer6->Add( gauge_progress, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	text_info = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxBORDER_SIMPLE|wxVSCROLL );
	text_info->Wrap( -1 );
	text_info->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );

	bSizer6->Add( text_info, 1, wxALL|wxEXPAND, 5 );


	bSizer23->Add( bSizer6, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	button_save_output = new wxButton( this, wxID_ANY, wxT("Zapisz odkodowane zdjęcie"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( button_save_output, 0, wxALIGN_CENTER|wxALL, 5 );

	panel_output_image = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	panel_output_image->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	panel_output_image->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	bSizer4->Add( panel_output_image, 1, wxEXPAND | wxALL, 5 );


	bSizer23->Add( bSizer4, 1, wxEXPAND, 5 );


	bSizer2->Add( bSizer23, 1, wxEXPAND, 5 );

	button_return = new wxButton( this, wxID_ANY, wxT("Powrót"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( button_return, 0, wxALL, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( frame_decode_AB::frame_encode_A_OnUpdateUI ) );
	button_load_input1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_decode_AB::button_load_input1_OnButtonClick ), NULL, this );
	button_load_input2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_decode_AB::button_load_input2_OnButtonClick ), NULL, this );
	button_decode->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_decode_AB::button_encode_OnButtonClick ), NULL, this );
	button_save_output->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_decode_AB::button_save_output_OnButtonClick ), NULL, this );
	button_return->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_decode_AB::button_return_OnButtonClick ), NULL, this );
}

frame_decode_AB::~frame_decode_AB()
{
	// Disconnect Events
	this->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( frame_decode_AB::frame_encode_A_OnUpdateUI ) );
	button_load_input1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_decode_AB::button_load_input1_OnButtonClick ), NULL, this );
	button_load_input2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_decode_AB::button_load_input2_OnButtonClick ), NULL, this );
	button_decode->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_decode_AB::button_encode_OnButtonClick ), NULL, this );
	button_save_output->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_decode_AB::button_save_output_OnButtonClick ), NULL, this );
	button_return->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frame_decode_AB::button_return_OnButtonClick ), NULL, this );

}
