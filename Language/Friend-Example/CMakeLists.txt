cmake_minimum_required(VERSION 3.5)

project(Friend-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
    main.cpp

    Examples.h
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
