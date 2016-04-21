#include<stdio.h>
#include<unistd.h>

int main(int argc,char* argv[])
{

 int pid;
 pid=fork();

 if(pid==0)
 {
  printf("\nI am a child-process(%d) of %s (%d).\n",getpid(),argv[0],getppid());
  sleep(50);
 }
 else if(pid>0)
 {
  printf("\nI am a parent-process(%d) of child process(%d).\n",getpid(),pid);
 }
 else
 {
 printf("\nError\n");
 }

}
