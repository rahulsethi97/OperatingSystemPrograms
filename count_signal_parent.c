#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>

void fun(int x)
{
if(x==SIGINT)
{
printf("\nProcess cannot be aborted\n");
}
}

int main(int argc,char* argv[])
{
signal(SIGINT,fun);
int pid;
pid=fork();

if(pid==0)
{
 int no=atoi(argv[1]),i;
 int n=atoi(argv[2]);
 int m=atoi(argv[3]);
 int count=(m-n+1)/no;
 int begin,end;
 begin=n;
 end=n+count-1;
 char str1[20];
 char str2[20];
 sprintf(str1,"%d",begin);
 sprintf(str2,"%d",end);
 
 for(i=1;i<=no;i++)
  {   
      int pid1;
      
      pid1=fork();
      if(pid1==0)
      {
         int R=execlp("/home/dell1/OS_LAb/child_of_count","child_of_count",str1,str2,NULL);
      }
      else if(pid1>0)
      {  
         printf("\nI am a process-no %d",i);
         wait(NULL);
      }
      else
       printf("\nError\n");
     
    begin=end+1;
    end=end+count; 
    sprintf(str1,"%d",begin);
    sprintf(str2,"%d",end);
  }
 sleep(20);
}
else if(pid>0)
{
 printf("\nI am a parent-process(%d) and i am gonna print numbers from %d to %d in %d sub-processs.\n",getpid(),atoi(argv[2]),atoi(argv[3]),atoi(argv[1]));
sleep(20);
}
else
{
printf("\nError\n");
}

}
