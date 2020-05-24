#pragma once
#include <wx/panel.h>
#include <wx/dcbuffer.h>

// funkcja rysujaca obrazek w panelu
void Repaint(wxImage imageToPaint, wxPanel* panel);