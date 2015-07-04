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
long long  hano(int n){//从int改为longlong 因为值可能大
	if(n==1) return 2;
	else {
		return 3*hano(n-1)+2;
	}
}
long long original_hano(int n){
	if(n==1) return 1;
	else return 2*original_hano(n-1)+1;

}
void move (char a ,char b){	
	printf("MOVE big plate from %c to---->%c\n",a,b);
}
void ori_hano(char a, char b,char c,int n){
	if(n==1) {
		move(a,c);
		return;
	}
	else{
		ori_hano(a,c,b,n-1);
		move(a,c);
		ori_hano(b,a,c,n-1);
	}
}


int main(){
	int n;
	char a='A',b='B',c='C';
	while (scanf("%d",&n)!=EOF){
		int ans=hano(n);
		printf("%lld\n",ans);//注意lld才是  不是ld
		printf("%d\n",original_hano(4));
		ori_hano(a,b,c,4);
	}
	return 0;
}

