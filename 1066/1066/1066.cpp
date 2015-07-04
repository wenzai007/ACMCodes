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

int buf[10008];
int N,M;
vector<int> v;//保存序号
int total;
bool mark[10008];
void dfs(int num){
	if((total+buf[num])==M){
		v.push_back(num);
		total+=buf[num];
		return;
	}
	else if((total+buf[num])>M){
		return;
	}
	else {
		for(int i=num;i<N;i++){
			//mark[i]=true;
			v.push_back(i);
			total+=buf[i];
			for(int j=i+1;j<N;j++){
				dfs(j);
				if(total==M) return;
				if(total>M) continue;
			}
			v.pop_back();
			total-=buf[i];
		}
	}
}
int main(){
	freopen("in.txt","r",stdin);   
	while (scanf("%d%d",&N,&M)!=EOF){
		v.clear();
		for(int i=0;i<N;i++){
			scanf("%d",&buf[i]);
		}
		for(int i=0;i<N;i++){
			mark[i]=false;
		}
		sort(buf,buf+N);
		total=0;
			
		dfs(0);
		if(v.empty()){
			printf("No Solution\n");
			continue;
		}
		for(int i=0;i<v.size();i++){
			if(i!=0) printf(" ");
			printf("%d",buf[v[i]]);
		}
		printf("\n");

	}
	return 0;
}

