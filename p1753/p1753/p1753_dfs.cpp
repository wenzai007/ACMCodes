#include<stdio.h>
#include<stdlib.h>

#include<string>
#include<string.h>
#include<ctype.h>

#include<math.h>
#include<algorithm>

#include<queue>
#include<stack>
#include<map>
#include<vector>
using namespace std;
int find;//有没有找到
int change[16]={
	
	51200,58368,29184,12544,  
     35968,20032,10016,4880,  
     2248,1252,626,305,  
     140,78,39,19  
};

char pic[4][4];
int cur;
dfs(int block,int dep){//从第0块开始变化
	if(dep==step){//  outlet_1
		if(cur==0||65535){
			find=true;
		}
		return;
	}
	if(dep>16||find)//之所以加上这个find是因为为了尽快的结整个dfs的过程  outlet_2
		return;
	cur^change[block];//turn over
	dfs(block+1,dep+1);
	cur^change[block];// recover !!  sure  this is to recover from begining
	dfs(block+1,dep);
}
int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%s",&pic[0])!=EOF){
		for(int i=0;i<3;i++){
			scanf("%s",&pic[i+1]);
		}
		cur=0;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				cur<<=1;
				if(pic[i][j]=='b')
					cur+=1;
			}
		}
		find=false;
		int step;
		for(step=0;step<=16;step++){
			dfs(0,0);
			if(find) break;
		}
		if(step>16)
			printf("Impossible\n");
		else 
			printf("%d\n",step);
	}
}
