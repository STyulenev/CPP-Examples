cmake_minimum_required(VERSION 3.5)

project(SpinLock-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
    main.cpp

    SpinLock.h
    SpinLock.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
