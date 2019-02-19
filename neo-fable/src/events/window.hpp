#pragma once
#include "event.hpp"

namespace events {
	class WindowFocus : public Event
	{
	public:
		WindowFocus() {};
		void debugPrint() const override
			{ std::cout << "WindowFocus" << std::endl; }

		GET_TYPE(windowFocus);
	};

	class WindowBlur : public Event
	{
	public:
		WindowBlur() {};
		void debugPrint() const override
			{ std::cout << "WindowBlur" << std::endl; }

		GET_TYPE(windowBlur);
	};

	class WindowClosed : public Event
	{
	public:
		WindowClosed() {};
		void debugPrint() const override
			{ std::cout << "WindowClosed" << std::endl; }

		GET_TYPE(windowClose);
	};

	class WindowMove : public Event
	{
	public:
		WindowMove(int x, int y) : x(x), y(y) {};
		void debugPrint() const override
			{ std::cout << "WindowMove: " << x << ", " << y << std::endl; }

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
			{ std::cout << "WindowResize: " << w << ", " << h << std::endl; }

		GET_TYPE(windowResize);
		inline int getWidth() const { return w; }
		inline int getHeight() const { return h; }
	private:
		int w, h;
	};
}