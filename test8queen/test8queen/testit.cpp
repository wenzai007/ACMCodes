
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>//��cmath ����û��math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
using namespace std;


const int num  = 8;/*���������޸ģ�num�Ƕ��ٽ�ľ��Ǽ��ʺ�����*/  
      int arr[num];  
      int cnt =0;  
void display()/*һ���򵥵��������������˳��ͳ�ƽ�ĸ���*/  
{  
    for(int i=0; i<num; ++i)  
        printf("%d\t",arr[i]);  
    printf("\n");  
    cnt++;  
}  
  
void queens(int pos=0)  
{         
    /*��֦����*/  
    /*ͬ��б�߻���ֱ����*/  
    for(int i=0; i<pos-1; ++i)  
    {  
        int off = arr[i] - arr[pos-1];  
        if(off ==0 || off ==pos-1-i || -off==pos-1-i)  
            return;  
    }  
  
    /*�������������*/  
    if( pos == num )  
    {   display();return;}  
      
      
    /*�ݹ�������ռ�*/  
    for(int k=0; k<num; ++k)  
    {  
        arr[pos]=k;  
        queens(pos+1);  
    }  
}  

int  main(int i,int j)  
{  
    queens();  
    printf("count:%d",cnt);  
    getchar();  
}  