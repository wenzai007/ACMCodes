/*
22/25
ԭ������Ϊ  û����ѡ�Ŀγ�ҲҪ��� 
����   3  0


*/


#define for if(0); else for 
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>>//��cmath ����û��math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
using namespace std;

const int pnum=40080;
const int knum=3000;
//vector<int,string> v[knum];����ʲôjb �������ô�����ô
vector<string> v[knum];

int n,k;
char na[20];
int per;
int main(){
	freopen("in.txt","r",stdin);   
	while (scanf("%d%d",&n,&k)!=EOF){
		for(int i=1;i<=k;i++){
				v[i].clear();
			}
		while (n--!=0){
			scanf("%s",na);
			string t=na;
			scanf("%d",&per);
			int cna;
			while(per--){
				scanf("%d",&cna);
				v[cna].push_back(t);
			}

		}
		for(int i=1;i<=k;i++){
			//if(v[i].size()){
				sort(v[i].begin(),v[i].end());
				printf("%d %d\n",i,v[i].size());
				for(int j=0;j<v[i].size();j++){
					printf("%s\n",v[i][j].c_str());
				}
		//	}
		}
	}
	return 0;
}
