cmake_minimum_required(VERSION 3.5)

project(Perfect-Forwarding-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
    main.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
