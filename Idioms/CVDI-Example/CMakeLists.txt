cmake_minimum_required(VERSION 3.5)

project(CVDI-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE
    main.cpp

    AbstractBase.h
    AbstractBase.cpp

    ConcreteClass.h
    ConcreteClass.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})
