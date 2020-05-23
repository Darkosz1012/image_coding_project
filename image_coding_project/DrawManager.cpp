#include "DrawManager.h"

void Repaint(wxImage imageToPaint, wxPanel* panel)
{
	wxBitmap bitmap(imageToPaint);	// bitmapa obrazka
	wxClientDC dc(panel);	// kontekst - panel
	dc.Clear();	// czyszczenie
	dc.DrawBitmap(bitmap, 0, 0, true);	// rysowanie
}