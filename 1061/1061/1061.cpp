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


char a[70],b[70];
int week,hour,minute;
char wout;
int main(){
	freopen("nimei.txt","r",stdin);   
	while (gets(a)){
		gets(b);
		int i;
		for(i=0;i<strlen(a)&&i<strlen(b);i++){
			if(a[i]==b[i]){
			//	if(b[i]>='A'&&b[i]<='Z'){这里错了
				//只能是A 到 G
			if(b[i]>='A'&&b[i]<='G'){
					week=a[i]-'A'+1;
					break;
				}
			}
		}
		for(int j=i+1;j<strlen(a)&&j<strlen(b);j++){
			if(a[j]==b[j]){
				//这里开始错了 只能是a到n不是a到z
				if(a[j]>='A'&&a[j]<='N'){
					hour=a[j]-'A'+10;
					break;
				}
				else if(a[j]>='0'&&a[j]<='9'){
					hour=a[j]-'0';
					break;
				}
			}
		}
		gets(a);
		gets(b);
		for(i=0;i<strlen(a)&&i<strlen(b);i++){
			if(a[i]==b[i]){
				if(a[i]>='A'&&a[i]<='z'){
					minute=i;
					break;
				}
			}
		}
		string w;
		switch(week){
			case 1: w="MON";
				break;
			case 2: w="TUE";
				break;
			case 3: w="WED";
				break;
			case 4: w="THU";
				break;
			case 5: w="FRI";
				break;
			case 6: w="SAT";
				break;
			case 7: w="SUN";
				break;
		}
		printf("%s %02d:%02d\n",w.c_str(),hour,minute);
	}	
	return 0;
}
