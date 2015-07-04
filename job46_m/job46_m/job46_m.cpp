#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
int out[1000000];
int n;

int main(){
	while(scanf("%d",&n)!=EOF){
		int idx=0;
		do{
			out[idx++]=n%8;
			n/=8;
		}
		while (n);
		for(int i=idx-1;i>=0;i--){
			printf("%d",out[i]);
		}
		printf("\n");
	}
	return 0;
}
