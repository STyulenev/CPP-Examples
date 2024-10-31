cmake_minimum_required(VERSION 3.5)

project(CTAD-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17) # 11 14 17 20
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
    main.cpp

    SomeClass.h
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
