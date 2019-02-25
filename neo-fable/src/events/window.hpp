#pragma once
#include "event.hpp"
#include "application/log.hpp"

namespace events {
	class WindowFocus : public Event
	{
	public:
		WindowFocus() {};
		void debugPrint() const override
			{ LOG_INFO("window focus event"); }

		GET_TYPE(windowFocus);
	};

	class WindowBlur : public Event
	{
	public:
		WindowBlur() {};
		void debugPrint() const override
			{ LOG_INFO("window blur event"); }

		GET_TYPE(windowBlur);
	};

	class WindowClosed : public Event
	{
	public:
		WindowClosed() {};
		void debugPrint() const override
			{ LOG_INFO("window closed event"); }

		GET_TYPE(windowClose);
	};

	class WindowMove : public Event
	{
	public:
		WindowMove(int x, int y) : x(x), y(y) {};
		void debugPrint() const override
			{ LOG_INFO("window move event: (", x, ", ", y, ")"); }

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
		void debugPrint() const override
			{ LOG_INFO("window resize event: width: ", w, ", height :", h); }

		GET_TYPE(windowResize);
		inline int getWidth() const { return w; }
		inline int getHeight() const { return h; }
	private:
		int w, h;
	};
}