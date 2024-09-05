cmake_minimum_required(VERSION 3.5)

project(FactoryMethod-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE
    main.cpp

    AbstractProduct.h

    ConcreteProduct1.h
    ConcreteProduct1.cpp

    ConcreteProduct2.h
    ConcreteProduct2.cpp

    AbstractCreator.h
    AbstractCreator.cpp

    ConcreteCreator1.h
    ConcreteCreator1.cpp

    ConcreteCreator2.h
    ConcreteCreator2.cpp

    SimpleFactoryMethod.h
    SimpleFactoryMethod.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})
