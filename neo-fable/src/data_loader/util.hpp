#pragma once

#include <string>
#include <fstream>
#include <iostream>

#include "stb_image/stb_image.h"

#include "application/log.hpp"

namespace data_loader {
	struct FileResult 
	{
		bool success;
		std::string content;
	};

	struct ImageData {
		int width, height;
		int channels;
		unsigned char* data;
	};

	FileResult loadFileToString(std::string path);
	ImageData loadImage(std::string path);
}