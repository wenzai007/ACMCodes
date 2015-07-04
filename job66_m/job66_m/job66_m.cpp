#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>// add graghs  
using namespace std;
int tree[1080];
int findroot(int x){
	if(tree[x]==-1) return x;
	else {
		int tmp=findroot(tree[x]);
		tree[x]=tmp;
		return tmp;
	}
}
int N,M;
int main(){
	freopen("in.txt","r",stdin);
	int a,b;
	while (scanf("%d",&N)!=EOF&&N){
		scanf("%d",&M);
		for(int i=1;i<=N;i++){
			tree[i]=-1;
		}
		while (M--){
			scanf("%d%d",&a,&b);
			a=findroot(a);
			b=findroot(b);
			if(a!=b)
				tree[a]=b;
		}
		int ans=0;
		for(int i=1;i<=N;i++ ){//n个连通分量要想连通的话 需要n-1条边 即一个树
			if(tree[i]==-1)
				ans++;
		}
		printf("%d\n",ans-1);


	}
	return 0;
}

