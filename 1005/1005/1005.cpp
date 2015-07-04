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
char input[180];
char sumdigit[20];
int idx;

int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%s",input)!=EOF){
		int sum=0;
		int idx=0;
		for(int i=0;i<strlen(input);i++){
			sum+=input[i]-'0';
		}
		//数位拆解！！
		do{
			sumdigit[idx++]=sum%10+'0';
			sum/=10;
		}
		while (sum);
		for(int i=idx-1;i>=0;i--){
			int cc=sumdigit[i];
			string s;
			switch (cc){
				case '0' :s="zero";
						  break;
				case '1' :s="one";
						  break;
				case '2' :s="two";
						  break;
                case '3' :s="three";
						  break;
				case '4' :s="four";
						  break;
				case '5' :s="five";
						  break;
				case '6' :s="six";
						  break;
				case '7' :s="seven";
						  break;
				case '8' :s="eight";
						  break;
				case '9' :s="nine";
						  break;
			}
			if(i!=idx-1) printf(" ");
			printf("%s",s.c_str());
		}
		printf("\n");
	}
	return 0;
}

