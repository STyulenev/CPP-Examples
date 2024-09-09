cmake_minimum_required(VERSION 3.5)

project(RAII-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE
    main.cpp

    SomeClass.h
    SomeClass.cpp

    RAIIWrapper.h
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})
