#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
//child dies fast but parent dont call wait
int main()
{
  pid_t pid;
  int stat_val;
  pid = fork();

  switch(pid){
    case -1:
      printf("Fork failed\n");
      _exit(1);
    case 0: //child
      break;
    default:
      while(1){
        printf("Parent stuck in infinite loop\n");
      }
      break;
  }

  if(pid > 0){
    pid = wait(&stat_val);
    printf("Child PID : %d\n",pid);
    printf("Child exited with status : %d\n",WEXITSTATUS(stat_val));
  }

}