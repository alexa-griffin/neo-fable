#pragma once

#include "event.hpp"
#include "keyboard.hpp"
#include "mouse.hpp"
#include "window.hpp"

#define ON_EVENT(type, classType, action) if (event.getType() == events::eventType::type) \
	{ \
		events::classType& e = (events::classType&)event; \
		action \
	}

#define ON_MOUSEDOWN(action)     ON_EVENT(mouseDown,	MouseDown,	  action)
#define ON_MOUSEUP(action)		 ON_EVENT(mouseUp,		MouseUp,	  action)
#define ON_MOUSEMOVE(action)     ON_EVENT(mouseMove,	MouseMove,	  action)
#define ON_SCROLL(action)        ON_EVENT(mouseScroll,  MouseScroll,  action)
#define ON_KEYDOWN(action)       ON_EVENT(keyDown,		KeyDown,	  action)
#define ON_KEYUP(action)         ON_EVENT(keyUp,		KeyUp,		  action)
#define ON_WINDOW_FOCUS(action)  ON_EVENT(windowFocus,  WindowFocus,  action)
#define ON_WINDOW_BLUR(action)   ON_EVENT(windowBlur,   WindowBlur,   action)
#define ON_WINDOW_MOVE(action)   ON_EVENT(windowMove,   WindowMove,   action)
#define ON_WINDOW_RESIZE(action) ON_EVENT(windowResize, WindowResize, action)
#define ON_WINDOW_CLOSE(action)  ON_EVENT(windowClose,  WindowClose,  action)