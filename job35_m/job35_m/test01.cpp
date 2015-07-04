#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

int main(){
	int i=0;
	int a=5;
	int b=10;
	while (i<10){
		i++;
		if(a==5){
			if(b==8)
				continue;
		}
		if(a==5){
			if(b==10)
				break;
		}
	}
	printf("aaa");
	
	return 0;
}