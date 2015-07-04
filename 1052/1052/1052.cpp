/*
  看了网上的  说
  算法很简单就是排序算法, 调用现成的sort之类的库就行了, 注意两点”
(1) 给定的node不一定都是在同一个链表上 (这就是为什么我们需要head node 
的address)
(2) head node address 可能为-1,小心segment fault.
(3) 如果链表是空，应当输出”0 -1″.

这道题对于key排序是显而易见的。要注意input输入的点，不一定
都在list上。题目中” total number of nodes in memory“不是
total number of nodes in list.不过建议出题的大神将”where 
N is the total number of nodes in the list “将其中的N 改为
M 会让题目意思更为清晰。
如果题目意思清楚了，那就使用father list array去记录list，
就可以了。（不要暴力查找了，会超时）

  那么我看就把 其中的在list上的挑出来就好了啊！见_2
24/25
测试点	结果	用时(ms)	内存(kB)	得分/满分
	0	答案正确	2	372	15/15
	1	答案正确	2	256	3/3
	2	答案正确	2	376	3/3
	3	答案正确	93	4580	3/3
	4	内存超限			0/1

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
	int addr;
	int v;
	int next;
	bool operator<(const node &b) const{//最后开始的时候少了
		//一个const  pat报错  vc 没有报错
		return v<b.v;
	}
}buf[100080];
vector <node> vec;
int va,ad,ne;
int n;
int first;
int main(){
	freopen("in.txt","r",stdin);   
	while (scanf("%d%d",&n,&first)!=EOF){
		node tmp;
		vec.clear();
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&ad,&tmp.v,&tmp.next);
			tmp.addr=ad;
			buf[ad]=tmp;
		}

		tmp=buf[first];
		while (tmp.next!=-1){
			vec.push_back(tmp);
			tmp=buf[tmp.next];
		}
		vec.push_back(tmp);
		sort(vec.begin(),vec.end());
		
		
		for(int i=0;i<vec.size()-1;i++){
			vec[i].next=vec[i+1].addr;
		}
		vec[vec.size()-1].next=-1;
		int ss=vec.size();
		printf("%d %05d\n",vec.size(),vec[0].addr);
		for(int i=0;i<vec.size()-1;i++){
			printf("%05d %d %05d\n",vec[i].addr,vec[i].v,vec[i].next);
		}
		printf("%05d %d %d\n",vec[ss-1].addr,vec[ss-1].v,vec[ss-1].next);
	}
	return 0;
}

