//另外一种方法是利用字符串的方法！ char-'0'
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
int a,b;
int a_digit[12],b_digit[12];
int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%d%d",&a,&b)!=EOF){
		int k=10;int a_i=0;int b_i=0;
		do{
			a_digit[a_i++]=a%10;
			a/=10;
		}
		while(a!=0);//注意有分号！！！
		a_i--;
		do {
			b_digit[b_i++]=b%10;
			b/=10;
		}
		while(b!=0);
		b_i--;
		int sum=0;
		for(int i=a_i;i>=0;i--){
			for(int j=b_i;j>=0;j--){
				sum+=a_digit[i]*b_digit[j];
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}





//effect
