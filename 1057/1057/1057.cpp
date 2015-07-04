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

stack<int>s;
int idx;
int sto[100008];
int work[100008];
vector <int>v;
int mid;
void peekm1(){
	int len=s.size();
	if(len%2==0){
		mid--;
	}
	//否则不变
}
void peekm2(){
	int len=s.size();
	if(len%2==1){
		mid++;
	}
}
/*
int peekm(){
	idx=0;
	int ans;
	int len=s.size();
	while (!s.empty()){
		work[idx]=sto[idx]=s.top();
		s.pop();
		idx++;
	}
	sort(work,work+idx);
	idx--;
	if(len%2==0)
		ans=work[len/2-1];
	else{
		ans=work[len/2];
		}
	for(int i=idx;i>=0;i--){
		s.push(sto[i]);
	}
	return ans;
}
*/

char instr[10];
int n;
int key;
string all,op;
int main(){
	freopen("in.txt","r",stdin);   
	while(scanf("%d",&n)!=EOF){
		mid=-1;
		while (!s.empty())s.pop();
		v.clear();
		gets(instr);//为了把那个\n去掉  因为前面没有去掉
		while(n--){
			gets(instr);
			all=instr;
			if(all.find(" ")==string::npos){
				if(all=="Pop"){
					if(s.empty()){
						printf("Invalid\n");
						continue;
					}
					else{
						printf("%d\n",s.top());
						s.pop();
						peekm1();
						v.pop_back();
						continue;
					}
				}
				if(all=="PeekMedian"){
					if(s.empty()){
						printf("Invalid\n");
						continue;
					}
					else{
						if(mid==-1){
							printf("wawawa");
								continue;
						}
						int outn=v[mid];
						printf("%d\n",outn);
						continue;
					}
				}
			
			}
			else{
				int pushk;
				char tmp[10];
			//	sscanf(instr,"%d",&pushk);这样接受不到任何数字
				sscanf(instr,"%s%d",tmp,&pushk);
				s.push(pushk);
				v.push_back(pushk);
				peekm2();
				continue;
			}
		}
	}
	return 0;
}

