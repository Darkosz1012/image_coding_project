#ifndef __GUI_frame_main__
#define __GUI_frame_main__

/**
@file
Subclass of frame_main, which is generated by wxFormBuilder.
*/

#include "GUI.h"

//// end generated include
#include "GUI_frame_encode_A.h"
#include "GUI_frame_decode_A.h"
#include "GUI_frame_encode_B.h"
#include "GUI_frame_decode_B.h"
#include "GUI_frame_encode_AB.h"
#include "GUI_frame_decode_AB.h"
#include <wx/app.h>
/** Implementing frame_main */
class GUI_frame_main : public frame_main
{
	protected:
		// Handlers for frame_main events.
		void button_encode_A_OnButtonClick( wxCommandEvent& event );
		void button_decode_A_OnButtonClick( wxCommandEvent& event );
		void button_encode_B_OnButtonClick( wxCommandEvent& event );
		void button_decode_B_OnButtonClick( wxCommandEvent& event );
		void button_encode_AB_OnButtonClick( wxCommandEvent& event );
		void button_decode_AB_OnButtonClick( wxCommandEvent& event );
	public:
		/** Constructor */
		GUI_frame_main( wxWindow* parent );
	//// end generated class members




};

#endif // __GUI_frame_main__
