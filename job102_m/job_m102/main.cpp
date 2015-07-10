/*

#include<stdio.h>
#include<limits.h>
#define maxsize 10005
int dp[3][maxsize];
typedef struct coin
{
    int weight;
    int worth;
}coin;
coin a[505];
int min(int a,int b)
{
    return a<b?a:b;
}
int main()
{    freopen("/Users/Knight/Documents/workspace/ACMCodes/job_m102/job_m102/in.txt","r",stdin);
    int t,e,f,w,n,i,j;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            scanf("%d %d",&e,&f);
            w=f-e;
            scanf("%d",&n);
            for(i=1;i<=n;i++)
                scanf("%d %d",&a[i].worth,&a[i].weight);
            
            for(int j=0;j<3;j++)
                for(i=0;i<maxsize;i++)
                    dp[j][i]=INT_MAX;//这个是为了初始化  其他的 确实如果不放的话  且考虑第0个的话，就是这样的
            for(int i=0;i<3;i++)dp[i][0]=0;
            
            for(i=1;i<=n;i++)
                for(j=a[i].weight;j<=w;j++)
                    if(dp[i][j-a[i].weight]!=INT_MAX)
                        dp[i][j]=min(dp[i-1][j],dp[i][j-a[i].weight]+a[i].worth);
            
            int i=n;//  第几维的数组，考虑到第几个是可以完全放入背包当中的
            for(;i>=1;i--){
                if(dp[i][w]!=INT_MAX){
                    printf("The minimum amount of money in the piggy-bank is %d.\n",dp[i][w]);
                    break;
                }
            }
            
            if(i==0)
                printf("This is impossible.\n");
            
            // print all the elements
            
            for(int i=0;i<3;i++){
                for(int j=0;j<=101;j++){
                    if(dp[i][j]!=INT_MAX){
                        printf("dp[%d][%d]=%d  ",i,j,dp[i][j]);
                    }
                }
                printf("\n");
            }
        }
    }
    printf("%d\n",INT_MAX);
    
    return 0;
}



*/