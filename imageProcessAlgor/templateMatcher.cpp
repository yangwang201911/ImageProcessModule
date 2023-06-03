#include <opencv2/opencv.hpp>
#include <windows.h>
#include <wincrypt.h>
#include <iostream>
#include <stdio.h>
#include "cutImageAlgr.h"
#include "templateMatcher.h"
using namespace cv;
using namespace std;
extern "C"
{
	// Template matcher
	__declspec(dllexport) int MatchTarget(char *image, int imageSize, char *target, int targetSize, int &loc_x, int &loc_y)
	{
		int quality = -1;
		char msg[256] = "";
		loc_x = -1;
		loc_y = -1;
		std::string imageData = Base64Decoder(image, imageSize);
		vector<uchar> decodedImage(imageData.begin(), imageData.end());
		cv::Mat imageMat = imdecode(decodedImage, cv::IMREAD_COLOR);

		std::string targetData = Base64Decoder(target, targetSize);
		vector<uchar> decodedTarget(targetData.begin(), targetData.end());
		cv::Mat targetMat = imdecode(decodedTarget, cv::IMREAD_COLOR);

		// TODO: implement the image matcher here

		loc_x = imageMat.rows / 2;
		loc_y = imageMat.cols / 2;
        quality = 90;
		sprintf_s(msg, sizeof(msg) - strlen(msg), "Quality: %d\t Location: %d x %d\n", quality, loc_x, loc_y);
		DebugPrint(msg);
		return quality;
	}
}
