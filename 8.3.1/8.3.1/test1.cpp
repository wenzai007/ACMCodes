#include<stdio.h>

int c;
void fun(int x){
	static int b=1;
	int d=b++;
	if(x>10)
		return;
	else{
		c+=d;
		fun(x+1);
	}
}
int main(){
	static int a=12;
	a++;
	a=100;
	fun(1);
	//static int a=12;//不行  重复定义
	return 0;
}
