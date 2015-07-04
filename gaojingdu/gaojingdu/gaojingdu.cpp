#define for if(0); else for
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>

#include<stack>
#include<queue>
#include<vector>
#include<map>
using namespace std;


struct big{
	int digit[1000];
	int size;
	void init(){
		for(int i=0;i<1000;i++){
			digit[i]=0;
			size=0;
		}
	}
	void set(char s[]){
		init();
		int len=strlen(s);
		int c=1,j=0,sum=0;
		for(int i=len-1;i>=0;i--){
			sum+=(s[i]-'0')*c;//  减去
			j++;
			c*=10;
			if(j==4||i==0){
				digit[size++]=sum;
				sum=0;
				j=0;
				c=1;
			}
		}
	}
	void set(int x){
		init();
		do{
			digit[size++]=x%10000;
			x/=10000;
		}
		while(x);
	}
	void output(){
		for(int i=size-1;i>=0;i--){
			//if(i!=0)  size-1
			if(i!=size-1)
				printf("%04d",digit[i]);
			else 
				printf("%d",digit[i]);
		}
		printf("\n");
	}
		
	big operator +(const big b)const{
		big c;
		c.init();
		int carry=0;
		for(int i=0;i<size||i<b.size;i++){
			int sum=digit[i]+b.digit[i]+carry;
			carry=sum/10000;
			c.digit[c.size++]=sum%10000;
		}
		if(carry!=0)
			c.digit[c.size++]=carry;
		return c;
	}
	big operator *(int x)const{//乘数x小于10000
		big c;
		c.init();
		int carry=0; int sum=0;
		for(int i=0;i<size;i++){
			sum=digit[i]*x+carry;
			carry=sum/10000;
			c.digit[c.size++]=sum%10000;
		}
		if(carry!=0)
			c.digit[c.size++]=carry;
		return c;
	}

	big operator /(int x)const {
		big c;
		c.init();
		int rem=0;int q;
		for(int i=size-1;i>=0;i--){
			q=(rem*10000+digit[i])/x;
			rem=(rem*10000+digit[i])%x;
			//c.digit[c.size++]=q;这里错了  结果必须是低位在前 高位在后这样才是统一
			//的存储方式！！！
			c.digit[i]=q;//这样写
		}
		c.size=0;int j;
		for(j=size-1;j>=0;j--){
			if(c.digit[j]!=0){
				c.size=j;//从高到低 第一个非零的位
				break;
			}
		}
		c.size++;
		return c;
	}
	int  operator %(int x)const{
		int rem=0;
		for(int i=size-1;i>=0;i--){
			//int q=(digit[i]+rem*10000)/x;
			rem=(digit[i]+rem*10000)%x;
		}
		return rem;
	}

}a,b,c;

int main(){a
	//freopen("in.txt","r",stdin);
	a.set("33445566");
	b.set(4);
	c.set("1122334488");
	big d=a+c;
	big e=a*4;
	big f=a/4;
	int g=a%4;
	g=c%4;
	d.output();
	e.output();
	f.output();
	return 0;
}