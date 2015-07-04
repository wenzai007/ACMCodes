/*
一开始我把它们从小到大排序，认为这样就最小了。。但是我没有考虑例如这样的数据：
6 6 7 11.
一直加下去是61，而如果先加前两个，再加7和11，最后加剩下的两个，这样算出来是60。
原因就是当加上前两个数字之后，变成了7 11 12，这时候应该加7和11的，而我加了7和12，此处多了1.
其实就是哈弗曼数中的所有方块节点的总和而已了，也就是说那个是哈弗曼树木的
wpl吧
然后就是上优先队列了。。
 *
 *
 * 
 *    
 * */

#define for if(0); else for 
#define pf printf
#define sf  scanf
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
/*  开始的错误写法
int main(){
	freopen("in.txt","r",stdin);   

int n;
int buf[5008];
int mybuf[5008];
	while(sf("%d",&n)!=EOF&&n){
		for(int i=0;i<n;i++){
			sf("%d",&buf[i]);
		}
		sort(buf,buf+n);
		int sum=buf[0];
		int id=0;
		for(int i=1;i<n;i++){
			sum+=buf[i];
			mybuf[id++]=sum;
		}
		int tot=0;
		for(int i=0;i<id;i++){
			tot+=mybuf[i];
		}
		pf("%d\n",tot);
	}
	return 0;
}
*/

priority_queue <int,vector<int>,greater<int>  > q;
int n;
int tmp;
int main(){
	freopen("in.txt","r",stdin);
	while(sf("%d",&n)!=EOF && n){
		while(!q.empty())
			q.pop();
		for(int i=0;i<n;i++){
			sf("%d",&tmp);
			q.push(tmp);
		}
		int sum=0;
		while(q.size()>1){
			int a=q.top();
			q.pop();
			int b=q.top();
			q.pop();
			q.push(a+b);
			sum+=a+b;
		}
		pf("%d\n",sum);
	}
	return 0;
}


