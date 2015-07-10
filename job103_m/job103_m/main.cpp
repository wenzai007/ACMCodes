#include<stdio.h>
#define maxsize 2010
int dp[maxsize];
typedef struct ri
{
    int price;
    int weight;
}ri;
ri rice[maxsize];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    
    freopen("/Users/Knight/Documents/workspace/ACMCodes/job103_m/job103_m/in.txt","r",stdin);
    int c,n,p,i,j,k,price,weight,num,s;
    scanf("%d",&c);
    {
        while(c--)
        {
            scanf("%d %d",&p,&n);
            j=1;
            for(i=1;i<=n;i++)
            {
                scanf("%d %d %d",&price,&weight,&num);
                k=1;
                while(num-k>0)
                {
                    rice[j].price=price*k;
                    rice[j].weight=weight*k;
                    num=num-k;
                    k=k*2;
                    j++;
                }
                if(num)
                {
                    rice[j].price=price*num;
                    rice[j].weight=weight*num;
                    j++;
                }
            }
            s=j-1;
            for(i=1;i<=p;i++)
                dp[i]=0;
            for(i=1;i<=s;i++)
                for(j=p;j>=rice[i].price;j--)
                    dp[j]=max(dp[j],dp[j-rice[i].price]+rice[i].weight);
            printf("%d\n",dp[p]);
        }
    }
    return 0;
}