
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>//有cmath 但是没有math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
using namespace std;


const int num  = 8;/*可以随意修改，num是多少解的就是几皇后问题*/  
      int arr[num];  
      int cnt =0;  
void display()/*一个简单的数组输出函数，顺便统计解的个数*/  
{  
    for(int i=0; i<num; ++i)  
        printf("%d\t",arr[i]);  
    printf("\n");  
    cnt++;  
}  
  
void queens(int pos=0)  
{         
    /*剪枝步骤*/  
    /*同在斜线或者直线上*/  
    for(int i=0; i<pos-1; ++i)  
    {  
        int off = arr[i] - arr[pos-1];  
        if(off ==0 || off ==pos-1-i || -off==pos-1-i)  
            return;  
    }  
  
    /*符合条件就输出*/  
    if( pos == num )  
    {   display();return;}  
      
      
    /*递归搜索解空间*/  
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