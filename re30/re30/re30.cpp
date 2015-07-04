#define for if(0); else for
#include <stdio.h>
#include<stdlib.h>

#include<string>
#include<string.h>
#include<ctype.h>

#include<math.h>
#include<algorithm>

#include<stack>
#include<queue>
#include<vector>
#include<map>
using namespace std;

priority_queue<int ,vector<int>,greater() > q;
int n;
int tmp;
int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d",&n)!=EOF){
		while(!q.empty()) q.pop();
		for(int i=0;i<n;i++){
			scanf("%d",&tmp);
			q.push(tmp);
		}
		int ans=0;
		while (q.size()!=1){
			int a=q.top();
			q.pop();
			int b=q.top();
			q.pop();
			ans+=(a+b);
			q.push(a+b);
		}
		//ans+=q.top();
		printf("%d\n",ans);
	}

	return 0;
}