#include<bits/stdc++.h>
using namespace std;

int arr[20][1005];


struct node
{
int info;
struct node *link;
};

struct node *front=NULL,*rear=NULL;  
 
void display_queue()
{
 struct node *temp=front;
 while(temp!=NULL)
 {
   cout<<temp->info<<" "; 
   temp=temp->link;
 } 
cout<<"\n";

}

int dequeue()// dequeue(&front);
{
       struct node *temp, *var=front;
       int ret;
      if(var!=NULL)
      {      
             ret=(front)->info;
             front = (front)->link;
             free(var);
      }
      else
        ret=-1;
      return ret;
}


void enqueue(int value)//enqueue(value,&rear,&front);
{
     struct node *temp;
     temp=(struct node *)malloc(sizeof(struct node));
     temp->info=value;
     if (front == NULL)
     {
           front=temp;
           (front)->link=NULL;
           rear=front;
     }
     else
     {
           (rear)->link=temp;
           rear=temp;
           (rear)->link=NULL;
     }
}

int service_time[10000];
int arrival_time[10000];
int wait_time[10000];
int turn_around[10000];
int hash_array[10000];
int sum;


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
 sum=sum+service_time[i];
}
return n;
}

void put_into_queue(int time,int n)
{
 for(int i=1;i<=n;i++)
 {
  if(arrival_time[i]==time)
  {
   enqueue(i);
  }
 }
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


int get_pos(int pid)// return position of process in queue
{
 struct node *temp=front;
 int ans=0,flag=0;
 while(temp!=NULL)
  {
   ans++;
   if(temp->info==pid)
   { 
     flag=1;
     break;
   } 
   temp=temp->link;
  }
if(flag)
  return ans;
else
  return 0;
}


void process(int n)
{  
   float avg;
   struct node *temp=front;
   for(int i=1;i<=n;i++)
   { 
     arr[i][0]=service_time[i];
     arr[i][1]=0;
   }   
   int pos=2,time=1,pos_obt[n+1],prab=1,sum1=sum;
   put_into_queue(0,n);
   while(sum--)
   { 
    display_queue();
    
    temp=front;
    

    if(front==NULL&&check(n))
     break;
     
     for(int i=1;i<=n;i++)
       { 
        pos_obt[i]=get_pos(i); 
       }
    
     for(int i=1;i<=n;i++)
       {   
        arr[i][pos]=pos_obt[i];
        if(pos_obt[i]==1)
           {  
             arr[i][1]++; 
             int val=dequeue();
             put_into_queue(time,n);
             
             if(arr[i][1]<arr[i][0])
               enqueue(val);

             if(arr[i][1]==arr[i][0])
                hash_array[i]=1;
           }
         
        
       }
       time++;
       pos++;
   }
   
   for(int i=1;i<=n;i++)
    {
      for(int j=2;j<=sum1+1;j++)
           cout<<arr[i][j]<<" ";
           cout<<"\n";
    }
   //return avg;
}


void display(int n,float avg)
{
  int i;
  ofstream obj;
  obj.open("/home/dell1/OS_LAb/Lab3/rr_graph.txt");

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
 n=get_data();
 process(n);
}
