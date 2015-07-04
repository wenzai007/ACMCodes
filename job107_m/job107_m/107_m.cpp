#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;

char instr[500];
char newone;
int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%s",instr)!=EOF){
		
		string s=instr;
		scanf(" %c",&newone);
		int t=s.find(newone,0);
		while (t!=string::npos){
			s.erase(t,1);// pos  lenth 
			t=s.find(newone,0);//str   pos不能写成t-1因为t可能为0 就越界了
		}
		printf("%s\n",s.c_str());
	}
	return 0;
}
