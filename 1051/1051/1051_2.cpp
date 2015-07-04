/*
完全不会做  骗分也没骗到  h(n)=C(2n,n)/(n+1) (n=0,1,2,...)
这个是卡特兰树 虽然和这道题没什么关系  但是防止以后遇到
这道题  是上网看了才知道怎么做的  
见 1051 _2 
就是说  开始的时候
既然入栈必须是1 2 3 4 5 6 7 。。。n的入栈顺序 那么
读到当前的出栈序列  比如说 3  那么 他之前必须要有1 2 先入栈
才可以  当前读到的如果是6的话 那么当前所有未入栈的序列中
必须要 从未入栈的序列排序 从下到大直到6才能入栈的顺序
所以可以进行模拟  而当前  如果又是  序列是  4 2 1 。。出栈的
顺序的话 那么 由于 1 2 3 4 入栈 然后读到2  与栈顶不同
那么就一直tmp++  入栈肯定是死循环 因为tmp当前是5，6,7、、
所以一直到栈满  然后退出！  出现错误  技巧 维护一个tmp变量
初始值是1；  不断递增


算是模拟题吧, 根据给定的pop序列, 还原push 和 pop的过程,
因为一个pop sequence 只能对应一个唯一的push pop的操作过程
, 所以到最后能还原那么这个pop sequence是可行的, 否则不可
能, 比如: 3, 2, 1, 7, 5, 6, 4. 这个序列, 那么我们看第一
个3, 要pop出3, 那么肯定要先push 1, push 2, push 3, 
pop 3, 接下来看2, 此时栈顶确实是2那么 pop 2, 接下来1类
似, 好了下面一个是7, 那么我们必须要先push 4, push 5, 
push 6, push 7, 然后pop 7可以得到一个7, 接下来需要5,
但是此时栈顶元素是6, 所以这个sequence就是不可能了。 这
样的算法基本上市一个线性算法。



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

stack<int> s;
int M,N,K;
int p;
int buf[1080];
int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d%d%d",&M,&N,&K)!=EOF){
		while(!s.empty()) s.pop();
		while (K--){
			bool flag=true;
			int tmp=1;
			for(int i=0;i<N;i++){
				scanf("%d",&buf[i]);
			}
			for(int i=0;i<N;i++){
				int p=buf[i];
				if(flag==false) break;
				while(s.size()<=M&&flag){
					if(s.empty()||s.top()!=p){
						s.push(tmp++);
					}
					else {//也就是 s不空且s.top==p
						s.pop();
						break;//进行下一个
					}
					if(s.size()>M){//这是唯一的
				//普安断不合法的条件
						flag=false;
						break;
					}
				}
			}
			
			if(flag==false)
				printf("NO\n");
			//else if(!s.empty())不加也可以
		//	printf("NO\n");
			else printf("YES\n");
			while(!s.empty()) s.pop();
		}
	}
	return 0;
}