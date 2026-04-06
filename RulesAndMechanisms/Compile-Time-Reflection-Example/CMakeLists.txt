cmake_minimum_required(VERSION 3.5)

project(Compile-Time-Reflection-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
    Example1.h

    main.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
