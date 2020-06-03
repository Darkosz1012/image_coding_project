#include "TextBoxLogger.h"

void TextBoxLogger::info(const std::string& message)
{
	_log = _log + "[INFO] " + message + '\n';
	_textBox->SetLabelText(_log);
}

void TextBoxLogger::error(const std::string& message)
{
	_log = _log + "[ERROR] " + message + '\n';
	_textBox->SetLabelText(_log);
}

