/*
找两条链表的公共结点，先遍历其中一条，并且一一做访问标记，
再遍历第二条，一旦访问过就输出结点值。结点值一开始一直
用string来保存，用了map，太麻烦，最后一点超时了。
参考网上程序，改用int型来保存，顺利ac。有时需要的
是思路的转换。
*/


#include<cstdio>   
const int NUM=100005;  
int a[NUM];  
int visit[NUM];  
int main()  
{  
    int x,y,n,i;  
    int s1,s2;  
    char c;  
    //freopen("C:\\Documents and Settings\\Administrator\\桌面\\input.txt","r",stdin);   
  
    scanf("%d%d%d",&s1,&s2,&n);  
    for(i=0;i<n;i++){  
        scanf("%d %c %d",&x,&c,&y);  
        a[x]=y;  
    }  
    x=s1;  
    while(x!=-1){  
        visit[x]=1;  
        x=a[x];  
          
    }  
    x=s2;  
    while(x!=-1){  
        if(visit[x]==1){  
            printf("%05d",x);  
            return 0;  
        }  
        x=a[x];  
    }  
    printf("-1");  
    return 0;  
  
  
}  