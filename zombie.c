#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc,char* argv[])
{

int pid;
pid=fork();

if(pid==0)
{
 printf("\nI am a child-process(%d) of %s (%d) and i am terminating.\n",getpid(),argv[0],getppid());
 sleep(50);
}
else if(pid>0)
{
 sleep(20);
 int s;
 int i=wait(&s);
 sleep(50);
 printf("\nI am a parent-process(%d) of child process(%d) of Status:%d.\n",getpid(),i,WEXITSTATUS(s));
}
else
{
printf("\nError\n");
}


}
