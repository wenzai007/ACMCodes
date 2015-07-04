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
const int maxsize=30;
int tree[maxsize];
int  findroot(int x){
	if(tree[x]==-1)return x;
	else {
		tree[x]=findroot(tree[x]);
		return tree[x];
	}
}
struct vertex{
	double x,y;
}buf_v[maxsize];

int transfer(char cc){
	return cc-'A'+1;
} 
struct edge {
	int a,b;
	int  distance;
	bool operator <(const edge &b)const{
		return distance<b.distance;
	}
}buf_e[maxsize*maxsize/2];

int n,k,dis,a,b;
char c,d;
int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d",&n)!=EOF&&n){
		for(int i=1;i<=n;i++)
			tree[i]=-1;
		int edge_id=0;
		for(int i=1;i<=n-1;i++){
			scanf(" %c\n",&c);
			a=transfer(c);
			scanf("%d",&k);
			for(int j=1;j<=k;j++){
				scanf(" %c",&d);
				b=transfer(d);
				scanf("%d",&dis);
				buf_e[edge_id].a=a;
				buf_e[edge_id].b=b;
				buf_e[edge_id].distance=dis;
				edge_id++;
			}
		}
		sort(buf_e,buf_e+edge_id);//开始写成buf_e+edge_id-1 导致出错
		int ans=0;
		for(int i=0;i<edge_id;i++){
			a=buf_e[i].a;
			b=buf_e[i].b;
			a=findroot(a);
			b=findroot(b);
			if(a!=b){
				tree[a]=b;
				ans+=buf_e[i].distance;
			}
		}
		int root_num=0;
		for(int i=1;i<=n;i++){
			if(tree[i]==-1) root_num++;
		}
		if(root_num==1)
			printf("%d\n",ans);
		else printf("no MST");
	}
	return 0;
}

