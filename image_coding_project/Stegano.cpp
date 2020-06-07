#include "Stegano.h"

// konstruktor
Stegano::Stegano(wxImage& myInputImage, wxImage& myRefImage, std::function<void(int, int)> progressFunction)
{
	_progressFunction = progressFunction;

	if (myInputImage.IsOk()) inputImage = myInputImage.Copy();

	if (myRefImage.IsOk()) referImage = myRefImage.Copy();
	else referImage.LoadFile("stegano_refer.png");

	if (!referImage.IsOk()) throw std::invalid_argument("Image is not ok");

	// reskalowanie obrazka referencyjnego
	int width = myInputImage.GetSize().GetWidth();
	int height = myInputImage.GetSize().GetHeight();
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
void Stegano::SteganoCode(wxImage & imageOutput)
{
	if (!inputImage.IsOk()) throw std::invalid_argument("Image is not ok");

	// wczytanie i przygotowanie obrazkow
	imageOutput = referImage.Copy();
	int size = imageOutput.GetSize().GetWidth() * imageOutput.GetSize().GetHeight() * 3;	// rozmiar danych
	// pobranie danych
	unsigned const char * data = inputImage.GetData();
	unsigned char * finalData = imageOutput.GetData();
	// kodowanie kazdego piksela
	int lumType;
	for (int i = 0; i < size; i += 3)
	{
		lumType = ComputeLumTypeCode(i,data);		// okreslenie jasnosci piksela
		CodeCurrentPixel(i, lumType, finalData);	// zakodowanie imageInput w obrazku referencyjnym
		_progressFunction(i, size);		// obsluga gauge
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
void Stegano::SteganoDec(wxImage & imageOutput)
{
	if (!inputImage.IsOk()) throw std::invalid_argument("Image is not ok");

	// wczytanie i przygotowanie obrazkow
	imageOutput = inputImage.Copy();
	int size = imageOutput.GetSize().GetWidth() * imageOutput.GetSize().GetHeight() * 3;	// rozmiar danych
	// pobranie danych
	unsigned const char * refData = referImage.GetData();
	unsigned char * finalData = imageOutput.GetData();
	// dekodowanie kazdego piksela
	int lumType;
	for (int i = 0; i < size; i += 3)
	{
		lumType = ComputeLumTypeDecode(i, refData,finalData);	// okreslenie jasnosci piksela
		finalData[i] = finalData[i + 1] = finalData[i + 2] = lumType == 0 ? 0 : lumType == 1 ? 37 : lumType == 2 ? 74 : 
			lumType == 3 ? 111 : lumType == 4 ? 147 : lumType == 5 ? 183 : lumType == 6 ? 219 : 255;	// odkodowanie obrazka z inputImage za pomoca obrazka referencyjnego
		_progressFunction(i, size);	// obsluga gauge
	}
}