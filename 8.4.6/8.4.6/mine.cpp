#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>//有cmath 但是没有math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
using namespace std;


struct node{
	int a,b;
	bool operator <(const node B)const{
		return a<B.a;
	}
}cow[25008];
int n,t;

int main(){
	freopen("in.txt","r",stdin);   
	while(scanf("%d%d",&n,&t)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d%d",&cow[i].a,&cow[i].b);
		}
		sort(cow,cow+n);
		int right=0;
		int nowp=0;
		int begin=1;
		int tmp;
		int cnt=0;
		bool flag=false;
		while(right<t){
			for(int i=nowp;i<n;i++){
				if(cow[i].a<=begin&&cow[i].b>=begin){
					flag=true;
					if(cow[i].b>right)
						right=cow[i].b;
						tmp=i;
				}
				if(cow[i].a>begin){
					break;
				}
			}
			if(flag==false){
				printf("-1\n");
				return 0;
			}
			else
				flag=false;
			if(begin!=right+1){
				cnt++;
			}
			begin=right+1;//begin 在循环中不能变
			nowp=tmp;// nowp 在循环中不能变
		}
		printf("%d\n",cnt);
	}
	return 0;
}

