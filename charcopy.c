#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
  char c;//buffer
  int in = open("file.in",O_RDONLY);
  int out = open("file.out",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
  while((read(in, &c,1))>0) write(out,&c,1);

  
}