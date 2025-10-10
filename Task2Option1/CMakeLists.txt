cmake_minimum_required(VERSION 3.15)
project(TrimBlanks)

find_package(Catch2 REQUIRED)

add_executable(trimBlanks 
    trimBlanks.cpp 
    main.cpp
)

add_executable(tests 
    trimBlanks.cpp 
    tests.cpp
)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)