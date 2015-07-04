#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
int n,k;
int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%d",&n)!=EOF){
		for(k=10;n/k!=0;k*=10);//can i? 
		int rem=(n*n)%k;
		if(rem==n)printf("Yes!\n");
		else printf("No!\n");
	}
	return 0;
}
