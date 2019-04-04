#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include "exec.h"

void redirection (int argc, char* argv[])
{
  for (int i = 1; i <  argc ; i++)
  {
     if ((strcmp(argv[i], ">") == 0) || (strcmp(argv[i], ">>") == 0))
      {
        char *str = argv[i + 1];
          int fd = open(str, O_RDONLY);
          if (fd > 0)
          {  
            dup2(fd, STDOUT_FILENO);
            //printf("moi\n");
          }
          close (fd);
      }
  }
}

int main(int argc, char *argv[])
{
  redirection(argc, argv);
  return 0;
}