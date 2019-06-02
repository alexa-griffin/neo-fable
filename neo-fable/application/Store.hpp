#pragma once

#include "../util/util.hpp"
#include "../abstract/Camera.hpp"

namespace application {
	struct State 
	{
		abstract::Camera* camera;
		util::Json data;
	};

	class Store
	{
	public:
		Store();
		~Store();
		State* getState() { return &state; };
		
		template<typename T>
		void setState(const char* key, T value);
	private:
		State state;
	};
}

