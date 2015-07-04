/*
   ntime Error(ARRAY_BOUNDS_EXCEEDED) // array bounds exceed     数组越界
   Runtime Error(DIVIDE_BY_ZERO) //divisor is nil                                   除零
   Runtime Error(ACCESS_VIOLATION) //illegal memory access                  非法内存读取
   Runtime Error(STACK_OVERFLOW) //stack overflow                             系统栈过载
   这个是我们评测机帮助里面的，应该差不多
   AC了，其实和1019题目一样。
   但是对于java而言，一定要注意。
   1019是每个计算公式一行。
   这个有可能1行有两个公式。
   为单个数字的时候
   ，也要输出结果。
   另外，就是没有小数。对于除法而言，相除结果一定是整数!!。
   最后输出结果即可。
   上代码。

   题目意义不是很明确。


   给一些测试用例吧：

   1+2
   1
   0
   1+2     3/1

   结果应该依次是：

   3
   1
   0
   3
   3
   第二个注释  你红你妹啊？!!   //*/  
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
//#define  isnum(char x)  x>='0'&&x<='9'?1:0 //？？？格式对么 用不用char？
//不行 不能有 类型名 
// 用宏的话就是 runtime error  不用的话现在wa

int map[5][5]={
	1,0,0,0,0,
	1,0,0,0,0,
	1,0,0,0,0,
	1,1,1,0,0,
	1,1,1,0,0,
};
char express[5000];
stack <int> nums;
stack <int> symtype;
void getnext(bool &thetype,int &value ,int &idx){//貌似必须要用下标
	if(idx==0&&symtype.empty()){
		thetype=1;
		value=0;
		return;
	}
	if(express[idx]==0){
		thetype=1;
		value=0;
		return;
	}
	if((express[idx])>='0'&&express[idx]<='9'){
		thetype=0;// is a  number 
		int tmpvalue=0;
		for(;(express[idx]>='0'&&express[idx]<='9')&&express[idx]!=0;idx++){
			tmpvalue*=10;
			tmpvalue+=express[idx]-'0';//又一次忘记减去'0'
		}
		value=tmpvalue;
		return;
	}
	else {
		thetype=1; // is a operator 
		switch (express[idx]){
			case '+': value=1;
					  break;
			case '-': value=2;
					  break;
			case '*': value=3;
					  break;
			case '/': value=4;
					  break;

		}
		idx++;
		return;
	}
}

int main(){
	freopen ("in.txt","r",stdin);
	while (scanf("%s",express)!=EOF){//  no break
		while(!nums.empty()) nums.pop();
		while(!symtype.empty()) symtype.pop();
		bool thetype; int value; int idx=0;
		while (1){
			getnext(thetype,value,idx);
			if(thetype==0){//  it is a number 0 equal to false 
				nums.push(value);
				continue;// can i do this?
			}
			//if(symtype.empty()||map[value][symtype.top()==1]){//  这里的 thetype 必然是1 前面把滤过了
			//                         请问这是什么？？？太粗心了吧？
			else{  if(symtype.empty()||map[value][symtype.top()]==1){	
				symtype.push(value);//能continue么？感觉可以 试一下
				//continue;//真心不能continue的 因为只有一个数的话那么
				// #1#  符号栈内只有## 应该结束反而跳过了检查！！ 
			}
			else{
				while (map[value][symtype.top()==0]){
					int res;
					int toptype=symtype.top();
					symtype.pop();
					int b=nums.top();
					nums.pop();
					int a=nums.top();
					nums.pop();
					switch (toptype){//竟然case'1'所以报错
						case 1: res=a+b;
								break;
						case 2: res=a-b;
								break;
						case 3: res=a*b;
								break;
						case 4: 
								res=a/b;
								break;

					}
					nums.push(res);

				}
			}
			symtype.push(value);
			}
			if(symtype.size()==2&&symtype.top()==0)break;
		}
		printf("%d\n",nums.top());
		}
		return 0;
	}











	//effect

