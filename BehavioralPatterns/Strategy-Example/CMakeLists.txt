cmake_minimum_required(VERSION 3.5)

project(Strategy-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE
    main.cpp

    StrategyInterface.h
    ConcreteStrategyA.h
    ConcreteStrategyA.cpp
    ConcreteStrategyB.h
    ConcreteStrategyB.cpp

    Context.h
    Context.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})
