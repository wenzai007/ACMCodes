//网上的两个很好的代码 关键都是标记节点已经访问  我是个2b
//code1、   dfs

#include<stdio.h>   
#include<string.h>   
  
#define max 1001   
int edge[max][max];  
int visited[max];  
//int query[max];  
int N; // the total number of cities   
int M; // the number of remaining highways   
int K; // the number of cities to be checked   
  
void dfs(int t)  
{  
    visited[t] = 1;  
    int i;  
    for(i=1; i<=N; i++)  
    {  
        if(!visited[i] && edge[i][t] == 1)  
            dfs(i);  
    }  
}  
  
  
  
int main()  
{     
    int i,j;  
    int a,b;      
    scanf("%d%d%d",&N,&M,&K);  
    for(i=0; i<M; i++)  
    {  
        scanf("%d%d",&a,&b);  
        edge[a][b] = 1;  
        edge[b][a] = 1;  
    }  
    int temp;  
    int num;  
    for(i=0; i<K; i++)  
    {  
        num = 0;  
        scanf("%d",&temp);  
        memset(visited,0,sizeof(visited));  
        visited[temp] = 1;  
        for(j=1; j<=N; j++)  
        {  
            if(visited[j] == 0)  
            {                 
                dfs(j);  
                num ++;  
            }  
        }  
        printf("%d\n",num-1);  
    }  
  
} 


//
//


