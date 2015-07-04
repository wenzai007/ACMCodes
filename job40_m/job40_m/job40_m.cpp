#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
//编写一个函数判断是否是反序数
int a_digit[4],b_digit[4];
bool isreverse(int a,int b){
	int i=0;
	do{
		a_digit[i++]=a%10;
		a/=10;
	}
	while(a!=0);
	i=0;
	do{
		b_digit[i++]=b%10;
		b/=10;
	}
	while(b!=0);
	for(i=0;i<4;i++){
		if (a_digit[i]!=b_digit[3-i])
			return false;
	}
	return true;
}
int main(){
	int res[100];
	int idx=0;
	int a=1000;
	while(a<=1112){
		if(isreverse(a,a*9)){
			res[idx++]=a;//傻× 直接输出就行了啊  还存什么数组。。
		}
		a++;
	}
	for(int i=0;i<idx;i++){
		printf("%d\n",res[i]);
	}
	return 0;
}
