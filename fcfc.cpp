#include<bits/stdc++.h>
using namespace std;

int service_time[10000];
int arrival_time[10000];
int wait_time[10000];
int turn_around[10000];


int get_data()
{
int n,i,flag;
printf("\nHow many Processes, Do you want? : ");
scanf("%d",&n);

printf("\nDo you want to enter arrival time of processes or every process is availabe from starting (1/0)? : ");
scanf("%d",&flag);
if(flag==1)
printf("\nMake sure you enter the process attributes in sorted order according to the arrival time.\n");

for(i=1;i<=n;i++)
{
 
 if(flag==1)
 {
   printf("\nArrival time of process no %d: ",i);
   scanf("%d",&arrival_time[i]);
 }
 else
 {
   arrival_time[i]=0;
 }
 printf("\nService time of process no %d: ",i);
 scanf("%d",&service_time[i]);
}
return n;
}


float process(int n)
{ 
  int end,start=0,i;
  float avg,sum=0,size=n;
  for(i=1;i<=n;i++)
   {
     end=start+service_time[i];
     if(arrival_time[i]<=start)
       {
        wait_time[i]=start-arrival_time[i];
        start=end;
       }
     else
      {
         start=arrival_time[i]+service_time[i];
      }
     
     
     sum=sum+wait_time[i];
   }
   for(i=1;i<=n;i++)
     turn_around[i]=service_time[i]+wait_time[i];
   
    avg=sum/size;
   return avg;
}


void display(int n,float avg)
{
  int i;
  ofstream obj;
  obj.open("/home/dell1/OS_LAb/Lab3/fcfs_graph.txt");

  char str1[20];
  char str2[20];

   printf("\n\n   Processes\t   Arrival\t   Service\t     Wait\t     Turn_Around\t");
 for(i=1;i<=n;i++)
  {
    printf("\n\n       P%d\t       %d\t       %d\t       %d\t       %d\t",i,arrival_time[i],service_time[i],wait_time[i],turn_around[i]);
    sprintf(str1,"%d",i);
    sprintf(str2,"%d",wait_time[i]);
    obj<<str1<<" "<<str2<<"\n";
  }
  
  
  printf("\nAverage Waiting Time: %f\n",avg);
}


int main()
{
int n;
float avg;

n=get_data();
avg=process(n);
display(n,avg);
}

