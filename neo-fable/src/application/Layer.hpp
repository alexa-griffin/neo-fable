#pragma once
#include <string>

#include "Window.hpp"
#include "../events/events.hpp"

namespace application {
	class Layer {
	public:
		Layer(std::string name, std::shared_ptr<application::Window> win)
			: name(name) { window = win; };

		virtual ~Layer();

		inline const std::string getName() const { return name; }

		virtual void update() = 0;

		// lifecycle methods
		virtual void onMount() {}
		virtual void onUnmount() {}

		// events
		// bool to return if the event is handled
		virtual bool onEvent(const events::Event& e) { return false; };
	protected:
		std::string name; // for debuging
		std::shared_ptr<Window> window;
	};
}