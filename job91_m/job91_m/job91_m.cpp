//另一种方法用了  stl  直接见  online、、几行就搞定了。。头文件 algorithm、
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>

#include<algorithm>
#include<math.h>

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>
using namespace std;
char word[8];
char ans[8];
bool mark[8];
int L;
void output(){
	printf("%s\n",ans+1);
	/*TLE 此处一开始 因为复杂度太高 寻址过多
	但是如果用 printf("%s")就好了  说明
	以后输出的时候如果考虑时间的话最好用
	字符串的输出！！！
	for(int i=1;i<=L;i++){
		printf("%c",ans[i]);
	}
	*/
	//printf("\n");
}
void dfs(int num){
	if(num==L+1){
		output();
		return;
	}
	for(int i=1;i<=L;i++){
		if(mark[i]==false){
			mark[i]=true;
			ans[num]=word[i];
			dfs(num+1);
			mark[i]=false;
		}
	}
}
int main(){//做完了看看大家有没有用非递归的写的！看谁用的非回溯法
	freopen("in.txt","r",stdin);
	while (scanf("%s",word+1)!=EOF){//这个是为了从下标1开始存储
		//int L=strlen(word);这个结果就是0
		L =strlen(word+1);//这个abcd的话结果就是4 但是下面要<=L
		for(int i=1;i<=L;i++){
			mark[i]=false;
		}
		//忘记初始化ans[]导致出错！！
		for(int i=1;i<8;i++)
			ans[i]=0;//置空！！
		dfs(1);
		printf("\n");
	}
	return 0;
}

