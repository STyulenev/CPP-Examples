cmake_minimum_required(VERSION 3.5)

project(Virtual-Constructor-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE
    main.cpp

    AbstractTarget.h

    ConcreteTarget.h
    ConcreteTarget.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})
