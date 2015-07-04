#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>

#include<algorithm>
#include<math.h>

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>
using namespace std;
int buf[12];
int main(){
	while(scanf("%d",&buf[0])!=EOF){
		for(int i=1;i<=9;i++){
			scanf("%d",&buf[i]);
		}
			sort(buf,buf+10);
			printf("max=%d\n",buf[9]);
	}
	return 0;
}

