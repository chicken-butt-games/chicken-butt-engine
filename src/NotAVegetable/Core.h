//
// Created by Muhamed Hassan on 2019-06-05.
//

#pragma once

#define NAV_DEBUG // TODO: define this in the ide

#ifdef NAV_DEBUG
#define NAV_ENABLE_ASSERTS
#endif

#ifdef NAV_ENABLE_ASSERTS
#define NAV_ASSERT(x, ...) { if(!(x)) { NAV_ERROR("Assertion Failed: {0}", __VA_ARGS__); __builtin_trap(); } }
#define NAV_CORE_ASSERT(x, ...) { if(!(x)) { NAV_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __builtin_trap(); } }
#else
#define NAV_ASSERT(x, ...)
#define NAV_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

