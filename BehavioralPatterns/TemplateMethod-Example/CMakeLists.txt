cmake_minimum_required(VERSION 3.5)

project(TemplateMethod-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE
    main.cpp

    AbstractClass.h
    AbstractClass.cpp
    ConcreteClass1.h
    ConcreteClass1.cpp
    ConcreteClass2.h
    ConcreteClass2.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})
