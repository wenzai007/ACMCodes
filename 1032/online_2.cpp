/*
����������Ĺ�����㣬�ȱ�������һ��������һһ�����ʱ�ǣ�
�ٱ����ڶ�����һ�����ʹ���������ֵ�����ֵһ��ʼһֱ
��string�����棬����map��̫�鷳�����һ�㳬ʱ�ˡ�
�ο����ϳ��򣬸���int�������棬˳��ac����ʱ��Ҫ��
��˼·��ת����
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
    //freopen("C:\\Documents and Settings\\Administrator\\����\\input.txt","r",stdin);   
  
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