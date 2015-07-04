/*
参考了  网上    28  / 30 
测试点	结果	用时(ms)	内存(kB)	得分/满分
0	答案正确	2	1024	16/16
1	答案正确	2	1148	2/2
2	答案错误	2	1144	0/2
3	答案正确	3	1144	3/3
4	答案正确	2	1024	2/2
5	答案正确	2	1144	2/2
6	答案正确	47	1656	3/3
这个    1038_2    我去  so easy

少考虑了一种极限的情况 就是全都是0的时候
题目中说的是  non negetive 
加上
yes
3月16日 14:46	 答案正确	30	1038	C++ (g++)	51	1536	wenzai007
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

const int size=100008;
int n;
char instr[10];
string buf[size];

bool cmp(const string &aa, const string &bb){
	string t1=aa+bb;
	string t2=bb+aa;
	return t1<t2;
}
int main(){
	freopen("in.txt","r",stdin);   
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%s",instr);
			buf[i]=instr;
		}
		sort(buf,buf+n,cmp);
		bool allzero=true;
		for(int i=0;i<n;i++){
			int ddd;
			sscanf(buf[i].c_str(),"%d",&ddd);
			if(ddd!=0)
				allzero =false;
		}
		if(allzero==true){
			printf("0\n");
			continue;
		}
		for(int i=0;i<n;i++){
			if(i==0){
				int dd;
				sscanf(buf[0].c_str(),"%d",&dd);
				printf("%d",dd);
			}
			else{
				printf("%s",buf[i].c_str());
			}
		}
		printf("\n");
	}
	return 0;
}

