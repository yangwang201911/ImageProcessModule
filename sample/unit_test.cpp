#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cutImageAlgr.h>
using namespace std;

int main()
{
    char msg[] = "hello world";
    std::cout << "msg: " << msg << std::endl; 
    auto imageEncodedData = Base64Encoder(msg, strlen(msg));
    std::cout << "Encoded msg: " << imageEncodedData << std::endl;

    auto imageDecodedData = Base64Decoder(&imageEncodedData[0], imageEncodedData.size());
    std::cout << "Decoded msg: " << imageDecodedData << std::endl;
    return 0;
}