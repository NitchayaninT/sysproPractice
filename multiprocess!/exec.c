#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
//can transform both child&parent into another program
int main()
{
  pid_t pid;
  pid = fork();

  switch(pid){
    case -1:
      printf("Fork failed\n");
      _exit(1);
    case 0://child
      execl("./something","something","hello","world","yey",NULL);
      break;
    default:
      execl("./something","something","i","dont love","syspro",NULL);
    break;
  }
  
}