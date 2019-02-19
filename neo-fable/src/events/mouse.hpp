#pragma once
#include "event.hpp"


namespace events {
	class MouseButton : public Event
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
		void debugPrint() const override
			{ std::cout << "MouseDown: " << button << std::endl; }

		GET_TYPE(mouseDown);
	};


	class MouseUp : public MouseButton
	{
	public:
		MouseUp(int button) : MouseButton(button) {};
		void debugPrint() const override
			{ std::cout << "MouseUp: " << button << std::endl; }

		GET_TYPE(mouseUp);
	};


	class MouseMove : public Event
	{
	public:
		MouseMove(double x, double y) : x(x), y(y) {};
		void debugPrint() const override
			{ std::cout << "MouseMove: " << x << ", " << y << std::endl; }

		GET_TYPE(mouseMove);
		double inline getX() const { return x; }
		double inline getY() const { return y; }
	private:
		double x, y;
	};

	class MouseScroll : public Event
	{
	public:
		MouseScroll(double x, double y) : x(x), y(y) {};
		void debugPrint() const override
			{ std::cout << "MouseScroll: " << x << ", " << y << std::endl; }

		GET_TYPE(mouseScroll);
		double inline getX() const { return x; }
		double inline getY() const { return y; }
	private:
		double x, y;
	};
}