//yes  ac  only in one time !!
#include<stdio.h>
#include<stdlib.h>

#include<string>
#include<string.h>
#include<ctype.h>

#include<math.h>
#include<algorithm>

#include<queue>
#include<stack>
#include<map>
#include<vector>
using namespace std;
bool findit;//有没有找到
int change[16]={
	
	51200,58368,29184,12544,  
     35968,20032,10016,4880,  
     2248,1252,626,305,  
     140,78,39,19  
};

char pic[4][4];
int cur;
int step;
void dfs(int block,int dep){//从第0块开始变化
	if(dep==step){//  outlet_1
		if(cur==0||cur==65535){
			findit=true;
		}
		return;
	}
	if(block>=16||findit)//之所以加上这个findit是因为为了尽快的结整个dfs的过程  outlet_2
		//另外 如果翻到了16的话  那么后面就不要再去执行了！
		return;
	cur=cur^change[block];//turn over
	dfs(block+1,dep+1);
	cur=cur^change[block];// recover !!  sure  this is to recover from begining
	dfs(block+1,dep);
}
int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%s",&pic[0])!=EOF){
		for(int i=0;i<3;i++){
			scanf("%s",&pic[i+1]);
		}
		cur=0;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				cur<<=1;
				if(pic[i][j]=='b')
					cur+=1;
			}
		}
		findit=false;
		for(step=0;step<=16;step++){
			dfs(0,0);
			if(findit==true) break;
		}
		if(step>16)
			printf("Impossible\n");
		else 
			printf("%d\n",step);
	}
	return 0;
}

/*: 1. error C2872: “find”: 不明确的符号
1>        可能是“d:\documents\visual studio 2008\projects\p1753\p1753\p1753_mine_dfs.cpp(16) : bool find”
1>        或       “d:\软件\c++vs2008\vc\include\algorithm(72) : _InIt std::find(_InIt,_InIt,const _Ty &)”
1>d:\documents\visual studio 2008\projects\p1753\p1753\p1753_mine_dfs.cpp(35) : error C2872: “find”: 不明确的符号
1>        可能是“d:\documents\visual studio 2008\projects\p1753\p1753\p1753_mine_dfs.cpp(16) : bool find”
1>        或       “d:\软件\c++vs2008\vc\include\algorithm(72) : _InIt std::find(_InIt,_InIt,const _Ty &)”

能说什么呢   这个算法中竟然也有find这个函数 这个我了个草
*/
