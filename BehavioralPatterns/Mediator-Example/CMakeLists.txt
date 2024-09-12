cmake_minimum_required(VERSION 3.5)

project(Mediator-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE
    main.cpp

    MediatorInterface.h

    BaseComponent.h
    BaseComponent.cpp

    Component1.h
    Component1.cpp
    Component2.h
    Component2.cpp

    ConcreteMediator.h
    ConcreteMediator.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})
