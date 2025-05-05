cmake_minimum_required(VERSION 3.5)

project(MockObject-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE
    main.cpp

    IService.h
    Services.h
    Client.h
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})
