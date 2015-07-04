#include<stdio.h>
int road[10001];

int main(){
	int L;
	int M;
	int left,right;
	while(scanf("%d%d",&L,&M)!=EOF){
		for(int i=0;i<L+1;i++){
			road[i]=1;
		}
		while (M--!=0){
			scanf("%d%d",&left,&right);
			for(int i=left;i<=right;i++){
				road[i]=0;
			}
		}
		int cnt=0;
		for(int i=0;i<=L;i++){
			if(road[i]==1){
				cnt++;
			}
		}
		printf("%d\n",cnt);

	}
}






//the middle  effect!
