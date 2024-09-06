cmake_minimum_required(VERSION 3.5)

project(AbstractFactory-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE
    main.cpp

    AbstractProductA.h
    AbstractProductB.h
    AbstractFactory.h

    ConcreteProductA1.h ConcreteProductA1.cpp
    ConcreteProductA2.h ConcreteProductA2.cpp

    ConcreteProductB1.h ConcreteProductB1.cpp
    ConcreteProductB2.h ConcreteProductB2.cpp

    ConcreteFactory1.h ConcreteFactory1.cpp
    ConcreteFactory2.h ConcreteFactory2.cpp
)

add_executable(${PROJECT_NAME}  ${PROJECT_SOURCE})
