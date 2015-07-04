#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
int ans_str[100];
//第一次是wa  原因如下
//int a,b,m;这样是不够的 a，b是int但是a+b不一定了
int m;
long long a,b;
int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d%ld%ld",&m,&a,&b)!=EOF&&m){
		a+=b;//a=a+b
		int idx=0;
		do{
			ans_str[idx++]=a%m;
			a/=m;
		}
		while(a);
		for(int i=idx-1;i>=0;i--){
			printf("%d",ans_str[i]);
		}
		printf("\n");
	}
	return 0;
}




//effect
