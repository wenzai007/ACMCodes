//其实就是简单的字符串排序的问题吧  
//应该不用 %2d 一个一个的来输入   直接用strcmp函数应该就是可以的了
//小于0的时候前面比后面小  因为时间的格式就是一个字符串
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
using namespace std;
struct p{
	char id[20];
	char  start[10];
	char  end[10];
}pp[1000];//题目不明确   没告诉最大值
bool cmp1(p p1,p p2){
	return strcmp(p1.start,p2.start)<0;
}
bool cmp2(p p1,p p2){
	return strcmp(p1.end,p2.end)<0;
}
int main(){
	freopen("in.txt","r",stdin);
	int n;
	while (scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%s%s%s",pp[i].id,pp[i].start,pp[i].end);
		}
		sort(pp,pp+n,cmp1);
		char earliest[22];
		//strcopy(earliest,pp[0].id);函数名称写错了！！
		strcpy(earliest,pp[0].id);
		sort(pp,pp+n,cmp2);
		char latest[28];
		strcpy(latest,pp[n-1].id);
		//latest=pp[n-1].id;
		printf("%s %s\n",earliest,latest);

	}
	return 0;
}

