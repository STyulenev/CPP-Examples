cmake_minimum_required(VERSION 3.5)

project(LockConvoy-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LockConvoy-Example main.cpp)

include(GNUInstallDirs)
install(TARGETS LockConvoy-Example
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
