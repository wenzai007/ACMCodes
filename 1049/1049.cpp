/*
好像也不用 那么麻烦 ！  因为遍历一下   数一下 每一个数字
有 多少个1  然后累加  当然这种方法一定会超时的 
22/30  我已经很满意了。。。
测试点	结果	用时(ms)	内存(kB)	得分/满分
		0	答案正确	2	380	12/12
		1	答案正确	2	368	3/3
		2	答案正确	1	256	3/3
		3	答案正确	2	256	3/3
		4	运行超时			0/4
		5	答案正确	1	256	1/1
		6	运行超时			0/4

  剪枝怎么样  ？
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
int n;

int numof1(int a){
	int sum=0;
	do{
		if(a%10==1)
			sum++;
		a/=10;
	}
	while(a);
	return sum;
}
int main(){
	freopen("in.txt","r",stdin);   
	while (scanf("%d",&n)!=EOF){
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=numof1(i);
		}
		printf("%d\n",sum);
	}
	return 0;
}

