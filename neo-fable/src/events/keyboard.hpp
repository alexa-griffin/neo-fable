#pragma once
#include "event.hpp"

namespace events {
	class KeyPress : public Event 
	{
	public:
		inline int GetKeyCode() const { return keyCode; }
	protected:
		KeyPress(int keyCode) : keyCode(keyCode) {}
		int keyCode;
	};

	class KeyDown : public KeyPress 
	{
	public:
		KeyDown(int keyCode) : KeyPress(keyCode) {}
		void debugPrint() const override
			{ std::cout << "KeyDown: " << keyCode << std::endl; }

		GET_TYPE(keyDown);
	};

	class KeyUp : public KeyPress
	{
	public:
		KeyUp(int keyCode) : KeyPress(keyCode) {}
		void debugPrint() const override
			{ std::cout << "KeyUp: " << keyCode << std::endl; }

		GET_TYPE(keyUp);
	};
}