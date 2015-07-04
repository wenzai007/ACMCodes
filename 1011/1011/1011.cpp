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
char  name[3];
double each_big[3];
double input[3]; 
int main(){
	freopen("in.txt","r",stdin);
	for(int i=0;i<3;i++){
		scanf("%lf%lf%lf",&input[0],&input[1],&input[2]);
		int max=0;
		if(input[1]>input[0]){
			max=1;
		}
		if(input[2]>input[0]&&input[2]>input[1]){
			max=2;
		}
		switch (max){
			case 0:name[i]='W';
				each_big[i]=input[0];
				break;
			case 1:name[i]='T';
				each_big[i]=input[1];
				break;
			case 2: name[i]='L';
				each_big[i]=input[2];
				break;
		}
	}
	printf("%c %c %c ",name[0],name[1],name[2]);
	double sum=(each_big[0]*each_big[1]*each_big[2]*0.65-1)*2;
	printf("%.2lf\n",sum);


	return 0;
}

