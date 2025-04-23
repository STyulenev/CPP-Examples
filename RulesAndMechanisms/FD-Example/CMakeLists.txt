cmake_minimum_required(VERSION 3.5)

project(FD-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
    main.cpp

    SomeClass1.h
    SomeClass1.cpp

    SomeClass2.h
    SomeClass2.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
