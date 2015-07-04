#include<stdio.h>
long long ans[91];
int main(){
	int n;
	ans[1]=1;
	ans[2]=2;
	for(int i=3;i<=90;i++){
		ans[i]=ans[i-1]+ans[i-2];
	}
	while(scanf("%d",&n)!=EOF){
		printf("%lld\n",ans[n]);
	}
	return 0;
}
