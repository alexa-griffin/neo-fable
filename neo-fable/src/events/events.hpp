#pragma once

#include "event.hpp"
#include "keyboard.hpp"
#include "mouse.hpp"
#include "window.hpp"

#define ON_EVENT(classs, evType, action) if (event.getType() == events::eventType::evType) \
	{ \
		events::classs& e = (events::classs&)event; \
		action \
	}


#define ON_MOUSE_DOWN(action)	   ON_EVENT(MouseUp, mouseUp, action)
#define ON_MOUSE_UP(action)        ON_EVENT(MouseDown, mouseDown, action)
#define ON_MOUSE_MOVE(action)	   ON_EVENT(MouseMove, mouseMove, action)
#define ON_MOUSE_SCROLL(action)	   ON_EVENT(MouseScroll, mouseScroll, action)

#define ON_KEY_UP(action)          ON_EVENT(KeyUp, keyUp, action)
#define ON_KEY_DOWN(action)	       ON_EVENT(KeyDown, keyDown, action)

#define ON_WINDOW_FOCUS(action)    ON_EVENT(WindowFocus, windowFocus, action)
#define ON_WINDOW_BLUR(action)     ON_EVENT(WindowBlur, windowBlur, action)
#define ON_WINDOW_MOVE(action)     ON_EVENT(WindowMove, windowMove, action)
#define ON_WINDOW_RESIZE(action)   ON_EVENT(WindowResize, windowResize, action)
#define ON_WINDOW_CLOSE(action)    ON_EVENT(WindowClose, windowClose, action)