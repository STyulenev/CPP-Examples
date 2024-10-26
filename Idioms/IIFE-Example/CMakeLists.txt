cmake_minimum_required(VERSION 3.5)

project(IIFE-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE
    main.cpp

    SomeClass.h
    SomeClass.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})
