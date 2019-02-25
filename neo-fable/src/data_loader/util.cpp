#include "util.hpp"

namespace data_loader {
	FileResult<std::string> loadFileToString(std::string path) 
	{
		FileResult<std::string> res;
		std::ifstream file(path);
		if (file.is_open()) 
		{
			res.success = true;
			res.content.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
		}
		else 
		{
			res.success = false;
			res.content = "";
			LOG_WARN("failed to load file", path);
		}

		return res;
	}
}