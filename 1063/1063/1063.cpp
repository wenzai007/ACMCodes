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
map<int,int>mp[58];
int N;
int s,np;
int k,a,b;
int main(){
	freopen("in.txt","r",stdin);   
	while(scanf("%d",&N)!=EOF){
		for(int i=1;i<=N;i++){
			scanf("%d",&s);
			while(s--){
				scanf("%d",&np);
				if(mp[i].find(np)==mp[i].end()){
					mp[i][np]=1;
				}
			}
		}
		scanf("%d",&k);
		while (k--){
			scanf("%d%d",&a,&b);
			int common=0;
			if(mp[a].size()>mp[b].size()){
				int tmp=a;
				a=b;
				b=tmp;
			}
			map<int,int> ::iterator it;
			for(it=mp[a].begin();it!=mp[a].end();it++){
				int nn=it->first;
				if(mp[b].find(nn)!=mp[b].end()) common++;
			}
			int total=mp[a].size()+mp[b].size();
			total-=common;
			//double ans=(double)common/total;
			double ans=(double)common/(double)total;
			ans*=100;
			int nans=floor(ans*10+0.5);
			ans=(double)nans/10;
			printf("%.1lf",ans);
			string baifenhao="%";
			printf("%s",baifenhao.c_str());
			printf("\n");
		}
	}
	return 0;
}

