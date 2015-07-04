//既然k是小于10000的说明这个数字范围可能很大   用longlong
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
//bool  mark[10000000];// yi qian wan  
bool  mark[200000];
//int  prime[10008];//这里也越界了应该 运行时候错误！！
//int  prime[10000008];
//int prime[20000];
int prime[50000];
int  size_prime=1;
//int i,j;！！！！！这里出错了  j当为i*i的时候就会溢出了 所以最好是 long long
int i;
int j;
//long long j;
void init (){
	//	for (int i=0;i<1000000;i++){//少写了一个0然后运行时错误！！！0x00f5146f 可以看到是那个数组越界了
	for (i=0;i<200000;i++){
		mark[i]=true;
	}
	for(i=2;i<200000;i++){
		if(mark[i]==false) continue;
		prime[size_prime++]=i;
		if(i>1000) continue;//新加上的一句话 果然不会运行时出错了
		                  //不加上的话 果断运行的时候就会出错！！
		for(j=i*i;j<200000;j+=i){
			mark[j]=false;
		}
	}
}

int main(){
	init();
	int n;
	while (scanf("%d",&n)!=EOF){
		printf("%d\n",prime[n]);
	}
	return 0;
}
