#ifndef DEBUG_H
#define DEBUG_H

#include <SDL.h>
#include <iostream>

namespace GAME {
	/// This enum is a simple 8-bit unsigned int
	enum class EMessageType : unsigned short {
		INFO = 0,
		WARNING,
		ERROR,
		FATAL_ERROR
	};

	class Debug {
	public:
		Debug() = delete; /// New in C++ 11: this deletes the automatic constructor from being formed if no other constructor is decleared 
		static void Log(const EMessageType MsgType, const char Class[], const char Method[], const char Contents[], bool writeToConsole);
	};
}

#endif