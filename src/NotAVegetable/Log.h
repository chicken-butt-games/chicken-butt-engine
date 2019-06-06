//
// Created by Muhamed Hassan on 2019-06-06.
//

#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace NotAVegetable {
    class Log {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {return s_CoreLogger;}
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {return s_ClientLogger;}

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };

}
// Core log macros
#define NAV_CORE_TRACE(...) ::NotAVegetable::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NAV_CORE_INFO(...) ::NotAVegetable::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NAV_CORE_WARN(...) ::NotAVegetable::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NAV_CORE_ERROR(...) ::NotAVegetable::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NAV_CORE_FATAL(...) ::NotAVegetable::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define NAV_TRACE(...) ::NotAVegetable::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NAV_INFO(...) ::NotAVegetable::Log::GetClientLogger()->info(__VA_ARGS__)
#define NAV_WARN(...) ::NotAVegetable::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NAV_ERROR(...) ::NotAVegetable::Log::GetClientLogger()->error(__VA_ARGS__)
#define NAV_FATAL(...) ::NotAVegetable::Log::GetClientLogger()->fatal(__VA_ARGS__)
