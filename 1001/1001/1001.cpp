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
int a,b;
int out[10];
int idx;
int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d%d",&a,&b)!=EOF){
		int ori=a+b;
		int c=abs(ori);
		idx=0;
		do{
			out[idx++]=c%1000;
			c/=1000;
		}
		while(c);
		if(ori<0)printf("-");
		for(int i=idx-1;i>=0;i--){
			if(i==idx-1){
				printf("%d",out[i]);
			}
			else printf("%03d",out[i]);
			if(i!=0)printf(",");
		}
	}
	return 0;
}

