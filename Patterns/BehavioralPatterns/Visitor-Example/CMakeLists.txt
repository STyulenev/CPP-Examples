cmake_minimum_required(VERSION 3.5)

project(Visitor-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE
    main.cpp

    ComponentInterface.h
    ConcreteComponentA.h
    ConcreteComponentA.cpp
    ConcreteComponentB.h
    ConcreteComponentB.cpp

    VisitorInterface.h
    ConcreteVisitor1.h
    ConcreteVisitor1.cpp
    ConcreteVisitor2.h
    ConcreteVisitor2.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})
