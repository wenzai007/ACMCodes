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
vector<int>v;
int main(){
	//freopen("in.txt","r",stdin);   
	for(int i=0;i<10;i++){
		v.push_back(i);
	}
	sort(v.begin(),v.end(),greater<int>());
	string a="ertyui";
	printf(a[2]=='t'?"yes":"no");
	int bb;
	bb=a[2]>'a'?123:898;
	return 0;
}

