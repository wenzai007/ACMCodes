//����ȷ 25�֣�

#define for if(0); else for 
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

#include<time.h>
using namespace std;

string reverse(const string s){
	string b;
	b=s;
	reverse(b.begin(),b.end());//ע�������ʲô
	return b;
}

string addd(string a,string b){
	string c;
	
	int l=a.size();
	int carry=0;int sum=0;
	//for(int i=l-1;i>=0;i++){shit���� ����һ��
	//�������Ը����ͽ�����  ��Ϊ���Բ��� �������
	//����� ֻ�� ִ����� ����ֱ�������������
	// string subscript out of range ���д��󣡣�
	for(int i=l-1;i>=0;i--){
		sum=a[i]+b[i]-'0'-'0'+carry;
		carry=sum/10;
		//c.insert(0,sum%10+'0');û���������ֻ����iterator �� char
		//������  int �� string �Ĳ���
		c.insert(c.begin(),sum%10+'0');
	}
	if(carry){
		c.insert(c.begin(),carry+'0');
	}
	return c;
}

bool ispalin (const string a){
	int l=a.length(),ll=a.length();
	l-=1;
	l/=2;
	bool isor=true;
	for(int i=0;i<=l;i++){
		if(a[i]!=a[ll-1-i])
			isor=false;
	}
	return isor;
}
string aa,bb,cc;
int k;
char instr[20];
int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%s",instr)!=EOF){
		aa=instr;
		scanf("%d",&k);
		int cnt=0;
		bool flag=false;
		while (true){
			if(ispalin(aa)){
				flag=true;
				break;
			}
			cnt++;
			if(cnt>k) break;
			bb=reverse(aa);
			aa=addd(aa,bb);
		}
		if(flag==false){
			printf("%s\n",aa.c_str());
			printf("%d\n",k);
		}
		else {
			printf("%s\n%d\n",aa.c_str(),cnt);
		}
	}
	return 0;
}

