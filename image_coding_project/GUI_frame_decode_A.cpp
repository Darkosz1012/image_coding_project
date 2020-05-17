#include "GUI_frame_decode_A.h"

GUI_frame_decode_A::GUI_frame_decode_A( wxWindow* parent )
:
frame_decode_A( parent )
{

}

void GUI_frame_decode_A::frame_encode_A_OnUpdateUI( wxUpdateUIEvent& event )
{
// TODO: Implement frame_encode_A_OnUpdateUI
}

void GUI_frame_decode_A::button_load_input_OnButtonClick( wxCommandEvent& event )
{
    auto openFileDialog = std::make_unique<wxFileDialog>(this, _("Choose a image to load"), wxEmptyString,
    wxEmptyString,_("Img files  (*.jpg)|*.jpg|Png files (*.png)|*.png"), wxFD_OPEN);
    if (openFileDialog->ShowModal() == wxID_OK)
    {
        wxString fileName = openFileDialog->GetPath();
    }
}

void GUI_frame_decode_A::button_encode_OnButtonClick( wxCommandEvent& event )
{
    
}

void GUI_frame_decode_A::button_save_output_OnButtonClick( wxCommandEvent& event )
{
    auto saveFileDialog = std::make_unique<wxFileDialog>(this, _("Choose a image to load"), wxEmptyString,
    wxEmptyString,_("Img files  (*.jpg)|*.jpg|Png files (*.png)|*.png"), wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition);
    if (saveFileDialog->ShowModal() == wxID_OK)
    {
        wxString fileName = saveFileDialog->GetPath();
    }
}
