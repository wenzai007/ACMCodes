/*
����֮����һ���ո����

����������Ϊ�� 
Youwant someone to help you
You
I
�����滻,û������һֱ��ǹ��

���� �ҵķ�����ֱ̫�鷳��  ��online�������
ֱ�����е��ַ���ȫ������ �ո񲻾ͺ��˰�����
Ȼ�������ʱ���ٰ����˵Ŀո�ȥ������
*/
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>>//��cmath ����û��math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>
using namespace std;
char instr[108];
char old[108];
char change[108];
int main(){
	freopen("in.txt","r",stdin);
	while (gets(instr)){
		string a=instr;
		gets(old);//sizeof �Ǿ�̬������Ĵ�С ֻ��strlen�����ַ����ĳ���
		//string oold=old;
		//oold+=' ';//youyou  ��ʱ�����滻you  ����Ҫ�ÿո�ģ���
	//	oold.insert(0,1,' ');
		gets(change);
	//	string cchange=change;
	//	cchange+=' ';
	//	cchange.insert(0,1,' ');
			//��һ�� ��û��insert���������������е� ��
		int t=a.find(old,0);
		while (t!=string::npos){
		//ȥ���õ�  ��д������
			bool changeornot=false;
			if(t==0){
				if(t==a.size()-strlen(old))
					changeornot=true;
				else if(a[t+strlen(old)]==' ')
					changeornot=true;
			}
			else {
				if(t==a.size()-strlen(old)){
					if(a[t-1]==' ') 
						changeornot=true;
				}
				else if(a[t-1]==' '&&a[t+strlen(old)]==' ')
					changeornot=true;

			}
			if(changeornot==true) {
				a.replace(t,strlen(old),change);
				t=a.find(old,t);
			}
			else{
				t=a.find(old,t+strlen(old));
			}

			
			
			
			
			
			
			
			
			/*
				//if(t==0&&a[strlen(old)==' ']) changeornot=true;//�ַ���һ��������󣡣���ܳn���ˣ�@��
			if(t==0){
				
			}
			if(t==0&&a[strlen(old)]==' ') changeornot=true;
			else if(t==a.size()-strlen(old)&&a[t-1]==' ')changeornot=true;
			else if(t!=0&&t!=a.size()-1&&a[t-1]==' '&&a[t+strlen(old)]==' ')changeornot=true;
			else if(t==0&&t==a.size()-strlen(old))changeornot=true;
			//������仰�᲻��Խ���أ�����ȷԽ���ˣ���
						*/
		}
		printf("%s\n",a.c_str());//c_str()���ص���const char *����z
	}
	return 0;
}

