#pragma once
#include <string>
#include "../events/events.hpp"

namespace application {
	class Layer {
	public:
		Layer(std::string name) : name(name) {}
		virtual ~Layer();

		virtual void update() const = 0;

		// lifecycle methods
		virtual void update() {}
		virtual void onMount() {}
		virtual void onUnmount() {}
		virtual void onEvent(::events::Event& e) {}

		inline const std::string getName() const { return name; }
	protected:
		std::string name; // for debuging
	};
}