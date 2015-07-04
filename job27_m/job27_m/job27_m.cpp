#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
//stack <char> opera;//程序莫名其妙的停止了!! 卧槽 应该是int啊
stack <int> opera;
stack <double> nums;
int map[5][5]={//分别为#号 + — * / ij代表要进去的比已经进去的
	1,0,0,0,0, 			//运算符的优先级  是大还是小，大的话就入栈
	1,0,0,0,0,   //小的话那么就  先计算前面的东西直到现在的运算符
	1,0,0,0,0,			//比栈顶的大
	1,1,1,0,0,
	1,1,1,0,0,
};// 定义的时候分号
char instr[220];
//搞一个读入的函数
void getnext(bool &optype,int &value,int &ipx){//引用类型为了传的不是值而是真正的地址处的变量
	//整个过程没有机会读到 ‘ ’空格字符 
	if(ipx==0&&opera.empty()){//但不对ipx进行处理 下一次仍然是0
		optype=true;
		value=0;
		return;
	}
	if(instr[ipx]==0){
		optype=true;
		value=0;
		return;
	}
	//if(instr[ipx]>'9'&&instr[ipx]<'0'){//！！！sb 你认为有这样的东西么&&
	if(instr[ipx]>'9'||instr[ipx]<'0'){
		optype=true;
		if(instr[ipx]=='+')value=1;
		else if(instr[ipx]=='-')value=2;
		else if(instr[ipx]=='*')value=3;
		else if(instr[ipx]=='/')value=4;
		ipx+=2;//直接跳过了空格 并且最后一个字符不可能是运算符
		//所以不用考虑是否是最后一个字符
		return;
	}
	if(instr[ipx]>='0'&&instr[ipx]<='9'){
		optype=false;
		int numstr=0;
		//for (;instr[ipx]!=' ';ipx++){//！！少考虑下一个没到头的情况
		for (;instr[ipx]!=' '&&instr[ipx]!=0;ipx++){
			numstr*=10;
			//numstr+=instr[ipx];！！ 没有减去字符串'0'
			numstr+=instr[ipx]-'0';
		}
		value=numstr;
		if(instr[ipx]!=0) ipx++;// 如果这个数字不是最后一个那么跳过空格
		return;//  否则的话 就直接返回  进而等待下一次进入函数 由上面的
		// 情况进行处理
	}
}
int main(){
	freopen("in.txt","r",stdin);

	//while (scanf("%s",instr)!=EOF){  这里错了 scanf遇到空格就截取
	//我们需要读取一整行！！！！
	while(gets(instr)){
		//if(instr[0]=='0')break;这就不对了 第一个操作数也可以是0啊
		while (!opera.empty()) opera.pop();
		while (!nums.empty()) nums.pop();
		if(instr[0]=='0'&&instr[1]==0) break;
		int idx=0;int value;bool optype;double res;
		while (1){
			getnext(optype,value,idx);
			if(optype==false){
				nums.push((double)value);
				//continue;
			}
			else {
				if (opera.empty()||map[value][opera.top()]==1){
					opera.push(value);
				}
				else {
					while(map[value][opera.top()]==0){
						int symboltmp=opera.top();
						opera.pop();
						double num1=nums.top();
						nums.pop();
						double num2=nums.top();
						nums.pop();
						switch(symboltmp){//注意是num2在前面
						case 1: res= num1+num2;
							break;
						case 2: res= num2-num1;
							break;
						case 3: res= num1*num2;
							break;
						case 4: res=num2/num1;
							break;

						}
						nums.push(res);
					}
					opera.push(value);

				}
				//if(opera.size()==2&&opera.top()=='0'){//程序不报错也不输出也
				//也不能看变量 因为不可能等于'0
				//只可能为0
			}
			if(opera.size()==2&&opera.top()==0)
				//opera.pop();
				//opera.pop();
				break;
		}
		//printf("%.2lf\n",res);
		printf("%.2lf\n",nums.top());
	}
	return 0;
}






















//effect


















//effect
