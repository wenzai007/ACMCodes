#define for if(0); else for
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>

#include<stack>
#include<queue>
#include<vector>
#include<map>
using namespace std;

const int size=108;
int n,m;
bool mark[size];
struct edge{
	int next;
	int cost;
};
vector<edge>v[size];
int d[size];

int a,b,c;

void dij(){
	d[1]=0;
	mark[1]=true;
	int newp=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<v[newp].size();j++){
			int nex=v[newp][j].next;
			int nc=v[newp][j].cost;
			if(nex==true) continue;
			if(d[nex]==-1||d[nex]>d[newp]+nc){
				d[nex]=d[newp]+nc;
			}
		}
		int min=0x7fffffff;
		for(int j=1;j<=n;j++){
			if(mark[j]==false&&d[j]!=-1){
				if(d[j]<min){
					min=d[j];
					newp=j;
				}
			}
		}
		mark[newp]=true;
	}	
}

int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d%d",&n,&m)!=EOF){
		if(m==0&&n==0) break;
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&a,&b,&c);
			edge tmp;
			tmp.next=b; tmp.cost=c;
			v[a].push_back(tmp);
			tmp.next=a;
			v[b].push_back(tmp);
		}
		for(int i=1;i<=n;i++){
			mark[i]=false;
			d[i]=-1;
		}

		dij();
		printf("%d\n",d[n]);
	}
	return 0;
}