#include<stdio.h>
#include<algorithm>
using namespace std;
int buf[1002];
int n;
int main(){
	while (scanf("%d",&n)!=EOF){
		if(n==-1) break;
		if(n==1) {
			int only;
			scanf("%d",&only);
			printf("%d\n",only);
			printf("-1");
			printf("\n");
		}
		else {
			for(int i=0;i<n;i++){
				scanf("%d",&buf[i]);
			}
			sort(buf,buf+n);
			printf("%d\n",buf[n-1]);
			for(int i=0;i<n-1;i++){
				if(i==0)printf("%d",buf[i]);
				else printf(" %d",buf[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
