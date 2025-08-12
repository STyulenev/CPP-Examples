cmake_minimum_required(VERSION 3.5)

project(STL-RangesLibrary-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
    main.cpp

    Example1.h

    Others.h
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
