#include "Stegano.h"

// konstruktor
Stegano::Stegano(wxImage imageInput, wxGauge * myGauge)
{
	gauge = myGauge;	// gauge
	if (!referImage.LoadFile("stegano_refer.png")) wxMessageBox(_("Nie uda³o za³adowaæ siê obrazka referencyjnego!"));	// zaladowanie obrazka referencyjnego
	// reskalowanie obrazka referencyjnego
	int width = imageInput.GetSize().GetWidth();
	int height = imageInput.GetSize().GetHeight();
	referImage.Rescale(width, height);
}

// funkcja okreslajaca typ jasnosci pod kodowanie
int Stegano::ComputeLumTypeCode(int index, unsigned const char * data)
{
	double luminance = (0.299*data[index] + 0.587*data[index + 1] + 0.114*data[index + 2]) / 255;
	return luminance < 0.125 ? 0 : luminance < 0.25 ? 1 : luminance < 0.375 ? 2 : luminance < 0.5 ? 3 : luminance < 0.625 ? 4 : luminance < 0.75 ? 5 : luminance < 0.875 ? 6 : 7;
}

// kodowanie pikselu - dodanie (lub odjecie) wartosci danym w kanale, w zaleznosci od typu jasnosci
void Stegano::CodeCurrentPixel(int index, int lumType, unsigned char * finalData)
{
	if (lumType == 1 || lumType == 3 || lumType == 5 || lumType == 7) finalData[index + 2] = finalData[index + 2] == 255 ? finalData[index + 2] - 1 : finalData[index + 2] + 1;
	if (lumType == 2 || lumType == 3 || lumType == 6 || lumType == 7) finalData[index + 1] = finalData[index + 1] == 255 ? finalData[index + 1] - 1 : finalData[index + 1] + 1;
	if (lumType == 4 || lumType == 5 || lumType == 6 || lumType == 7) finalData[index] = finalData[index] == 255 ? finalData[index] - 1 : finalData[index] + 1;
}

// kodowanie steganograficzne podanego obrazka
void Stegano::SteganoCode(wxImage & imageInput)
{
	// wczytanie i przygotowanie obrazkow
	wxImage inputCopy = imageInput.Copy();
	imageInput = referImage.Copy();
	int size = imageInput.GetSize().GetWidth() * imageInput.GetSize().GetHeight() * 3;	// rozmiar danych
	gauge->SetRange(size);	// zakres gauge
	// pobranie danych
	unsigned const char * data = inputCopy.GetData();
	unsigned char * finalData = imageInput.GetData();
	// kodowanie kazdego piksela
	int lumType;
	for (int i = 0; i < size; i += 3)
	{
		lumType = ComputeLumTypeCode(i,data);		// okreslenie jasnosci piksela
		CodeCurrentPixel(i, lumType, finalData);	// zakodowanie imageInput w obrazku referencyjnym
		gauge->SetValue(i);		// obsluga gauge
	}
}

// funkcja okreslajaca typ jasnosci pod dekodowanie
int Stegano::ComputeLumTypeDecode(int index, unsigned const char * data, unsigned const char * finalData)
{
	int lumType = 0;
	if (abs(finalData[index] - data[index]) == 1) lumType += 4;
	if (abs(finalData[index + 1] - data[index + 1]) == 1) lumType += 2;
	if (abs(finalData[index + 2] - data[index + 2]) == 1) lumType += 1;
	return lumType;
}

// dekodowanie steganograficzne podanego obrazka
void Stegano::SteganoDec(wxImage & imageInput)
{
	int size = imageInput.GetSize().GetWidth() * imageInput.GetSize().GetHeight() * 3;	// rozmiar danych
	// pobranie danych
	unsigned const char * data = referImage.GetData();
	unsigned char * finalData = imageInput.GetData();
	gauge->SetRange(size);	// zakres gauge
	// dekodowanie kazdego piksela
	int lumType;
	for (int i = 0; i < size; i += 3)
	{
		lumType = ComputeLumTypeDecode(i,data,finalData);	// okreslenie jasnosci piksela
		finalData[i] = finalData[i + 1] = finalData[i + 2] = lumType == 0 ? 0 : lumType == 1 ? 37 : lumType == 2 ? 74 : 
			lumType == 3 ? 111 : lumType == 4 ? 147 : lumType == 5 ? 183 : lumType == 6 ? 219 : 255;	// odkodowanie obrazka z inputImage za pomoca obrazka referencyjnego
		gauge->SetValue(i);	// obsluga gauge
	}
}