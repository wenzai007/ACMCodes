/*
��ȫ���������� ���߼л����㷨 
*/
#define for if(0); else for 
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>>//��cmath ����û��math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
using namespace std;
const int size =100008;
int  N,M;
int buf[size];
int main(){
	freopen("in.txt","r",stdin);   
	while (scanf("%d%d",&N,&M)!=EOF){
		for(int i=0;i<N;i++){
			scanf("%d",&buf[i]);
		}
		sort(buf,buf+N);
		int i=0,j=N-1;
		bool find=false;
		while (i<j){
			if(buf[i]+buf[j]==M){
				find=true;
				printf("%d %d\n",buf[i],buf[j]);
			//	continue;���continue���������������while
				break;
			}
			if(buf[i]+buf[j]<M)  i++;
			else j--;
		}
		if(find==false){
			printf("No Solution\n");
		}
	}
	return 0;
}

