/*
   ntime Error(ARRAY_BOUNDS_EXCEEDED) // array bounds exceed     ����Խ��
   Runtime Error(DIVIDE_BY_ZERO) //divisor is nil                                   ����
   Runtime Error(ACCESS_VIOLATION) //illegal memory access                  �Ƿ��ڴ��ȡ
   Runtime Error(STACK_OVERFLOW) //stack overflow                             ϵͳջ����
   ����������������������ģ�Ӧ�ò��
   AC�ˣ���ʵ��1019��Ŀһ����
   ���Ƕ���java���ԣ�һ��Ҫע�⡣
   1019��ÿ�����㹫ʽһ�С�
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
   �ڶ���ע��  ������ð���!!   //*/  
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
//#define  isnum(char x)  x>='0'&&x<='9'?1:0 //��������ʽ��ô �ò���char��
//���� ������ ������ 
// �ú�Ļ����� runtime error  ���õĻ�����wa

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
void getnext(bool &thetype,int &value ,int &idx){//ò�Ʊ���Ҫ���±�
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
			tmpvalue+=express[idx]-'0';//��һ�����Ǽ�ȥ'0'
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
			//if(symtype.empty()||map[value][symtype.top()==1]){//  ����� thetype ��Ȼ��1 ǰ����˹���
			//                         ��������ʲô������̫�����˰ɣ�
			else{  if(symtype.empty()||map[value][symtype.top()]==1){	
				symtype.push(value);//��continueô���о����� ��һ��
				//continue;//���Ĳ���continue�� ��Ϊֻ��һ�����Ļ���ô
				// #1#  ����ջ��ֻ��## Ӧ�ý������������˼�飡�� 
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
					switch (toptype){//��Ȼcase'1'���Ա���
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

