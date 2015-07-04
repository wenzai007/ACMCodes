
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<algorithm>
#include<math.h>

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>
using namespace std;
const  int maxsize=128;

int tree[maxsize];
int findroot(int x){
	if(tree[x]==-1)return x;
	else{
		tree[x]=findroot(tree[x]);
		return tree[x];
		/*上面写的对不对？
		int tmp=findroot(tree[x]);
		tree[x]=tmp;
		return tmp;
		*/
	}

}
struct edge{
	int a,b;
	int cost;
	bool operator <(const edge &b)const{
		return cost<b.cost;
	}
} buf_edge[maxsize*maxsize/2];
int N,M;
int a,b,cost;
int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d",&N)!=EOF&&N){
		scanf("%d",&M);//m是点的个数

		for(int i=1;i<=N;i++){
			tree[i]=-1;
		}
		int e_idx=0;
		for(int i=0;i<N;i++){
			scanf("%d%d%d",&buf_edge[e_idx].a,&buf_edge[e_idx].b,&buf_edge[e_idx].cost);
			e_idx++;
		}
		sort(buf_edge,buf_edge+e_idx);
		int sum=0;
		for(int i=0;i<N;i++){
			a=findroot(buf_edge[i].a);
			b=findroot(buf_edge[i].b);
			if(a!=b){
				tree[a]=b;
				sum+=buf_edge[i].cost;
			}
		}
		int root_num=0;
		for(int i=1;i<=M;i++){
			if(tree[i]==-1)
				root_num++;
		}
		if(root_num==1)
			printf("%d\n",sum);
		else printf("?\n");
	}
	return 0;
}

