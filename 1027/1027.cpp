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

int color[3];
char mars[3][2];
int main(){
	while (scanf("%d%d%d",&color[0],&color[1],&color[2])!=EOF){
		for(int i=0;i<3;i++){
			for(int j=0;j<2;j++){
				mars[i][j]='0';
			}
		}
		for(int i=0;i<3;i++){
			int idx=0;
			do{
				int  digit=color[i]%13;
				char c;
				if(digit<10&&digit>=0){
					c=digit+'0';
				}
				else{
					c=digit-10+'A';
				}
				mars[i][idx++]=c;
				color[i]/=13;
			}
			while(color[i]);
		}
		printf("#");
		for(int i=0;i<3;i++){
			for(int j=1;j>=0;j--){
				printf("%c",mars[i][j]);
			}
		}
		printf("\n");
		
	}
	return 0;
}

