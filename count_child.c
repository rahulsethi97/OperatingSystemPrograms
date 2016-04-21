#include<stdio.h>
#include<sys/wait.h>
#include<signal.h>

void fun(int x)
{
if(x==SIGINT)
{
  printf("\nProcess cannot be aborted\n");
  sleep(2);
}
}

int main(int argc,char* argv[])
{ 
 signal(SIGINT,fun);
 int n=atoi(argv[1]);
 int m=atoi(argv[2]);
 int i;
 for(i=n;i<=m;i++)
 { 
 sleep(1);
 printf("%d \n",i);
 fflush(stdout);
 }
 return 3;
}
