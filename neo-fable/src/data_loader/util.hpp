#pragma once
#include <string>
#include <fstream>
#include <iostream>

namespace data_loader {
	template <typename T>
	struct FileResult 
	{
		bool success;
		T content;
	};

	FileResult<std::string> loadFileToString(std::string path);
}