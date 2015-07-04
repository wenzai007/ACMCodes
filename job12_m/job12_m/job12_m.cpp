#include <stdio.h>
int people[201];
int book[201];
int main(){
	int n,m;
	int tmp;
	
	while (scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<201;i++){
		book[i]=0;
	    }
		for(int i=0;i<n;i++){
			scanf("%d",&tmp);
			people[i]=tmp;
			book[tmp]++;
		}
		for(int i=0;i<n;i++){
			if(book[(people[i])]==1){
				printf("BeiJu\n");
			}
			else printf("%d\n",book[people[i]]-1);
		}
	}
}











//for middle  effect!!
