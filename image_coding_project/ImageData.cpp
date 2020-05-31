#include "ImageData.h"


unsigned char& ImageData::at(unsigned int i, unsigned int j, unsigned int k) {
	unsigned long int index = (i * _width + j) * 3 + k;

	if (index >= _width * _height * 3) throw std::out_of_range("Out of range width " + std::to_string(_width) + " height " + std::to_string(_height) + " index " + std::to_string(index));

	return _data[index];
}
unsigned char ImageData::at(unsigned int i, unsigned int j, unsigned int k) const {
	unsigned long int index = (i * _width + j) * 3 + k;

	if (index >= _width * _height * 3) throw std::out_of_range("Out of range width " + std::to_string(_width) + " height " + std::to_string(_height) + " index " + std::to_string(index));

	return _data[index];
}
double ImageData::getLuminance(unsigned int i, unsigned int j) {
	unsigned long int index = (i * _width + j) * 3;

	if (index >= _width * _height * 3) throw std::out_of_range("Out of range width "+std::to_string(_width)+" height "+std::to_string(_height) + " index " + std::to_string(index));

	return (0.299*_data[index] + 0.587*_data[index + 1] + 0.114*_data[index + 2]) / 255;
}

void ImageData::set(unsigned int i, unsigned int j, unsigned char r, unsigned char g, unsigned char b) {
	at(i, j, 0) = r;
	at(i, j, 1) = g;
	at(i, j, 2) = b;
}
void ImageData::set(unsigned int i, unsigned int j, unsigned char brightness) {
	at(i, j, 0) = brightness;
	at(i, j, 1) = brightness;
	at(i, j, 2) = brightness;
}