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
int a,b,c;
int main(){
	for(int a=0;a<=9;a++)
		for(int b=0;b<=9;b++)
			for(int c=0;c<=9;c++){
				if((a*100+b*10+c+b*100+c*10+c)==532){
					printf("%d %d %d\n",a,b,c);
				}
			
			}
	return 0;
}

