#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
struct bigInteger{
	int digit[1008];//能放4000位
	int size;
	void init(){
		for(int i=0;i<1008;i++){
			digit[i]=0;
		}
		size=0;
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
		//for(int i=size-1;i>=0;i++){//你妹的！ 写++习惯了是不是
			//是不是不会写他妈的--了
	    for(int i=size-1;i>=0;i--){
			if(i==size-1)printf("%d",digit[i]);
			else printf("%04d",digit[i]);
		}
		printf("\n");
	}
	//因为是阶乘所以返回自己是最好的  不要再重新返回一个big类
	//a =a*i; 所以之后就可以写成 a*i;  自动给自己赋值了；
	void operator *(int x){//见总结本105
		int i,carry;
		//for(i=0,carry=0;i<size;i++){//去掉i++
		for(i=0,carry=0;i<size;){
			int tmp=digit[i]*x+carry;
			carry=tmp/10000;
			//digit[size++]=tmp%10000;这就不对了要是想改变的话
			//那么应该不是size++ 而是i++
			digit[i++]=tmp%10000;
		}
		if(carry!=0) 
			digit[size++]=carry;//因为本题中x最大是1000所以这样就可以了
		//否则的话 应该考虑   位数再多一些
		//比如 如果索要成的整数最大是100000 那么应该把这些个
		//biginteger  变成  每六位一截取！！  
	}
}a;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int value;
	while(scanf("%d",&value)!=EOF){
		a.set(1);
		for(int i=1;i<=value;i++){
			a*i;
		}
		a.output();
	}
	return 0;
}

