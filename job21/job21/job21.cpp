#include <stdio.h>
int main(){
	double a;
	while(scanf("%lf",&a)!=EOF){
		if(a==-1) break;
		printf("%lf",a);
	}
}
