#include <opencv2/opencv.hpp>
#include <windows.h>
#include <wincrypt.h>
#include <iostream>
#include <stdio.h>
#include "cutImageAlgr.h"
#include "cutBaseLineDetection.h"
using namespace cv;
using namespace std;
extern "C"
{
	__declspec(dllexport) int CutTraceDetection(char *image, int imageSize, float& quality)
    {
        char msg[256] = "";
        sprintf_s(msg + strlen(msg), sizeof(msg) - strlen(msg), "Calling CutLineDetection()....\n");
        quality = -1.0;
		std::string imageData = Base64Decoder(image, imageSize);
		std::vector<uchar> decodedImage(imageData.begin(), imageData.end());
		cv::Mat imageMat = imdecode(decodedImage, cv::IMREAD_COLOR);

        if (!imageMat.data)
        {
            sprintf_s(msg + strlen(msg), sizeof(msg) - strlen(msg), "Error: Failed to load image data.\n");
            DebugPrint(msg);
            return -1;
        }

		// TODO: implement the cut line detection here

		sprintf_s(msg + strlen(msg), sizeof(msg) - strlen(msg), "Cut trace quality: %.2f\n", quality);
        sprintf_s(msg + strlen(msg), sizeof(msg) - strlen(msg), "Calling CutLineDetection()....Done\n");
		DebugPrint(msg);
        return 0;
    }
}