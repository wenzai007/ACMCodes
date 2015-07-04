//多出来的一道  oil 的题 
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>

#include<algorithm>
#include<math.h>

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>
using namespace std;
int output[3];
int n,x,y,z;
int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d",&n)!=EOF){
		int max=-1;
		scanf("%d%d%d",&x,&y,&z);
		for(int i=1;i<=9;i++){
			for(int j=0;j<=9;j++){
				int total=i*10000+x*1000+y*100+z*10+j;
				if(total%n==0){
					int per=total/n;
					if(per>max){
						max=per;
						output[0]=i;output[1]=j;output[2]=per;
					}
				}
			}
		}
		if(max==-1) printf("0\n");
		else printf("%d %d %d\n",output[0],output[1],output[2]);
	}
	return 0;
}

