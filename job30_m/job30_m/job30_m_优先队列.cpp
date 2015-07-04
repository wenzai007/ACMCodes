#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
//int node[1008];
//priority_queue<<int>,vector<int>,greater<int>> qq;
//声明都错了
//priority_queue<int,vector<int>,greater<int>> qq;
//上面这个提交的时候说是compile Error 因为两个>>太近了
//  中间要有空格 才行 否则他以为是输出。。。
int n;
int tmp;
int main(){
	//freopen("in.txt","r",stdin);
	
	while(scanf("%d",&n)!=EOF){
		while(!qq.empty()){qq.pop();}
		for(int i=0;i<n;i++){
			scanf("%d",&tmp);
			qq.push(tmp);
		}
		int idx=0;
		int sum=0;
		while (qq.size()>1){
			int a=qq.top();
			qq.pop();
			int b=qq.top();
			qq.pop();
			qq.push(a+b);
			sum+=a+b;
		}

		/*
		while(idx<n-1){
			sort(node+idx,node+n);
			sum+=node[idx]+node[idx+1];
			node[idx+1]+=node[idx];
			idx++;
		}
		*/
		printf("%d\n",sum);
	}
	return 0;
}
