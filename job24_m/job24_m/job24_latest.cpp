#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;
int L,N;
int buf[660];

bool cmp(int a,int b) {
	return a>b;
}

int totaltmp=0;//存储的是当前的 和
// the most important function!

int main(){
	freopen ("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while (scanf("%d%d",&L,&N)!=EOF&&L){

		for(int i=0;i<N;i++) scanf("%d",&buf[i]);

		sort(buf,buf+N,cmp);
		//*这个部分去掉就对  否则就是wa
		totaltmp=0;
		for(int i=0;i<N;i++){
			totaltmp+=buf[i];
		}



		//*/
		//else{
		if(totaltmp>L){	
			int px;
			int tot=0;
			for(px=0;px<N;px++){
				tot+=buf[px];
				if(tot>=L)break;
			}
			if(tot==L){
				printf("%d\n",px+1);
			}
			else {
				printf("%d\n",px+1);
			}
		}
		else if(totaltmp<L){
			printf("impossible\n");
			continue;
		}
		else if(totaltmp==L){
			int ppp;
			for(ppp=0;ppp<N;ppp++){
				if(buf[ppp]<=0)break;
			}

			printf("%d\n",ppp);
			continue;
		}

		//}
	}
	return 0;
}