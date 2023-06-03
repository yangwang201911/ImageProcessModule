// cutImageAlgr.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
extern "C"
{
	__declspec(dllexport) void BaseFunctionTest(char *data, int length);
	__declspec(dllexport) void DebugPrint(const char *message);
}
__declspec(dllexport) std::string Base64Encoder(char *data, int length);
__declspec(dllexport) std::string Base64Decoder(char *data, int length);