#define for if(0); else for 
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>//有cmath 但是没有math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
using namespace std;

const int size=1080;
bool mark[size];
vector<int> v[size];
int n,lev;
int num;
int tmp;
int cnt;
void bfs(int qr,int level){
	queue<int> q ;
	q.push(qr);
	mark[qr]=true;
	int last,rear=-8;
	int vlen=v[qr].size();
	if(!v[qr].empty())
		last=v[qr][vlen-1];
	while (!q.empty()&&level<lev){
		int np=q.front();
		q.pop();
		cnt++;
		if(np==last){
			level++;
			if(level==lev)
				break;
			if(!v[np].empty()){
				int lens=v[np].size();
				int m;
				for(m=lens-1;m>=0;m--){
					if(mark[v[np][m]]==false)
						break;
				}
				if(m>=0){
					last=v[np][m];
				}
				else{
					last=rear;
				}
			}
				//last=v[np][(v[np].size()-1)];
			else {
				if(rear==-8){
					continue;
				}
				last=rear;
			}
		}
		for(int i=0;i<v[np].size();i++){
			int nw=v[np][i];
			if(mark[nw]==false){
				mark[nw]=true;
				q.push(nw);
				rear=nw;
			}
		}
	}
}
int main(){
	freopen("in.txt","r",stdin);   
	while (scanf("%d%d",&n,&lev)!=EOF){
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&num);
			for(int j=0;j<num;j++){
				scanf("%d",&tmp);
				v[tmp].push_back(i);
			}
		}
		scanf("%d",&num);
		int query;
		for(int i=0;i<num;i++){
			scanf("%d",&query);
			cnt=-1;
			for(int i=1;i<=n;i++){
				mark[i]=false;
			}
			bfs(query,0);
			printf("%d\n",cnt);
		}

	}
	return 0;
}

