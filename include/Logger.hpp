/**
 * Copyright 2023 the JayCeS authors. All rights reserved.
 *
 * MIT license.
 */

#pragma once

#include <spdlog/spdlog.h>

namespace jayces
{
/**
 * @class Logger
 * @brief Class description...
 */
class Logger
{
private:
    /* Variables */
    static std::shared_ptr<spdlog::logger> s_Logger;

public:
    static void Init();

    inline static std::shared_ptr<spdlog::logger>& GetLogger()
    {
        return s_Logger;
    }

    /* Operators */

    /* Setter & Getter */
};
} // namespace jayces

#define JCS_TRACE(...) ::jayces::Logger::GetLogger()->trace(__VA_ARGS__)
#define JCS_INFO(...) ::jayces::Logger::GetLogger()->info(__VA_ARGS__)
#define JCS_WARN(...) ::jayces::Logger::GetLogger()->warn(__VA_ARGS__)
#define JCS_ERROR(...) ::jayces::Logger::GetLogger()->error(__VA_ARGS__)
#define JCS_FATAL(...) ::jayces::Logger::GetLogger()->fatal(__VA_ARGS__)
