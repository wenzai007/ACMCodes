#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
int node[1008];
int n;
int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&node[i]);
		}
		int idx=0;
		int sum=0;
		while(idx<n-1){
			sort(node+idx,node+n);
			sum+=node[idx]+node[idx+1];
			node[idx+1]+=node[idx];
			idx++;
		}
		printf("%d\n",sum);
	}
	return 0;
}
