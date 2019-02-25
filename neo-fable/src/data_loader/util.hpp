#pragma once

#include <string>
#include <fstream>
#include <iostream>

#include "application/log.hpp"

namespace data_loader {
	template <typename T>
	struct FileResult 
	{
		bool success;
		T content;
	}; //NOTE: why the hell did past me think it was a good idea to use a template here?

	FileResult<std::string> loadFileToString(std::string path);
}