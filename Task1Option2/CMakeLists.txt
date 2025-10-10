cmake_minimum_required(VERSION 3.15)
project(MultiplyElement)

find_package(Catch2 REQUIRED)

add_executable(multiply_each_element 
    numbers.cpp 
    main.cpp
)

add_executable(tests 
    numbers.cpp 
    tests.cpp
)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)