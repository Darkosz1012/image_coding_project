#pragma once

#include <memory>
#include <stdexcept>
#include <string>
class ImageData
{
protected:
	unsigned char * _data;
	unsigned int _width;
	unsigned int _height;
public:
	ImageData(unsigned char* data, unsigned int width, unsigned int height): _data(data), _width(width), _height(height){}
	unsigned char& at(unsigned int i, unsigned int j, unsigned int k);
	unsigned char at(unsigned int i, unsigned int j, unsigned int k)const;
	void set(unsigned int i, unsigned int j, unsigned char r, unsigned char g, unsigned char b);
	void set(unsigned int i, unsigned int j, unsigned char brightness);
	double getLuminance(unsigned int i, unsigned int j);

	unsigned int getWidth() {
		return _width;
	}
	unsigned int getHeight() {
		return _height;
	}
};

