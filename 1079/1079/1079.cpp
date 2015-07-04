/*
成功A掉   原来记录层数的时候是这么的简单我去
以前太傻逼了  那个就是先不管你是什么我先把当前的
节点的儿子们全都放在队列中去  然后呢 我在看当前的节点是不是本层的最后一个（endoflevel） 如果是的话那么吧endoflevel这个变量重新置为queue.back()这个函数也很吊  居然可以访问队列中的最后插入的元素、
我了个去 他妹的啊 ！！ 所以很简单的害怕个几把啊

*/
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>

#include<stack>
#include<queue>
#include<vector>
#include<map>
using namespace std;

const int num=100008;
vector <int> v[num];
int n;
double price,rate;
int  amo[num];
bool isleaf[num];
queue<int> q;
//不用visit数组 没有必要的  因为层次遍历是树不像图那样复杂

double bfs(){
	double total=0;
	int level=0;
	q.push(0);
	int np,endoflev;
	endoflev=0;
	while (!q.empty()){
		np=q.front();
		q.pop();
		for(int i=0;i<v[np].size();i++){
			q.push(v[np][i]);
		}
		if(isleaf[np]==true){
			total+=amo[np]*price*pow(double(1+rate/100),level);
		}
		if(np==endoflev){//此处少了一个判断条件
			//就是说如果队列是空的时候那么如果endoflev=q.back();的话会内存溢出 所以要判断的！
			if(q.empty())break;//加上这句就好了
			level++;
			endoflev=q.back();
		}
	}
	return total;
}
int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%d",&n)!=EOF){
		scanf("%lf%lf",&price,&rate);
		memset(isleaf,false,sizeof(bool)*num);
		memset(amo,0,sizeof(int)*num);
		while(!q.empty()) q.pop();
		for(int i=0;i<n;i++){
			v[i].clear();
		}
		int tn,tson,tamo;
		for(int i=0;i<n;i++){
			scanf("%d",&tn);
            if(tn==0){
				isleaf[i]=true;
				scanf("%d",&tamo);
				amo[i]=tamo;
				continue;
			}
			for(int j=0;j<tn;j++){
				scanf("%d",&tson);
				v[i].push_back(tson);
			}
		}
		double res=bfs();
		printf("%.1lf\n",res);
	}
	return 0;
}
