//先自己写的 然后对比一下别人和我的思路其实一样的，我的 是完全正确的
//其实就是我自己的思路  这算是一种贪心的算法

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

char ins[40];
int c_num;
int e_num;
struct node{
	int id;
	int t;
	int c;
	bool operator <(const node B)const {
		if(t*B.c!=c*B.t){
			return c*B.t>t*B.c;
		}
		else {
			return id<B.id;
		}
	}
}buf[1008];
int main(){
	freopen("in.txt","r",stdin);   
	sf("%d",&c_num);
	gets(ins);
	while(c_num--){
		sf("%d",&e_num);
		int n_id=1;
		for(int i=0;i<e_num;i++){
			buf[i].id=n_id++;
			sf("%d%d",&buf[i].t,&buf[i].c);
		}
		sort(buf,buf+e_num);
		for(int i=0;i<e_num;i++){
			if(i!=0)
				pf(" ");
			pf("%d",buf[i].id);
		}
		pf("\n");
		if(c_num!=0)
			pf("\n");
		gets(ins);//最后一个可能是空的！什么也读不到
	}
	return 0;
}

