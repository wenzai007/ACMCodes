//完全是再写一遍 大整数的 加 乘除模  初始化(两个 参数分别为整数以及字符串)   输入输出 这8个函数  
//8个函数 没有减法

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
#define  maxsize  1000
using namespace std;
struct  bigInteger{
	int digit[maxsize];
	int size;
	void init(){
		for(int i=0;i<maxsize;i++){
			digit[i]=0;
		}
		size=0;
	}
	void  set(char s[]){
		init();
		int L=strlen(s);
		int sum=0;
		for(int i=L-1,j=0,c=1;i>=0;i--){
			int value=s[i]-'0';
			sum+=value*c;
			c*=10;
			j++;
			if(j==4||i==0){
				digit[size++]=sum;
				j=0;  c=1; sum=0;
			}
		}
	}
	void set_int(int x){
		init();
		do{
			digit[size++]=x%10000;
			x/=10000;
		}
		while (x);
	}
	void output(){
		for(int i=size-1;i>=0;i--){
			if(i==size-1){
				printf("%d",digit[i]);
			}
			else printf("%04d",digit[i]);
			//此处出错导致第一次waprintf("\n");
		}
		printf("\n");
	}
	bigInteger  operator + (const bigInteger &b ){
		bigInteger c;
		c.init();
		int carry =0;
		for(int i=0;i<size||i<b.size;i++){
			int tmp=digit[i]+b.digit[i]+carry;
			carry=tmp/10000;
			c.digit[c.size++]=tmp%10000;
		}
		if(carry!=0)  c.digit[c.size++]=carry;
		return c;
	}
	bigInteger operator *(int x)const{
		bigInteger c;
		c.init();
		int carry=0;
		for(int i=0;i<size;i++){
			int tmp=digit[i]*x+carry;
			carry=tmp/10000;
			c.digit[c.size++]=tmp%10000;
		}
		if(carry){
			c.digit[c.size++]=carry;
		}
		return c;

	}
	bigInteger operator /(int x) const {
		if(x==0)printf(" you can not divide zero");
		bigInteger c;
		c.init();
		int rem=0;int q;
		for(int i=size-1;i>=0;i--){
			int tmp=(digit[i]+rem*10000);
			q=tmp/x;
			rem=tmp%x;
			c.digit[i]=q;
		}
		c.size=0;int id;
		for(id=size-1;id>=0;id--){
			if(c.digit[id]!=0)
				break;
		}
		c.size=id+1;
		return c;
	}
	int operator  %(int x)const{
		int rem=0;
		for(int i=size-1;i>=0;i--){
			int tmp=digit[i]+rem*10000;
			rem=tmp%x;
		}
		return rem;
	}
}a,weigh,sum;
char instr[1080];
char process[100000];
int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%s",instr)!=EOF){
		a.set(instr);
		int psize=0;
		memset(process,0,sizeof(process));
		do{
			int bi_dig=a%2;
			process[psize++]=bi_dig+'0';
			a=a/2;
		}
		while(!(a.size==0&&a.digit[0]==0));
		weigh.set_int(1);
		sum.set_int(0);
		for(int i=psize-1;i>=0;i--){
			if(process[i]=='1'){
				sum=sum+weigh;
			}
			weigh=weigh*2;
		}
		sum.output();

	}

	/*
	   a.set_int(11112222);
	   b.set_int(11113333);
	   m=a*2;
	   m=m/2;
	   a.set_int(1000801);
	   int a_rem=a%1000;
	   a.set(instr);
	   */
	return 0;
}








//effect
