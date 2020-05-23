#include "LoadSaveManager.h"

// konstruktor
LoadSaveManager::LoadSaveManager(wxWindow * openedWindow)
{
	currentWindow = openedWindow;
}

// zaladowanie obrazka do zakodowania
void LoadSaveManager::Load()
{
	// okno ladowania
	auto openFileDialog = std::make_unique<wxFileDialog>(currentWindow, _("Wybierz obraz do za³adowania"), wxEmptyString,
		wxEmptyString, _("Png files (*.png)|*.png|Img files  (*.jpg)|*.jpg"), wxFD_OPEN);
	// zamkniecie okna przed wczytaniem
	if (openFileDialog->ShowModal() == wxID_CANCEL) return;
	// handlery
	wxImage::AddHandler(new wxPNGHandler);
	wxImage::AddHandler(new wxJPEGHandler);
	// pobranie sciezki
	wxString fileName = openFileDialog->GetPath();
	// wczytanie obrazka
	if (!loadedImage.LoadFile(fileName)) wxMessageBox(_("Nie uda³o siê za³adowaæ obrazka!"));
}

// zapisanie zakodowanego obrazka
void LoadSaveManager::Save(wxImage imageToSave)
{
	// okno zapisu
	wxFileDialog saveFileDialog(currentWindow, "Zapisywanie jako", "", "", "PNG files (*.png)|*.png", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	// zamkniecie okna przed zapisem
	if (saveFileDialog.ShowModal() == wxID_CANCEL) return;
	// bitmapa zakodowanego obrazka
	wxBitmap bitmap(imageToSave);
	wxImage tmp = bitmap.ConvertToImage();
	// handler
	tmp.AddHandler(new wxPNGHandler);
	// zapis do pliku
	tmp.SaveFile(saveFileDialog.GetPath());
}

// getter zaladowanego obrazka
wxImage LoadSaveManager::getLoadedImage()
{
	return loadedImage;
}