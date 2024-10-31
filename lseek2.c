#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
  int in, out;
  char c;
  in = open("file2.in",O_RDONLY);
  out = open("file2.out",O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
  lseek(in,15,SEEK_SET);//move 15 times

  read(in,&c,1);
  write(out,&c,1);//h
  read(in,&c,1);
  write(out,&c,1);//e
  read(in,&c,1);
  write(out,&c,1);//l
  
  lseek(in,-5,SEEK_CUR);
  read(in,&c,1);
  write(out,&c,1);//l
  lseek(in,-2,SEEK_CUR);
  read(in,&c,1);
  write(out,&c,1);//o

  lseek(in,5,SEEK_CUR);
  read(in,&c,1);
  write(out,&c,1);//w
  lseek(in,1,SEEK_CUR);
  read(in,&c,1);
  write(out,&c,1);//o
  read(in,&c,1);
  write(out,&c,1);//r

  lseek(in,-5,SEEK_CUR);
  read(in,&c,1);
  write(out,&c,1);//l
  lseek(in,1,SEEK_CUR);
  read(in,&c,1);
  write(out,&c,1);//d
  return 0;
}