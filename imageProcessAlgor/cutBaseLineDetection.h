#pragma once

#include <iostream>
extern "C"
{
	/**
	 * @brief measure offset between the center of the image to the center of cut line
	 * @param image 		source image data buffer encoded with Base64
	 * @param imageSize		buffer size
	 * @param quality		save the cut trace quality to chech if it existed
	 * @return return 0 if successful, otherwise non-zero will return.
	 */
	__declspec(dllexport) int CutTraceDetection(char *image, int imageSize, float &quality);
}