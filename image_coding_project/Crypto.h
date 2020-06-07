#pragma once
#include <wx/wx.h>
#include <memory>
#include <stdexcept>
#include <functional>
#include "ImageData.h"
#include "randomutils.h"
class Crypto
{
public:
	Crypto(std::function<void(int number, int all)> progressFunction = [](int,int) {}) :_progressFunction{ progressFunction } {}
	void encode(const wxImage& originalImage, wxImage& codedImage1, wxImage& codedImage2 );
	void decode(const wxImage& codedImage1, const wxImage& codedImage2, wxImage& originalImage);
protected:
	std::function<void(int, int)> _progressFunction;

	void setC1(ImageData& codeImg, int i, int j);
	void setC2(ImageData& codeImg, int i, int j);
	int decodePixelValue(const ImageData& codeImg1, const ImageData& codeImg2, int i, int j);
};