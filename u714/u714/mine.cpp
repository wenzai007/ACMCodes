/*这道题和最大值最小化很8.3.5很像的  基本一模一样  二分的细节  详细解释可以看8.3.5 
 * 要考虑清楚
 *
 * */

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

int book[508];
int  outpos[508];
int b_num,p_num;

bool cansplit(long long x ){//一般 二分的话就要需要有bool型的变量
	long long sum=0;
	int t=0;//一共需要几个分割线  当然是p_num-1 个了
	for(int i=b_num-1;i>=0;i--){
		sum+=book[i];
		if(sum>x){
			sum=book[i];
			t++;
		}
		if(t>p_num-1)
			return false;
	}
	return true;
}

int main(){
	freopen("in.txt","r",stdin);   
	int c_num;
	sf("%d",&c_num);

	while (c_num--){
		sf("%d%d",&b_num,&p_num);
		for(int i=0;i<b_num;i++){
			sf("%d",&book[i]);
		}
		long long maxofthem=0,sumofthem=0;
		for(int i=0;i<b_num;i++){
			if(maxofthem<book[i])
				maxofthem=book[i];
			sumofthem+=book[i];
		}
		long long l,r,mid;
		l=maxofthem;r=sumofthem;
		while(l<r){//此处二分的细节要考虑清楚！！
			mid=(l+r)/2;
			if(cansplit(mid))//r的值始终是可以满足cansplit的！
				r=mid;
			else
				l=mid+1;
		}
		//最后的l的值就是可以的最小的值
		long long msum=0;
		int splitnum=0;
		memset(outpos,0,sizeof(outpos));
		for(int i=b_num-1;i>=0;i--){
			msum+=book[i];
			if(msum>l){
				msum=book[i];
				outpos[i]=1;
				splitnum++;
			}
		}
		if(splitnum<p_num-1){
			for(int i=0;i<b_num;i++){
				if(outpos[i]==1)//此处很重要的，如果和之前的斜杠重复了
								//那么需要重新找一个新的斜杠，否则的话
								//会这样100/100 100/100 100的情况
								//正确应该100/100/100/100 100
					continue;
				outpos[i]=1;
				splitnum++;
				if(splitnum==p_num-1)
					break;
			}
		}
		for(int i=0;i<b_num-1;i++){
			pf("%d ",book[i]);
			if(outpos[i])
				pf("/ ");
		}
		pf("%d\n",book[b_num-1]);
		
	}
	return 0;
}

