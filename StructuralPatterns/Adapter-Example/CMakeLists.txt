cmake_minimum_required(VERSION 3.5)

project(Adapter-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE
    main.cpp

    Target.h
    Target.cpp

    Adaptee.h
    Adaptee.cpp

    Adapter.h
    Adapter.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})
