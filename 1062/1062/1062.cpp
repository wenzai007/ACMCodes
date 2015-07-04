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

struct N{
	char id[10];
	int ta;
	int vi;
	bool operator <(const N &b)const{
		if((ta+vi)!=(b.ta+b.vi)){
			return (ta+vi)>(b.ta+b.vi);
		}
		else if(vi!=b.vi){
			return vi>b.vi;
		}
		else {
			return strcmp(id,b.id)<0;
		}
	}
};
vector<N> v[3];
char id[10];
int nt,nv;
int t,low,high;
int main(){
	freopen("in.txt","r",stdin);   
	//freopen("out.txt","w",stdout);
	while (scanf("%d%d%d",&t,&low,&high)!=EOF){
		for(int i=0;i<t;i++){
			scanf("%s%d%d",id,&nv,&nt);
			N tmp;  
			strcpy(tmp.id,id); 
			tmp.ta=nt; 
			tmp.vi=nv;
			if(nt<low||nv<low) continue;
			if(nt>=high&&nv>=high) {
				v[0].push_back(tmp);
				continue;
			}
			if(nt<high&&nv>=high){
				v[1].push_back(tmp);
				continue;
			}
			if(nt<high&&nv<high){
				if(nt<=nv){
					v[2].push_back(tmp);
					continue;
				}
			}
			
			v[3].push_back(tmp);
			
		}
		int M=v[0].size()+v[1].size()+v[2].size()+v[3].size();
		printf("%d\n",M);
		sort(v[0].begin(),v[0].end());
		sort(v[1].begin(),v[1].end());
		sort(v[2].begin(),v[2].end());
		sort(v[3].begin(),v[3].end());
		for(int i=0;i<4;i++){
			for(int j=0;j<v[i].size();j++){
				printf("%s %d %d\n",v[i][j].id,v[i][j].vi,v[i][j].ta);
			}
		}
	}
		return 0;
}

