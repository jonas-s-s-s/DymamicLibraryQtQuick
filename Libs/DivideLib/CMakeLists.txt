cmake_minimum_required(VERSION 3.16)
project(DivideLib VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)
qt_standard_project_setup(REQUIRES 6.5)

include_directories(../../LibApi)

add_library(DivideLib SHARED
        ../../LibApi/ExampleApi.h
        DivideLib.h
        DivideLib.cpp
)

target_link_libraries(DivideLib
    PRIVATE Qt6::Quick
)
