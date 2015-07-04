//仍然是畅通工程  建立两个边的 结构体数组  （一个是已经建好的）
//另一个是未建设的    先遍历一下看是否连通  是则输出0
//否则  排序未建成的  依次选择  直到便利为完成   在输出
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
struct  edge_finish{
	int a,b;
	int cost;
}buf_finish[maxsize*maxsize/2];

struct edge_empty{
	int a,b;
	int cost;
	//bool operator <(const edge_empty &b){//！这里错了啊  少了一个const 结果出错 本地可以、
		//但是 提交的时候出错
	bool operator <(const edge_empty &b)const{
		return cost<b.cost;
	}
}buf_empty[maxsize*maxsize/2];

int findroot(int x){
	if(tree[x]==-1)return x;
	else {
		int tmp=findroot(tree[x]);
		tree[x]=tmp;
		return tmp;
	}
}

int N;
int a,b,cost,judge;

int main(){
	
	freopen ("in.txt","r",stdin);
	while (scanf("%d",&N)!=EOF&&N){
		for(int i=1;i<=N;i++){
			tree[i]=-1;
		}
		int finish_id=0,empty_id=0;
		for(int i=0;i<N*(N-1)/2;i++){
			scanf("%d%d%d%d",&a,&b,&cost,&judge);
			if(judge==0){
				buf_empty[empty_id].a=a;
				buf_empty[empty_id].b=b;
				buf_empty[empty_id].cost=cost;
				empty_id++;
			}
			else{
				buf_finish[finish_id].a=a;
				buf_finish[finish_id].b=b;
				buf_finish[finish_id].cost=cost;
				finish_id++;
			}
		}
		for(int i=0;i<finish_id;i++){
			a=findroot(buf_finish[i].a);
			b=findroot(buf_finish[i].b);
			if(a!=b){
				tree[a]=b;
			}
		}
		int root_num=0;
		/*
		for(int i=1;i<=N;i++){
			if(tree[i]==-1)
				root_num++;
		}
		if(root_num==1){
			printf("0\n");
			continue;
		}
		*/
		//wa 忘记了排序啊！！ 不排序的话不是最小生成树了 所以wa
		sort(buf_empty,buf_empty+empty_id);
		int ans=0;
		for(int i=0;i<empty_id;i++){
			a=findroot(buf_empty[i].a);
			b=findroot(buf_empty[i].b);
			cost=buf_empty[i].cost;
			if(a!=b){
				tree[a]=b;
				ans+=cost;
			}
		}
		root_num=0;
		for(int i=1;i<N;i++){
			if(tree[i]==-1)
				root_num++;
		}
		if(root_num>1)
			printf("no MST");
		else printf("%d\n",ans);
	}
	return 0;
}

