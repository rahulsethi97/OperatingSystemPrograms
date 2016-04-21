#include<bits/stdc++.h>
using namespace std;

int arr[10000];
int mat[25][10000];

int find(int target,int size,int pos)
{

	for(int i=0;i<size;i++)
	{   
	    if(mat[i][pos]==target)
  			return 1;
	}
	return 0;
}

void display(int size,int n)
{
	for(int i=0;i<size+2;i++)
	{   
		if(i==0)
		{
			for(int j=0;j<n;j++)
			{
				cout<<arr[j]<<" ";
			}
		}
		else if(i==1)
		{
			for(int j=0;j<n;j++)
			{
				cout<<"--";
				       
			}
		}
		else
		{
			for(int j=0;j<n;j++)
			{
				cout<<mat[i-2][j]<<" ";
			}
		}
		cout<<"\n";
	}
	cout<<"\n";
}


int least_recently(int size,int curr_pos)
{
	int ret_pos,min_ind=INT_MAX,curr_element,ind,pos;
    
    for(int i=0;i<size;i++)
    {
		 curr_element=mat[i][curr_pos];
		 if(curr_element==0)
		   return i;
		   
		 for(int j=curr_pos;j>=0;j--)
		 {
		 	if(arr[j]==curr_element)
		 	{
		 		ind=j;
		 		pos=i;
		 		break;
		 	}
		 }
		 
		 if(ind<min_ind)
		  {
		  	min_ind=ind;
		  	ret_pos=pos;
		  }
    }
    return ret_pos;
}

int process(int size,int n)
{
    int pos,page_faults=1;
    
    mat[0][0]=arr[0];
	for(int i=1;i<n;i++)
	{    
	    
	    if(!find(arr[i],size,i-1))
	    {
	    	pos=least_recently(size,i-1);
			mat[pos][i]=arr[i];
			page_faults++;
		}
		
		if(i!=0)
		{
			for(int j=0;j<size;j++)
			{
				if(mat[j][i]==0)
				  mat[j][i]=mat[j][i-1];
			}
		}
	}
	return page_faults;
}


int main()
{
	int n;
	cout<<"Enter the number of pages: ";
	cin>>n;
	
	cout<<"Enter all the pages needed: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int size;
	cout<<"Enter the alloc size: ";
	cin>>size;
	
	int page_faults=process(size,n);
	display(size,n);
	cout<<"No of page faults:    "<<page_faults<<"\n";
	cout<<"No of Hits:           "<<n-page_faults<<"\n";
}
