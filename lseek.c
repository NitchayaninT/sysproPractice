#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
  int in, out;
  char c; // char buffer
  in = open("file.in", O_RDONLY);
  out = open("file.out", O_WRONLY);
  lseek(in, 10, SEEK_SET); //move pointer to the right by 10
  // the file pointer automatically advances by the number of bytes read after
  // each read cal
  int counter = 16;
  while (counter > 0) {
    read(in, &c, 1);
    write(out, &c, 1);
    printf("writing to file.out\n");

    // lseek(in,1,SEEK_CUR);
    counter--;
  }
}