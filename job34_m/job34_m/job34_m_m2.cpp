//果然错了 题目并没有说是1 2 3 的输入
//而是可能是  任何的字符串
// 修改
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
int tree[1008];

int main(){
	freopen("in.txt","r",stdin);
	freopen("outmy.txt","w",stdout);
	int n;
	int deep_real;
	int deep_s;
	//printf("%lf\n",log(2.71828));//
	//printf("%lf\n",pow(2.0,2.1));
	while (scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&tree[i]);//又一次忘记&
		}
		scanf("%d",&deep_s);//忘记&！！！
		deep_real=(int)(log((double)n)/log(2.0)+1);
		if(deep_s>deep_real||deep_s<1){
			printf("EMPTY\n");
			continue;
		}
		//int count_out;
		int level_first=double(pow(2.0,deep_s-1));
		int level_last=level_first*2-1;
//		while(level_first<=n&&level_first<=level_last)
		for(int i=level_first;i<=level_last&&i<=n;i++){
			if(i==level_first)printf("%d",tree[i]);
			else printf(" %d",tree[i]);
		}
		printf("\n");
	}
	return 0;
}
