#pragma once
#include "termcolor/termcolor.hpp"

//TODO: make log level settings

namespace application {
	namespace log {
		//TODO: make this an external file
		inline void print() {};

		// single arguement varient in order to eleminate the trailing comma
		template<typename T>
		inline void print(T f)
		{
			std::cout << f << std::endl;
		};

		template<typename T, typename... Args>
		inline void print(T f, Args... args) 
		{
			std::cout << f << " ";
			print(args ...);
		};
	}
}


#ifdef __PRODUCTION_BUILD__
	#define LOG_ERROR(m)
	#define LOG_WARN(m)
	#define LOG_INFO(m)
	#define LOG_VAR(v)
#else
//TODO: define log levels for these
#define LOG_ERROR(...) \
	std::cout << ::termcolor::red << "[ERROR]" << ::termcolor::reset << ": "; \
	::application::log::print(__VA_ARGS__)

#define LOG_WARN(...)  \
	std::cout << ::termcolor::yellow << "[WARNING]" << ::termcolor::reset << ": "; \
	::application::log::print(__VA_ARGS__)

#define LOG_INFO(...)  \
	std::cout << ::termcolor::cyan << "[INFO]" << ::termcolor::reset << ": "; \
	::application::log::print(__VA_ARGS__)

// for logging expression names and values
#define LOG_VAR(v) ::application::log::print(#v, v)
#endif