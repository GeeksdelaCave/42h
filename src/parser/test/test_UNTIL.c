/**
 ** \file test_UNTIL.c
 */
#include "test.h"
/**
 ** \brief test Unit for until grammar
 */
void test_UNTIL()
{
    char *str[] =
    {
      "",
      "until ! a=15 b=569 15 < kergjkergerklg 16 < jsdhvjsdfhvs | uhhvhbrb=15",
    };
    struct parser_s *p1= parser_new_from_string(str[1]);
    read_until(p1);
    printf("%s \n", p1->input);
}
