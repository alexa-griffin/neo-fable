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
	#define LOG_ERROR(...)
	#define LOG_WARN(...)
	#define LOG_INFO(...)
	#define LOG_TRACE(...)
	#define LOG_NL()
	#define LOG_BLK()
	#define LOG_VAR(...)
#else
//TODO: define log levels for these
#define LOG_ERROR(...) ::application::log::print(::termcolor::red, "[ERROR]", ::termcolor::reset, ": ", __VA_ARGS__)
#define LOG_WARN(...) ::application::log::print(::termcolor::yellow, "[WARNING]", ::termcolor::reset, ": ", __VA_ARGS__)
#define LOG_INFO(...) ::application::log::print(::termcolor::cyan, "[INFO]", ::termcolor::reset, ": ", __VA_ARGS__)
#define LOG_TRACE(...) ::application::log::print(::termcolor::grey, "[TRACE]", ::termcolor::reset, ": ", __VA_ARGS__)

#define LOG_NL() ::application::log::print(std::endl)
#define LOG_BLK() ::application::log::print("")

// for logging expression names and values
#define LOG_VAR(v) ::application::log::print(#v, v)
#endif