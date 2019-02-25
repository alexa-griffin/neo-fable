#pragma once
#include "event.hpp"
#include "application/log.hpp"

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
			{ LOG_INFO("keydown event:", keyCode); }

		GET_TYPE(keyDown);
	};

	class KeyUp : public KeyPress
	{
	public:
		KeyUp(int keyCode) : KeyPress(keyCode) {}
		void debugPrint() const override
			{ LOG_INFO("keyup event:", keyCode); }

		GET_TYPE(keyUp);
	};
}