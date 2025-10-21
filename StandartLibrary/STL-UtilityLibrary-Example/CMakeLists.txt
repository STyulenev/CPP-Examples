cmake_minimum_required(VERSION 3.5)

project(STL-UtilityLibrary-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
    main.cpp

    Example1.h # General-purpose utilities

    # Bitset
    # Bit manipulation (since C++20)
    Example4.h # Function objects (since C++11)
    # Hash support (since C++11)
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
