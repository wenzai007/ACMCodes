//这道题  是用状态的  变化来求解的 是的
//但是总是wa的原因是  清空队列的 位置写错了！！
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
int maze[52][52][52];
bool mark[52][52][52];
struct step{
	int x,y,z,t;
};
queue<step>q;
int K,k,a,b,c,tt;
int gotype[][3]={
	-1,0,0,
	1,0,0,
	0,-1,0,
	0,1,0,
	0,0,-1,
	0,0,1
};
int bfs(int a,int b,int c){
	while (!q.empty()){
		step nowp=q.front();
		q.pop();
		if(nowp.x==a-1&&nowp.y==b-1&&nowp.z==c-1) {
			//此处不要用什么break了 还要判断是因为这个break还是因为
			//q是空了才break的  这里直接从函数的地方返回就好了！！
			return nowp.t;
		}
		for(int i=0;i<6;i++){
			int x=nowp.x+gotype[i][0];
			int y=nowp.y+gotype[i][1];
			int z=nowp.z+gotype[i][2];
			int t=nowp.t+1;
			if (mark[x][y][z]==true) continue;
			if(x<0||x>a-1||y<0||y>b-1||z<0||z>c-1) continue ;
			//少了最关键的一句话  你这个傻× 迷宫如果没有墙的话还叫
			//个jb毛的迷宫了啊！！！
			if(maze[x][y][z]==1) continue;  //是墙的话还走毛！！！
			step tmp;
			tmp.x=x;tmp.y=y;tmp.z=z;tmp.t=t;
			mark[x][y][z]=true;
			q.push(tmp);
		}
	}
	return -1;//队列已经空了  但是还是没有到达  终点！！
}
int main(){
	freopen("in.txt","r",stdin);
	scanf("%d",&K);//应该不用 EOF了吧  
	while(!q.empty())q.pop();//！！！wa的原因  位置写错了！！
	while(K--!=0){
		scanf("%d%d%d%d",&a,&b,&c,&tt);
		while(!q.empty()) q.pop();
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
				for(int k=0;k<c;k++){
					scanf("%d",&maze[i][j][k]);
					mark[i][j][k]=false;
				}
			}
		}
		step st;
		st.x=st.y=st.z=st.t=0;
		q.push(st);
		mark[0][0][0]=true;
		int ans=bfs(a,b,c);
		//if(ans==-1||ans>tt) printf("-1\n");
		//else printf("%d\n",ans);
		if(ans<=tt )printf("%d\n",ans);
		else printf("-1\n");
	}
	
	return 0;
}

