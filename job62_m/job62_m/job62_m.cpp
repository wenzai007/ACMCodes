//全面的联系  高精度整数的输入输出函数  以及加减乘除求模 5个函数
//基本涵盖了所有的函数  这道题搞定了之后再做  前面落下的一道高精度的
//题目！！
//默写一遍后 不要调试   而是  对着书看答案 这个没法挑食 
//太多了  有错误的话  就是不好弄的了
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
	void set(int x){
		init();
		do{
			int tmp=x%10000;
			digit[size++]=tmp;
			x/=10000;
		}
		while(x);
	}
	void output(){
		for(int i=size-1;i>=0;i--){
			if(i==size-1)printf("%d",digit[i]);
			else printf("%04d",digit[i]);
		}
	}
	bigInteger operator +(const bigInteger &b)const{
		bigInteger  c;
		c.init();
		int carry=0;
		int i;
		for(i=0;i<size||i<b.size;i++){
			int tmp=digit[i]+b.digit[i]+carry;
			carry=tmp/10000;
			tmp%=10000;
			c.digit[c.size++]=tmp;
		}
		if(carry!=0){
			c.digit[c.size++];
		}
		return c;
	}
	bigInteger  operator *(int x)const {
		bigInteger c;
		c.init();
		int i,carry=0;
		for(i=0;i<size;i++){
			int tmp=digit[i]*x+carry;
			carry=tmp/10000;
			tmp%=10000;
			//c.digit[size++]=tmp;//出错了！！！
			c.digit[c.size++]=tmp;
		}
		if(carry!=0)  
			//c.digit[size++];//出错了
			c.digit[c.size++];
		return c;
	}
	bigInteger  operator /(int x) const{
		bigInteger c;
		c.init();
		int i,carry=0;
		for(i=size-1;i>=0;i--){
			int tmp=digit[i]+carry*10000;
			int q=tmp/x;
			carry=digit[i]%x;
			c.digit[i]=q;
		}
		//这里少了一句话！！！！！！！下面这句
		c.size=0;//为了 考虑特殊情况  如果商是零的情况。
		for(int j=0;j<maxsize;j++){
			if (c.digit[j]!=0)
				c.size=j;
		}
		c.size++;
		return c;
	}
	int operator %(int x)const {
		int rem=0;int i;
		for(i=size-1;i>=0;i--){
			int tmp=digit[i]+rem*10000;
			//rem=tmp%10000;//看清了%的是什么
			rem=tmp%x;
		}
		return rem;
	}
}sum,weigh,a;
char instr[10000];// binary  maybe
char outstr[10000];// to print and store
int M,N;
int main(){
	freopen ("in.txt","r",stdin);
	freopen ("out.txt","w",stdout);
	while(scanf("%d%d",&M,&N)!=EOF){
		scanf("%s",instr);
		sum.set(0);
		weigh.set(1);
		int L=strlen(instr);
		int each_dig;
		char cc;
		//for(int i=L-1;i>=0;i++){//又一次！！
		for(int i=L-1;i>=0;i--){
			//有前眼没后眼char c=instr[i];
			cc=instr[i];
			if(cc>='0'&&cc<='9') each_dig=cc-'0';
			else each_dig=cc-'A'+10;
			//sum=sum+each_dig*weigh;//错了 乘法两个数放反了
			sum=sum+weigh*each_dig;
			//2.试一试能不能用 sum+= 好像不行的吧   
			weigh=weigh*M;
		}
		int size_out=0;
		do{
			each_dig=sum%N;
			if (each_dig>=0&&each_dig<=9) cc=each_dig+'0';
			else cc=each_dig+'a'-10;
			outstr[size_out++]=cc;
			sum=sum/N;
		}
		while (!(sum.size==1&&sum.digit[0]==0));
		for (int k=size_out-1;k>=0;k--){
			printf("%c",outstr[k]);
		}
		printf("\n");
	} 
	return 0;
}

