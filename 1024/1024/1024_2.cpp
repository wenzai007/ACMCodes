//答案正确 25分！

#define for if(0); else for 
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>>//有cmath 但是没有math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
using namespace std;

string reverse(const string s){
	string b;
	b=s;
	reverse(b.begin(),b.end());//注意参数是什么
	return b;
}

string addd(string a,string b){
	string c;
	
	int l=a.size();
	int carry=0;int sum=0;
	//for(int i=l-1;i>=0;i++){shit！！ 又有一次
	//单步调试根本就进不来  因为调试不走 定义变量
	//的语句 只走 执行语句 所以直接由于这个错误
	// string subscript out of range 运行错误！！
	for(int i=l-1;i>=0;i--){
		sum=a[i]+b[i]-'0'-'0'+carry;
		carry=sum/10;
		//c.insert(0,sum%10+'0');没有这个函数只能是iterator 和 char
		//或者是  int 和 string 的参数
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

