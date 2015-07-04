//写了一半 发现可以用并查集的  
//而且关键的一点是！！！！！
//我没必要  边读入边处理的！！我完全可以把case中的输入数据
//先存起来  然后再每个  case 下面再处理啊！！！！！
//这回就对了嘛！！！
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
using namespace std;

const int size=1080;//边最多也就size *size/2
int tree[size];
int in_edge[size*size/2][2];//保存输入的所有的边  先不处理

int findroot(int x){//  并查集的找祖先函数  
	//if(tree[x]==-1) return -1;这是什么JB啊？？
	if(tree[x]==-1) return x;
	else {
		int tmp=findroot(tree[x]);
		tree[x]=tmp;
		return tmp;
	}
}

int  N,M,K;

int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d",&N)!=EOF){
		scanf("%d%d",&M,&K);
		for(int i=0;i<M;i++){
			scanf("%d%d",&in_edge[i][0],&in_edge[i][1]);
		}
		int tocheck;
		while (K--!=0){
			scanf("%d",&tocheck);
			for(int i=1;i<=N;i++){
				tree[i]=-1;
			}
			for(int i=0;i<M;i++){
				if(in_edge[i][0]==tocheck||in_edge[i][1]==tocheck)
					continue;
				int a=in_edge[i][0];
				int b=in_edge[i][1];
				a=findroot(a);
				b=findroot(b);
				if(a!=b){
					tree[a]=b;
				}
			}
			int ans=0;
			for(int i=1;i<=N;i++){
				if(tree[i]==-1)
					ans++;
			}
			printf("%d\n",ans-2);
		}
	}
	return 0;
}

