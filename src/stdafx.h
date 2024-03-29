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

#include <cstdio>
#include <tchar.h>

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <optional>

#include <imgui.h>
#include <IconsFontAwesome5.h>
#include "imgui/imgui_custom.h"
#include <addons/imguivariouscontrols/imguivariouscontrols.h>

#include <coveo/linq.h>
#include <enum.h>

#include "logger/ILogger.h"

#include "Utilities.h"
#include "storage/IStorage.h"
#include "storage/JsonStorage.h"

#include "ui/IView.h"
#include "ui/ItestView.h"
#include "ui/fonts/Fonts.h"
#include "ui/colors/Colors.h"

#include "query/IQueryHandler.h"
#include "query/QueryDispatcher.h"
#include "command/ICommandHandler.h"
#include "command/CommandDispatcher.h"

using namespace coveo::linq;