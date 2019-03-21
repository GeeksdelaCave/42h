cmake_minimum_required(VERSION 3.5)
project(42sh)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Werror -Wextra -std=c99 -pedantic")
set(CMAKE_CTEST_COMMAND "${CMAKE_CTEST_COMMAND} -V ")

set(TESTS_DIR_IN  "${CMAKE_CURRENT_SOURCE_DIR}/tests/")
set(TESTS_DIR_OUT "${CMAKE_CURRENT_BINARY_DIR}/tests/")


# Copy tests
# TU
configure_file(${TESTS_DIR_IN}/tests_unit.py ${TESTS_DIR_OUT}/tests_unit.py COPYONLY)
# TA
configure_file(${TESTS_DIR_IN}/tests_yaml.yml ${TESTS_DIR_OUT}/tests_yaml.yml COPYONLY)
configure_file(${TESTS_DIR_IN}/tests_yaml.py  ${TESTS_DIR_OUT}/tests_yaml.py  COPYONLY)

# Copy doc
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/doc/42sh.1 ${CMAKE_CURRENT_BINARY_DIR}/doc/42sh.1)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile ${CMAKE_CURRENT_BINARY_DIR}/doc/Doxyfile)


# Compile the project
add_executable(42sh
            src/core/main.c
            #src/parser/parser.c
            src/utils/string.h
            src/utils/string.c
        )

# Run test suite
add_custom_target(check
                  COMMAND python3 tests/tests_unit.py
                  COMMAND python3 tests/tests_yaml.py)

# Run documentation generation
add_custom_target(doc
                  COMMAND doxygen doc/Doxyfile)
