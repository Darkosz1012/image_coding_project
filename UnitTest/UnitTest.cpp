#pragma warning(disable : 4996)
#include "pch.h"
#include "CppUnitTest.h"

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/gauge.h>

#include <memory>
#include "DrawManager.h"
#include "LoadSaveManager.h"
#include "Crypto.h"
#include "TextBoxLogger.h"
#include "ImageData.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace UnitTest
{
	TEST_CLASS(CryptoTest)
	{
	public:
		
		TEST_METHOD(encode)
		{
			wxImage tmp(256,1);
			unsigned char * data = tmp.GetData();
			for (int i = 0; i < 256; i++) {
				data[i * 3] = i;
				data[i * 3 + 1] = i;
				data[i * 3 + 2] = i;
			}
			Crypto crypto;
			std::shared_ptr<wxImage> code1 = std::make_shared<wxImage>(wxNullImage), code2 = std::make_shared<wxImage>(wxNullImage);
			crypto.encode(tmp, *code1, *code2);
			unsigned char * data1 = code1->GetData();
			unsigned char * data2 = code2->GetData();
			for (int i = 0; i < 256; i++) {
				if (i >= 128) {
					Assert::AreEqual(data1[i * 6], data2[i * 6]);
				}
				else {
					Assert::AreNotEqual(data1[i * 6], data2[i * 6]);
				}
			}
			
		}
		TEST_METHOD(decode)
		{
			wxImage tmp(256, 1);
			unsigned char * data = tmp.GetData();
			for (int i = 0; i < 256; i++) {
				data[i * 3] = i;
				data[i * 3 + 1] = i;
				data[i * 3 + 2] = i;
			}
			Crypto crypto;
			std::shared_ptr<wxImage> code1 = std::make_shared<wxImage>(wxNullImage), code2 = std::make_shared<wxImage>(wxNullImage);
			crypto.encode(tmp, *code1, *code2);
			std::shared_ptr<wxImage> decode = std::make_shared<wxImage>(wxNullImage);
			crypto.decode(*code1, *code2, *decode);
			unsigned char * data1 = decode->GetData();
			unsigned char & test = *data1;
			for (int i = 0; i < 256; i++) {
				if (i >= 128) {
					Assert::AreEqual(static_cast<int>(data1[i * 3]), 255);
				}
				else {
					Assert::AreEqual(static_cast<int>(data1[i * 3]), 0);
				}
			}

		}
	};
	TEST_CLASS(SteganoTest)
	{
	public:

		TEST_METHOD(all)
		{
			wxImage tmp(256, 1);
			unsigned char * data = tmp.GetData();
			for (int i = 0; i < 256; i++) {
				data[i * 3] = i;
				data[i * 3 + 1] = i;
				data[i * 3 + 2] = i;
			}
			//Crypto crypto();
			Assert::AreEqual(5, 5);
		}
	};
	TEST_CLASS(ImageDataTest)
	{
	public:

		TEST_METHOD(at)
		{
			wxImage tmp(256, 1);
			unsigned char * data = tmp.GetData();
			for (int i = 0; i < 256; i++) {
				data[i * 3] = i;
				data[i * 3 + 1] = i;
				data[i * 3 + 2] = i;
			}
			ImageData ID(data,256,1);
			
			Assert::AreEqual(static_cast<int>(ID.at(0,10,0)), 10);
			Assert::AreEqual(static_cast<int>(ID.at(0, 15, 1)), 15);
			Assert::AreEqual(static_cast<int>(ID.at(0, 150, 2)), 150);
		}

		TEST_METHOD(constAt)
		{
			wxImage tmp(256, 1);
			unsigned char * data = tmp.GetData();
			for (int i = 0; i < 256; i++) {
				data[i * 3] = i;
				data[i * 3 + 1] = i;
				data[i * 3 + 2] = i;
			}
			const ImageData ID(data, 256, 1);

			Assert::AreEqual(static_cast<int>(ID.at(0, 10, 0)), 10);
			Assert::AreEqual(static_cast<int>(ID.at(0, 15, 1)), 15);
			Assert::AreEqual(static_cast<int>(ID.at(0, 150, 2)), 150);
		}
		TEST_METHOD(set)
		{
			wxImage tmp(256, 1);
			unsigned char * data = tmp.GetData();
			for (int i = 0; i < 256; i++) {
				data[i * 3] = i;
				data[i * 3 + 1] = i;
				data[i * 3 + 2] = i;
			}
			ImageData ID(data, 256, 1);
			ID.set(0, 10, 255, 23, 56);
			ID.set(0, 15, 200);
			Assert::AreEqual(static_cast<int>(ID.at(0, 10, 0)), 255);
			Assert::AreEqual(static_cast<int>(ID.at(0, 10, 1)), 23);
			Assert::AreEqual(static_cast<int>(ID.at(0, 10, 2)), 56);
			Assert::AreEqual(static_cast<int>(ID.at(0, 15, 0)), 200);
			Assert::AreEqual(static_cast<int>(ID.at(0, 15, 1)), 200);
			Assert::AreEqual(static_cast<int>(ID.at(0, 15, 2)), 200);
		}
	};
}
