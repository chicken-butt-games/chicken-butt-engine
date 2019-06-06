cmake_minimum_required(VERSION 3.14)
project(NotAVegetable VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

include_directories(vendor/spdlog/include)

add_library(
        NotAVegetable
        SHARED
        src/NotAVegetable/Application.cpp
        src/NotAVegetable/Log.cpp
)

