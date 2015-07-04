#include<stdio.h>
#include<algorithm>//not sure about the spelling
using namespace std;
int n;
int num[101];
int main(){
	while (scanf("%d",&n)!=EOF){
		if(n==-1)break;
		for(int i=0;i<n;i++){
			scanf("%d",&num[i]);
		}
		sort(num,num+n);
		for(int i=0;i<n;i++){
			//if(i!=0) printf(" ");
			printf("%d ",num[i]);
		}
		printf("\n");
		
	}

		
}
