cmake_minimum_required(VERSION 3.5)

project(Union-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE
    main.cpp

    Example1.h
    Example2.h
    Example3.h
    Example4.h
    Example5.h
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})
