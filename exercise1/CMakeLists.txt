cmake_minimum_required(VERSION 3.8)
project(exercise1)

set(CMAKE_CXX_STANDARD 14)

add_library(exercise1 exercise1.cpp)

add_executable(test_is_even
    test/test_is_even.cpp
    test/catch_main.cpp)
target_link_libraries(test_is_even exercise1)

add_executable(test_count_odd
    test/test_count_odd.cpp
    test/catch_main.cpp)
target_link_libraries(test_count_odd exercise1)

add_executable(test_even_sum
    test/test_even_sum.cpp
    test/catch_main.cpp)
target_link_libraries(test_even_sum exercise1)

add_executable(test_copy_if_divisible_by
    test/test_copy_if_divisible_by.cpp
    test/catch_main.cpp)
target_link_libraries(test_copy_if_divisible_by exercise1)

add_executable(test_largest_div_by_three
    test/test_largest_div_by_three.cpp
    test/catch_main.cpp)
target_link_libraries(test_largest_div_by_three exercise1)

add_executable(test_is_sorted
    test/test_is_sorted.cpp
    test/catch_main.cpp)
target_link_libraries(test_is_sorted exercise1)