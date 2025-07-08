cmake_minimum_required(VERSION 3.5)

project(Preprocessor-Directives-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE
    main.cpp

    Definations.h

    Example1.h
    Example1A.cpp
    Example1B.cpp

    Example2.h
    Example3.h
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})
