#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>// add graghs  
using namespace std;
const int size=1008;
int tree[size];
int T,N,M,a,b;
int findroot(int x){
	if(tree[x]==-1)return x;
	else {
		int tmp=findroot(tree[x]);
		tree[x]=tmp;
		return tmp;
	}
}
int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d",&T)!=EOF){
		while (T--){
			scanf("%d%d",&N,&M);
			for(int i=1;i<=N;i++){
				tree[i]=-1;
			}
			while(M--){
				scanf("%d%d",&a,&b);
				a=findroot(a);
				b=findroot(b);
				if(a!=b)
					tree[a]=b;
			}
			int ans=0;
			for(int i=1;i<=N;i++){
				if(tree[i]==-1)
					ans++;
			}
			printf("%d\n",ans);
			
		}
	}
	return 0;
}

