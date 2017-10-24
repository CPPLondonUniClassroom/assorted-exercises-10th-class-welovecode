cmake_minimum_required(VERSION 3.8)
project(exercise2)

set(CMAKE_CXX_STANDARD 14)

add_library(exercise2 exercise2.cpp)

add_executable(test_shift_char
    test/test_shift_char.cpp
    test/catch_main.cpp)
target_link_libraries(test_shift_char exercise2)

add_executable(test_rot13
    test/test_rot13.cpp
    test/catch_main.cpp)
target_link_libraries(test_rot13 exercise2)

add_executable(test_encode
    test/test_encode.cpp
    test/catch_main.cpp)
target_link_libraries(test_encode exercise2)

add_executable(test_decode
    test/test_decode.cpp
    test/catch_main.cpp)
target_link_libraries(test_decode exercise2)