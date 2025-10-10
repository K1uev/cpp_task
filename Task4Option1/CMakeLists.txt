cmake_minimum_required(VERSION 3.15)
project(CrossSet)

find_package(Catch2 REQUIRED)

add_executable(crossSet 
    crossSet.cpp 
    main.cpp
)

add_executable(tests 
    crossSet.cpp 
    tests.cpp
)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)