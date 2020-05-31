#include "GUI_frame_encode_A.h"

GUI_frame_encode_A::GUI_frame_encode_A( wxWindow* parent )
:
frame_encode_A( parent )
{

}

void GUI_frame_encode_A::frame_encode_A_OnUpdateUI( wxUpdateUIEvent& event )
{
// rysowanie wczytanego obrazka, jezeli istnieje
if (inputImage.IsOk()) Repaint(inputImage, panel_input_image);
// rysowanie zakodowanego obrazka, jezeli istnieje
if (outputImage.IsOk()) Repaint(outputImage, panel_output_image);
}

void GUI_frame_encode_A::button_load_input_OnButtonClick( wxCommandEvent& event )
{
LoadSaveManager loadFile(this); // powiazanie menad¿era wczytywania z oknem
loadFile.Load();	// wczytanie obrazka
if (loadFile.getLoadedImage().IsOk())	// jezeli wczytany obrazek istnieje
{
inputImage = loadFile.getLoadedImage();	// przekazanie wczytanego obrazka
Repaint(inputImage, panel_input_image);	// rysowanie wczytanego obrazka
outputImage = wxNullImage;	// reset zakodowanego obrazka
panel_output_image->ClearBackground();	// czyszczenie panelu z zakodowanym obrazkiem
setGaugeValue(0);	// reset gauge
}
}

void GUI_frame_encode_A::button_encode_OnButtonClick( wxCommandEvent& event )
{
if (inputImage.IsOk())	// jezeli wczytany obrazek istnieje
{
// przygotowanie menad¿era kodowania i obrazka do zakodowania
Stegano meCoding(inputImage, gauge_progress);
outputImage = inputImage.Copy();
meCoding.SteganoCode(outputImage);	// kodowanie
Repaint(outputImage, panel_output_image);	// rysowanie zakodowanego obrazka
}
}

void GUI_frame_encode_A::button_save_output_OnButtonClick( wxCommandEvent& event )
{
if (outputImage.IsOk())	// jezeli zakodowany obrazek istnieje
{
LoadSaveManager saveFile(this);	// powiazanie menad¿era zapisu z oknem
saveFile.Save(outputImage);	// zapis
}
}

void GUI_frame_encode_A::button_return_OnButtonClick( wxCommandEvent& event )
{
	// TODO: Implement button_return_OnButtonClick
}



// metoda obslugujaca gauge - ustawianie zakresu
void GUI_frame_encode_A::setGaugeRange(int myRange)
{
	gauge_progress->SetRange(myRange);
}

// metoda obslugujaca gauge - ustawianie wartosci
void GUI_frame_encode_A::setGaugeValue(int myValue)
{
	gauge_progress->SetValue(myValue);
}