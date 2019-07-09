//
// Created by Muhamed Hassan on 2019-06-06.
//

#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace ChickenButtEngine {
    class Log {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }

        inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };

}
// Core log macros
#define CBE_CORE_TRACE(...) ::ChickenButtEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CBE_CORE_INFO(...) ::ChickenButtEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CBE_CORE_WARN(...) ::ChickenButtEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CBE_CORE_ERROR(...) ::ChickenButtEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CBE_CORE_FATAL(...) ::ChickenButtEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define CBE_TRACE(...) ::ChickenButtEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CBE_INFO(...) ::ChickenButtEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define CBE_WARN(...) ::ChickenButtEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CBE_ERROR(...) ::ChickenButtEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define CBE_FATAL(...) ::ChickenButtEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)
