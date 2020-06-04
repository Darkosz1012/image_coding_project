#pragma once
#include <wx/wx.h>

class Stegano
{
protected:
	wxImage inputImage;
	wxImage referImage;
	wxGauge* gauge;
public:
	// konstruktor
	Stegano(wxImage& myInputImage, wxImage& myRefImage, wxGauge * myGauge);
	// kodowanie
	void SteganoCode(wxImage & myOutputImage);
	// dekodowanie
	void SteganoDec(wxImage & myOutputImage);
protected:
	// funkcja okreslajaca typ jasnosci pod kodowanie
	int ComputeLumTypeCode(int index, unsigned const char * data);
	// kodowanie pikselu
	void CodeCurrentPixel(int index, int lumType, unsigned char * finalData);
	// funkcja okreslajaca typ jasnosci pod dekodowanie
	int ComputeLumTypeDecode(int index, unsigned const char * data, unsigned const char * finalData);
};