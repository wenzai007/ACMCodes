//筛素数 如果一个数不是素数 那么它必然是某个小于他的素数的倍数
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
bool mark[10008];
int prime[5000];
int size_prime=0;
void init(){
	for(int i=0;i<10008;i++)
		//mark[i]==true;！！查半天没查出来怎么回事看看等号写成什么了//初始的时候都是素数  
		mark[i]=true;
	for(int i=2;i<10008;i++){
		if(mark[i]==false)
			continue;
		prime[size_prime++]=i;
		for(int j=i*i;j<10008;j+=i){
			//mark[j]==false;
			mark[j]=false;
		}
	}
}

int main(){

	int  n,each_num;
	init();
	while(scanf("%d",&n)!=EOF){
		each_num=0;
		for(int i=0;i<size_prime&&prime[i]<n;i++){
			if(prime[i]%10==1&&prime[i]<n){
				each_num++;
				if(each_num==1){
					printf("%d",prime[i]);
				}
				else if(each_num>1){
					printf(" %d",prime[i]);
				}
			}
		}
		if(each_num==0)
			printf("-1\n");
		else
			printf("\n");
	} 
	return 0;
}
