#pragma once

#include <string>
#include <functional>
#include <iostream>

namespace events {
	enum eventType
	{
		none = 0, // meta & for errors
		mouseDown, mouseUp, mouseMove, mouseScroll, // mouse
		keyDown, keyUp, // keyboard
		windowFocus, windowBlur, windowMove, windowResize, windowClose // window
	};

	class Event
	{
	public:
		virtual eventType getType() const = 0;
		virtual void debugPrint() const = 0;

	protected:
		bool handled = false;
	};
}

#define GET_TYPE(type) static eventType getStaticType() { return eventType::##type; } \
					   virtual eventType getType() const override { return getStaticType(); }