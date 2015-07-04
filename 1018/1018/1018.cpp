//我的思路是用dfs  然后每一次都记录路径 最后处理 选择最少的路径
#define for   if(0);else for
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>//有cmath 但是没有math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
using namespace std;

const int size=528;
int curbike[size];//每个 车站的车数
struct edge{
	int  next;
	int time_cost;
};
vector<edge> v[size];
vector<int> path_work;// current use
vector<int> path_store[size];// strore the pathes 
bool mark[size];

int bike_cost[size];//dij算法的时候用到
int dis[size];//同样是dij算法用到的

int cmax,N,sp,M;
int r1,r2,tt;
int idx;//路径下标
int sum_time,sum_bike;//记录走到当前的总时间和总车辆数目
struct record{//用于最后的路径选择的时候进行排列
	int id;
	int sum_t;
	int sum_b;
	bool operator <(const record &b)const{
		if(sum_b==0&&b.sum_b!=0){
			return true;
		}
		else if(sum_b==0&&b.sum_b==0){
			return false;
		}
		else if(sum_b!=0&&b.sum_b==0){
			return false;
		}
		else if(sum_b^b.sum_b>0){//同号
			return abs(sum_b)<abs(b.sum_b);
		}
		else if(sum_b^b.sum_b){
			return  sum_b>0&&b.sum_b<0;
		}
	}

}rr[size];
void dij(){
	for(int i=0;i<=N;i++){
		dis[i]=-1;
	}//设置为每一个点都是不可达
	mark[0]=true;
	dis[0]=0;
	bike_cost[0]=0;//初试时刻 0节点处 设为没有车
	int newp=0;
	for(int i=1;i<=N;i++){//这里不是n-1次了  因为从0开始所以n次
		for(int j=0;j<v[newp].size();j++){
			int n_next=v[newp][j].next;
			int time=v[newp][j].time_cost;
			if(mark[n_next]==true) continue;
			if(dis[n_next]==-1||dis[n_next]>dis[newp]+time){
				dis[n_next]=dis[newp]+time;
				bike_cost[n_next]=bike_cost[newp]+curbike[n_next];
			}
			else if(dis[n_next]==dis[newp]+time&&bike_cost[n_next]<bike_cost[newp]+curbike[n_next]){
				bike_cost[n_next]=bike_cost[newp]+curbike[n_next];
			}
		}
		int min=0x7fffffff;
		for(int j=0;j<=N;j++){
			if(mark[j]==false&&dis[j]!=-1){
				if(dis[j]<min){
					min=dis[j];
					newp=j;
				}
			}
		}
		mark[newp]=true;
	}
}
void dfs(int p){
	if(p==sp){
		if(sum_time==dis[sp]){
			for(int i=0;i<path_work.size();i++){
				//path_store[idx][i]=path_work[i];//存储这个路径
				//不能这么写 应该是添加返回这个不是数组
				path_store[idx].push_back(path_work[i]);
			}
			rr[idx].id=idx;
			rr[idx].sum_t=sum_time;
			rr[idx].sum_b=sum_bike;
			idx++;
			return ;
		}
	}
	for(int i=0;i<v[p].size();i++){
		int next=v[p][i].next;
		int nt=v[p][i].time_cost;
		int nb=curbike[next];
		if(mark[next]==false){
			mark[next]=true;
			sum_time+=nt;
			int step=curbike[next]-(cmax/2);//能增加或者减少多少
			sum_bike+=step;
			path_work.push_back(next);
			dfs(next);
			mark[next]=false;
			sum_time-=nt;
			sum_bike-=step;
			path_work.pop_back();//注意没有参数
		}
	}
}


int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%d",&cmax)!=EOF){
		scanf("%d%d%d",&N,&sp,&M);
		int i;//用于for循环当中。。。为了  vc 的用处 同时也能
		//和 vc2008 相互兼容
		for(i=1;i<=N;i++){
			scanf("%d",&curbike[i]);
			v[i].clear();
			path_store[i].clear();
		}
		path_work.clear();
		for(i=0;i<M;i++){
			scanf("%d%d%d",&r1,&r2,&tt);
			edge tmp; tmp.time_cost=tt;
			tmp.next=r2; 
			v[r1].push_back(tmp);
			tmp.next=r1;
			v[r2].push_back(tmp);
		}
		for(i=0;i<=N;i++){//为了dij算法
			mark[i]=false;
		}
		dij();//找最短的路径和 最多的车辆和
		int shortest=dis[sp];
		for(i=0;i<=N;i++){//为了dfs 算法
			mark[i]=false;
		}
		mark[0]=true;
		idx=0;//为了记录不同路径的下标
		sum_time=0;
		sum_bike=0;
		path_work.push_back(0);
		dfs(0);
		sort(rr,rr+idx);
		int ist=rr[0].id;
		int sendorback=rr[0].sum_b;
		int realsend; int realback;
		if(sendorback<=0) {
			realsend=abs(sendorback);
			realback=0;
		}
		else {
			realsend=0;
			realback=sendorback;
		}
		printf("%d ",realsend);
		for(int i=0;i<path_store[ist].size();i++){
			if(i!=0) printf("->");
			printf("%d",path_store[ist][i]);
		}
		printf(" %d\n",realback);
		int aaa=0;

	}
	return 0;
}
/*
测试点
3月13日 18:05	 部分正确	24	1018	C++ (g++)	2	380	we
测试点	结果	用时(ms)	内存(kB)	得分/满分


0	答案正确	2	376	12/12
1	答案正确	2	368	2/2
2	答案正确	2	256	2/2
3	答案正确	2	380	2/2
4	答案正确	2	376	2/2
5	答案错误	2	380	0/2
6	答案正确	2	256	2/2
7	答案错误	1	256	0/3
8	答案正确	2	376	2/2
9	运行超时			0/1查看代码

*/

