cmake_minimum_required(VERSION 3.5)

project(Facade-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE
    main.cpp

    SubSystem1.h
    SubSystem1.cpp
    SubSystem2.h
    SubSystem2.cpp

    Facade.h
    Facade.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})
