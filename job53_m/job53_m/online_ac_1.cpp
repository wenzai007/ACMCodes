#include<stdio.h>
#include<string.h>


int main()
{
	int n,i,f,j,a[10000],num,s,l,r,mid;
	a[0]=2;s=1;
	for(i=3;i<32770;i=i+2)//这里是打出素数
	{
		f=0;
		for(j=0;j<s;j++)
		{
			if(a[j]*a[j]>i)
				break;
			if(i%a[j]==0)
			{
				f=1;
				break;
			}
		}
		if(f==0)
			a[s++]=i;
	}
	while(scanf("%d",&n),n)
	{
		num=0;
		for(i=0;a[i]*2<=n;i++)
		{
			l=0;r=s;
			while(r>l)//查找时一定要用2分啊！不然超时超到哭！！
			{
				mid=(r+l)/2;
				if(a[i]+a[mid]==n)
				{
					num++;
					break;
				}
				if(a[i]+a[mid]<n)
					l=mid+1;
				if(a[i]+a[mid]>n)
					r=mid;
			}
		}
		printf("%d\n",num);
	}
	return 0;
}