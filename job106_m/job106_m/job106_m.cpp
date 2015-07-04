/*
单词之间用一个空格隔开

若样例输入为： 
Youwant someone to help you
You
I
则不能替换,没看清题一直中枪！

另外 我的方法简直太麻烦了  看online这个方法
直接所有的字符串全都加上 空格不就好了啊！！
然后输出的时候再把两端的空格去掉！！
*/
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
using namespace std;
char instr[108];
char old[108];
char change[108];
int main(){
	freopen("in.txt","r",stdin);
	while (gets(instr)){
		string a=instr;
		gets(old);//sizeof 是静态的数组的大小 只有strlen才是字符串的长度
		//string oold=old;
		//oold+=' ';//youyou  的时候不能替换you  所以要用空格的！！
	//	oold.insert(0,1,' ');
		gets(change);
	//	string cchange=change;
	//	cchange+=' ';
	//	cchange.insert(0,1,' ');
			//查一下 有没有insert函数啊！！！！有的 ！
		int t=a.find(old,0);
		while (t!=string::npos){
		//去你妹的  重写！！！
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
				//if(t==0&&a[strlen(old)==' ']) changeornot=true;//又犯了一次这个错误！！！艹n次了！@！
			if(t==0){
				
			}
			if(t==0&&a[strlen(old)]==' ') changeornot=true;
			else if(t==a.size()-strlen(old)&&a[t-1]==' ')changeornot=true;
			else if(t!=0&&t!=a.size()-1&&a[t-1]==' '&&a[t+strlen(old)]==' ')changeornot=true;
			else if(t==0&&t==a.size()-strlen(old))changeornot=true;
			//上面这句话会不会越界呢？？的确越界了！！
						*/
		}
		printf("%s\n",a.c_str());//c_str()返回的是const char *类型z
	}
	return 0;
}

