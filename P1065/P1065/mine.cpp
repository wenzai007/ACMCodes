//这题应该也可以用动态规划  但是这里面我们就先用贪心的算法吧
//一次 ac 了关键是  明确了怎样的思想和流程  然后自己实现就好了
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

int c,n;
struct node{
	int l,r;
	bool flag;
	bool operator <(const node & B)const{
		if(l==B.l){
			return r<B.r;
		}
		else {
			return l<B.l;
		}
	}
}buf[5080];

int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%d",&c)!=EOF){
		for(int k=0;k<c;k++){
			scanf("%d",&n);
			for(int i=0;i<n;i++){
				scanf("%d%d",&buf[i].l,&buf[i].r);
			}
			sort(buf,buf+n);
			for(int i=0;i<n;i++){
				buf[i].flag=false;
			}
			int cnt=0;
			int tmp=buf[0].r;
			for(int i=0;i<n;i++){
				if(buf[i].flag==false){
					cnt++;
					tmp=buf[i].r;
				}
				for(int j=i+1;j<n;j++){
					if(buf[j].r>=tmp&&buf[j].flag==false){
						buf[j].flag=true;
						tmp=buf[j].r;
					}
				}
			}
			printf("%d\n",cnt);

		}
	}

	return 0;
}

