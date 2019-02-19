#pragma once

#include <string>
#include <functional>

namespace events {
	enum eventType
	{
		none = 0, // meta
		mouseDown, mouseUp, mouseMove, mouseScroll, // mouse
		keyDown, keyUp, // keyboard
		windowFocus, windowBlur, windowMove, windowResize, windowClose // window
	};

	class Event
	{
	public:
		virtual eventType getType() const = 0;
	protected:
		bool handled = false;
	};

	/*class Dispatcher
	{
		template<typename T>
		using eventCallback = std::function<bool(T&)>;

	public:
		Dispatcher(Event& e) : event(e) {}
		bool Dispatch(eventCallback<T> callback)
		{
			if (event.getType() == T::getType())
			{
				m_Event.Handled = callback(*(T*)&m_Event);
				return true;
			}
			return false;
		}

	private:
		Event& event;
	};*/
}

#define GET_TYPE(type) static eventType getStaticType() { return eventType::##type; } \
					   virtual eventType getType() const override { return getStaticType(); }