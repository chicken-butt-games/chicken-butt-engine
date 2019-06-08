cmake_minimum_required(VERSION 3.14)
project(NotAVegetable VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        vendor/spdlog/include
        src
        vendor/GLFW/include
)
add_library(
        NotAVegetable
        SHARED
        src/NotAVegetable/Application.cpp
        src/NotAVegetable/Log.cpp
        src/Platform/MacOS/MacOSWindow.cpp
)

add_subdirectory(vendor/GLFW)

target_link_libraries(
        NotAVegetable
        glfw
)

set_source_files_properties(
        src/NotAVegetable/navpch.cpp
        PROPERTIES
        COMPILE_FLAGS "-include src/NotAVegetable/navpch.h"
)

