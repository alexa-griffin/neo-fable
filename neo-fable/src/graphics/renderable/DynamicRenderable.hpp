#pragma once

#include <vector>

namespace graphics {

	class DynamicRenderable
	{
	public:
		DynamicRenderable();
		~DynamicRenderable();

		std::vector<float> getPosData();
		std::vector<float> getColorData();

		unsigned int getIndices();
	};
}
