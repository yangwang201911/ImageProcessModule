// cutImageAlgr.cpp : Defines the entry point for the application.
//
#include <opencv2/opencv.hpp>
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
		char msg[256] = "";
		sprintf_s(msg, "Function Name:\n\tBaseFunctionTest\nBrief:\n\tPrint the debug msg to check if Debug callback works\n"
						"Parameters:\n\tdata, char*, Pointer. point to the data buffer;\n\tlength, int, length of the data;\n"
						"Return:\n\tvoid\n Argument:\n\tdata = %p\n\tlength = %d\n", data, length);
#if 0
		// 解码Base64字符串
		std::string base64Encoded(data, length);
		std::string binaryData = base64_decode(base64Encoded);

		// 处理图像数据
		cv::Mat image = cv::imdecode(cv::Mat(binaryData), cv::IMREAD_COLOR);
		// ...
#endif
		DebugPrint(msg);
	}

}

