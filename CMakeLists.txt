cmake_minimum_required(VERSION 3.5.2)
project(42sh)

# enable_testing()

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



add_executable(42sh

  src/dot/generate_dot_file_ast.c
  src/dot/generate_dot_file_ast.c

  src/ast/ast.c
  src/ast/ast.h
  src/ast/ast_andor.c
  src/ast/ast_andor.h
  src/ast/ast_command.h
  src/ast/ast_command.c
  src/ast/ast_compound_list.c
  src/ast/ast_compound_list.h
  src/ast/ast_dogroup.h
  src/ast/ast_dogroup.c
  src/ast/ast_pipeline.c
  src/ast/ast_pipeline.h
  src/ast/ast_else.h
  src/ast/ast_else.c
  src/ast/ast_for.h
  src/ast/ast_for.c
  src/ast/ast_if.h
  src/ast/ast_if.c
  src/ast/ast_list.h
  src/ast/ast_list.c
  src/ast/ast_pipeline.h
  src/ast/ast_pipeline.c
  src/ast/ast_simple_command.c
  src/ast/ast_simple_command.h
  src/ast/ast_until.h
  src/ast/ast_until.c
  src/ast/ast_while.h
  src/ast/ast_while.c
  src/ast/error.h

  #src/parser/ast.h
  src/parser/commands.h
  src/parser/grammar.h
  src/parser/parser.h
  src/parser/parser_capture.h
  src/parser/parser_capture.c
  src/parser/parser_init.c
  src/parser/parser_read.c
  src/parser/parser_read_tools.c
  src/parser/parser_read_tools.h
  src/parser/read_and_or.c
  src/parser/read_and_or.h
  src/parser/read_case.c
  src/parser/read_case_clause.c
  src/parser/read_case_item.c
  src/parser/read_command.c
  src/parser/read_command.h
  src/parser/read_compound_list.c
  src/parser/read_do_group.c
  src/parser/read_element.c
  src/parser/read_element.h
  src/parser/read_else.c
  src/parser/read_for.c
  src/parser/read_funcdec.c
  src/parser/read_funcdec.h
  src/parser/read_if.c
  src/parser/read_input.c
  src/parser/read_input.h
  src/parser/read_list.c
  src/parser/read_list.h
  src/parser/read_pipeline.c
  src/parser/read_pipeline.h
  src/parser/read_prefix.c
  src/parser/read_prefix.h
  src/parser/read_redirection.c
  src/parser/read_redirection.h
  src/parser/read_shell_command.c
  src/parser/read_shell_command.h
  src/parser/read_simple_command.c
  src/parser/read_simple_command.h
  src/parser/read_until.c
  src/parser/read_while.c
  src/parser/read_word.c
  src/parser/repetition_tools.h
  src/parser/rules.h
  src/parser/parser_option.h
  src/parser/parser_option.c

  src/parser/test/test.c
  src/parser/test/test.h
  src/parser/test/test_ANDOR.c
  src/parser/test/test_ASSIGN.c
  src/parser/test/test_COMMAND.c
  src/parser/test/test_COMPOUND.c
  src/parser/test/test_DOGROUP.c
  src/parser/test/test_ELEMENT.c
  src/parser/test/test_FOR.c
  src/parser/test/test_IF.c
  src/parser/test/test_INPUT.c
  src/parser/test/test_LIST.c
  src/parser/test/test_PIPELINE.c
  src/parser/test/test_PREFIX.c
  src/parser/test/test_REDIRECTION.c
  src/parser/test/test_SIMPLECOMMAND.c
  src/parser/test/test_UNTIL.c
  src/parser/test/test_WHILE.c
  src/parser/test/test_WORD.c
  src/utils/main.c

  )

add_custom_target(check
  COMMAND python3 tests/tests_unit.py
  COMMAND python3 tests/tests_yaml.py
  COMMAND python3 tests/tests_while.yml
  COMMAND python3 tests/tests_and_or.yml
  COMMAND python3 tests/tests_assign.yml
  COMMAND python3 tests/tests_ast.yml
  COMMAND python3 tests/tests_case.yml
  COMMAND python3 tests/tests_compound.yml
  COMMAND python3 tests/tests_dogroup.yml
  COMMAND python3 tests/tests_element.yml
  )
