cmake_minimum_required(VERSION 3.5)

project(STL-ContainersLibrary-Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
    # ========== Sequence ==========
    #array.cpp
    #vector.cpp
    #forward_list.cpp
    #list.cpp
    #deque.cpp

    # ========== Associative ==========

    #set.cpp
    map.cpp
    #multi_set...
    #multi_map...

    # ========== Unordered associative ==========
    #unordered_set...
    #unordered_map...

    # ========== Adaptors ==========
    #stack...
    #queue...
    #priority_queue...
    #flat_set...
    #flat_multiset...
    #flat_map...
    #flat_multimap...

    # Test class
    SomeClass.h
    SomeClass.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
