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
int n;
int main(){
	while (scanf("%d",&n)!=EOF){
		for(int x=0;x<=100;x++)
			for(int y=0;y<=100-x;y++){
				int z=100-x-y;
				if(15*x+9*y+z<=3*n)
					printf("x=%d,y=%d,z=%d\n",x,y,z);
			}
	}
	return 0;
}

