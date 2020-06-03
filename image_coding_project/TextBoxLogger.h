#pragma once
#pragma warning(disable:4996)

#include <string>
#include <memory>
#include <wx/wxprec.h>
#include <wx/wx.h>


class TextBoxLogger
{
public:

	TextBoxLogger(wxStaticText* textBox) : _textBox(textBox), _log("") {}
	void info(const std::string& message);
	void error(const std::string& message);
private:
	std::unique_ptr<wxStaticText> _textBox;
	std::string _log;

};