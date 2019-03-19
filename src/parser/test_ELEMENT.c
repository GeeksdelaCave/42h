#include "test.h"

void test_ELEMENT()
{
  int size = 4;
  char *str[] =
    {
      "WORD",
      "12        <      WORD",
      "vfdbfdbd<word",
      "545445454545454 < dgnfjfjnfn",
      "rvioejjearvijervjzerjvejrvjervjevjejvraajievjirzavjizjvi45454545454/////",
      "svslkjvnsjnvdjnsdvnsjdvnsdnvjsndjvnsjdvnjmlsDVNSDklvmSKVJv",
    };
  for (int i = 0; i < size; i++)
    {
      if (i % 2)
	{
      struct parser_s *p = parser_new_from_string(str[i]);
      assert(read_element(p) == 1);
	}
      else
	{
	  struct parser_s *p = parser_new_from_string(str[i]);
	  assert(read_element(p) == 1);
	}
    }
}
