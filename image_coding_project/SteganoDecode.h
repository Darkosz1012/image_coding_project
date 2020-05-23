#include <wx/image.h>
#include <wx/wx.h>
#include <wx/filedlg.h>
#include <memory>

class SteganoDecode
{
protected:
	wxImage decodedImage;
	wxImage referImage;
public:
	// konstruktor
	SteganoDecode(wxImage);
	// kodowanie
	void SteganoDec();
	// getter zakodowanego obrazka
	wxImage getDecodedImage();
};
