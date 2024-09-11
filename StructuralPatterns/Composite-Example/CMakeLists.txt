cmake_minimum_required(VERSION 3.5)

project(Composite-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE
    main.cpp

    Component.h
    Component.cpp

    Leaf.h
    Leaf.cpp

    Composite.h
    Composite.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})
