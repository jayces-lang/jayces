/**
 * Copyright 2023 the JayCeS authors. All rights reserved.
 *
 * MIT license.
 */

#include "../include/Logger.hpp"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace jayces
{
std::shared_ptr<spdlog::logger> Logger::s_Logger;

void Logger::Init()
{
    spdlog::set_pattern("%^[%T] %n: %v%$");

    s_Logger = spdlog::stdout_color_mt("JayCeS");
    s_Logger->set_level(spdlog::level::trace);
}
} // namespace jayces