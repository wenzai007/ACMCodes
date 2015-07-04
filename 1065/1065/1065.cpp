//开始  只有12分     原因  1  没有用  tmp存储 
// 2   判断的时候没有用<=0  而只是<0 不行的
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
long long a,b,c,tmp;
int n;
int main(){
	freopen("in.txt","r",stdin);   
	//a=(long long)pow(2.0,63)-1;
	while (scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a,&b,&c);
			tmp=a+b;
			printf("Case #%d: ",i);
			//if(a>0&&b>0&&tmp<0){//擦 真奇怪啊 用tmp就对不用就
				//错了
			if(a>0&&b>0&&tmp<=0){
				printf("true\n");
				continue;
			}
			//if(a<0&&b<0&&tmp>0){
			if(a<0&&b<0&&tmp>=0){
				printf("false\n");//少了一个continue 12分
				//他妈的找了半个小时
				continue;
			}
			if(tmp>c)
				printf("true\n");
			else
				printf("false\n");
		}
	}
	return 0;
}

