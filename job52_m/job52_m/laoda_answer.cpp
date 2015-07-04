//既然k是小于10000的说明这个数字范围可能很大  
//这句话是错误的 经测 第10000个质数大概是100000左右 所以mark数组根本不可能要一千万
//你对质数的密度估计错误.你可以测试一下 看第10000个质数到底是多少
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
//bool  mark[10000000];// yi qian wan  
bool  mark[200000];//足够了
//int  prime[10008];//这里也越界了应该??  运行时候错误！！
//int  prime[10000008];
//int prime[20000];
int prime[50000];
int  size_prime=1;
//int i,j;！！！！！这里出错了  j当为i*i的时候就会溢出了?? 所以最好是 long long 用了也不行，。。。。。
//用longlong是可行的 我猜是因为你没把i 也改成Longlong
//j=i*i这个表达式计算的时候 先计算i*i 他会自动生成一个临时变量来存储i*i的结果，因为I是int的 所以他的临时存储的变量也是int的
//比如 当i=3时，他先计算3*3,用temp=9去记录一下 然后 j=9. 当i=10000时 可能10000*10000已经超int 变成了负数 然后j=这个负数。所以只把j改成longlong是没用的
int i;
long long j;
void init (){
	for (i=0;i<200000;i++){//上面开200000，这里也要到200000
		mark[i]=true;
	}
	for(i=2;i<200000;i++){
		if(mark[i]==false) continue;
		prime[size_prime++]=i;

		if (i<=2000){//这里j=i*i当i比较大的时候 i*i超过了int的范围 导致j变成负数，进而mark[j]下标超界。可以预先判断一下是否i<=根号（200000），如果不是，那就直接略过了。也可以用longlong。
		for(j=i*i;j<200000;j+=i){
			mark[j]=false;
		}
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