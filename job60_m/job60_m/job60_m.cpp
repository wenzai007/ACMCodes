#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
struct bigInteger{
	int digit[1000];
	int size;
	void init(){
		for(int i=0;i<1000;i++){
			digit[i]=0;
		}
		size=0;
	}
	void set(char str[]){
		init();
		int lenth=strlen(str);
		int tmp=0;
		for(int i=lenth-1,c=1,j=0;i>=0;i--){
			tmp+=(str[i]-'0')*c;
			j++;
			c*=10;
			if(j==4||i==0){
				j=0;c=1;
				digit[size++]=tmp;
				tmp=0;
			}
		}
	}
	void output(){
		//for(int i=size-1;i>=0;i++){出错 看看i--
        for(int i=size-1;i>=0;i--){
			//if(i==0)printf("%d",digit[size]);
			//else printf("%04d",digit[size]);
			//写的什么JB！！！
			if(i==size-1)printf("%d",digit[i]);//开始写错了！！
			else printf("%04d",digit[i]);
		}
		printf("\n");
	}

	bigInteger operator + (const bigInteger &b) const{
		bigInteger c;
		c.init();
		int i,j,carry;
		//for(i=0,j=0,carry=0;i<size||j<b.size;i++,j++){
		for(i=0,carry=0;i<size||i<b.size;i++){
			c.digit[c.size]=digit[i]+b.digit[i]+carry;
			carry=c.digit[c.size]/10000;
			c.digit[c.size]%=10000;
			c.size++;
		}
		if(carry!=0){
			c.digit[c.size++]=carry;
		}
		return c;

	}
}a,b,c;
char a_str[1008],b_str[1008];
int main(){
	freopen ("in.txt","r",stdin);
	freopen ("out1.txt","w",stdout);
	while(scanf("%s%s",a_str,b_str)!=EOF){
		a.set(a_str); b.set(b_str);
		c=a+b;
		c.output();
	}
	return 0;
}

