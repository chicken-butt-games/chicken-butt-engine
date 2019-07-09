cmake_minimum_required(VERSION 3.14)
project(ChickenButtEngine VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

add_compile_definitions(
        CBE_DEBUG
)

set_source_files_properties(
        src/ChickenButtEngine/cbepch.cpp
        PROPERTIES
        COMPILE_FLAGS "-include src/NotAVegetable/cbepch.h"
)


add_subdirectory(vendor/GLFW)
add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/GLAD)
add_subdirectory(vendor/imgui)
add_subdirectory(vendor/glm)

add_library(
        ChickenButtEngine
        SHARED
        src/ChickenButtEngine/Application.cpp
        src/ChickenButtEngine/Log.cpp
        src/Platform/MacOS/MacOSWindow.cpp
        src/Platform/MacOS/MacOSInput.cpp
        src/ChickenButtEngine/Layer.cpp
        src/ChickenButtEngine/LayerStack.cpp
        src/ChickenButtEngine/ImGui/ImGuiLayer.cpp
        src/cbepch.cpp
        src/ChickenButtEngine/ImGui/ImGuiBuild.cpp
)

target_include_directories(
        ChickenButtEngine
        PUBLIC
        src
)


target_link_libraries(
        ChickenButtEngine
        PUBLIC
        glfw
        spdlog
        glad
        imgui
        glm
)
