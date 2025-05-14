cmake_minimum_required(VERSION 3.5)

project(Extern-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE
    main.cpp

    Example0.h

    Example1.h
    Example1.cpp

    Example2.h
    Example2.cpp

    Example3.h
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})
