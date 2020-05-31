#include "GUI_frame_decode_A.h"

GUI_frame_decode_A::GUI_frame_decode_A( wxWindow* parent )
:
frame_decode_A( parent )
{

}

void GUI_frame_decode_A::frame_decode_A_OnUpdateUI( wxUpdateUIEvent& event )
{
// rysowanie wczytanego obrazka, jezeli istnieje
if (inputImage.IsOk()) Repaint(inputImage, panel_input_image);
// rysowanie zdekodowanego obrazka, jezeli istnieje
if (outputImage.IsOk()) Repaint(outputImage, panel_output_image);
}

void GUI_frame_decode_A::button_load_input_OnButtonClick( wxCommandEvent& event )
{
LoadSaveManager loadFile(this);	// powiazanie menad¿era wczytywania z oknem
loadFile.Load();	// wczytanie obrazka
if (loadFile.getLoadedImage().IsOk())	// jezeli wczytany obrazek istnieje
{
inputImage = loadFile.getLoadedImage();	// przekazanie wczytanego obrazka
Repaint(inputImage, panel_input_image);	// rysowanie wczytanego obrazka
outputImage = wxNullImage;	// reset odkodowanego obrazka
panel_output_image->ClearBackground();	// czyszczenie panelu z odkodowanym obrazkiem
setGaugeValue(0);	// reset gauge
}
}

void GUI_frame_decode_A::button_decode_OnButtonClick( wxCommandEvent& event )
{
if (inputImage.IsOk())	// jezeli wczytany obrazek istnieje
{
// przygotowanie menad¿era dekodowania i obrazka do odkodowania
Stegano meCoding(inputImage, gauge_progress);
outputImage = inputImage.Copy();
meCoding.SteganoDec(outputImage);	// dekodowanie
Repaint(outputImage, panel_output_image);	// rysowanie zdekodowanego obrazka
}
}

void GUI_frame_decode_A::button_save_output_OnButtonClick( wxCommandEvent& event )
{
if (outputImage.IsOk())	// jezeli zdekodowany obrazek istnieje
{
LoadSaveManager saveFile(this);	// powiazanie menad¿era zapisu z oknem
saveFile.Save(outputImage);	// zapis
}
}

void GUI_frame_decode_A::button_return_OnButtonClick( wxCommandEvent& event )
{
// TODO: Implement button_return_OnButtonClick
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