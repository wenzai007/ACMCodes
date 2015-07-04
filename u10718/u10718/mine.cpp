//第一次 wa  原因： 逻辑分析不严密 还是不对劲的
//贪心的思想
//正确的思路是这样的：  首先  让M是0 然后对着N的每一位  
//进行比较  如果N【k】是0  那么看看m【k】能不能是1  就是让当前的
//位为1的时候 看看其最小值还能不能小于等于U 行则1 不行则0  当N【k】为1的时候 
//再看看 M【k】的值能不能是0 就是当前位为0  那么其最大值会不会大于等于L
//行则0 不行则1
#define for if(0); else for 
#define pf printf
#define sf  scanf
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
long long N,M;
long long L,U;
int a[50],b[50];
int ida,idb;
void store(){
	ida=idb=0;
	long long x=N;
	while(x>0){
		a[ida++]=x%2;
		x/=2;
	}
	//x=M;千错万错不应该错在这里啊 傻× 初始的时
	//你令M等于L 但是M现在美誉任何值啊 这样诠释零啊
	//完蛋呢？？？
	x=L;
	while(x>0){
		b[idb++]=x%2;
		x/=2;
	}
}

/*
   long long  justdoit(){//这个判断的东西写错了！！
   long long ans=L;
   for(int i=31;i>=0;i--){
   long long tmp=(long long )1<<i;//这个是当前的这一位的权重
   if(a[i]==0){
   if(ans+tmp<=U){
   ans+=(b[i]==1)?0:tmp;
   }
   }
   else{//一定是1
   if(ans-tmp>=L){
   ans-=(b[i]==0)?0:tmp;
   }
   }
   }
   return ans;
   }
   */

long long  justdoit(){//上面的那个判断的东西写错了！！知道不 你如果本身是
	//1还判断什么  本身是0还判断个鸟啊
	//long long ans=0;
	long long sum=0;//记录前面已经定下来的位的总和数目
	for(int i=31;i>=0;i--){
		long long tmp=(long long )1<<i;//这个是当前的这一位的权重
		if(a[i]==0){
			if((sum+tmp)<=U){
				sum+=tmp;
				//b[i]=1;可以不用写
			}
			else{
				//b[i]=0;可以不用写
			}
		}
		else{//a[i]==1
			if((sum+tmp-1)>=L){//这个是当前位如果为0时候的最大值
				//b[i]=0;
			}
			else{
				sum+=tmp;
				//b[i]=1;必须为1；
			}
		}
	}
	return sum;
}

int main(){
	freopen("in.txt","r",stdin);   
	while(sf("%d%d%d",&N,&L,&U)!=EOF){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		store();
		long long res=justdoit();
		pf("%lld\n",res);
	}
	return 0;
}

