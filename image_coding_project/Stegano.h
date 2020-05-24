#pragma once
#include <wx/wx.h>

class Stegano
{
protected:
	wxImage referImage;
	wxGauge* gauge;
public:
	// konstruktor
	Stegano(wxImage, wxGauge *);
	// kodowanie
	void SteganoCode(wxImage &);
	// dekodowanie
	void SteganoDec(wxImage &);
protected:
	// funkcja okreslajaca typ jasnosci pod kodowanie
	int ComputeLumTypeCode(int, unsigned const char *);
	// kodowanie pikselu
	void CodeCurrentPixel(int, int, unsigned char *);
	// funkcja okreslajaca typ jasnosci pod dekodowanie
	int ComputeLumTypeDecode(int, unsigned const char *, unsigned const char *);
};