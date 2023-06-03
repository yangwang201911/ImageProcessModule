#pragma once

#include <iostream>
extern "C"
{
	__declspec(dllexport) int RotateTransform(char *image, int imageSize, double &angle);
}