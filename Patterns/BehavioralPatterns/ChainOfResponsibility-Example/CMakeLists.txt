cmake_minimum_required(VERSION 3.5)

project(ChainOfResponsibility-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE
    main.cpp

    HandlerInterface.h

    AbstractHandler.h
    AbstractHandler.cpp

    Handlers.h
    Handlers.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})
