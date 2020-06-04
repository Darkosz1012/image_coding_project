#include "GUI_frame_decode_A.h"

GUI_frame_decode_A::GUI_frame_decode_A(wxWindow* parent) : frame_decode_A(parent), _logger(text_info)
{
	inputImage = std::make_shared<wxImage>(wxNullImage);
	refImage = std::make_shared<wxImage>(wxNullImage);
	outputImage = std::make_shared<wxImage>(wxNullImage);
}

void GUI_frame_decode_A::frame_decode_A_OnUpdateUI(wxUpdateUIEvent& event)
{
	RepaintAll();
}

void GUI_frame_decode_A::button_load_input_OnButtonClick(wxCommandEvent& event)
{
	LoadSaveManager loadFile(this);	// powiazanie menad¿era wczytywania z oknem
	loadFile.Load();	// wczytanie obrazka
	if (loadFile.getLoadedImage().IsOk())	// jezeli wczytany obrazek istnieje
	{
		inputImage = std::make_shared<wxImage>(loadFile.getLoadedImage());	// przekazanie wczytanego obrazka
		Repaint(*inputImage, panel_input_image);	// rysowanie wczytanego obrazka
		outputImage = std::make_shared<wxImage>(wxNullImage);	// reset zakodowanego obrazka
		panel_output_image->ClearBackground();	// czyszczenie panelu z zakodowanym obrazkiem
		setGaugeValue(0);	// reset gauge
		_logger.info("Poprawnie załadowano obraz do kodowania");
	}
	else _logger.error("Wystąpił błąd podczas ładowania obrazu do dekodowania");
}

void GUI_frame_decode_A::button_load_ref_OnButtonClick(wxCommandEvent& event)
{
	LoadSaveManager loadFile(this); // powiazanie menadzera wczytywania z oknem
	loadFile.Load();	// wczytanie obrazka
	if (loadFile.getLoadedImage().IsOk())	// jezeli wczytany obrazek istnieje
	{
		refImage = std::make_shared<wxImage>(loadFile.getLoadedImage());	// przekazanie wczytanego obrazka
		Repaint(*refImage, panel_input_ref);	// rysowanie wczytanego obrazka
		outputImage = std::make_shared<wxImage>(wxNullImage);	// reset zakodowanego obrazka
		panel_output_image->ClearBackground();	// czyszczenie panelu z zakodowanym obrazkiem
		setGaugeValue(0);	// reset gauge
		_logger.info("Poprawnie załadowano obraz wzorcowy");
	}
	else _logger.error("Wystąpił błąd podczas wczytywania obrazu wzorcowego");
}

void GUI_frame_decode_A::button_decode_OnButtonClick(wxCommandEvent& event)
{
	if (inputImage != nullptr && inputImage->IsOk())	// jezeli wczytany obrazek istnieje
	{
		// przygotowanie menad¿era dekodowania i obrazka do odkodowania
		Stegano meCoding(*inputImage, *refImage, gauge_progress);
		meCoding.SteganoDec(*outputImage);	// dekodowanie
		Repaint(*outputImage, panel_output_image);	// rysowanie zdekodowanego obrazka
		_logger.info("Poprawnie odkodowano obraz");
	}
	else _logger.error("Wystąpił błąd podczas dekodowania obrazu");
}

void GUI_frame_decode_A::button_save_output_OnButtonClick(wxCommandEvent& event)
{
	if (outputImage != nullptr && outputImage->IsOk())	// jezeli zdekodowany obrazek istnieje
	{
		LoadSaveManager saveFile(this);	// powiazanie menad¿era zapisu z oknem
		saveFile.Save(*outputImage);	// zapis
		_logger.info("Poprawnie zapisano odkodowany obraz");
	}
	else _logger.info("Wysątpił błąd podczas zapisu odkodowanego obrazu");
}

void GUI_frame_decode_A::button_return_OnButtonClick(wxCommandEvent& event)
{
	Destroy();
}

void GUI_frame_decode_A::RepaintAll()
{
	if (inputImage != nullptr && inputImage->IsOk()) Repaint(*inputImage, panel_input_image);

	if (refImage != nullptr && refImage->IsOk()) Repaint(*refImage, panel_input_ref);

	if (outputImage != nullptr && outputImage->IsOk()) Repaint(*outputImage, panel_output_image);
}


// metoda obslugujaca gauge - ustawianie zakresu
void GUI_frame_decode_A::setGaugeRange(int myRange)
{
	gauge_progress->SetRange(myRange);
}



// metoda obslugujaca gauge - ustawianie wartosci
void GUI_frame_decode_A::setGaugeValue(int myValue)
{
	gauge_progress->SetValue(myValue);
}