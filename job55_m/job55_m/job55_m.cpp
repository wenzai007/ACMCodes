//不够简洁  看答案的写法！！！
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
int a ,k;
bool mark[10001];
int prime[10001];

int factorial_num[1008];

int  a_primes[1008];
int  a_num[1008];
int  a_size;
void init (){
	int i,j,size_prime;
	size_prime=0;
	for(i=0;i<10001;i++){
		mark[i]=true;
	}
	//for(i=0;i<10001;i++){i从几开始
	for(int i=2;i<10001;i++){
		if(mark[i]==false)
			continue;
		prime[size_prime++]=i;
		if(i>108) continue;
		for(j=i*i;j<10001;j+=i){
			mark[j]=false;
		}
	}
}

void factorial_lauch(int n){//求阶乘的素数们
	int p_tmp;
	for(int i=0;i<1008;i++){
		//factorial_num[i]==0;//又一次==！！！！
		factorial_num[i]=0;
	}
	for(int i=0;prime[i]<=n;i++){
		p_tmp=prime[i];
		while (n/p_tmp>=1){
			//factorial_num[i]++;不对了
			factorial_num[i]+=n/p_tmp;
			p_tmp*=prime[i];
		}
	}
}
void a_getprime(int n){
	for(int i=0;i<1008;i++){//初始化
		a_primes[i]=0;
		a_num[i]=0;
	}
	a_size=0;
	//int bound = (int) sqrt(double(n))1+;写的什么？
	int bound = (int) sqrt(double(n))+1;
	for(int i=0;prime[i]<bound;i++){
		if(n%prime[i]==0){
			a_primes[a_size]=prime[i];
			while(n%prime[i]==0){
				a_num[a_size]++;
				n/=prime[i];
			}
			a_size++;

			if(n==1) break;
		}
	}
	if(n>1){
		a_primes[a_size]=n;
		a_num[a_size]=1;
	}
}

int k_value(){
	int min=9999999;//取一个大数
	int k_tmp;
	for(int i=0,j=0;i<=a_size&&a_primes[i]!=0;){
		if(prime[j]<a_primes[i]){
			j++;
			continue;
		}
		k_tmp=factorial_num[j]/a_num[i];
		if(k_tmp<min) min=k_tmp;
		i++;
	}
	return min;
}

int main(){
	int n,a;
	freopen("in.txt","r",stdin);
	init();
	while(scanf("%d%d",&n,&a)!=EOF){
		factorial_lauch(n);
		a_getprime(a);
		int ans=k_value();
		printf("%d\n",ans);
	}
	return 0;
}







//  effect

