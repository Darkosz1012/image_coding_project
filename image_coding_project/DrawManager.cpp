#include "DrawManager.h"

void Repaint(wxImage imageToPaint, wxPanel* panel)
{
	//pobranie rozmiaru panelu
	int panelWidth = panel->GetSize().x;
	int panelHeight = panel->GetSize().y;
	// pobranie rozmiaru obrazka
	int width = imageToPaint.GetSize().GetWidth();
	int height = imageToPaint.GetSize().GetHeight();
	// odpowiednie reskalowanie obrazka do panelu
	if (width / height >= panelWidth / panelHeight) imageToPaint.Rescale(panelWidth, height*panelWidth / width);
	else imageToPaint.Rescale(width*panelHeight / height, panelHeight);
	
	wxClientDC _myDC(panel);	// kontekst - panel
	wxBitmap buffer = wxBitmap(panelWidth, panelHeight);	// bitmapa obrazka
	wxBufferedDC myDC(&_myDC, buffer);	// buffer
	myDC.Clear();	// czyszczenie
	myDC.DrawBitmap(imageToPaint,0,0);	// rysowanie
}