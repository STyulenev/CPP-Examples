cmake_minimum_required(VERSION 3.16)

project(Attorney-Client-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE
    main.cpp

    AbstractBase.h

    ConcreteClass.h
    ConcreteClass.cpp

    Attorney.h
    Attorney.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})
