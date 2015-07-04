#include<stdio.h>
int buf[101];
int main(){
	int n;
	int num;
	while (scanf("%d",&n)!=EOF&&n!=0){
		for(int i=0;i<101;i++)buf[i]=0;
		while (n--!=0){
			scanf("%d",&num);
			buf[num]++;
		}
		scanf("%d",&num);
		printf("%d\n",buf[num]);
	}
}
