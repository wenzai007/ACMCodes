//为了测试一下   用sort排序的话 会不会超时
#include<stdio.h>
#include<algorithm>
using namespace std;
int buf[1000000];
bool ppp(int a,int b){
	return a>b;
}
int main(){
	int n;
	int m;
	int tmp;
	while (scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&tmp);
			buf[i]=tmp;
		}
		sort(buf,buf+n,ppp);
		for(int i=0;i<m;i++){
			if(i==0) printf("%d",buf[i]);
			else printf(" %d",buf[i]);
		}
		printf("\n");

	}
}
