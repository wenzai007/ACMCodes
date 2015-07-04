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

int list[200];
int n;
int sum;
int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&list[i]);
		}
 		//是不是现在是2楼  然后2楼有请求 也要加上呢  我就先按照加上算吧
 		int cur=0;
		sum=0;
		for(int i=0;i<n;i++){
			if(list[i]>cur){
				sum+=(list[i]-cur)*6;
				sum+=5;
				cur=list[i];
				continue;
			}
			if(list[i]<cur){
				sum+=(cur-list[i])*4;
				sum+=5;
				cur=list[i];
				continue;
			}
			sum+=5;//如果是仍然是本层呼叫的话 那么再停5秒
		}
		printf("%d\n",sum);
	}
	return 0;
}

