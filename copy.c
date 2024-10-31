#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void) {
  char buf[1024]; //buffer
  int nread;
  int in = open("file.in",O_RDONLY);
  int out = open("file.out",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);

  //while the return from read is not 0
  while((nread = read(in,buf,sizeof(buf)))>0)     write(out,buf,nread);
//when we write to the file, the last parameter (no. of bytes) is the number of bytes read from the file. not from the buffer.
  
  return 0;
}