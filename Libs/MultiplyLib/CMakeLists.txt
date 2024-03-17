cmake_minimum_required(VERSION 3.16)
project(MultiplyLib VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick Core)

qt_standard_project_setup(REQUIRES 6.5)

include_directories(../../LibApi)

add_library(MultiplyLib SHARED
        ../../LibApi/ExampleApi.h
        MultiplyLib.h
        MultiplyLib.cpp
)

qt_add_resources(MultiplyLib "MultiplyLib"
    PREFIX "/MultiplyLib"
    FILES
        resources/picture.svg
        resources/panel.qml
)


target_link_libraries(MultiplyLib
    PRIVATE Qt6::Quick
)
