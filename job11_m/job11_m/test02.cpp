#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	for(int i=0;i<-8;i++){
		printf("ss");

	}
	int buf[]={1,4,3,6};
	sort(buf,buf-8);// 果然是这个地方的原因 导致的assertion failed！！
	printf(" daf");
	getchar();
		
}