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

char buf[80][80];
char instr[90];
int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%s",instr)!=EOF){
		int len=strlen(instr);
		for(int i=0;i<len/2;i++){
			for(int j=0;j<len/2;j++){
				buf[i][j]=' ';
			}
		}
		int rem=(len+2)%3;
		int n1=((len+2)-rem)/3;
		int n3=n1;
		int n2=n1+rem;
		for(int i=0;i<n1;i++){
			buf[i][0]=instr[i];
		}
		for(int i=n1;i<n1+n2-1;i++){
			buf[n1-1][i-n1+1]=instr[i];
		}
		for(int i=0;i<n1;i++){
		//	buf[n1-i-1][n2-1]=instr[n1+n2+i-1];错了！！
		buf[n1-i-2][n2-1]=instr[n1+n2+i-1];//行数
		}
		for(int i=0;i<n1;i++){
			buf[i][n2]=0;
			printf("%s\n",buf[i]);
		}

	}
	return 0;
}

