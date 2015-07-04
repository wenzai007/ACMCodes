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
int n,m,a,b;
int findroot(int x){
	if(tree[x]==-1)return x;
	else {
		int tmp=findroot(tree[x]);
		tree[x]=tmp;
		return tmp;
	}
}


int main(){
	freopen ("in.txt","r",stdin);
	while (scanf("%d",&n)!=EOF&&n){
		scanf("%d",&m);
		for(int i=1;i<=n;i++){
			tree[i]=-1;
		}
		for(int i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			a=findroot(a);
			b=findroot(b);
			if(a!=b){
				tree[a]=b;
			}
		}
		//int root_num=1;二货 初试必然应该设成0啊
		int root_num=0;
		for(int i=1;i<=n;i++){
			if(tree[i]==-1)  root_num++;
		}
		if(root_num==1)  
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

