cmake_minimum_required(VERSION 3.14)
project(NotAVegetable VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

add_compile_definitions(
        NAV_DEBUG
)


include_directories(
        vendor/spdlog/include
        src
        vendor/GLFW/include
        vendor/GLAD/include
)
add_library(
        NotAVegetable
        SHARED
        src/NotAVegetable/Application.cpp
        src/NotAVegetable/Log.cpp
        src/Platform/MacOS/MacOSWindow.cpp
        src/NotAVegetable/Layer.cpp
        src/NotAVegetable/LayerStack.cpp
        src/NotAVegetable/ImGui/ImGuiLayer.cpp
        src/Platform/OpenGL/ImGuiOpenGLRenderer.cpp
)

add_subdirectory(vendor/GLFW)
add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/GLAD)
add_subdirectory(vendor/imgui)

target_link_libraries(
        NotAVegetable
        glfw
        spdlog
        glad
        imgui
)

set_source_files_properties(
        src/NotAVegetable/navpch.cpp
        PROPERTIES
        COMPILE_FLAGS "-include src/NotAVegetable/navpch.h"
)

