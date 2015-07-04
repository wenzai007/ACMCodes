#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

int main(){
	freopen("in.txt","r",stdin);
	int a,b,k;
	int a_rem,b_rem;
	while(scanf("%d%d%d",&a,&b,&k)!=EOF){
		if(a==0&&b==0)break;
		 a_rem=a%(10*k);
		 b_rem=b%(10*k);
		 if(a_rem==b_rem) printf("-1\n");
		 else printf("%d\n",a+b);
	}
	return 0;
}







//effect
