#include<stdio.h>
#include<limits.h>
#define maxsize 10005
int dp[maxsize];

/*
 算了  最后发现其实还是只有一维的才能最终  正确的解决好这个问题  前面的二维的根本没有办法解决好问题！！！！
 */


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
{   freopen("/Users/Knight/Documents/workspace/ACMCodes/job102_m/job_m102/in.txt","r",stdin);
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
            for(i=1;i<maxsize;i++)
                dp[i]=INT_MAX;
            dp[0]=0;
            for(i=1;i<=n;i++){
                for(j=a[i].weight;j<=w;j++){
                    if(dp[j-a[i].weight]!=INT_MAX)// 如果是无穷的话就跳过
                        dp[j]=min(dp[j],dp[j-a[i].weight]+a[i].worth);
                    printf("dp[%d][%d]=%d  ",i,j,dp[j]);
                    
                }
                printf("\n");
            }
            
            
            if(dp[w]!=INT_MAX)
                printf("The minimum amount of money in the piggy-bank is %d.\n",dp[w]);
            else
                printf("This is impossible.\n");
        }
    }
    return 0;
}