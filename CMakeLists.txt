cmake_minimum_required(VERSION 3.9)
project(42sh)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Werror -Wextra -std=c99 -pedantic")

add_executable(42sh src/core/main.c
               src/parser/parser.c)
