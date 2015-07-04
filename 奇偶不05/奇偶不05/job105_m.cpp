#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>

#include<algorithm>
#include<math.h>>//有cmath 但是没有math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>
using namespace std;
//const int size=1080;//小了  2080 才够
const int size=2080;//小了  2080 才够
int indegree[size];
vector<int > v[size];
map <string,int> M;
char a[100],b[100];
queue <int> q;
int main(){
	freopen("in.txt","r",stdin);
	int n;
	while (scanf("%d",&n)!=EOF&&n){
		for(int i=1;i<=n*2;i++){//至多有2*n个人  
			indegree[i]=0;
			v[i].clear();
		}
		M.clear();
		while (!q.empty()) q.pop();
		int idx=1;
		while(n--!=0){
			scanf("%s%s",a,b);
			int ida,idb;
			if(M.find(a)==M.end()){
				M[a]=idx;
				ida=idx;
				idx++;
			}
			else ida=M[a];
			if(M.find(b)==M.end()){
				M[b]=idx;
				idb=idx;
				idx++;
			}
			else idb=M[b];
			indegree[idb]++;
			v[ida].push_back(idb);
		}
		int zero_num=0;
		for(int i=1;i<idx;i++){
			if(indegree[i]==0){
				zero_num++;
				q.push(i);
			}
		}
		if(zero_num!=1) {
			printf("No\n");
			continue;
		}
		int ans=1;
		while (!q.empty()){
			int nowp=q.front();
			q.pop();
			for(int i=0;i<v[nowp].size();i++){
				int tmp=v[nowp][i];
				indegree[tmp]--;
				if(indegree[tmp]==0){
					ans++;
					q.push(tmp);
				}
			}
		}
		if(ans==idx-1) printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
}

