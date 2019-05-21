cmake_minimum_required(VERSION 3.9)
project(42sh)

# enable_testing()

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-I -Wall -Werror -Wextra -std=c99 -pedantic")
set(CMAKE_CTEST_COMMAND "${CMAKE_CTEST_COMMAND} -V ")

set(TESTS_DIR_IN  "${CMAKE_CURRENT_SOURCE_DIR}/tests/")
set(TESTS_DIR_OUT "${CMAKE_CURRENT_BINARY_DIR}/tests/")


# Copy tests
# TU
configure_file(${TESTS_DIR_IN}/tests_unit.py ${TESTS_DIR_OUT}/tests_unit.py COPYONLY)
# TA
configure_file(${TESTS_DIR_IN}/tests_yaml.yml ${TESTS_DIR_OUT}/tests_yaml.yml COPYONLY)
configure_file(${TESTS_DIR_IN}/tests_yaml.py  ${TESTS_DIR_OUT}/tests_yaml.py  COPYONLY)

FILE(GLOB MyCSources src/parser/*.c)
FILE(GLOB MyCSourcesast src/ast/*.c)
FILE(GLOB MyHeaderParser src/parser/*.h)
FILE(GLOB MyHeaderAst src/ast/*.h)
FILE(GLOB Main src/*.c)
add_executable(42sh
                ${MyHeaderParser}
                ${MyHeaderAst}
                ${MyCSources}
                ${MyCSourcesast}
				${Main}
               )
