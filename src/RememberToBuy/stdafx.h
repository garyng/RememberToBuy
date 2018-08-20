// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

// For Hypodermic
template<class ArgumentType, class ResultType>
struct unary_function
{
	typedef ArgumentType argument_type;
	typedef ResultType result_type;
};

#include <stdio.h>
#include <tchar.h>

#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include <imgui.h>
#include "imgui/imgui_custom.h"
#include <IconsFontAwesome5.h>

#include "logger/ILogger.h"
#include "ui/fonts/Fonts.h"
#include "ui/colors/Colors.h"
#include "Utilities.h"
