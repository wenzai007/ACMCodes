#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
//指针不初始化的话  那么就会运行时出错！！

int main(){
	char * p=(char *)malloc(sizeof(char)*5);
	for(int i=0;i<10;i++){
		scanf("%s",p);
	}

	return 0;
}
