#include "SteganoDecode.h"

// konstruktor
SteganoDecode::SteganoDecode(wxImage imageToDecode)
{
	if (!referImage.LoadFile("stegano_refer.png")) wxMessageBox(_("Nie uda³o za³adowaæ siê obrazka referencyjnego!"));
	int width = imageToDecode.GetSize().GetWidth();
	int height = imageToDecode.GetSize().GetHeight();
	referImage.Rescale(width, height);
	decodedImage = imageToDecode.Copy();
}

// dekodowanie steganograficzne podanego obrazka
void SteganoDecode::SteganoDec()
{
	int size = decodedImage.GetSize().GetWidth() * decodedImage.GetSize().GetHeight() * 3;
	unsigned const char * data = referImage.GetData();
	unsigned char * finalData = decodedImage.GetData();
	// ustawienie gauge ////////////////////////////////////////////////////////////
	// kodowanie kazdego piksela
	for (int i = 0; i < size; ++i)
	{
		finalData[i] -= data[i];
	}

	for (int i = 0; i < size; i += 3)
	{
		if (finalData[i] == 1)
		{
			finalData[i] = finalData[i + 1] = finalData[i + 2] = 255;
		}
	}
}

// getter zdekodowanego obrazka
wxImage SteganoDecode::getDecodedImage()
{
	return decodedImage;
}