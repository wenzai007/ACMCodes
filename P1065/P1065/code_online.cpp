
/*
   简单贪心
   与 hdu2037相似都是对数据进行排序
   先按l排序，如果l相同的话，在按w
   排序，直接按题意比较即可！ 
   */
#include<stdio.h>
#include<stdlib.h>
typedef struct stick
{
	int l;
	int w;
}stick;
int cmp(const void *a,const void *b)
{
	if((*(stick *)a).l==(*(stick *)b).l)
	{
		return (*(stick *)a).w-(*(stick *)b).w;
	}
	else
	{
		return (*(stick *)a).l-(*(stick *)b).l;
	}
}
int main()
{
	int n,m,i,sum,temp,j;
	stick p[5002];
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	while(n--)
	{
		sum=0;
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&p[i].l,&p[i].w);
		}
		qsort(p,m,sizeof(p[0]),cmp);
		for(i=0;i<m;i++)
		{
			if(p[i].w!=0)
			{
				temp=p[i].w;
				sum++;
				for(j=i+1;j<m;j++)
				{
					if(p[j].w>=temp)
					{
						temp=p[j].w;
						p[j].w=0;
					}
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
