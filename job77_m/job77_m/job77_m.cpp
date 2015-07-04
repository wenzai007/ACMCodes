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
struct edge{
	int next;
	int d;
	int p;
};//没有加分号！！！
/*
dis_d[1080];
dis_p[1080]; 是什么导致了103个error？？？
mark[1080];
*/
int dis_d[1080];
int dis_p[1080]; 
bool mark[1080];
vector <edge> vertexs[1080];
int n,m,a,b,d,p;
int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d%d",&n,&m)!=EOF){
		if(!n&&!m) break;
		for(int i=1;i<=n;i++){
			dis_d[i]=-1;
			dis_p[i]=-1;
			vertexs[i].clear();
			mark[i]=0;
		}
		for(int i=0;i<m;i++){
			scanf("%d%d%d%d",&a,&b,&d,&p);
			edge tmp;
			tmp.d=d;
			tmp.p=p;
			tmp.next=a;
			vertexs[b].push_back(tmp);
			tmp.next=b;
			vertexs[a].push_back(tmp);
		}
		scanf("%d%d",&a,&b);//  start and  destination
		int newp=a;
		mark[newp]=1;
		dis_d[newp]=0;
		dis_p[newp]=0;
		for(int i=0;i<n-1;i++){
			for(int j=0;j<vertexs[newp].size();j++){
				edge ntmp=vertexs[newp][j];
				int n_next=ntmp.next;
				int dd=ntmp.d;
				int pp=ntmp.p;
				if(mark[n_next]==true) continue ;
				if(dis_d[n_next]==-1||dd+dis_d[newp]<dis_d[n_next]){
					dis_d[n_next]=dd+dis_d[newp];
					dis_p[n_next]=pp+dis_p[newp];//粗心 p写成d
				}
				if(dd+dis_d[newp]==dis_d[n_next]&&pp+dis_p[newp]<dis_p[n_next]){
					dis_d[n_next]=dd+dis_d[newp];
					dis_p[n_next]=pp+dis_p[newp];
				}
			}
			int min_d=100000000;
			int min_p=100000000;
			for(int j=1;j<=n;j++){
				if(mark[j]==true) continue;
				if(dis_d[j]==-1) continue;
				if(dis_d[j]<min_d||dis_d[j]==min_d&&dis_p[j]<min_p){
					newp=j;
					min_d=dis_d[j];
					min_p=dis_p[j];
				}
			}
			mark[newp]=true;
		}
		printf("%d %d\n",dis_d[b],dis_p[b]);

	}
	return 0;
}

