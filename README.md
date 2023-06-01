# ImageProcessModule
This repo implements some functions to process inputting images and provides a DLL file.
# Software requirements
* CMake 3.13 or higher  (install CMake via the powershell CMD)
`winget install cmake`
* make  
`winget install make`
* Microsoft Visual Studio 2019 or higher
* [OpenCV](https://opencv.org/releases/)
## How to build DLL
1. clone repo to local
2. create build folder
3. Run cmake within this build folder.  
`cmake -G "Visual Studio 17 2022" -DCMAKE_BUILD_TYPE=Release -DOpenCV_DIR=/path/to/opencv/OpenCVConfigcmake ..`
4. Build  
  `cd build`  
  `cmake --build . --config Release --verbose`
