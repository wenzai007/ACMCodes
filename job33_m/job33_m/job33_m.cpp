#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
//TLE 原因是用了递归。。。
int m,n;//输入m小于等于n
int sum;
/*递归是不行了，超时 那么试一试循环行不行
int subtotal(int m,int n){
	sum++;//m 必然不大于n
	if(2*m<=n){
		subtotal(2*m,n);
	}
	if((2*m+1)<=n){
		subtotal(2*m+1,n);
	}
	return sum;
}
*/
stack<int> ss;int p;
void subtotal(int m,int n,int &sum){
	p=m;
	while (p<=n ||!ss.empty()){
		if(p<=n){
			sum++;
			ss.push(p);
			p*=2;
		}
		else {
			int mm=ss.top();
			ss.pop();
			p=mm*2+1;
		}
	
	}
}
int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%d%d",&m,&n)!=EOF){
		if(m==0&&n==0)break;
		sum=0;
		while (!ss.empty()){
			ss.pop();
		}
		subtotal(m,n,sum);
		printf("%d\n",sum);
	}
	return 0;
}
