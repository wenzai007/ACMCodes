#include<stdio.h>
//第一次出错 运行时错误  stack overflow
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

//char map[108][108];不能起名叫map否则报错
//“map”: 不明确的符号可能是“ std::map”
char pic[108][108];
bool mark[108][108];
int m,n;
int go[][2]={//上下左右  斜着的4个
	-1,0,
	1,0,
	0,1,
	0,-1,
	-1,-1,
	-1,1,
	1,-1,
	1,1
};//忘记加分号！！
void dfs(int x,int y){
	//int nx=x,ny=y;
	for(int i=0;i<8;i++){
		int nx=x+go[i][0];
		int ny=y+go[i][1];
		//这里的nx，ny代表的明显是第几行第几列
		//if(nx<0||nx>n-1||ny<0||ny>m-1) continue;
		if(nx<0||nx>m-1||ny<0||ny>n-1) continue;
		//少加了一个判断的如果走过了 continue啊
		//又一个无限循环！！！！！！
		if(mark[nx][ny]==true) continue;
		if(pic[nx][ny]=='*') continue;
		//艹 少加了一句话 mark啊！导致无限循环！
		mark[nx][ny]=true;
		dfs(nx,ny);
	}
}

int main(){
	freopen("in.txt","r",stdin);
	//int m,n;不能再这里定义 dfs不认识m和n了
	while (scanf("%d%d",&m,&n)!=EOF){
		if(!m&&!n)break;
		for(int i=0;i<m;i++){
			scanf("%s",pic[i]);//很好 注意这种写法
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				mark[i][j]=false;
			}
		}
		/*
		int sx,sy;
		for(sx=0;sx<m;sx++){
			for(sy=0;sy<n;sy++){
				if(pic[sx][sy]=='@')break;
			}
		}
		if(sx==m&&sy==n){//这个是没找到的时候结束的条件！
			printf("0\n");
			continue;
		}
		mark[sx][sy]=true;
		dfs(sx,sy);
		int ans=0;
		*/
		int ans=0;
		for(int i=0;i<m;i++){//擦 写了这个貌似上面的没用了啊！
			for(int j=0;j<n;j++){
				if(mark[i][j]==false&&pic[i][j]=='@'){
					mark[i][j]=true;//少加了这句话！！
					dfs(i,j);
					ans++;
				}
			}
		}
		printf("%d\n",ans);

	}
	return 0;
}

