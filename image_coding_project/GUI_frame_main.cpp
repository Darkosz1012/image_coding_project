#include "GUI_frame_main.h"

GUI_frame_main::GUI_frame_main( wxWindow* parent )
:
frame_main( parent )
{

}

void GUI_frame_main::button_encode_A_OnButtonClick( wxCommandEvent& event )
{
wxFrame *encodeAFrame = new GUI_frame_encode_A(nullptr);
encodeAFrame->Show(true);
}

void GUI_frame_main::button_decode_A_OnButtonClick( wxCommandEvent& event )
{
wxFrame *decodeAFrame = new GUI_frame_decode_A(nullptr);
decodeAFrame->Show(true);
}

void GUI_frame_main::button_encode_B_OnButtonClick( wxCommandEvent& event )
{
// TODO: Implement button_encode_B_OnButtonClick
}

void GUI_frame_main::button_decode_B_OnButtonClick( wxCommandEvent& event )
{
// wxFrame *decodeBFrame = new frame_decode_A(nullptr);
// decodeBFrame->Show(true);
}

void GUI_frame_main::button_encode_AB_OnButtonClick( wxCommandEvent& event )
{
// TODO: Implement button_encode_AB_OnButtonClick
}

void GUI_frame_main::button_decode_AB_OnButtonClick( wxCommandEvent& event )
{
// TODO: Implement button_decode_AB_OnButtonClick
}
