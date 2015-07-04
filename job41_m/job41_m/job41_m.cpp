#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
//写一个函数判断他的平方是否是对称
int digit[9000];
bool isSymmetry(int a){
	int idx=0;
	a*=a;
	do{
		digit[idx++]=a%10;
		a/=10;
	}
	while(a);//也就是a不为零 简便！！
	for(int i=0;i<=(idx-1)/2;i++){
		if(digit[i]!=digit[idx-1-i])
			return false;
	}
	return true;
}
int main(){
	for(int m=0;m<256;m++){
		if(isSymmetry(m)){
			printf("%d\n",m);
			//printf("%d  %d\n",m,m*m);
		}
	}
	return 0;
}
