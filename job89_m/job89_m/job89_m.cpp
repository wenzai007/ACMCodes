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


int primes[]={2,3,5,7,11,13,17,19,23,29,31,37};//12 numbers
int ans[28];
bool mark[28];
int N;//必须在这里声明 否则的话  dfs函数就不认识N了
bool isprime(int x){
	for(int i=0;i<12;i++){
		if(primes[i]==x)return true;
		//return false ;尼玛 有这么判断素数的么？神马逻辑

	}
	return false;
}



void  dfs(int num){//num 是当前 的数字的下标
	if(num>1) {
		if(!isprime(ans[num]+ans[num-1]))
			return;
	}
	if(num==N){
		if(!isprime(ans[num]+ans[1]) ) return;//不输出 继续枚举
		for(int i=1;i<=N;i++){
			if(i!=1) printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
		//此处开始忘记加return了  居然也ac了因为下面的for循环中全是false 所以执行完for循环之后自动return 了 但是 正确的写法是加上return
		return ;
	}
	for(int i=2;i<=N;i++){
		if(mark[i]==false){
			mark[i]=true;
			ans[num+1]=i;
			dfs(num+1);//如果不行的话 就会 在for循环中找下一个解
			//mark[num+1]=false;我把一个完全没有意义的数给置为false
			mark[i]=false;
		}
	}
}

int main(){
	freopen("in.txt","r",stdin);
	int cnt=0;
	while (scanf("%d",&N)!=EOF){
		cnt++;
		printf("Case %d:\n",cnt);
		for(int i=1;i<=N;i++){
			mark[i]=false;
		}
		mark[1]=true;
		ans[1]=1;
		//dfs(2);我勒个去 这个直接就返回了
		//还枚举个屁啊！
		dfs(1);
		printf("\n");
	}
	return 0;
}

