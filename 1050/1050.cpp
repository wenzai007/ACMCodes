/*
	初步想法   hash映射   字符  一共也就255个字符 
	所以  遇到一个字符那么就设置其为true  代表要删除
	删除的时候用数组  王道的模拟题中的算法
	就是  记录被删除的数目不断递增  当前删了k个
	然后被删的掠过 没被删的往前移动k个  相当于覆盖了被删除的
	元素  正确是正确 
	但是   卧槽
	这么简单的方法你为什么没想到、也是hash
	但是包括在第二行的就根本不打印就好了啊  2b
	int main()  
{  
    string a, b;  
    getline(cin, a);  
    getline(cin, b);  
    vector<bool> existed(MAX, false);  
    for (int i = 0; i < b.size(); ++i)  
        existed[b[i]] = true;  
    for (int i = 0; i < a.size(); ++i)  
        if (!existed[a[i]]) printf("%c",a[i]);  
    printf("\n");  
    return 0;  
}  

*/#define for if(0); else for 
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

const  int size=10008;
char ori[size];
char sec[size];
bool del[300];
int main(){
	freopen("in.txt","r",stdin);   
	while (gets(ori)){
		gets(sec);
		int len1=strlen(ori);
		int len2=strlen(sec);
		for(int i=0;i<len2;i++){
			del[sec[i]]=true;
		}
		int k=0;
		for(int i=0;i<len1;i++){
			if(del[ori[i]]==true){
				k++;
				continue;
			}
			else{
				ori[i-k]=ori[i];
			}
		}
		ori[len1-k]=0;//最后加上一个'\0'符号
		printf("%s\n",ori);
	}
	return 0;
}

