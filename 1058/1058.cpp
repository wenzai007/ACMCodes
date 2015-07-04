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

struct n{
	int g,s,k;
}a,b,c;

int main(){
	freopen("in.txt","r",stdin);   
	while (scanf("%d.%d.%d%d.%d.%d",&a.g,&a.s,&a.k,&b.g,&b.s,&b.k)!=EOF){
		int carry=0;
		int sum=a.k+b.k;
		carry=sum/29;
		sum%=29;
		c.k=sum;
		sum=a.s+b.s+carry;
		carry=sum/17;
		sum%=17;
		c.s=sum;
		sum=a.g+b.g+carry;
		c.g=sum;
		printf("%d.%d.%d\n",c.g,c.s,c.k);
	}
	return 0;
}

