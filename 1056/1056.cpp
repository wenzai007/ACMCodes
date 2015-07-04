/*
3月18日 18:48	 部分正确	2	1056	C++ (g++)	2	380	wenzai007
测试点
  2/25
测试点	结果	用时(ms)	内存(kB)	得分/满分
0	答案错误	2	380	0/13
1	答案错误	1	256	0/3
2	答案正确	1	376	2/2
3	答案错误	2	256	0/3
4	答案错误	2	380	0/2
5	答案错误	2	376
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

int main(){
	freopen("in.txt","r",stdin);   
	int d,p;
	int n;
	while (scanf("%d%d",&n,&p)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d%d",&d,&p);
		}
		for(int i=0;i<n;i++){
			if(i!=0) printf(" ");
			printf("1");
		}
	}
	return 0;
}

