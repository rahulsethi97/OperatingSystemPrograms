#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>

int pid;

void fun(int x)
{ 
 if(x==SIGCONT)
 {
  printf("\nProcess cannot be continued\n");
  exit(1);
 }
 if(x==SIGTSTP&&pid)
 {
  printf("\nProcess cannot be stopped\n");
  sleep(30);
 }
 if(x==SIGTERM&&pid)
 {
  printf("\nProcess cannot be terminated\n");
  sleep(30);
 }
 if(x==SIGINT&&pid)
 {
  printf("\nProcess cannot be aborted\n");
  sleep(30);
 }
 if(x==SIGCHLD)
 {
 int s,i;
 i=wait(&s);
 printf("\nChild-process(%d) of parent-process(%d) destroyed with exit-status(%d).\n",i,getpid(),WEXITSTATUS(s));
 }
}

int main(int argc,char* argv[])
{ 
 signal(SIGTERM,fun);
 signal(SIGCONT,fun);
 int n=atoi(argv[1]);
 int m=atoi(argv[2]);
 signal(SIGINT,fun);
 signal(SIGCHLD,fun);
 signal(SIGTSTP,fun);
 
 
 pid=fork();

 
 if(pid==0)
 { 
 printf("\nI am a child-process(%d) of parent-process(%d).\n",getpid(),getppid());
 
 
 for(;n<=m;n++)
  { 
    printf("%d ",n);
    fflush(stdout);
    sleep(1);
  }
 
 }

 else if(pid>0)
 {
 printf("\nI am a parent-process(%d) of child-process(%d).\n",getpid(),pid);
 sleep(m-n+2);
 }

 else
 {
 printf("\nError\n");
 }

 if(!pid)
  return 5;
 else
  return 0;
 
}
