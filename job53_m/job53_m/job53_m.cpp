//利用王道数据结构辅导书上面的方法
//两边去夹 就可以了！
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
bool mark[50000];
int prime[30000];
void init(){
	int size_prime=0;
	for(int i=0;i<50000;i++){
		mark[i]=true;
	}
	//for(int i=0;i<50000;i++){//出现完全进行不下去的情况 也没有报错  又错了 同样的  从2开始
	for(int i=2;i<50000;i++){
		if(mark[i]==false)continue;
		prime[size_prime++]=i;
		if(i>300)continue;
		for(int j=i*i;j<50000;j+=i){
			mark[j]=false;
		}
	}
}


int main(){
	freopen("in.txt","r",stdin);
	//！！又一次忘记初始化！！！！
	init();
	int even;
	//while (scanf("%d",even)!=EOF&&even){第几次u错误？？
	while (scanf("%d",&even)!=EOF&&even){
		int p_idx=0;
		while(prime[p_idx]<even){
			p_idx++;
		}
		p_idx--;//最后一个小于even的素数
		int pair_num=0,i=0,j=p_idx;
		while(i<=j){
			if(prime[i]+prime[j]==even){
				i++;j--;
				pair_num++;
				continue;
			}
			if(prime[i]+prime[j]<even){
				i++;continue;
			}
			else{
				j--;
			}
		}
		printf("%d\n",pair_num);
	}

	return 0;
}
