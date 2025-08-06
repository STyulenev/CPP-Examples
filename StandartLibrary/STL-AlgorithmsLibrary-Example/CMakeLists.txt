cmake_minimum_required(VERSION 3.5)

project(STL-AlgorithmsLibrary-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
    main.cpp

    Example1.h
    Example2.h
    Example3.h
    Example4.h
    Example5.h
    Example6.h

    Other.h
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
