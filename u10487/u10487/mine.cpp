#define for if(0); else for 


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
	int num;
	int m;
	int testnum;


int buf[1080];

int justdoit(int tn){
	sort(buf,buf+num);
	int l=0,r=num-1;
	int closest=buf[l]+buf[r];
	while (l<r){
		int nsum=buf[l]+buf[r];
		if(nsum==tn) {
			closest=nsum;
			break;
		}
		if(nsum<tn){
			if(abs(nsum-tn)<abs(closest-tn)){
				closest=nsum;
			}
			l++;
		}
		else{
   			if(abs(nsum-tn)<abs(closest-tn)){
				closest=nsum;
			}
			r--;
		}
	}
	return closest;
}


int main(){
	freopen("in.txt","r",stdin); 
	int case_num=0;
	while(scanf("%d",&num)&&num){
		case_num++;
		printf("Case %d:\n",case_num);
		for(int i=0;i<num;i++){
			scanf("%d",&buf[i]);
		}
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			scanf("%d",&testnum);
			int res=justdoit(testnum);
			printf("Closest sum to %d is %d.\n",testnum,res);
		}
	}
	
	return 0;
}

