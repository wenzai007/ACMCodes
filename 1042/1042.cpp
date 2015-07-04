#define for if(0); else for 
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>>//有cmath 但是没有math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
using namespace std;

int st[58], wk[58],order[58];
int k;
int main(){
	freopen("in.txt","r",stdin);   
	while (scanf("%d",&k)!=EOF){
		for(int i=1;i<=54;i++){
			st[i]=i;
		}
		for(int i=1;i<=54;i++){
			scanf("%d",&order[i]);
		}
		while (k--!=0){
			for(int i=1;i<=54;i++){
				wk[order[i]]=st[i];//执行一次
			}
			for(int i=1;i<=54;i++){
				st[i]=wk[i];//存回去
			}
		}
		for(int i=1;i<=54;i++){
			if(i!=1) printf(" ");
			int np=st[i];
			np--;
			int color=np/13;
			int num=np%13;
			switch (color){
			case 0:printf("S");
				break;
			case 1:printf("H");
				break;
			case 2:printf("C");
				break;
			case 3:printf("D");
				break;
			case 4:printf("J");
				break;
			}//end  switch
			printf("%d",num+1);
		}
		
	}
	return 0;
}

