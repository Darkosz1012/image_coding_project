#include "GUI_frame_encode_B.h"

GUI_frame_encode_B::GUI_frame_encode_B(wxWindow* parent) : frame_encode_B(parent), _logger(text_info)
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
		Crypto crypto([=](int number, int all) {
			this->gauge_progress->SetValue(static_cast<double>(number) / all * 100 + 1);
		});
		crypto.encode(*inputImage, *outputImage1, *outputImage2);
		RepaintAll();
		_logger.info("Poprawnie zakodowano obraz");
	}
	catch (std::exception err) {
		_logger.error("Wyst¹pi³ b³¹d podczas kodowania obrazu");
		_logger.error(err.what());
	}
}

void GUI_frame_encode_B::button_save_output1_OnButtonClick(wxCommandEvent& event)
{
	if (outputImage1 != nullptr && outputImage1->IsOk())
	{
		LoadSaveManager saveFile(this);
		saveFile.Save(*outputImage1);
		_logger.info("Poprawnie zapisano pierwszy zakodowany obraz");
	}
	else _logger.info("Wys¹tpi³ b³¹d podczas zapisu pierwszego zakodowanego obrazu");
}

void GUI_frame_encode_B::button_save_output2_OnButtonClick(wxCommandEvent& event)
{
	if (outputImage2 != nullptr && outputImage2->IsOk())
	{
		LoadSaveManager saveFile(this);
		saveFile.Save(*outputImage2);
		_logger.info("Poprawnie zapisano drugi zakodowany obraz");
	}
	else _logger.info("Wys¹tpi³ b³¹d podczas zapisu drugiego zakodowanego obrazu");
}

void GUI_frame_encode_B::button_return_OnButtonClick(wxCommandEvent& event)
{
	Destroy();
}


//void GUI_frame_encode_B::progress(int number, int all) 
//{
//	gauge_progress->SetValue(static_cast<double>(number) / all * 100 + 1);
//}

void GUI_frame_encode_B::RepaintAll()
{
	if (inputImage != nullptr && inputImage->IsOk())
		Repaint(*inputImage, panel_input_image);

	if (outputImage1 != nullptr && outputImage1->IsOk())
		Repaint(*outputImage1, panel_output_image1);

	if (outputImage2 != nullptr && outputImage2->IsOk())
		Repaint(*outputImage2, panel_output_image2);
}