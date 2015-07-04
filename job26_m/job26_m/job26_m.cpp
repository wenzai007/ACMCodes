//又一次 还是自己的粗心大意而导致 其他字符输出空格而我却输出了  原来的
//字符  多么明显的错误  查了半个多小时！！  真是服了
//  

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
struct seq{
	bool suit;
	char cc;
	int num;
}buf[110];
stack<seq> c_stack;
int main(){
	freopen("in.txt","r",stdin);
	char tmp[110];
	seq seqtmp;
	while (scanf("%s",tmp)!=EOF){
		//
		for(int i=0;tmp[i]!='\0';i++){
			buf[i].cc=tmp[i];
			buf[i].suit=true;
			buf[i].num=i;
		}
		for(int i=0;tmp[i]!='\0';i++){
			if(tmp[i]=='('){
				c_stack.push(buf[i]);
			}
			if(tmp[i]==')'){
				if(c_stack.empty()){//??????
					c_stack.push(buf[i]);
					continue;
				}
				seqtmp=c_stack.top();
				if(seqtmp.cc=='('){
					c_stack.pop();
					continue;
				}
				else if(seqtmp.cc==')'){
					c_stack.push(buf[i]);
				}
			}
		}// end for other chars do not care 
		while (!c_stack.empty()){
			seqtmp=c_stack.top();
			c_stack.pop();
			buf[seqtmp.num].suit=false;
		}
		for(int i=0;tmp[i]!='\0';i++){
			printf("%c",tmp[i]); 
		}
		//char empty='\0';
		//printf("%c",empty);
		printf("\n");
		for(int i=0;tmp[i]!='\0';i++){
			if(buf[i].suit==false){
				if(buf[i].cc=='('){
					printf("$");
				}
				else if(buf[i].cc==')'){
					printf("?");
				}
			}
			else {
				printf(" ");
			}
		}
		//printf("%c",empty);
		printf("\n");
	}
	return 0;
}














//effect

