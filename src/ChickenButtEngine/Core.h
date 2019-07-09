//
// Created by Muhamed Hassan on 2019-06-05.
//

#pragma once


#ifdef CBE_DEBUG
#define CBE_ENABLE_ASSERTS
#endif

#ifdef CBE_ENABLE_ASSERTS
#define CBE_ASSERT(x, ...) { if(!(x)) { CBE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __builtin_trap(); } }
#define CBE_CORE_ASSERT(x, ...) { if(!(x)) { CBE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __builtin_trap(); } }
#else
#define CBE_ASSERT(x, ...)
#define CBE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define CBE_BIND_EVENT_FN(fn)std::bind(&fn, this, std::placeholders::_1)