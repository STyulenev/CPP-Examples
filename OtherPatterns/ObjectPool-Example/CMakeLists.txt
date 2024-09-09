cmake_minimum_required(VERSION 3.5)

project(ObjectPool-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE
    main.cpp

    Resource.h Resource.cpp
    ObjectPool.h ObjectPool.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})
