cmake_minimum_required(VERSION 3.5)

project(Decorator-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE
    main.cpp

    AbstractComponent.h
    ConcreteComponent.h
    ConcreteComponent.cpp

    Decorator.h
    Decorator.cpp
    ConcreteDecoratorA.h
    ConcreteDecoratorA.cpp
    ConcreteDecoratorB.h
    ConcreteDecoratorB.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})
