#pragma once

#include <iostream>
extern "C"
{
	__declspec(dllexport) int PixelSizeMeasure(char *image, int imageSize, int focalDistance, int& pixelSize);
}