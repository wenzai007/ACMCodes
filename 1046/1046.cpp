/*
分别记录1从左到右到各个点的距离和从右到左的各个点的距离

  麻烦了  看了网上的思路  其实就是记录一个就行了

  就是 顺时针的所有长度 然后不是二者距离1的差值
  就是整个圆周的距离减去  这个差值  不用记录逆时针的距离的
*/
#define for if(0); else for 
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
const int size=100080;

int rdis[size];
int ldis[size];
int dif[size];
int N,K;
int main(){
	freopen("in.txt","r",stdin);   
	while (scanf("%d",&N)!=EOF){
		rdis[1]=0;int sum=0;int d;
		for(int i=1;i<N;i++){//前n-1个数
			scanf("%d",&d);
			dif[i]=d;
			sum+=d;
			rdis[i+1]=sum;
		}
		scanf("%d",&d);//最后一个
		ldis[1]=0;sum=d;
		for(int i=N;i>=2;i--){
			ldis[i]=sum;
			sum+=dif[i-1];
		}
		scanf("%d",&K);
		int a,b;
		while (K--!=0){
			scanf("%d%d",&a,&b);
			if(a>b){
				int tmp=a;
				a=b;
				b=tmp;
			}
			int min1=rdis[b]-rdis[a];
			int min2=ldis[b]+rdis[a];
			printf("%d\n",min1<=min2?min1:min2);
		}

	}
	return 0;
}

