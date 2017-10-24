cmake_minimum_required(VERSION 3.8)
project(exercise3)

set(CMAKE_CXX_STANDARD 14)

add_library(exercise3 exercise3.cpp)

add_executable(test_split
    test/test_split.cpp
    test/catch_main.cpp)
target_link_libraries(test_split exercise3)

add_executable(test_quoted_split
    test/test_quoted_split.cpp
    test/catch_main.cpp)
target_link_libraries(test_quoted_split exercise3)

add_executable(test_parse_csv
    test/test_parse_csv.cpp
    test/catch_main.cpp)
target_link_libraries(test_parse_csv exercise3)
