#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
bool judge(int x){
	if(x<=1)return false;
	int bound=(int)sqrt((double)x)+1;//后加的避免多次计算
	//	for(int i=2;i<=(int)sqrt((double)x)+1;i++){//错误 是小于 没有等于否则2和3 就会判断错误！！！！！！
	for(int i=2;i<bound;i++){
		if(x%i==0) return false;
	}
	return true;
}
int main(){
	int n;
	while (scanf("%d",&n)!=EOF){
		printf(judge(n)?"yes\n":"no\n");
	}
	return 0;
}
