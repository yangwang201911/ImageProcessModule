#pragma once

#include <iostream>
extern "C"
{
    __declspec(dllexport) int CutTraceDetection(char *image, int imageSize,
                                                double &angle,
                                                int &traceCenterOffset,
                                                int &tranceWidth,
                                                int &maxTraceWidth,
                                                int &maxArea);
}