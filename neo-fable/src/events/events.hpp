#pragma once

#include "event.hpp"
#include "keyboard.hpp"
#include "mouse.hpp"
#include "window.hpp"

#define ON_EVENT(type, action) if (event.getType() == events::eventType::type) \
	{ \
		events::MouseScroll& e = (events::MouseScroll&)event; \
		action \
	}