cmake_minimum_required(VERSION 3.9)
project(42sh)

# enable_testing()

set(CMAKE_C_STANDARD 99)
#set(CMAKE_C_FLAGS "-Wall -Werror -Wextra -std=c99 -pedantic")
set(CMAKE_CTEST_COMMAND "${CMAKE_CTEST_COMMAND} -V ")

set(TESTS_DIR_IN  "${CMAKE_CURRENT_SOURCE_DIR}/tests/")
set(TESTS_DIR_OUT "${CMAKE_CURRENT_BINARY_DIR}/tests/")


# Copy tests
# TU
configure_file(${TESTS_DIR_IN}/tests_unit.py ${TESTS_DIR_OUT}/tests_unit.py COPYONLY)
# TA
configure_file(${TESTS_DIR_IN}/tests_yaml.yml ${TESTS_DIR_OUT}/tests_yaml.yml COPYONLY)
configure_file(${TESTS_DIR_IN}/tests_yaml.py  ${TESTS_DIR_OUT}/tests_yaml.py  COPYONLY)



add_executable(42sh
        src/core/main.c

        src/ast/ast/ast.h
        src/ast/ast/ast_and.c
        src/ast/ast/ast_case.c
        src/ast/ast/ast_cmd.c
        src/ast/ast/ast_destruct.c
        src/ast/ast/ast_for.c
        src/ast/ast/ast_if.c
        src/ast/ast/ast_or.c
        src/ast/ast/ast_pipeline.c
        src/ast/ast/ast_print.c
        src/ast/ast/ast_red.c
        src/ast/ast/ast_while.c
        src/ast/ast/error.h

        src/utils/string.c
        src/utils/string.h
        )

add_custom_target(check
                  COMMAND python3 tests/tests_unit.py
                  COMMAND python3 tests/tests_yaml.py)