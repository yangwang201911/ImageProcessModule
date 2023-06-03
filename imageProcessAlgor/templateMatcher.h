
#pragma once

#include <iostream>
extern "C"
{
	__declspec(dllexport) int MatchTarget(char *image, int image_size, char *target, int target_size, int &loc_x, int &loc_y);
}