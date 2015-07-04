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
const int maxsize=108;
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
struct edge {
	int a,b;
	double distance;
	bool operator <(const edge &b)const{
		return distance<b.distance;
	}
}buf_e[maxsize*maxsize/2];

int n,a,b;
double x,y;
int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++)
			tree[i]=-1;
		for(int i=1;i<=n;i++){
			scanf("%lf%lf",&buf_v[i].x,&buf_v[i].y);
		}
		int edge_id=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				double x_dif=buf_v[i].x-buf_v[j].x;
				double y_dif=buf_v[i].y-buf_v[j].y;
				double dis=sqrt(x_dif*x_dif+y_dif*y_dif);
				buf_e[edge_id].a=i;
				buf_e[edge_id].b=j;
				buf_e[edge_id].distance=dis;
				edge_id++;
			}
		}
		sort(buf_e,buf_e+n*(n-1)/2);
		double ans=0;
		for(int i=0;i<n*(n-1)/2;i++){
			int a=buf_e[i].a;
			int b=buf_e[i].b;
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
			printf("%.2lf\n",ans);
		else printf("no MST");
	}
	return 0;
}

