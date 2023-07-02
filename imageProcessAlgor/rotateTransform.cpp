#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include "cutImageAlgr.h"
#include "rotateTransform.h"

using namespace std;
using namespace cv;
static char * g_dynamicMem = nullptr;
#define MEM_MAX_SIZE 1024 * 1024 * 50
extern "C"
{
	__declspec(dllexport) int RotateTransform(char *image, int imageSize, double &angle, char **outputImage)
    {
        char msg[256] = "";
        sprintf_s(msg + strlen(msg), sizeof(msg) - strlen(msg), "Calling RotateTransform()....\n");
        sprintf_s(msg + strlen(msg), sizeof(msg) - strlen(msg), "Encoded input image size: %d\n", imageSize);
		std::string imageData = Base64Decoder(image, imageSize);
		std::vector<uchar> decodedImage(imageData.begin(), imageData.end());
		cv::Mat srcImage = imdecode(decodedImage, cv::IMREAD_COLOR);
        if (!srcImage.data)
        {
            sprintf_s(msg + strlen(msg), sizeof(msg) - strlen(msg), "Error: Failed to load image data.\n");
            DebugPrint(msg);
            return -1;
        }
        int centerX = srcImage.cols / 2;
        int centerY = srcImage.rows / 2;

        int squareSize = 50;
        int startX = centerX - (squareSize / 2);
        int startY = centerY - (squareSize / 2);
        int endX = startX + squareSize;
        int endY = startY + squareSize;

		// TODO: implement the image rotating transform here

        angle = -10.0;

        cv::Scalar color(0, 255, 0);
        int thickness = 5;
        cv::rectangle(srcImage, cv::Point(startX, startY), cv::Point(endX, endY), color, thickness);
        sprintf_s(msg + strlen(msg), sizeof(msg) - strlen(msg), "Rotate angle: %.2f\n", angle);

        std::vector<uchar> buffer;
        std::vector<int> params = {cv::IMWRITE_JPEG_QUALITY, 100};
        cv::imencode(".jpg", srcImage, buffer, params);
        char* ptr = reinterpret_cast<char*>(buffer.data());
        std::string outputImageDate = Base64Encoder(ptr, buffer.size());
        if (!g_dynamicMem) {
            g_dynamicMem = (char*)malloc(MEM_MAX_SIZE * sizeof(char));
        }
        if (outputImageDate.size() >= MEM_MAX_SIZE) {
            sprintf_s(msg + strlen(msg), sizeof(msg) - strlen(msg), "[ERROR] Destation image buffer is not large enough. Maximum buffer size is %d and Current dumped image size is %d.\n", MEM_MAX_SIZE, outputImageDate.size());
            return -1;
        }
        strcpy(g_dynamicMem, outputImageDate.c_str());
        if (outputImage) {
            *outputImage = g_dynamicMem;
        }
        sprintf_s(msg + strlen(msg), sizeof(msg) - strlen(msg), "Calling RotateTransform()....Done\n");
        DebugPrint(msg);
        return 0;
    }
}