#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <opencv2/opencv.hpp>
#include <cutImageAlgr.h>
#include <templateMatcher.h>
using namespace std;
using namespace cv;

void test_base64_text();
void test_base64_image_show(std::string path);
void test_base64_image_matcher(std::string image, std::string target);
int main()
{
    test_base64_text();
    test_base64_image_matcher("image.jpg", "target.jpg");
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

void test_base64_image_matcher(std::string image, std::string target)
{
    Mat img = imread(image);
    vector<uchar> data;
    imencode(".jpg", img, data);
    string encodedImg = Base64Encoder(reinterpret_cast<char *>(data.data()), data.size());
    
    data.clear();
    Mat targetMat = imread(target);
    imencode(".jpg", targetMat, data);
    string encodedTarget = Base64Encoder(reinterpret_cast<char *>(data.data()), data.size());
    int loc_x = -1;
    int loc_y = -1;
    auto quality = MatchTarget(&encodedImg[0], encodedImg.size(), &encodedTarget[0], encodedTarget.size(), loc_x, loc_y);
    std::cout << "Quality: " << quality << "\tlocation: " << loc_x << "x" << loc_y << std::endl;
}