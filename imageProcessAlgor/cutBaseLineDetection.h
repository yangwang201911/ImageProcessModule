#pragma once

#include <iostream>
extern "C"
{
	__declspec(dllexport) int CutLineDetection(char *image, int imageSize, int& delta_x, int& delta_y);
}