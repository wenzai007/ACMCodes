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
//用邻接表来存储  这个因为只存储节点编号就可以了 所以没有必要用结构体
//另外 这种拓扑排序的话 一般都是要用一个数组来保存所有的 节点的入度的
//完成之后我要试验一下 是不是有的一些indgree的数组中的值变成了负数！！
//要注意节点是从0开始编号的
int indegree[180];
vector <int> v[180];
queue <int> qq;
int n,m; int a,b;
int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d",&n)!=EOF&&n){
		scanf("%d",&m);
		for(int i=0;i<n;i++){
			indegree[i]=0;
			v[i].clear();
		}
		while (!qq.empty()) qq.pop();
		for(int i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			indegree[b]++;
			//v[a].push_back[b];:push_back”: 函数调用缺少参数列表；请使用“&std::
			v[a].push_back(b);
		}
		for(int i=0;i<n;i++){
			if(indegree[i]==0)
				qq.push(i);
		}
		int cnt=0;
		//while (!qq.empty){“!”: 绑定成员函数表达式上的非法操作
		while (!qq.empty()){
			int newp=qq.front();
			qq.pop();
			cnt++;
			for(int i=0;i<v[newp].size();i++){//此处一会改一下语句
				//然后看一下效果！
				indegree[v[newp][i]]--;//虽然是可能成为负数但是这个是必
				//必须的 因为如果不减 后面的每一个发现是0都入队 那么可能
				//无限循环了！！当然也可以在后面减 等等。应该不会出现负
				//数  因为既然是0入度了  那么后面的边不可能再指向它了啊
				//！！ 所以最少就是0了！
				if(indegree[v[newp][i]]==0) 
					qq.push(v[newp][i]);
			}
		}
		if(cnt==n) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

