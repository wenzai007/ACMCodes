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
	if(a==0)
		return b;
	gcd(b%a,a);
}
int lcm(int a,int b){
	return a*b/gcd(a,b);
}
int main(){
	while (scanf("%d%d",&a,&b)!=EOF){
		printf("%d\n",lcm(a,b));
	}
	return 0;
}
