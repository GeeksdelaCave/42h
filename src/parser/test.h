#ifndef TEST_H
#define TEST_H
#include <assert.h>
#include <unistd.h>
#include "ast.h"
void test_WORD();
void test_PREFIX();
void test_ELEMENT();
void test_REDIRECTION();
void test_SIMPLECOMMAND();
void test_COMMAND();
void test_REDIRECTION();
void test_PIPELINE();
void test_ANDOR();
#endif
