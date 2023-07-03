#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include "cutImageAlgr.h"
#include "rotateTransform.h"

using namespace std;
using namespace cv;
#define MEM_MAX_SIZE 1024 * 1024 * 50
extern "C"
{
    __declspec(dllexport) int RotateTransform(char *image, int imageSize, double &angle)
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
        sprintf_s(msg + strlen(msg), sizeof(msg) - strlen(msg), "Calling RotateTransform()....Done\n");
        DebugPrint(msg);
        return 0;
    }
}