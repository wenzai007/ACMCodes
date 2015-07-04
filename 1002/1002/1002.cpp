#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>>//有cmath 但是没有math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>
using namespace std;
const int size=1080;
double  sum[size];
int main(){
	freopen("in.txt","r",stdin);
	int k,ex;
	double co;
	while (scanf("%d",&k)!=EOF){
		for(int i=0;i<size;i++){
			sum[i]=0;
		}
		while (k--!=0){
			scanf("%d%lf",&ex,&co);
			sum[ex]+=co;
		}
		scanf("%d",&k);
		while (k--!=0){
			scanf("%d%lf",&ex,&co);
			sum[ex]+=co;
		}
		int num=0;
		for(int i=size-1;i>=0;i--){
			if(sum[i]!=0) num++;
		}
		if(num==0){
			printf("0\n");
			continue;
		}
		printf("%d ",num);
		int cnt=0;
		for(int i=size-1;i>=0;i--){
			if(sum[i]!=0){
				cnt++;
				if(cnt!=num)
					printf("%d %.1lf ",i,sum[i]);
				else printf("%d %.1lf",i,sum[i]);
			}
		}
		printf("\n");
	}
	
	return 0;
}

