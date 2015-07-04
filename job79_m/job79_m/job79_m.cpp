//这道题其实是贪心的策略  找的时候  每次只找最近的点  如果进入点后出不来///了那么  只能输出没有路了  
//优先diji的   不管什么阵营 只不过最短路径上面方发现不合理则说这个解不存
//在  本体不是动态的寻找最优解 而是静态的找到最优的路径   照完了之后判断
//到底是不是  合理的  是就输出   否则 输出不是
//并不是边判断合不合理 在找最短路  是一种贪心的算法  他只求最优解、换句
//话说 优先考虑距离最短  不是优先考虑阵营的问题
//
//
//
//
//这道题的思路 ：  因为至多只能跨越一次阵营 所以 把从一到二的边
//变为单向变   然后不能从2到1  只能从1到2  就好了  但是这样的话 要处理的
//时候 如果用 邻接表的话就会比较麻烦一 点  （因为需要查找 ，但是也还好复///杂度大概是o（n+e）可以接受）
//另外一种方法就是   用临街矩阵 这样也是可以的而且处理任意链各个数的关系
//的和时候比较好  比较快  有时间的话 再用邻接矩阵实现以下
//2.另外   这个题也可以用 这个方法  找出
//第二种解法：根据所属阵营将原图分为A，B两个子图，在A图中求1到各点的最短距离，在B图中秋2到各点的最短距离，最后选择一条经过两个不同阵营的花费时间最小的一条路。


#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>

#include<algorithm>
#include<math.h>

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>
using namespace std;
//没必要   应该 改为更小的 负数而不是正无穷 #define inreach  0x7fffffff //为了将2到1的边改为不可达
const  int maxsize=680;
struct edge{
	int next;
	int t;
};
bool mark[maxsize];
int dis[maxsize];

int camp[maxsize];
 vector<edge> v[maxsize];//!! error C2143: 语法错误 : 缺少“;”(在“<”的前面) 
 //因为using namespace std;放在了后面！！
int n,m,a,b,t;  

///using namespace std;2b 竟然放在了后面

int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d",&n)!=EOF&&n){
		for(int i=1;i<=n;i++){
			v[i].clear();
			camp[i]=0;
			dis[i]=-1;
			mark[i]=false;
		}
		scanf("%d",&m);
		while (m--!=0){
			scanf("%d%d%d",&a,&b,&t);
			edge tmp;
			tmp.next=a;
			tmp.t=t;
			//vector[b].push_back(tmp);！写的什么
			v[b].push_back(tmp);
			tmp.next=b;
			//vector[a].push_back(tmp);
			v[a].push_back(tmp);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&camp[i]);
		}
		for(int i=1;i<=n;i++){
			if(camp[i]==2){
				//for(int j=0;j<=v[i].size();j++){//小于
				for(int j=0;j<v[i].size();j++){
					if(camp[v[i][j].next]==1){
						v[i][j].t=-8;
					}
				}
			}
		}
		// now   dijkstra
		int newp=1;
		dis[1]=0;
		mark[1]=true;
		for(int i=2;i<=n;i++){
			for(int j=0;j<v[newp].size();j++){
				int n_next=v[newp][j].next;
				int tt=v[newp][j].t;
				//if(mark[n_next]==true)continue ;考虑少了情况  tt虽然是-8但是下面的dis[n_next]仍然是-1 没有滤掉
				if(mark[n_next]==true||tt==-8)continue ;
				if(dis[n_next]==-1||dis[n_next]>dis[newp]+tt){
					dis[n_next]=dis[newp]+tt;
				}
			}
			int mindis=0x7fffffff;
			for(int j=1;j<=n;j++){
				if(mark[j]==true) continue;
				if(dis[j]<0)continue;//此处不是-1 而是小于零 因为考虑了
				//重新设置的单向边！！
				if(dis[j]<mindis){
					mindis=dis[j];
					newp=j;
				}
			}
			mark[newp]=true;
		}
		if(mark[2]==false) 
			printf("-1\n");
		else printf("%d\n",dis[2]);
	}
	return 0;
}

