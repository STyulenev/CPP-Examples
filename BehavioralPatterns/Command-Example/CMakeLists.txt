cmake_minimum_required(VERSION 3.5)

project(Command-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE
    main.cpp

    CommandInterface.h
    SimpleCommand.h
    SimpleCommand.cpp
    ComplexCommand.h
    ComplexCommand.cpp

    Receiver.h
    Receiver.cpp

    Invoker.h
    Invoker.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})
