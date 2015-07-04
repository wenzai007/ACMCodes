#define for if(0); else for 
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

#include<time.h>
using namespace std;


char ins[300];
string stan;
int slen;
int n;
int main(){
	freopen("in.txt","r",stdin);   
	while (scanf("%d",&n)!=EOF){
		int min=0xffffff;
		gets(ins);
		for(int i=0;i<n;i++){
			//scanf("%s",ins);
			gets(ins);
			if(i==0){
				stan=ins;
				slen=strlen(ins);
				continue;
			}
			int j,k;
			int cnt=0;
			for(j=slen-1,k=strlen(ins)-1;j>=0,k>=0;j--,k--){
				if(ins[k]!=stan[j])
					break;
				cnt++;
			}
			if(cnt<min)
				min=cnt;
		}
		string outs=stan.substr(slen-min);//这里啊  沃勒个去 多减了一个1少了8分
		printf("%s\n",outs.c_str());
	
	}
	return 0;
}

