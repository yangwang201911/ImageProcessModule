
#pragma once

#include <iostream>
extern "C"
{
	__declspec(dllexport) int MatchTarget(char *image, int imageSize, char *target, int targetSize, int &loc_x, int &loc_y);
}