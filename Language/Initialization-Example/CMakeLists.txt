cmake_minimum_required(VERSION 3.5)

project(Initialization-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20) # 98 / 11 / 14 / 17 / 20 / 23 / 26
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
    main.cpp

    Example1.h
    Example2.h
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
