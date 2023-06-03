#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <opencv2/opencv.hpp>
#include <cutImageAlgr.h>
using namespace std;
using namespace cv;

void test_base64_text();
void test_base64_image_show(std::string path);
int main()
{
    test_base64_text();
    test_base64_image_show("image.jpg");
    return 0;
}

void test_base64_text()
{
    char msg[] = "hello world";
    std::cout << "msg: " << msg << std::endl;
    auto imageEncodedData = Base64Encoder(msg, strlen(msg));
    std::cout << "Encoded msg: " << imageEncodedData << std::endl;
    auto imageDecodedData = Base64Decoder(&imageEncodedData[0], imageEncodedData.size());
    std::cout << "Decoded msg: " << imageDecodedData << std::endl;
}

void test_base64_image_show(std::string path)
{
    Mat img = imread(path);
    vector<uchar> data;
    std::cout << "start show image...\n";
    imencode(".jpg", img, data);
    string encodedImg = Base64Encoder(reinterpret_cast<char *>(data.data()), data.size());

    string decodedData = Base64Decoder(&encodedImg[0], encodedImg.size());
    vector<uchar> decodedImage(decodedData.begin(), decodedData.end());
    Mat decodedMat = imdecode(decodedImage, cv::IMREAD_COLOR);
    cv::imshow("image", decodedMat);
    cv::waitKey(0);
}