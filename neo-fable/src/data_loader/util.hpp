#pragma once

#include <string>
#include <fstream>
#include <iostream>

#include "application/log.hpp"

namespace data_loader {
	struct FileResult 
	{
		bool success;
		std::string content;
	};

	FileResult loadFileToString(std::string path);
}