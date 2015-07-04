#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
priority_queue <int , vector<int>,greater<int>  > qq;
int n;
int main(){
	freopen("in.txt","r",stdin);
	int tmp;
	int sum;
	while (scanf("%d",&n)!=EOF&&n){
		while (!qq.empty()) qq.pop();
		for(int i=0;i<n;i++){
			scanf("%d",&tmp);
			qq.push(tmp);
		}
		sum=0;
		while(qq.size()>1){
			int a=qq.top();
			qq.pop();
			int b=qq.top();
			qq.pop();
			qq.push(a+b);
			sum+=a+b;
		}
		printf("%d\n",sum);
	
	}
	return 0;
}
