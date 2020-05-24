#pragma once
#include <wx/wx.h>

class LoadSaveManager
{
protected:
	wxImage loadedImage;
	wxWindow * currentWindow;
public:
	// konstruktor
	LoadSaveManager(wxWindow *);
	// zaladowanie obrazka do zakodowania
	void Load();
	// zapisanie zakodowanego obrazka
	void Save(wxImage);
	// getter zaladowanego obrazka
	wxImage getLoadedImage();
};