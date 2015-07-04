//1. 不知道bool  负数也是true 
//2  粗心  a写成b
//3  粗心   变量写混了  不是一个地方的变量！
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
int N,M;
int dis[108];
bool mark[108];

struct edge{//这个边表的话 只存储next节点   
	int next;
	int cost;
};
vector <edge> vertexs[108];
int a,b,cost;
int main(){
	freopen ("in.txt","r",stdin);
	while (scanf("%d%d",&N,&M)!=EOF){
		if(!N&&!M) break;
		for(int i=1;i<=N;i++){
			vertexs[i].clear();
			dis[i]=-1;
			mark[i]=0;
			//mark[i]=-1;//错了 只要bool类型的不是0的话就是true 即使是负数也是true forgot  at the  first time 
		}
		for(int i=1;i<=M;i++){
			scanf("%d%d%d",&a,&b,&cost);
			edge tmp;
			tmp.next=b;
			tmp.cost=cost;
			vertexs[a].push_back(tmp);
			//tmp.next=b;//调试半天
			tmp.next=a;
			vertexs[b].push_back(tmp);
		}
		mark[1]=true;
		dis[1]=0;
		int newp=1;
		//for(int i=2;i<=N;i++){//!!不是这样写的。。 //一共要搞n-1次
		for(int i=0;i<N-1;i++){
			for(int j=0;j<vertexs[newp].size();j++){
				int new_next=vertexs[newp][j].next;
				int thecost=vertexs[newp][j].cost;
				if(mark[new_next]==true) continue;
				if(dis[new_next]==-1||dis[newp]+thecost<dis[new_next]){
					//dis[new_next]=dis[newp]+cost;调了半天 ！ 变量起得类似导致写错
					dis[new_next]=dis[newp]+thecost;
				}
			}
			int mindis=100000000;
			for(int j=1;j<=N;j++){
				if(mark[j]==1) continue;//过滤 筛掉
				if(dis[j]==-1) continue;// 过滤  筛掉
				if(dis[j]<mindis){
					newp=j;
					mindis=dis[j];
				}
			}
			// forgot the mark[]again!!!!!!!
			mark[newp]=true;
		}
		printf("%d\n",dis[N]);

	}
	return 0;
}

