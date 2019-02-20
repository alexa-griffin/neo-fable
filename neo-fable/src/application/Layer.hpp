#pragma once
#include <string>
#include "../events/events.hpp"

namespace application {
	class Layer {
	public:
		Layer(std::string name) : name(name) {}
		virtual ~Layer();

		inline const std::string getName() const { return name; }

		virtual void update() = 0;

		// lifecycle methods
		virtual void onMount() {}
		virtual void onUnmount() {}
		virtual bool onEvent(::events::Event& e) { return false;  } 
		// bool to return if the event is handled

	protected:
		std::string name; // for debuging
	};
}