#include <wx/image.h>
#include <wx/wx.h>
#include <wx/filedlg.h>
#include <memory>

class SteganoEncode
{
protected:
	wxImage encodedImage;
	wxImage referImage;
public:
	// konstruktor
	SteganoEncode(wxImage);
	// kodowanie
	void Stegano();
	// getter zakodowanego obrazka
	wxImage getEncodedImage();
};
