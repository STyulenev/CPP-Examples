cmake_minimum_required(VERSION 3.5)

project(State-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE
    main.cpp

    Context.h
    Context.cpp

    AbstractState.h
    AbstractState.cpp
    ConcreteStateA.h
    ConcreteStateA.cpp
    ConcreteStateB.h
    ConcreteStateB.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})
