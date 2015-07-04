#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
bool mark[10001];
int prime[10001];
int  size_prime=0;
void init(){
	for(int i=0;i<10001;i++){
		mark[i]=true;
	}
	for(int i=2;i<10001;i++){
		if(mark[i]==false)
			continue ;
		//prime[size_prime++];这是什么？？
		prime[size_prime++]=i;
		if(i>500) continue;
		for(int j=i*i;j<10001;j+=i){
			//mark[j]==false;=又写成了==
			mark[j]=false;
		}
	}
}
int total_num(int N){
	int total_num=0;
	int bound=(int)sqrt((double)N)+1;
	for(int i=0;i<size_prime-1&&prime[i]<bound;i++){
		while (N%prime[i]==0){
			total_num++;
			N/=prime[i];
		}
		if(N==1)break; //这里加一句话！ 减少耗时！
		
	}
	if(N==1) return total_num;
	return total_num+1;
}



int main(){
	init();
	int N;
	while(scanf("%d",&N)!=EOF){
		printf("%d\n",total_num(N));
	}
	return 0;
}








// effect
