#include "GUI_frame_encode_A.h"
#include "TextBoxLogger.h"

GUI_frame_encode_A::GUI_frame_encode_A(wxWindow* parent) : frame_encode_A(parent), _logger(text_info)
{
	inputImage = std::make_shared<wxImage>(wxNullImage);
	refImage = std::make_shared<wxImage>(wxNullImage);
	outputImage = std::make_shared<wxImage>(wxNullImage);
	gauge_progress->SetRange(100);
}

void GUI_frame_encode_A::frame_encode_A_OnUpdateUI(wxUpdateUIEvent& event)
{
	RepaintAll();
}

void GUI_frame_encode_A::button_load_input_OnButtonClick(wxCommandEvent& event)
{
	LoadSaveManager loadFile(this); // powiazanie menadzera wczytywania z oknem
	loadFile.Load();	// wczytanie obrazka
	if (loadFile.getLoadedImage().IsOk())	// jezeli wczytany obrazek istnieje
	{
		inputImage = std::make_shared<wxImage>(loadFile.getLoadedImage());	// przekazanie wczytanego obrazka
		Repaint(*inputImage, panel_input_image);	// rysowanie wczytanego obrazka
		outputImage = std::make_shared<wxImage>(wxNullImage);	// reset zakodowanego obrazka
		panel_output_image->ClearBackground();	// czyszczenie panelu z zakodowanym obrazkiem
		gauge_progress->SetValue(0);	// reset gauge
		_logger.info("Poprawnie załadowano obraz do kodowania");
	}
	else _logger.error("Wystąpił błąd podczas wczytywania obrazu do zakodowania");
}

void GUI_frame_encode_A::button_load_ref_OnButtonClick(wxCommandEvent& event)
{
	LoadSaveManager loadFile(this); // powiazanie menadzera wczytywania z oknem
	loadFile.Load();	// wczytanie obrazka
	if (loadFile.getLoadedImage().IsOk())	// jezeli wczytany obrazek istnieje
	{
		refImage = std::make_shared<wxImage>(loadFile.getLoadedImage());	// przekazanie wczytanego obrazka
		Repaint(*refImage, panel_input_ref);	// rysowanie wczytanego obrazka
		outputImage = std::make_shared<wxImage>(wxNullImage);;	// reset zakodowanego obrazka
		panel_output_image->ClearBackground();	// czyszczenie panelu z zakodowanym obrazkiem
		gauge_progress->SetValue(0);	// reset gauge
		_logger.info("Poprawnie załadowano obraz wzorcowy");
	}
	else _logger.error("Wystąpił błąd podczas wczytywania obrazu wzorcowego");
}

void GUI_frame_encode_A::button_encode_OnButtonClick(wxCommandEvent& event)
{
	if (inputImage != nullptr && inputImage->IsOk())	// jezeli wczytany obrazek istnieje
	{
		// przygotowanie menad¿era kodowania i obrazka do zakodowania
		Stegano meCoding(*inputImage, *refImage, [=](int number, int all) { this->gauge_progress->SetValue(static_cast<double>(number) / all * 100 + 1); });
		meCoding.SteganoCode(*outputImage);	// kodowanie
		Repaint(*outputImage, panel_output_image);	// rysowanie zakodowanego obrazka
		_logger.info("Poprawnie zakodowano obraz");
	}
	else _logger.error("Wystąpił błąd podczas kodowania obrazu");

}

void GUI_frame_encode_A::button_save_output_OnButtonClick(wxCommandEvent& event)
{
	if (outputImage != nullptr && outputImage->IsOk())	// jezeli zakodowany obrazek istnieje
	{
		LoadSaveManager saveFile(this);	// powiazanie menad¿era zapisu z oknem
		saveFile.Save(*outputImage);	// zapis
		_logger.info("Poprawnie zapisano zakodowany obraz");
	}
	else _logger.info("Wystąpił błąd podczas zapisu zakodowanego obrazu");

}

void GUI_frame_encode_A::button_return_OnButtonClick(wxCommandEvent& event)
{
	Destroy();
}

void GUI_frame_encode_A::RepaintAll()
{
	if (inputImage != nullptr && inputImage->IsOk()) Repaint(*inputImage, panel_input_image);

	if (refImage != nullptr && refImage->IsOk()) Repaint(*refImage, panel_input_ref);

	if (outputImage != nullptr && outputImage->IsOk()) Repaint(*outputImage, panel_output_image);
}