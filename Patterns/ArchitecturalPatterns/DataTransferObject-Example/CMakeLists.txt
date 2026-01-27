cmake_minimum_required(VERSION 3.5)

project(DataTransferObject-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE
    main.cpp

    DTO.h
    DTO.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})
