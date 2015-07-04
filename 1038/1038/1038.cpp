/*
根本就运行不下去啊   死循环！！
网上的代码好简单     直接a+b<b+a 就好了！！shit 
见 1038_2  

死循环 的却是有的！！  大哥指点   加上一句 ix++；
然后   28/30 到手！！
测试点	结果	用时(ms)	内存(kB)	得分/满分
0	答案正确	2	1024	16/16
1	答案正确	2	1144	2/2
2	答案正确	3	1024	2/2
3	答案正确	2	1148	3/3
4	答案正确	2	1024	2/2
5	答案错误	2	1024	0/2
6	答案正确	40	1648	3/3

第五个测试点错了 不知道为什么  过了！
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

bool cmp(const string &aa, const string &bb){/*
											 技巧  此处为了不用判断a和b谁更长 在外边调用的时候
											 进行判断  此处不用判断！！默认b更长！
	*/
	string a=aa; string b=bb;
	char first=a[0];//第一个字符
	int la=a.size();int lb=b.length();
	int ix=0;
	while (ix<la&&ix<lb){//这里是死循环
	/*
	if(strcmp(a[ix],b[ix])!=0 )
	return strcmp(a[ix],b[ix])<0;
	strcmp 的参数只是 两个必须是const char *
	不可以是char  类型 否则编译不会通过的！！
		*/
		if(a[ix]!=b[ix]){
			return a[ix]<b[ix];
		}
		//下面少了一句  ix++所以是死循环 加上!!
		ix++;//加上这个就他妈的对了！！
	}
	if(la==lb){ return false;} //二者是相等的 返回false
	if(la>lb){//交换两个字符串
		string tmp=a;
		a=b;
		b=tmp;
	}
	
	//b比a长
	while(ix<b.size()&&b[ix]==first){
		ix++;
	}
	if(ix==b.size()) return false;//二者相等
	else {
		if(b[ix]<first) {
			if(la<lb)
				return false;
			else 
				return true;
		}
		else{ //就是b[ix]>first 的时候
			if(la<lb)
				return true;
			else 
				return false;
		}
	}
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
			if(ddd!=0)  allzero=false;
		}
		if(allzero==true){
			printf("0\n");
			continue;
		}
		else {
			int first;
			sscanf(buf[0].c_str(),"%d",&first);
			printf("%d",first);
			for(int i=1;i<n;i++){
				printf("%s",buf[i].c_str());
			}
			printf("\n");
		}

	}
	return 0;
}

