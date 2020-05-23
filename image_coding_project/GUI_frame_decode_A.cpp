#include "GUI_frame_decode_A.h"

GUI_frame_decode_A::GUI_frame_decode_A( wxWindow* parent )
:
frame_decode_A( parent )
{

}

void GUI_frame_decode_A::frame_encode_A_OnUpdateUI( wxUpdateUIEvent& event )
{
// TODO: Implement frame_encode_A_OnUpdateUI
	if (inputImage.IsOk()) Repaint(inputImage, panel_input_image);
	if (outputImage.IsOk()) Repaint(outputImage, panel_output_image);
}

void GUI_frame_decode_A::button_load_input_OnButtonClick( wxCommandEvent& event )
{
	LoadSaveManager loadFile(this);
	loadFile.Load();
	inputImage = loadFile.getLoadedImage();
	Repaint(inputImage, panel_input_image);
}

void GUI_frame_decode_A::button_encode_OnButtonClick( wxCommandEvent& event )
{
	SteganoDecode meCoding(inputImage);
	meCoding.SteganoDec();
	outputImage = meCoding.getDecodedImage();
	Repaint(outputImage, panel_output_image);
}

void GUI_frame_decode_A::button_save_output_OnButtonClick( wxCommandEvent& event )
{
	LoadSaveManager saveFile(this);
	saveFile.Save(outputImage);
}

void GUI_frame_decode_A::button_return_OnButtonClick( wxCommandEvent& event )
{
// TODO: Implement button_return_OnButtonClick
}
