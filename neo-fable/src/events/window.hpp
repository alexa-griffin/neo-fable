#pragma once
#include "event.hpp"

namespace events {
	class WindowFocus : public Event
	{
	public:
		WindowFocus() {};
		GET_TYPE(windowFocus);
	};

	class WindowBlur : public Event
	{
	public:
		WindowBlur() {};
		GET_TYPE(windowBlur);
	};

	class WindowClosed : public Event
	{
	public:
		WindowClosed() {};
		GET_TYPE(windowClose);
	};

	class WindowMove : public Event
	{
	public:
		WindowMove(int x, int y) : x(x), y(y) {};
		GET_TYPE(windowMove);
		inline int getX() const { return x; }
		inline int getY() const { return y; }

	private:
		int x, y;
	};

	class WindowResize : public Event
	{
	public:
		WindowResize(int w, int h) : w(w), h(h) {};
		GET_TYPE(windowResize);
		inline int getWidth() const { return w; }
		inline int getHeight() const { return h; }
	private:
		int w, h;
	};
}