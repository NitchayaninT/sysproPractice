#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[ ])
{
  printf("There are %d arguments passed\n",argc);

  for(int i=0;i<argc;i++)
    {
      printf("argv[%d] = %s\n",i,argv[i]);
    }

  return 0;
}