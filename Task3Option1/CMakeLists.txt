cmake_minimum_required(VERSION 3.15)
project(WordCount)

find_package(Catch2 REQUIRED)

add_executable(wordCount 
    WordCount.cpp 
    main.cpp
)

add_executable(tests 
    WordCount.cpp 
    tests.cpp
)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)