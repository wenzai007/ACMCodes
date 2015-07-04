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
int N;
int a,b,cost;
int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d",&N)!=EOF&&N){
		int M=N*(N-1)/2;
		for(int i=1;i<=N;i++){
			tree[i]=-1;
		}
		for(int i=1;i<=N*(N-1)/2;i++){
			scanf("%d%d%d",&buf_edge[i].a,&buf_edge[i].b,&buf_edge[i].cost);
		}
		sort(buf_edge+1,buf_edge+1+N*(N-1)/2);
		int sum=0;
		for(int i=1;i<=M;i++){
			a=findroot(buf_edge[i].a);
			b=findroot(buf_edge[i].b);
			if(a!=b){
				tree[a]=b;
				sum+=buf_edge[i].cost;
			}
		}
		int root_num=0;
		for(int i=1;i<=N;i++){
			if(tree[i]==-1)
				root_num++;
		}
		if(root_num==1)
			printf("%d\n",sum);
		else printf("can not form a MST");
	}
	return 0;
}

