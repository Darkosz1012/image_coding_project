#include "GUI_frame_encode_B.h"

GUI_frame_encode_B::GUI_frame_encode_B(wxWindow* parent)
	:
	frame_encode_B(parent)
{
	inputImage = std::make_shared<wxImage>(wxNullImage);
	outputImage1 = std::make_shared<wxImage>(wxNullImage);
	outputImage2 = std::make_shared<wxImage>(wxNullImage);
	gauge_progress->SetRange(100);
}

void GUI_frame_encode_B::frame_encode_B_OnUpdateUI(wxUpdateUIEvent& event)
{
	RepaintAll();
}

void GUI_frame_encode_B::button_load_input_OnButtonClick(wxCommandEvent& event)
{
	LoadSaveManager loadFile(this);
	loadFile.Load();
	if (loadFile.getLoadedImage().IsOk())
	{
		inputImage = std::make_shared<wxImage>(loadFile.getLoadedImage());
		Repaint(*inputImage, panel_input_image);
		outputImage1 = std::make_shared<wxImage>(wxNullImage);
		panel_output_image1->ClearBackground();
		outputImage2 = std::make_shared<wxImage>(wxNullImage);
		panel_output_image2->ClearBackground();

	}
}

void GUI_frame_encode_B::button_encode_OnButtonClick(wxCommandEvent& event)
{
	try {
		Crypto crypto([=](int a, int b) {
			this->progress(a, b);
		});
		crypto.encode(*inputImage, *outputImage1, *outputImage2);
		RepaintAll();
	}
	catch (std::exception err) {
		text_info->SetLabelText(wxString(err.what()));
	}
}

void GUI_frame_encode_B::button_save_output1_OnButtonClick(wxCommandEvent& event)
{
	if (outputImage1 != nullptr && outputImage1->IsOk())
	{
		LoadSaveManager saveFile(this);
		saveFile.Save(*outputImage1);
	}
}

void GUI_frame_encode_B::button_save_output2_OnButtonClick(wxCommandEvent& event)
{
	if (outputImage2 != nullptr && outputImage2->IsOk())
	{
		LoadSaveManager saveFile(this);
		saveFile.Save(*outputImage2);
	}
}

void GUI_frame_encode_B::button_return_OnButtonClick(wxCommandEvent& event)
{
	// TODO: Implement button_return_OnButtonClick
}


void GUI_frame_encode_B::RepaintAll()
{
	if (inputImage != nullptr && inputImage->IsOk())
		Repaint(*inputImage, panel_input_image);

	if (outputImage1 != nullptr && outputImage1->IsOk())
		Repaint(*outputImage1, panel_output_image1);

	if (outputImage2 != nullptr && outputImage2->IsOk())
		Repaint(*outputImage2, panel_output_image2);
}

void GUI_frame_encode_B::progress(int number, int all) {
	gauge_progress->SetValue(static_cast<double>(number) / all * 100 + 1);
}