#include "Store.hpp"


namespace application {
	Store::Store()
	{
		state.camera = nullptr;
		state.data = util::Json({});
	}


	Store::~Store()
	{
	}

	template<typename T>
	void Store::setState(const char* key, T value)
	{ //TODO: middleware
		state.data[key] = value;
	}
}
