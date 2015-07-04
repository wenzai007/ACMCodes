/*
这道题  我的思路使用map  map<string,vector<int>>
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


//map<string,vector<int>> mp;
/*上面这样写的后果  19个error  因为写的不够分开
error C2146: syntax error : missing ',' before 
identifier 'mp'
C:\vc6.0 fuck projects\1039\1039.cpp(24) : error C2065: 
'mp' : undeclared identifier
C:\vc6.0 fuck projects\1039\1039.cpp(24) : error C2143: 
syntax error : missing '>' before ';'
*/
map < string,vector<int> > mp;//把它们都分开 并且map是小写的
int N,K;
char name[8];
int cour,c_num;
int main(){
	freopen("in.txt","r",stdin);   
	while (scanf("%d%d",&N,&K)!=EOF){
		while (K--!=0){
			scanf("%d%d",&cour,&c_num);
			for(int i=0;i<c_num;i++){
				scanf("%s",name);
				string na=name;
				if(mp.find(na)==mp.end()){
					vector<int>v;
					v.push_back(cour);
					mp.insert(make_pair(na,v));
					//或者  mp[na]=v;
				}
				else{
					mp[na].push_back(cour);
				}
			}//for
		}//少了一个括号 导致运行结果错误

		for(int i=0;i<N;i++){
			scanf("%s",name);
			string na=name;
			printf("%s ",name);
			int ss=mp[na].size();
			printf("%d",ss);
			if(ss==0) {
				printf("\n"); 
				continue;
			}
			printf(" ");
			//sort(mp[na].begin(),mp[na].end());//看一下到底是不是默认排序的呢？
			// 我猜应该不是的
			for(int j=0;j<ss;j++){
				if(j!=0) printf(" ");
				printf("%d",mp[na][j]);
			}
			printf("\n");
		}
	}

	return 0;
}

