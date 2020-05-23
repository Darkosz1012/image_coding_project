#include "SteganoEncode.h"

// konstruktor
SteganoEncode::SteganoEncode(wxImage imageToEncode)
{
	if(!referImage.LoadFile("stegano_refer.png")) wxMessageBox(_("Nie uda³o za³adowaæ siê obrazka referencyjnego!"));
	int width = imageToEncode.GetSize().GetWidth();
	int height = imageToEncode.GetSize().GetHeight();
	referImage.Rescale(width, height);
	encodedImage = imageToEncode.Copy();
	/*
	int referWidth = referImage.GetSize().GetWidth();
	int referHeight = referImage.GetSize().GetHeight();

	if (width > referWidth && height > referHeight)
	{
		if(width/)
	}
	else
	{
		if (width > referWidth) referImage.Rescale(width,4/6*width);
		else
		{
			if(height > referHeight) referImage.Rescale(6/4*height, height);
		}
	}
	*/
}

// kodowanie steganograficzne podanego obrazka
void SteganoEncode::Stegano()
{
	// wczytanie obrazka do zakodowania
	wxImage encodeImgCpy = encodedImage.Copy();
	encodedImage = referImage.Copy();
	// dane
	int size = encodeImgCpy.GetSize().GetWidth() * encodeImgCpy.GetSize().GetHeight() * 3;
	unsigned const char * data = encodeImgCpy.GetData();
	unsigned char * finalData = encodedImage.GetData();
	// ustawienie gauge ////////////////////////////////////////////////////////////
	// kodowanie kazdego piksela
	for (int i = 0; i < size; i += 3)
	{
		if (data[i] == 255 && data[i + 1] == 255 && data[i + 2] == 255)	// jezeli piksel jest bialy
		{
			finalData[i] += 1;	// zwiekszenie kanalu czerwonego
		}
	}
}

// getter zakodowanego obrazka
wxImage SteganoEncode::getEncodedImage()
{
	return encodedImage;
}