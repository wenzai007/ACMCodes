
/*
   ����п���1����������ʽ��
   Ϊ�������ֵ�ʱ��
   ��ҲҪ��������
   ���⣬����û��С�������ڳ������ԣ�������һ��������!!��
   ������������ɡ�
   �ϴ��롣

   ��Ŀ���岻�Ǻ���ȷ��
   ��һЩ���������ɣ�
   1+2
   1
   0
   1+2     3/1
   ���Ӧ�������ǣ�

   3
   1
   0
   3
   3

   runtime error   ��ȥ ���߼��Ĵ���	
   //while (map[value][symtype.top()==0]){ map[4][1]��ѭ��
//*/  
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
#define  isnum(x)  x>='0'&&x<='9'?1:0

int map[5][5]={//���ȼ�    0#(�Լ��ӵĿ�ʼ��������)   1+  2-  3*  4/   map[i][j]Ϊ1 ����i��ջ�ڵ�j���ȼ��� 
	1,0,0,0,0,
	1,0,0,0,0,
	1,0,0,0,0,
	1,1,1,0,0,
	1,1,1,0,0,
};
char express[5000];// ���ʽ ����
stack <int> nums;// ����ջ  
stack <int> symtype;
void getnext(bool &thetype,int &value ,int &idx){//thetype ���ֻ��Ƿ���
	// value ֵ    idx  ���ʽ�±�  
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
	if(isnum(express[idx])){
		thetype=0;// is a  number 
		int tmpvalue=0;
		for(;isnum(express[idx])&&express[idx]!=0;idx++){
			tmpvalue*=10;
			tmpvalue+=express[idx]-'0';//��һ�����Ǽ�ȥ'0'
		}
		value=tmpvalue;
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
			if(thetype==0){//  ������ջ  it is a number 0 equal to false 
				nums.push(value);
				continue;
			}
			if(symtype.empty()||map[value][symtype.top()]==1){	
				symtype.push(value);			}
			else{
				//while (map[value][symtype.top()==0]){
				while (map[value][symtype.top()]==0){
					int res;
					int toptype=symtype.top();
					symtype.pop();
					int b=nums.top();
					nums.pop();
					int a=nums.top();
					nums.pop();
					switch (toptype){					case 1: res=a+b;
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
				symtype.push(value);
			}
			if(symtype.size()==2&&symtype.top()==0)break;
		}
		printf("%d\n",nums.top());
	}
	return 0;
}











