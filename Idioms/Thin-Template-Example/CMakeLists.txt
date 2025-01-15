cmake_minimum_required(VERSION 3.5)

project(Thin-Template-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
    main.cpp

    SomeArray.h
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
