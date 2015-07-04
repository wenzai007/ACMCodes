#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>//有cmath 但是没有math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>
using namespace std;
char sstr_c[50];
char lstr_c[100];
string lstr;
int main(){
	freopen("in.txt","r",stdin);
	gets(sstr_c);
	for(int i=0;i<strlen(sstr_c);i++){
		sstr_c[i]=tolower(sstr_c[i]);
	}//全变成小写
	int len=strlen(sstr_c);
    while(gets(lstr_c)){
		string b=lstr_c;string c=lstr_c;
		for(int i=0;i<b.size();i++){
			b[i]=tolower(b[i]);//可以直接用b[i]作为数组的名称！
		}
		int t=b.find(sstr_c,0);
		while(t!=string::npos){
			b.erase(t,len);
			c.erase(t,len);
			t=b.find(sstr_c,0);
		}
		t=b.find(' ',0);
		while(t!=string::npos){
			b.erase(t,1);
			c.erase(t,1);
			t=b.find(' ',0);
		}
	//printf("%s\n",c);//不能这么写 因为必须转化成
		//const char*类型才可以的  用c.c_str() 
		//但是只是在函数中这样用是可以的  如果复制的话不信
		//必须要用strcopy函数进行复制才可以  因为c_str()返回的是一个临时
		//指针  不能进行操作 貌似只能在一个函数的范围内进行操作否则是
		//无效的 返回的是一个野指针  见 3.7号的汉王总结
		printf("%s\n",c.c_str());
	}
	
	//如果要用scanf("%s")的话  没有删掉那个\n 的符号 尽管下次scanf(%s)
	//的时候读到的是一个非空的字符串但是再
	//用gets函数的时候就会读到一个空字符见王道p186
	//的时候A就要读到\n  比较麻烦！！
	return 0;
}

