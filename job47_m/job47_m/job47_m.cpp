#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
int a,b;
int gcd(int a,int b){
	if(b==0)//没有判断a b均为0的情况 
		//  enen 
		return a;
	gcd(b,a%b);
}
int main(){
	while (scanf("%d%d",&a,&b)!=EOF){
		printf("%d\n",gcd(a,b));
	}
	return 0;
}
