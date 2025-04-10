cmake_minimum_required(VERSION 3.5)

project(STL-ContainersLibrary-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
    Example1.h
    Example2.h
    Example3.h
    Example4.h

    # Test class
    SomeClass.h
    SomeClass.cpp

    main.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
