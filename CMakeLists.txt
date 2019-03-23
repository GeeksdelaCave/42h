cmake_minimum_required(VERSION 3.9)
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
configure_file(${TESTS_DIR_IN}/tests_list.yml ${TESTS_DIR_OUT}/tests_list.yml COPYONLY)
configure_file(${TESTS_DIR_IN}/tests_and_or.yml ${TESTS_DIR_OUT}/tests_and_or.yml COPYONLY)
configure_file(${TESTS_DIR_IN}/tests_pipeline.yml ${TESTS_DIR_OUT}/tests_pipeline.yml COPYONLY)
configure_file(${TESTS_DIR_IN}/tests_eof.yml ${TESTS_DIR_OUT}/tests_eof.yml COPYONLY)
configure_file(${TESTS_DIR_IN}/tests_assign.yml ${TESTS_DIR_OUT}/tests_assign.yml COPYONLY)
configure_file(${TESTS_DIR_IN}/tests_element.yml ${TESTS_DIR_OUT}/tests_element.yml COPYONLY)
configure_file(${TESTS_DIR_IN}/tests_simple_command.yml ${TESTS_DIR_OUT}/tests_simple_command.yml COPYONLY)
configure_file(${TESTS_DIR_IN}/tests_compound.yml ${TESTS_DIR_OUT}/tests_compound.yml COPYONLY)
configure_file(${TESTS_DIR_IN}/tests_if.yml ${TESTS_DIR_OUT}/tests_if.yml COPYONLY)
configure_file(${TESTS_DIR_IN}/test_while.yml ${TESTS_DIR_OUT}/test_while.yml COPYONLY)
configure_file(${TESTS_DIR_IN}/tests_prefix.yml ${TESTS_DIR_OUT}/tests_prefix.yml COPYONLY)
configure_file(${TESTS_DIR_IN}/tests_word.yml ${TESTS_DIR_OUT}/tests_word.yml COPYONLY)
configure_file(${TESTS_DIR_IN}/tests_if.yml ${TESTS_DIR_OUT}/tests_redirection.yml COPYONLY)
configure_file(${TESTS_DIR_IN}/tests_dogroup.yml ${TESTS_DIR_OUT}/tests_dpgroup.yml COPYONLY)
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
