/*22fen


  string  改成  int 类型
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
	int next;
	char c;
};
map<int,node> mp;
vector<node> v1,v2;
//char  instr[10];
char instr2[10];
int instr;
int total;
int main(){
	freopen("C:\\vc6.0 fuck projects\\1032\\in.txt","r",stdin);
	while (scanf("%d",&instr)!=EOF){
		mp.clear();
		v1.clear();
		v2.clear();
		int  first=instr;
		scanf("%d",&instr);
		int second=instr;
		scanf("%d",&total);
		for(int i=0;i<total;i++){
			node tmp;
			scanf("%d",&instr);
			//string a=instr;
			tmp.addr=instr;
			char cc;
			scanf(" %c",&cc);
			tmp.c=cc;
			scanf("%d",&instr);
			//a=instr;
			tmp.next=instr;
			mp[tmp.addr]=tmp;
		}
		node nn;
		nn=mp[first];
		v1.push_back(nn);
		int nex=nn.next;
		while (true){
			if(nex==-1)break;
			nn=mp[nex];//下一个点
			v1.push_back(nn);
			nex=nn.next;
		}
		nn=mp[second];
		v2.push_back(nn);
		int nexx=nn.next;
		while (true){
			if(nexx==-1)break;
			nn=mp[nexx];//下一个点
			v2.push_back(nn);
			nexx=nn.next;
		}
		int s1=v1.size();
		int s2=v2.size();
		int  p1,p2;
		//if((s1-s2)<=0){看看这是什么逻辑！！
        if((s1-s2)>=0){
			p1=s1-s2;
			p2=0;
		}
		else{
			p1=0;
			p2=s2-s1;
		}
		while (v1[p1].next!=v2[p2].next){
			//最后一定是-1或者common
			p1++;
			p2++;
		}
		if(v1[p1].next==-1){
			printf("-1\n");
			continue;
		}
		printf("%05d\n",v1[p1].next);
	}
	return 0;
}