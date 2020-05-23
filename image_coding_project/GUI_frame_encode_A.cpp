#include "GUI_frame_encode_A.h"

GUI_frame_encode_A::GUI_frame_encode_A( wxWindow* parent )
:
frame_encode_A( parent )
{

}

void GUI_frame_encode_A::frame_encode_A_OnUpdateUI( wxUpdateUIEvent& event )
{
// TODO: Implement frame_encode_A_OnUpdateUI
	if(inputImage.IsOk()) Repaint(inputImage,panel_input_image);
	if(outputImage.IsOk()) Repaint(outputImage, panel_output_image);
}

void GUI_frame_encode_A::button_load_input_OnButtonClick( wxCommandEvent& event )
{
	LoadSaveManager loadFile(this);
	loadFile.Load();
	inputImage = loadFile.getLoadedImage();
	Repaint(inputImage, panel_input_image);
}

void GUI_frame_encode_A::button_encode_OnButtonClick( wxCommandEvent& event )
{
	SteganoEncode meCoding(inputImage);
	meCoding.Stegano();
	outputImage = meCoding.getEncodedImage();
	Repaint(outputImage, panel_output_image);
}

void GUI_frame_encode_A::button_save_output_OnButtonClick( wxCommandEvent& event )
{
	LoadSaveManager saveFile(this);
	saveFile.Save(outputImage);
}

void GUI_frame_encode_A::button_return_OnButtonClick( wxCommandEvent& event )
{
// TODO: Implement button_return_OnButtonClick
}
