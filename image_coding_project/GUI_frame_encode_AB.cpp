#include "GUI_frame_encode_AB.h"

GUI_frame_encode_AB::GUI_frame_encode_AB( wxWindow* parent ) : frame_encode_AB( parent ), _logger(text_info)
{
	inputImage = std::make_shared<wxImage>(wxNullImage);
	referenceImage = std::make_shared<wxImage>(wxNullImage);
	outputImage1 = std::make_shared<wxImage>(wxNullImage);
	outputImage2 = std::make_shared<wxImage>(wxNullImage);
	gauge_progress->SetRange(100);
}

void GUI_frame_encode_AB::frame_encode_AB_OnUpdateUI(wxUpdateUIEvent& event)
{
	RepaintAll();
}

void GUI_frame_encode_AB::button_load_input_OnButtonClick( wxCommandEvent& event )
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
		_logger.info("Poprawnie załadowano obraz do kodowania");

	}
	else _logger.error("Wystąpił błąd podczas ładowania obrazu do kodowania");
	
}

void GUI_frame_encode_AB::button_load_ref_OnButtonClick( wxCommandEvent& event )
{
	LoadSaveManager loadFile(this);
	loadFile.Load();
	if (loadFile.getLoadedImage().IsOk())
	{
		referenceImage = std::make_shared<wxImage>(loadFile.getLoadedImage());
		Repaint(*referenceImage, panel_input_ref);
		outputImage1 = std::make_shared<wxImage>(wxNullImage);
		panel_output_image1->ClearBackground();
		outputImage2 = std::make_shared<wxImage>(wxNullImage);
		panel_output_image2->ClearBackground();
		_logger.info("Poprawnie załadowano obraz referencyjny");
	}
	else _logger.error("Wystąpił błąd podczas ładowania obrazu referencyjnego");
}

void GUI_frame_encode_AB::button_encode_OnButtonClick( wxCommandEvent& event )
{
	_logger.info("Kodowanie metodą kryptograficzną");
	try {
		Crypto crypto([=](int number, int all) {
			this->gauge_progress->SetValue(static_cast<double>(number) / all * 50 + 1);
		});
		crypto.encode(*inputImage, *outputImage1, *outputImage2);
		_logger.info("Poprawnie zakodowano obraz metodą kryptograficzną");
		Repaint(*outputImage1, panel_output_image1);
		Repaint(*outputImage2, panel_output_image2);
	}
	catch (std::exception err) {
		_logger.error("Wystąpił błąd podczas kodowania obrazu metodą kryptograficzną");
		_logger.error(err.what());
	}
	//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	//gauge_progress->SetValue(0);

	_logger.info("Kodowanie metodą steganograficzną");
	if (outputImage1->IsOk() && outputImage2->IsOk())
	{
		Stegano meCoding1(*outputImage1, *referenceImage, [=](int number, int all) { this->gauge_progress->SetValue(static_cast<double>(number) / all * 25 + 51); });
		Stegano meCoding2(*outputImage2, *referenceImage, [=](int number, int all) { this->gauge_progress->SetValue(static_cast<double>(number) / all * 25 + 76); });
		meCoding1.SteganoCode(*outputImage1);
		meCoding2.SteganoCode(*outputImage2);
		Repaint(*outputImage1, panel_output_image1);
		Repaint(*outputImage2, panel_output_image2);
		_logger.info("Poprawnie zakodowano obraz metodą steganograficzną");
	}
	else  _logger.error("Wystąpił błąd podczas kodowania obrazu metodą steganograficzną");
}

void GUI_frame_encode_AB::button_save_output1_OnButtonClick( wxCommandEvent& event )
{
	if (outputImage1 != nullptr && outputImage1->IsOk())
	{
		LoadSaveManager saveFile(this);
		saveFile.Save(*outputImage1);
		_logger.info("Poprawnie zapisano pierwszy zakodowany obraz");
	}
	else _logger.info("Wysątpił błąd podczas zapisu pierwszego zakodowanego obrazu");
}

void GUI_frame_encode_AB::button_save_output2_OnButtonClick( wxCommandEvent& event )
{
	if (outputImage2 != nullptr && outputImage2->IsOk())
	{
		LoadSaveManager saveFile(this);
		saveFile.Save(*outputImage2);
		_logger.info("Poprawnie zapisano drugi zakodowany obraz");
	}
	else _logger.info("Wysątpił błąd podczas zapisu drugiego zakodowanego obrazu");
}

void GUI_frame_encode_AB::button_return_OnButtonClick( wxCommandEvent& event )
{
	Destroy();
}

void GUI_frame_encode_AB::RepaintAll()
{
	if (inputImage != nullptr && inputImage->IsOk())
		Repaint(*inputImage, panel_input_image);

	if (referenceImage != nullptr && referenceImage->IsOk())
		Repaint(*referenceImage, panel_input_ref);

	if (outputImage1 != nullptr && outputImage1->IsOk())
		Repaint(*outputImage1, panel_output_image1);

	if (outputImage2 != nullptr && outputImage2->IsOk())
		Repaint(*outputImage2, panel_output_image2);
}




