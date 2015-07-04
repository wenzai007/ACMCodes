//擦 一个完全图 连接两个点共有多少种走法？？？
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

int N,M,c1,c2;
const  int size=580;
int idx=0;

int sum_c=0;
int sum_p=0;

int people[size*size/2];
int cost[size*size/2];

int e_people[size];
bool  mark[size];
struct  edge{
	int next;
    int num_c;
};
vector <edge> v[size];
void dfs(int np){
	int nowp=np;
	if(nowp==c2){
		cost[idx]=sum_c;
		people[idx]=sum_p;
		idx++;
		return;
	}
	for(int i=0;i<v[nowp].size();i++){
		int nex=v[nowp][i].next;
		int num_c=v[nowp][i].num_c;
		if(mark[nex]==true) continue;
		sum_c+=num_c;
		sum_p+=e_people[nex];
		mark[nex]=true;
		dfs(nex);
		mark[nex]=false;
		sum_c-=num_c;
		sum_p-=e_people[nex];//开始找下一个边
	}
}


int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d",&N)!=EOF){
		scanf("%d%d%d",&M,&c1,&c2);
		idx=0;
		sum_c=0;
		sum_p=0;
		for(int i=0;i<N;i++){
			v[i].clear();
			mark[i]=false;
		}
		for(int i=0;i<N*N/2;i++){
			cost[i]=0x7fffffff;
			people[i]=0;
		}
		for(int i=0;i<N;i++){
			scanf("%d",&e_people[i]);
		}
		int t1,t2,tc;
		for(int i=0;i<M;i++){
			scanf("%d%d%d",&t1,&t2,&tc);
			edge ee;  ee.num_c=tc;  
			ee.next=t2;
			v[t1].push_back(ee);
			ee.next=t1;
			v[t2].push_back(ee);
		}
		mark[c1]=true;
		sum_p=e_people[c1];
		dfs(c1);
		int num_smallest=0;
		int smallest=0xfffffff;
		int mostpeople=0;
		for(int i=idx-1;i>=0;i--){
			if(cost[i]<smallest)
				smallest=cost[i];
		}
		for(int i=0;i<idx;i++){
			if(cost[i]==smallest){
				num_smallest++;
				if(people[i]>mostpeople){
					mostpeople=people[i];
				}
			}
		}
		printf("%d %d\n",num_smallest,mostpeople);

	}
	return 0;
}

