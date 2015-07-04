//上一个版本我做麻烦了  不用dfs的！！  直接就dij边写边记录路径
//就可以了 啊 ！！！！重写
//见  _2  ！vc2008
#define for if(0); else for 
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

#include<time.h>
using namespace std;


const int size=580;
struct edge{
	int next;
	int d;
	int c;
};

vector <int> path;
bool  mark[size];
int dis[size];
int cost[size];
vector <edge> v[size];
int N,M,S,D;
int c1,c2,dd,cc;
int sum_d,sum_c;
bool  findit;

void dij(){
	for(int i=0;i<N;i++){
		mark[i]=false;
		dis[i]=-1;
		cost[i]=0x6fffffff;
	}
	mark[S]=true;
	dis[S]=0;
	cost[S]=0;
	int newp=S;
	path.push_back(newp);
	for(int i=1;i<N;i++){
		for(int j=0;j<v[newp].size();j++){
			edge tmp=v[newp][j];
			int tid=tmp.next, td=tmp.d, tc=tmp.c;
			if(mark[tid]==true) continue;
			if(dis[tid]==-1||dis[tid]>dis[newp]+td){
				dis[tid]=dis[newp]+td;
				cost[tid]=cost[newp]+tc;
			}
			else if(dis[tid]==dis[newp]+td&&cost[tid]>cost[newp]+tc){
				cost[tid]=cost[newp]+tc;
			}
		}
		int min=0x6fffffff;
		for(int j=0;j<N;j++){
			if(mark[j]==false&&dis[j]!=-1){
				if(dis[j]<min){
					min=dis[j];
					newp=j;
				}
			}
		}
		path.push_back(newp);
		mark[newp]=true;
	}
}

/*
void dfs(int np){
	if(np==D){
		//if(sum_d==dis[D]&&sum_c==dis[D]){莫名其妙的错误的原因cost写成了dis
		//查了很久 他妈的  粗心的代价！
		if(sum_d==dis[D]&&sum_c==cost[D]){
			findit=true;
			return;
		}
	}

	for(int i=0;i<v[np].size();i++){
		edge tmp=v[np][i];
		int nx=tmp.next;
		int dx=tmp.d;
		int cx=tmp.c;
		if(mark[nx]==false){
			sum_d+=dx;
			sum_c+=cx;
			mark[nx]=true;
			path.push_back(nx);
			dfs(nx);
			if(findit==true) return;
			sum_d-=dx;
			sum_c-=cx;
			mark[nx]=false;
			path.pop_back();
		}
	}
}

*/
int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d%d%d%d",&N,&M,&S,&D)!=EOF){
		for(int i=0;i<N;i++){
			v[i].clear();
		}
		path.clear();
		for(int i=0;i<M;i++){
			scanf("%d%d%d%d",&c1,&c2,&dd,&cc);
			edge tmp;
			tmp.d=dd; tmp.c=cc; tmp.next=c2;
			v[c1].push_back(tmp);
			tmp.next=c1;
			v[c2].push_back(tmp);
		}
		dij();
		/*
		for(int i=0;i<N;i++){
			mark[i]=false;
		}
		mark[S]=true;
		sum_c=0;sum_d=0;
		findit=false;
		path.push_back(S);
		dfs(S);
		for(int i=0;i<path.size();i++){
			printf("%d ",path[i]);
		}
		*/
		printf("%d %d\n",dis[D],cost[D]);
	}
	return 0;
}

