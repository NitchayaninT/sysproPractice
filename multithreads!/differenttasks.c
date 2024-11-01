#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SIZE 1024

struct threadARGS {
  int count;
  char *message;
};
void *task(void *arg) {
  // type cast to struct pointer first!!
  struct threadARGS *args = (struct threadARGS *)arg;
  for (int i = 0; i < args->count; i++) {
    printf("%s ", args->message);
  }

  return (void *)args;
}

int main() {
  pthread_t thread[3];
  struct threadARGS thread_args[3];

  thread_args[0].count = 100;
  thread_args[0].message = "I";
  thread_args[1].count = 200;
  thread_args[1].message = "Love";
  thread_args[2].count = 100;
  thread_args[2].message = "You!!";
  for (int i = 0; i < 3; i++) {
    pthread_create(&thread[i], NULL, &task, &thread_args[i]);
    //usleep(100000);
  }
  for (int i = 0; i < 3; i++) {
    pthread_join(thread[i], (void*)&thread_args[i]);
  }
}