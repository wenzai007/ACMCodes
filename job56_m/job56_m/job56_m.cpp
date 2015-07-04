#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;

int main(){
	freopen ("in.txt","r",stdin);
	int n;
	int elem;
	while (scanf("%d",&n)!=EOF&&n){
		for(int i=0;i<n;i++){
			scanf("%d",&elem);
			double real=(double)sqrt((double)elem);
			int trim=(int)sqrt((double)elem);
			int total=0;
			for(int j=1;j<real;j++){
				if(elem%j==0)total++;
			}
			if(real==trim)
				printf("%d\n",total*2+1);
			else printf("%d\n",total*2);

		}
	}
	return 0;
}
