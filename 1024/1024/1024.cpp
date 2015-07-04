//只得到了16分  原因 低估了最后的结果的数字的范围
///最后的数字可能是10^40全都是高精度的整数
// 下面见   1024_2  这里面我用string进行  

#define win32  1
#ifdef win32
#define LL __int64 
#else
#define LL long long
#define ll_format lld
#endif
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>>//有cmath 但是没有math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
using namespace std;

int work_palin[30];
int work_reverse[30];
LL reverse(const LL aa){
	LL a=aa;
	int ix=0;
	do{
		work_reverse[ix++]=a%10;
		a/=10;
	}
	while(a);
	LL sum=0,c=1;
	for(int i=ix-1;i>=0;i--){
		sum+=work_reverse[i]*c;
		c*=10;
	}
	return sum;
}

bool ispalin(const LL aa){
	LL a=aa;
	int ix=0;
	do{
		work_palin[ix++]=a%10;
		a/=10;
	}
	while(a);
	bool flag=true;
	int px=ix-1;
	px/=2;
	for(int i=0;i<=px;i++){
		//if(work_palin[i]!=work_palin[ix-1-px])//出错了  px应该是i
		if(work_palin[i]!=work_palin[ix-1-i])
			flag=false;
	}
	return flag;
}
LL numin;
int k;
int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%I64d",&numin)!=EOF){
		scanf("%d",&k);
		int cnt=0;
		bool find=false;
		while (true){
			if(ispalin(numin)==true) {
				find=true;
				break;
			}
			cnt++;
			if(cnt>k) break;
			LL b=reverse(numin);
			numin+=b;
		}
		if(find==false){
			printf("%I64d\n",numin);
			printf("%d\n",k);
		}
		else{
			printf("%I64d\n",numin);
			printf("%d\n",cnt);
		}
	}
	return 0;
}

