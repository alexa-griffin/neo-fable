#pragma once
#include "event.hpp"


namespace events {
	class MouseButton : Event
	{
	public:
		int inline getButton() const { return button; }
	protected:
		MouseButton(int button) : button(button) {};
		int button;
	};


	class MouseDown : public MouseButton
	{
	public:
		MouseDown(int button) : MouseButton(button) {};
		GET_TYPE(mouseDown);
	};


	class MouseUp : public MouseButton
	{
	public:
		MouseUp(int button) : MouseButton(button) {};
		GET_TYPE(mouseUp);
	};


	class MouseMove : public Event
	{
	public:
		MouseMove(int x, int y) : x(x), y(y) {};
		GET_TYPE(mouseMove);
		int inline getX() const { return x; }
		int inline getY() const { return y; }
	private:
		int x, y;
	};

	class MouseScroll : public Event
	{
	public:
		MouseScroll(int x, int y) : x(x), y(y) {};
		GET_TYPE(mouseScroll);
		int inline getX() const { return x; }
		int inline getY() const { return y; }
	private:
		int x, y;
	};
}