// cutImageAlgr.cpp : Defines the entry point for the application.
//
#include <opencv2/opencv.hpp>
#include <windows.h>
#include <wincrypt.h>
#include <iostream>
#include <stdio.h>
#include "cutImageAlgr.h"
using namespace cv;
using namespace std;
extern "C" {
	// 声明回调函数类型
	typedef void(*DebugCallback)(const char*);

	// 定义全局变量保存回调函数
	static DebugCallback s_DebugCallback = nullptr;

	// 设置回调函数
	__declspec(dllexport) void SetDebugCallback(DebugCallback callback) {
		s_DebugCallback = callback;
	}

	// 调试输出函数
	__declspec(dllexport) void DebugPrint(const char* message) {
		if (s_DebugCallback) {
			s_DebugCallback(message);
		}
	}

	// 基本测试函数
	__declspec(dllexport) void BaseFunctionTest(char* data, int length)
	{
		char msg[2048] = "";
		sprintf_s(msg, "Function Name:\n\tBaseFunctionTest\nBrief:\n\tPrint the debug msg to check if Debug callback works\n"
						"Parameters:\n\tdata, char*, Pointer. point to the data buffer;\n\tlength, int, length of the data;\n"
						"Return:\n\tvoid\n Argument:\n\tdata = %s\n\tlength = %d\n", data, length);
		DebugPrint(msg);
	}
	__declspec(dllexport) void Base64Encoder(char* data, int length)
	{
		char msg[2048] = "";
		sprintf_s(msg, "Function Name:\n\tBase64Encoder\nBrief:\n\tEncode the input string with Base64.\n"
						"Parameters:\n\tdata, char*, Pointer. point to the source data;\n\tlength, int, length of the data;\n"
						"Return:\n\tvoid\n Argument:\n\tdata = %s\n\tlength = %d\n", data, length);
		std::string source(data, length);
		DWORD binarySize = static_cast<DWORD>(length);
		LPBYTE pbBinary = reinterpret_cast<LPBYTE>(data);

		DWORD dwFlags = CRYPT_STRING_BASE64;
		DWORD stringSize = 0;

		CryptBinaryToString(pbBinary, binarySize, dwFlags, nullptr, &stringSize);

		std::string encodedData(stringSize, '\0');

		if (!CryptBinaryToString(pbBinary, binarySize, dwFlags,
								 const_cast<LPTSTR>(encodedData.data()), &stringSize))
		{
			sprintf(msg + strlen(msg), "Encoded result: Failed to decode Base64 data. \nError code: %ld\n", GetLastError());
		} else {
			sprintf(msg + strlen(msg), "Encoded result: %s\n", encodedData.c_str());
		}

		DebugPrint(msg);
	}
	__declspec(dllexport) void Base64Decoder(char* data, int length)
	{
		char msg[2048] = "";
		sprintf_s(msg, "Function Name:\n\tBase64Decoder\nBrief:\n\tDecode the input string with Base64.\n"
						"Parameters:\n\tdata, char*, Pointer. point to the encoded data;\n\tlength, int, length of the data;\n"
						"Return:\n\tvoid\n Argument:\n\tdata = %s\n\tlength = %d\n", data, length);
		// Base64 编码后的字符串
		std::string source(data, length);
		DWORD dwFlags = CRYPT_STRING_BASE64;
		DWORD binarySize = 0;

		CryptStringToBinary(source.c_str(), 0, dwFlags, nullptr, &binarySize, nullptr, nullptr);

		std::string binaryData(binarySize, '\0');

		if (!CryptStringToBinary(source.c_str(), 0, dwFlags,
								 reinterpret_cast<LPBYTE>(&binaryData[0]), &binarySize, nullptr, nullptr))
		{
			sprintf(msg + strlen(msg), "Decoded result: Failed to decode Base64 data. \nError code: %ld\n", GetLastError());
		} else {
			sprintf(msg+ strlen(msg), "Decoded data: %s\n", binaryData.c_str());
		}
		DebugPrint(msg);
	}

}

