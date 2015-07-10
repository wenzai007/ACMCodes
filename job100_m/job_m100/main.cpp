#include <unistd.h> //路径

#include<stdio.h>
#include<limits.h>
#define maxsize 4010
#define size 2000
int dp[110][maxsize];
int max2(int a,int b)
{
    return a>b?a:b;
}
int max(int a,int b,int c)
{
    return max2(a,b)>c?max2(a,b):c;
}
int a[1010];
int main()
{
    //freopen("../in.txt","r",stdin);//这样的路径应该是可以的吧
   freopen("/Users/Knight/Documents/workspace/ACMCodes/job100_m/job_m100/in.txt","r",stdin);
    int t,n,num,i,j,zero;
    scanf("%d",&t);
    for(num=1;num<=t;num++)
    {
        zero=0;
        scanf("%d",&n);
        j=1;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[j++]);
            if(a[j-1]==0)
            {
                zero=1;
                j--;
            }
        }
        n=j-1;
        for(i=0;i<110;i++)
        for(j=0;j<maxsize;j++)
        dp[i][j]=INT_MIN;
        dp[0][size]=0;
        for(i=1;i<=n;i++)
        for(j=0;j<maxsize;j++)
        if(j-a[i]>=0&&j+a[i]<maxsize)
        dp[i][j]=max(dp[i-1][j-a[i]]+a[i],dp[i-1][j+a[i]]+a[i],dp[i-1][j]);
        else
        {
            if(j-a[i]<0&&j+a[i]<maxsize)
            dp[i][j]=max2(dp[i-1][j+a[i]]+a[i],dp[i-1][j]);
            else
            if(j+a[i]>=maxsize&&j-a[i]>=0)
            dp[i][j]=max2(dp[i-1][j-a[i]]+a[i],dp[i-1][j]);
            else
            dp[i][j]=dp[i-1][j];
        }
        if(dp[n][size]==0&&zero==0)
        printf("Case %d: -1\n",num);
        else
        printf("Case %d: %d\n",num,dp[n][size]/2);
        
        char buf[580];
        getcwd(buf,sizeof(buf));
        
        printf("the dir is-->   %s\n" ,buf);
        printf("min integer is :  %d\n", INT_MIN);
        for(int i=0;i<110;i++){
            for(int j=0;j<4010;j++){
                if(dp[i][j]>-20000){
                    printf("i: %d  j: %d  value： %d\n",i,j-2000,dp[i][j]);
                }
            }
        }
        
    }
    
    return 0;
    
}