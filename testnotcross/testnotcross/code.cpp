

#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>

#include<queue>
#include<stack>
#include<map>
#include<vector>
//傻逼了  妈蛋的 没有加上using namespace
using namespace std;
int cnt,n;

struct node{
	int a,b;
	bool operator <(const  node &S ) const{
		return b<S.b;
	}
}buf[180];

int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d",&n)!=EOF&&n){
		for(int i=0;i<n;i++){
			scanf("%d%d",&buf[i].a,&buf[i].b);
		}
		cnt=0;
		sort(buf,buf+n);
		int end=-8;
		for(int i=0;i<n;i++){
			if(buf[i].a>=end){//
				end = buf[i].b;
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}

