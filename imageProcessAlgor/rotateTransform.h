#pragma once

#include <iostream>
extern "C"
{
	/**
	 * @brief calculate the angel of the image
	 * @param image 		source image data buffer encoded with Base64
	 * @param imageSize		buffer size
	 * @param angle 		save the angle
	 * @param outputImage 	pointer to the saved output image encoded with Base64 
	 * @return return 0 if successful, otherwise non-zero will return.
	 */
	__declspec(dllexport) int RotateTransform(char *image, int imageSize, double &angle, char **outputImage);
}