#include<iostream>
using namespace std;

/*
 * Constants
 * ---------
 * MaxElements -- Maximum number of elements
 * Sentinel    -- Value used to terminate input
 */

#define MaxElements 250
#define Sentinel      -1

/* Private function prototypes */

/* Main program */

int GetIntegerArray(int array[], int Max,int Se);
void PrintIntegerArray(int array[],int n);
void ReverseIntegerArray(int array[],int n);
void SwapIntegerElements(int array[],int p1,int p2);
void GiveInstructions();
void SortIntegerArray(int array[],int n);
int FindSmallestInteger(int array[],int low,int high);
bool SearchArray(int array[],int n, int value);

int main()
{
    int list[MaxElements], n;
	GiveInstructions();
    n = GetIntegerArray(list, MaxElements, Sentinel);
    ReverseIntegerArray(list, n);
	cout<<"The reverse array is as follows: \n";
    PrintIntegerArray(list, n);
	SortIntegerArray(list, n);
	cout<<"The sorted array is as follows: \n";
	PrintIntegerArray(list, n);
	return 0;
}

int GetIntegerArray(int array[],int Max,int Se)
{int i,a;
for(i=0;;i++)
{
	Max=MaxElements;
	Se=Sentinel;
	cin>>a;
	if(i>0) 
	{
		if(SearchArray(array,i,a)) 
		{
			cout<<a<<" is already in the array. Please input again\n";
			cout<<"?";
			i--;
			continue;
		}
	}
    if(a==Se) break;
	cout<<"?";
	if(i>=Max) 
    {
		cout<<"Error!Data Overflow!";
		break;
	}
	array[i]=a;

}
	return(i);
}
void PrintIntegerArray(int array[],int n)
{
	int i;
	for(i=0;i<n;i++) cout<<array[i]<<" ";
	cout<<endl;
}
void ReverseIntegerArray(int array[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=n-1;j>i;j--) SwapIntegerElements(array, j, j-1);
	}
}
void SwapIntegerElements(int array[],int p1,int p2)
{
	int t;
	t=array[p1];
	array[p1]=array[p2];
	array[p2]=t;
}
void GiveInstructions()
{
	cout<<"Enter numbers, one per line, ending with the"<<endl;
	cout<<"sentinel value -1  The program will then"<<endl;
	cout<<"display those values in reverse order and sorted order."<<endl;
	cout<<"?";
}
void SortIntegerArray(int array[],int n)
{
	int index,i;
	for(i=0;i<n-1;i++)
	{
		index=FindSmallestInteger(array, i, n-1);
		SwapIntegerElements(array, index, i);
	}
}
int FindSmallestInteger(int array[],int low,int high)
{
	int a,i;
	a=array[low];
	for(i=low;i<=high;i++)
	{
		if(a>array[i]) a=array[i];
		
	}
	for(i=low;i<=high;i++)
	{
		if(array[i]==a) break;
	}
    return(i);
}	
bool SearchArray(int array[],int n, int value)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(array[i]==value)
		{
			return(1);
			break;
		}
	}
	return(0);
}
