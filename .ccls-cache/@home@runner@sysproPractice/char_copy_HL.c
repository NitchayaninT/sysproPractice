#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
  char c;//buffer
  FILE* in;
  FILE* out; //file pointer
  in = fopen("fileHL.in","r");
  out = fopen("fileHL.out","w");//for writing, file doesnt have to exist to write
  while((c=fgetc(in))!=EOF) fputc(c,out);

}