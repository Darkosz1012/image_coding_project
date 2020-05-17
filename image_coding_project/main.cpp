#include <wx/wx.h>
#include "GUI_frame_main.h"

class MyApp : public wxApp {

public:
	virtual bool OnInit() override;
	virtual int OnExit() override { return 0; }

};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	wxFrame *mainFrame = new GUI_frame_main(NULL);
	mainFrame->Show(true);
	SetTopWindow(mainFrame);

	return true;
}