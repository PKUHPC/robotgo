#pragma once
#ifndef MOUSE_H
#define MOUSE_H

#include "../base/os.h"
#include "../base/types.h"
#include <stdbool.h>

#if defined(IS_MACOSX)
	#include <ApplicationServices/ApplicationServices.h>

	typedef enum {
		LEFT_BUTTON = kCGMouseButtonLeft,
		RIGHT_BUTTON = kCGMouseButtonRight,
		CENTER_BUTTON = kCGMouseButtonCenter,
		BACK_BUTTON = 8,
		FORWARD_BUTTON = 9,
		WheelDown  =  4,
		WheelUp    = 5,
		WheelLeft  =  6,
		WheelRight = 7,
	} MMMouseButton;
#elif defined(USE_X11)
	enum _MMMouseButton {
		LEFT_BUTTON = 1,
		CENTER_BUTTON = 2,
		RIGHT_BUTTON = 3,
		BACK_BUTTON = 8,
		FORWARD_BUTTON = 9,
		WheelDown =  4,
		WheelUp  =  5,
		WheelLeft =  6,
		WheelRight = 7,
	};
	typedef unsigned int MMMouseButton;
#elif defined(IS_WINDOWS)
	enum _MMMouseButton {
		LEFT_BUTTON = 1,
		CENTER_BUTTON = 2,
		RIGHT_BUTTON = 3,
		BACK_BUTTON = 8,
		FORWARD_BUTTON = 9,
		WheelDown =  4,
		WheelUp  =  5,
		WheelLeft =  6,
		WheelRight = 7,
	};
	typedef unsigned int MMMouseButton;
#else
	#error "No mouse button constants set for platform"
#endif

#endif /* MOUSE_H */
