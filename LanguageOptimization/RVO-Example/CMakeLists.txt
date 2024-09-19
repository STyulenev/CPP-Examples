cmake_minimum_required(VERSION 3.5)

project(RVO-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Флаг для включения/отключения оптимизации RVO
#add_compile_options(
#    -fno-elide-constructors
#)

set(PROJECT_SOURCE
    main.cpp

    SomeClass.h
    SomeClass.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})
