cmake_minimum_required(VERSION 3.9)
project(42sh)

enable_testing()

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Werror -Wextra -std=c99 -pedantic")
set(CMAKE_CTEST_COMMAND "${CMAKE_CTEST_COMMAND} -V ")

configure_file(tests/tests_yaml.yml ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)



add_executable(42sh src/core/main.c)

add_test(NAME "unit_tests"
        COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/tests/tests.py)
add_test(NAME "commands_tests"
        COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/tests/tests_yaml.py)
