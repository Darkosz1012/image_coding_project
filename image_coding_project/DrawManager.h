#pragma once
#include <memory>
#include <wx/image.h>
#include <wx/bitmap.h>
#include <wx/panel.h>
#include <wx/dcbuffer.h>

/*

class DrawManager
{
	protected:

	public:
		// konstruktor
		DrawManager( );


};

*/

// funkcja rysujaca obrazek w panelu
void Repaint(wxImage imageToPaint, wxPanel* panel);