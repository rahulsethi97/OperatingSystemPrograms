#include<bits/stdc++.h>
using namespace std;


int service_time[10000];
int arrival_time[10000];
int wait_time[10000];
int turn_around[10000];
int hash_array[10000];

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

int check(int n)// function to check if all processes has been performed
{  
  int i;
  for(i=1;i<=n;i++)
  {
    if(hash_array[i]==0)
       return 0;
  }
  return 1;
}

int get_index(int time,int n)
{   

  int min=1000000,index=-1,flag=0,i;
  while(1)
  {
   if(flag)
     break;
    
    
   for(i=1;i<=n;i++)
    {
         if(arrival_time[i]<=time && hash_array[i]==0)
          {
            if(service_time[i]<min)
             { 
               min=service_time[i];
               index=i;
             }
            flag=1;
          }
    }
    time++;
  }
  return index;
}

float process(int n)
{
   
  int end,start=0,process_index,i,ctr=0;
  float avg,sum=0,size=n;
  while(1) 
    {
     if(check(n))
       break;
     
     
     process_index=get_index(start,n);
     
     //printf("For start= %d index= %d\n",start,process_index);
     if(ctr==9)
      exit(0);
 
     ctr++;
     hash_array[process_index]=1;

     end=start+service_time[process_index];
     
     if(arrival_time[process_index]<=start)
       {
        wait_time[process_index]=start-arrival_time[process_index];
        start=end;
       }
     else
      {
         start=arrival_time[process_index]+service_time[process_index];
      }
     
     
     sum=sum+wait_time[process_index];
   }
   for(i=1;i<=n;i++)
     {
         turn_around[i]=service_time[i]+wait_time[i];
     }
   
    avg=sum/size;
   return avg;
}


void display(int n,float avg)
{
  int i;
  ofstream obj;
  obj.open("/home/dell1/OS_LAb/Lab3/srn_graph.txt");

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

