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

int main(){
	int ii=10;
	srand(ii);
	unsigned int p=RAND_MAX;
	printf("%d!!!!!",ii%32767);
	for(int i=0;i<50000;i++){
		int r=rand();
		if(r<10){
			printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
			printf("%d---",r);
		}
	}
	int ll=0x7fff;
	printf("##################3%u---%d",p,ll);
	return 0;
}

