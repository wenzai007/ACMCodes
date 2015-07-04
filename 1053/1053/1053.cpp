/*
其实 就是dfs搜索 保存路径的
那么树的话    只保存 父节点的vector就好了  
不用保存 叶子节点  的 也就是说叶子节点的 vector是0的

  答案正确  30分！
*/
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


struct node{
	int num;
	int w;
//	bool operator <(const node &b){//第三次了 傻逼
	bool operator <(const node &b)const {
		return w>b.w;//递减排序
	}
}tree[108];
vector <node> v[108];

bool mark[108];
int n,par,weigh;

vector<int> sto[108];
vector<int> work;
int np,k,ch;
int sum;  int idx;

void dfs(int nowp){
	if(sum==weigh&&v[nowp].size()==0){
		for(int i=0;i<work.size();i++){
			sto[idx].push_back(work[i]);
			//idx++;这里写错了啊   尼玛的用了多少个vector啊
		}
		idx++;
		return;
	}
	else if(sum>weigh) return;//这里千万别忘了剪枝否则会超时
	for(int i=0;i<v[nowp].size();i++){
		int num=v[nowp][i].num;
		int w=v[nowp][i].w;
		if(mark[num]==false){
			sum+=w;
			work.push_back(w);
			mark[num]=true;
			dfs(num);
			sum-=w;
			//work.pop_back;开始的时候这个没加括号
			//这个bug找了一个小时
			work.pop_back();
			mark[num]=false;
		}
	}
	
}
int main(){
	freopen("in.txt","r",stdin);   
	for(int i=0;i<108;i++){
		tree[i].num=i;		
	}
	while (scanf("%d%d%d",&n,&par,&weigh)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&tree[i].w);
		}
		node tmp;
		for(int i=0;i<par;i++){
			scanf("%d%d",&np,&k);
			for(int j=0;j<k;j++){
				scanf("%d",&ch);
				tmp=tree[ch];
				v[np].push_back(tmp);
				//printf("%d %d",v[np][j].num,v[np][j].w);
			}
			if(k>1){
				sort(v[np].begin(),v[np].end());
			}
		}
		for(int i=0;i<n;i++){
			mark[i]=false;
		}
		sum=tree[0].w;
		idx=0;
		mark[0]=true;
		work.push_back(tree[0].w);
		dfs(0);
		for(int i=0;i<idx;i++){
			for(int j=0;j<sto[i].size();j++){
				if(j!=0) printf(" ");
				printf("%d",sto[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

