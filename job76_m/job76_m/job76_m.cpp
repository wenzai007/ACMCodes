#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>

#include<algorithm>
#include<math.h>

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>
using namespace std;
int ans[108][108];
int a,b,cost;
int N,M;
int main(){
	freopen ("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while (scanf("%d%d",&N,&M)!=EOF){
		if(!N&&!M) break;
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				ans[i][j]=-1;//用-1 表示无穷！！并且可能多个负数相加
				//所以不能负数的值太大  防止溢出
			}
		}
		for(int i=0;i<M;i++){
			scanf("%d%d%d",&a,&b,&cost);
			ans[a][b]=cost;
			ans[b][a]=cost;
		}
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				printf("%2d ",ans[i][j]);
			}
			printf("\n");
		}
		for(int k=1;k<=N;k++){
			printf("the k is: %2d\n",k);
			for(int i=1;i<=N;i++){
				for(int j=1;j<=N;j++){
					if(i==j){
						printf("%2d ",ans[i][j]);
						continue;
					}

					if(ans[i][k]<0||ans[k][j]<0){
						printf("%2d ",ans[i][j]);
						continue;
					}
					if(ans[i][j]<0||ans[i][k]+ans[k][j]<ans[i][j])
						ans[i][j]=ans[i][k]+ans[k][j];
					printf("%2d ",ans[i][j]);
				}
				printf("\n");
			}
		}
		printf("%d\n",ans[N][1]);
	}
	return 0;
}

