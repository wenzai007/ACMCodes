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


char pic[4][4];
int curstate;
int step;
bool findit;
int temp;
int tmp;
vector <int> v;
int change[16]={
	63624,62532,61986,61713,
	36744,20292,12066,7953,
	35064,17652,8946,4593,
	34959,17487,8751,4383
};
void dfs(int pos,int dep){
	if(dep==step){
		if(curstate==65535)
			findit=true;
		return;
	}
	if(findit||pos>15)
		return;
	curstate^=change[pos];//if not above  then flip it 
	v.push_back(pos);
	if(v.size()>4){
		temp=v[1];
		tmp=v[3];
	}
	dfs(pos+1,dep+1);
	if(findit==true) // i feel this must be added
	{ //!!这句话太多余了 v.push_back(pos+1);//shoud delete
		return;
	}
	v.pop_back();
	curstate^=change[pos];//recover
	dfs(pos+1,dep);
}
int main(){
	freopen("in.txt","r",stdin);   
	while (scanf("%s",&pic[0])!=EOF){
		for(int i=1;i<=3;i++){
			scanf("%s",&pic[i]);
		}
		v.clear();
		curstate=0;
		findit=false;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				curstate<<=1;
				if(pic[i][j]=='-')
					curstate+=1;//- is the state of open
			}
		}
		for(step=0;step<=16;step++){
			dfs(0,0);
			if(findit==true)
				break;
		}
		printf("%d\n",step);
		for(int i=0;i<v.size();i++){
			printf("%d %d\n",v[i]/4+1,v[i]%4+1);
		}

	}
	return 0;
}

