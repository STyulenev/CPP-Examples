cmake_minimum_required(VERSION 3.5)

project(TwoLinkedList-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
    main.cpp
    TwoLinkedList.h
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
