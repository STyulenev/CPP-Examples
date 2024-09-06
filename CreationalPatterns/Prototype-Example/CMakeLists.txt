cmake_minimum_required(VERSION 3.5)

project(Prototype-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE
    main.cpp

    AbstractPrototype.h
    AbstractPrototype.cpp

    ConcretePrototype1.h
    ConcretePrototype1.cpp
    ConcretePrototype2.h
    ConcretePrototype2.cpp

    PrototypeFactory.h
    PrototypeFactory.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})
