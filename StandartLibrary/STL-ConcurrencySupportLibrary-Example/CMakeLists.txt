cmake_minimum_required(VERSION 3.5)

project(STL-ConcurrencySupportLibrary-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
    main.cpp

    Example1.h # Threads
    Example5.h # Mutual exclusion
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
