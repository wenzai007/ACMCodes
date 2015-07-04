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

int M,N;
map<int ,int> mp;
int tmp;
int main(){
	freopen("in.txt","r",stdin);   
	while (scanf("%d%d",&M,&N)!=EOF){
		mp.clear();
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				int tmp;
				scanf("%d",&tmp);
				if(mp.find(tmp)==mp.end()){
					mp[tmp]=1;
				}
				else {
					mp[tmp]++;
				}
			}
		}
		map<int,int>::iterator it;
		int max=0;int domi=-1;
		for(it=mp.begin();it!=mp.end();it++){
			if(it->second>max){
				max=it->second;
				domi=it->first;
			}
		}
		printf("%d\n",domi);
	}
	return 0;
}

