#define for   if(0); else for 
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<math.h>
#include<algorithm>

#include<stack>
#include<queue>
#include<vector>
#include<map>
using namespace std;

char str[10080];
string out;
int main(){
	freopen("in.txt","r",stdin);
	while (gets(str)){
		string s= str;
		string sym=s.substr(0,1);
		int epos=s.find("E");
		string esyn=s.substr(epos+1,1);
		string exp=s.substr(epos+2);
		string num=s.substr(1,epos-1);
		int vava;
		sscanf(exp.c_str(),"%d",&vava);
		if(vava==0){
			string output=s.substr(0,epos);
			if(sym=="+")
				output.erase(0,1);
			printf("%s\n",output.c_str());
			continue;
		}
		if(esyn=="-"){
			int va;
			sscanf(exp.c_str(),"%d",&va);
			num.erase(1,1);
			string front="0.";
			for(int i=0;i<va-1;i++){
				front+="0";
			}
			num.insert(0,front);
			if(sym=="-")
				num.insert(0,"-");
			printf("%s\n",num.c_str());
			continue;
			
		}
		else {//指数是zheng数
			int va;//指数  真值
			sscanf(exp.c_str(),"%d",&va);
			num.erase(1,1);
			int len=num.size();
			len--;
			if(len<va){
				for(int i=0;i<va-len;i++){
					num+="0";
				}
			}
			else {
				num.insert(va,".");
			}
			if(sym=="-")
				num.insert(0,"-");
			printf("%s\n",num.c_str());
			continue;
		}
	}

	return 0;
}