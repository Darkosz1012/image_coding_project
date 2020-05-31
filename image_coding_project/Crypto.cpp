#include "Crypto.h"



void Crypto::encode(const wxImage& originalImage, wxImage& codedImage1, wxImage& codedImage2) {

	if (!originalImage.IsOk()) throw std::invalid_argument("Image is not ok");

	codedImage1 = * new wxImage(originalImage.GetWidth() * 2, originalImage.GetHeight() * 2);
	codedImage2 = * new wxImage(originalImage.GetWidth() * 2, originalImage.GetHeight() * 2);

	ImageData orgImg(originalImage.GetData(), originalImage.GetWidth(), originalImage.GetHeight());
	ImageData codeImg1(codedImage1.GetData(), codedImage1.GetWidth(), codedImage1.GetHeight());
	ImageData codeImg2(codedImage2.GetData(), codedImage2.GetWidth(), codedImage2.GetHeight());

	int size = orgImg.getHeight()*orgImg.getWidth();

	for (unsigned int i = 0; i < orgImg.getHeight(); i++) {
		for (unsigned int j = 0; j < orgImg.getWidth(); j++) {
			int rand = randomNumber<int>(0, 2);
			if (orgImg.getLuminance(i, j) > 0.5) {
				if (rand) {
					setC1(codeImg1, i, j);
					setC1(codeImg2, i, j);
				}
				else {
					setC2(codeImg1, i, j);
					setC2(codeImg2, i, j);
				}
			}
			else {
				if (rand) {
					setC1(codeImg1, i, j);
					setC2(codeImg2, i, j);
				}
				else {
					setC2(codeImg1, i, j);
					setC1(codeImg2, i, j);
				}
			}
		}
		_progressFunction((i + 1) * orgImg.getWidth(), size);
	}
}

void Crypto::decode(const wxImage& codedImage1, const wxImage& codedImage2, wxImage& originalImage) {
	if (!codedImage1.IsOk()) throw std::invalid_argument("Image is not ok.");
	if (!codedImage2.IsOk()) throw std::invalid_argument("Image is not ok.");
	if (codedImage1.GetWidth() != codedImage2.GetWidth() || codedImage1.GetHeight() != codedImage2.GetHeight()) throw std::invalid_argument("The images have different sizes.");

	originalImage = *new wxImage(codedImage1.GetWidth() / 2, codedImage1.GetHeight() / 2);

	ImageData orgImg(originalImage.GetData(), originalImage.GetWidth(), originalImage.GetHeight());
	ImageData codeImg1(codedImage1.GetData(), codedImage1.GetWidth(), codedImage1.GetHeight());
	ImageData codeImg2(codedImage2.GetData(), codedImage2.GetWidth(), codedImage2.GetHeight());

	int size = orgImg.getHeight()*orgImg.getWidth();

	for (unsigned int i = 0; i < orgImg.getHeight(); i++) {
		for (unsigned int j = 0; j < orgImg.getWidth(); j++) {
			if (decodePixelValue(codeImg1, codeImg2, i, j)) {
				orgImg.set(i, j, 255);
			}
			else {
				orgImg.set(i, j, 0);
			}
		}
		_progressFunction((i + 1) * orgImg.getWidth(), size);
	}
}

void Crypto::setC1(ImageData& codeImg, int i, int j) {
	codeImg.set(i * 2, j * 2, 0);
	codeImg.set(i * 2, j * 2 + 1, 255);
	codeImg.set(i * 2 + 1, j * 2, 255);
	codeImg.set(i * 2 + 1, j * 2 + 1, 0);
}

void Crypto::setC2(ImageData& codeImg, int i, int j) {
	codeImg.set(i * 2, j * 2, 255);
	codeImg.set(i * 2, j * 2 + 1, 0);
	codeImg.set(i * 2 + 1, j * 2, 0);
	codeImg.set(i * 2 + 1, j * 2 + 1, 255);
}

int Crypto::decodePixelValue(const ImageData& codeImg1, const ImageData& codeImg2, int i, int j) {
	if (codeImg1.at(i * 2, j * 2, 0) == codeImg2.at(i * 2, j * 2, 0)) {
		return 1;
	}
	else {
		return 0;
	}
}