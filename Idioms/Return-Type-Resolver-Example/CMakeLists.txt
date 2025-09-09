cmake_minimum_required(VERSION 3.5)

project(Return-Type-Resolver-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Return-Type-Resolver-Example main.cpp)

include(GNUInstallDirs)
install(TARGETS Return-Type-Resolver-Example
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
