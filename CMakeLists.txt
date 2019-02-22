cmake_minimum_required(VERSION 3.9)
project(42sh)

enable_testing()

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Werror -Wextra -std=c99 -pedantic")

add_executable(42sh src/core/main.c)

add_test(NAME cmake_version
        COMMAND cmake --version)
add_test(NAME testsuit
        COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/tests/tests.py)
add_test(NAME test2
        COMMAND echo "test")