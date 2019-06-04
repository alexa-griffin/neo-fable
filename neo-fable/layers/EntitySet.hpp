#pragma once

#include "../application/Layer.hpp"
#include "../abstract/Camera.hpp"
#include "../abstract/entity/Player.hpp"
#include "../abstract/entity/StaticObject.hpp"

namespace layers {
	class EntitySet : public application::Layer
	{
	public:
		EntitySet();
		~EntitySet();

		virtual void onUpdate(unsigned int dT);

		//TODO: push/pop based on chunks
		void push(abstract::Entity* en) { entities.push_back(en); };

	private:
		std::vector<abstract::Entity*> entities;
	};
}
