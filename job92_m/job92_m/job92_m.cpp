#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>

#include<algorithm>
#include<math.h>

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>
using namespace std;
char pic[10][10];
bool mark[10][10];
bool success;
int N,M,T;
int go[][2]={
	-1,0,
	1,0,
	0,-1,
	0,1
};
struct S{//状态  state
	int x,y;
	int t;
};//又一次忘记了分号！！c语言需要加java不需要
void dfs(S sn){
	int x=sn.x;
	int y=sn.y;
	int t=sn.t;
	if(pic[x][y]=='D'&&t==T){
		success=true;
		return ;
	}
	for(int i=0;i<4;i++){
		int px=x+go[i][0];
		int py=y+go[i][1];
		int pt=t+1;
		if(px<0||px>N-1||py<0||py>M-1||pic[px][py]=='X')continue;
		if(mark[px][py]==true) continue;
		S newp;  newp.x=px; newp.y=py;  newp.t=pt;
		mark[px][py]=true;
		dfs(newp);
		if(success==true) return;
		mark[px][py]=false;
	}
}

int main(){//注意开始的点可能不是0 0处
	freopen("in.txt","r",stdin);
	while(scanf("%d%d%d",&N,&M,&T)!=EOF){
		if(!N&&!M&&!T)break;
		for(int i=0;i<N;i++){
			scanf("%s",pic[i]);
		}
		int start_x,start_y;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				mark[i][j]=false;
				if(pic[i][j]=='S'){
					start_x=i;
					start_y=j;
				}
			}
		}
		S ss; ss.x=start_x; ss.y=start_y; ss.t=0;
		mark[start_x][start_y]=true;
		success=false;
		dfs(ss);
		if(success==false)
			printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}

