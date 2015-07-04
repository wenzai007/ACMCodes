//主要用了  multimap 以及 strtok两个函数   节省了//不少时间  但是 学习的时间  很多！ 

//map<string,std::vector<string>> queryMap[5];  我又2b了 用这个啊！！
//多么简单啊！
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
#include<map>//包含了  multimap

#include<time.h>
using namespace std;

multimap<string,string> mp[6];

string outstr[5000];//用于输出之前的排序
char instr[200];
int N;
int M;
int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d",&N)!=EOF){
		gets(instr);
		for(int k=0;k<N;k++){
			string id;
			string key;
			for(int i=0;i<6;i++){
				gets(instr);//！！果然出现了这个问题啊 ！！
				//这样的话instr是一个空的字符串  因为scanf和gets混用的结果啊！！
				key=instr;
				if(i==0){
					id=instr;
				}
				if(i!=3){// keywords  we process last
					mp[i].insert(pair<string,string>(key,id));
				}
				else {//i  is 3  the keywords 
					//char small_key[20];
					/*
					while (sscanf(instr,"%s",small_key)!=EOF){
					mp[3].insert(make_pair(string(small_key),id));  这个是死循环！！
					*/
					char *pt;
					pt=strtok(instr," ");
					while(pt){
						mp[3].insert(make_pair(string(pt),id));
						pt=strtok(NULL," ");
					}

				}// else 
			}//for   i
		}// for k
		scanf("%d",&M);
		gets(instr);
		int checkid;
		string checkstr;
		for(int i=0;i<M;i++){
			//gets(instr);
			scanf("%d: ",&checkid);
			gets(instr);
			checkstr=instr;
			int cnt=mp[checkid].count(checkstr);
			printf("%d: %s\n",checkid,instr);
			if(cnt==0){
				printf("Not Found\n");
				continue;
			}
			int idx=0;//保存在  outstr
			multimap<string,string>::iterator it;
			for(it=mp[checkid].lower_bound(checkstr);it!=mp[checkid].upper_bound(checkstr);it++){
				outstr[idx++]=it->second;
			}
			sort(outstr,outstr+idx);//
			for(int mm=0;mm<idx;mm++){
				printf("%s\n",outstr[mm].c_str());
			}
		}
	}//while 
	return 0;
}

