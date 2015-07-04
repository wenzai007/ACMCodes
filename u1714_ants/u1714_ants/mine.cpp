//两只蚂蚁碰头和不碰头是没有区别的  因为二者的速度是一样的 然后碰头的话 相当于二者互换  并且二者还
//没有任何区别的 至于代码么 那就是很简单的实现了

#define for if(0); else for 
#define pf printf
#define sf  scanf
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

int c_num;
int len,n;
int x;
struct node{
	int nearest;
	int longest;
}buf[1000008];
int main(){
	freopen("in.txt","r",stdin);   
	sf("%d",&c_num);
	while(c_num--){
		sf("%d%d",&len,&n);
		for(int i=0;i<n;i++){
			sf("%d",&x);
			if(x>=len/2){
				buf[i].nearest=len-x;
				buf[i].longest=x;
			}
			else{
				buf[i].nearest=x;
				buf[i].longest=len-x;
			}
		}
		int mymin=-20;
		int mymax=-20;
		for(int i=0;i<n;i++){
			if(buf[i].nearest>mymin){
				mymin=buf[i].nearest;
			}
			if(buf[i].longest>mymax){
				mymax=buf[i].longest;
			}
		}
		pf("%d %d\n",mymin,mymax);
	}
	return 0;
}

