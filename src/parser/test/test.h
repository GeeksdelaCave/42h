#ifndef TEST_H
#define TEST_H
#include <assert.h>
#include <unistd.h>
#include "../grammar.h"
#include "test_command.h"
void test_WORD();
void test_PREFIX();
void test_ELEMENT();
void test_REDIRECTION();
void test_REDIRECTION();
void test_PIPELINE();
void test_ANDOR();
void test_LIST();
void test_COMPOUND();
void test_DOGROUP();
#endif
