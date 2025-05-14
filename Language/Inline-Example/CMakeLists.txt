cmake_minimum_required(VERSION 3.5)

project(Inline-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE
    main.cpp

    Example1.h
    Example1A.cpp
    Example1B.cpp

)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE}
    Example2.h)
