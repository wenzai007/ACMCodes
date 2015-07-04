//1753这道题有两种方法  就是枚举dfs的方法   以及bfs的方法 一般最优的话我们会想到用bfs的方法
//但是dfs也是可以的只要每次遇到解的时候我们就返回就可以了
//这道题用的是bfs的方法 同时应用了位的压缩的方法  每一行每一列从左到右 从上到下  权重递减 共16位数字
//代表着一个状态  这样一个map 4*4的整数 矩阵就被压缩成了 一个1位的整数  整整少了16倍的空间
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

struct node{
	int state;
	int step;
};//一般是有逗号的吧
queue <node> q;
int change[16]={//要改变的状态  用这个去异或

	 51200,58368,29184,12544,  
     35968,20032,10016,4880,  
     2248,1252,626,305,  
     140,78,39,19  
};

bool visited[65536];
char pic[4][4];
int bfs(int np){
	node cur,next;
	cur.state=np;
	cur.step=0;
	visited[cur.state]=true;
	q.push(cur);
	while(!q.empty()){
		cur=q.front();
		q.pop();
		//太傻逼了  竟然忘记了 出队列 那不是死循环是什么？？？~~~！！！
		if(cur.state==0||cur.state==65535){
			return cur.step;
		}
		for(int i=0;i<16;i++){
			next.state=cur.state^change[i];
			if(visited[next.state]==true)
				continue;
			next.step=cur.step+1;
			//傻×  这里没有将相应的visited置为true
			visited[next.state]=true;
			if(next.state==0||next.state==65535){
				return next.step;
			}
			q.push(next);
		}
	}
	return -1;
}

int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%s",&pic[0])!=EOF){
		for(int i=0;i<3;i++){
			scanf("%s",&pic[i+1]);
		}
		int curstate=0;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				//先移位  然后负值  比如16个数字 移位要15次
				curstate<<=1;
				if(pic[i][j]=='b'){
					curstate+=1;
				}
			}
		}
		memset(visited,false,sizeof(visited));
		int res=bfs(curstate);
		if(res==-1)
			printf("Impossible\n");
		else
			printf("%d\n",res);

	}
	return 0;
}
