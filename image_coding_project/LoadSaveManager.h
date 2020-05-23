#pragma once
#include <wx/image.h>
#include <memory>
#include <wx/filedlg.h>
#include <wx/wx.h>
#include <wx/msw/window.h>

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