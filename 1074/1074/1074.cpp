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

struct N{
	int addr;
	int data;
	int next;
}buf[100000];

vector <N> v;
vector<N> vo;
int first;
int n,k;
int ta,td,tn;

int main(){
	freopen("in.txt","r",stdin);   
	while (scanf("%d%d%d",&first,&n,&k)!=EOF){
		N tmp;
		v.clear();
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&tmp.addr,&tmp.data,&tmp.next);
			buf[tmp.addr]=tmp;
		}
		int fa=first;
		while (buf[fa].next!=-1){
			v.push_back(buf[fa]);
			fa=buf[fa].next;
		}
		v.push_back(buf[fa]);//最后一个点
		int len=v.size();
		int fir=0;
		while (fir+k-1<len){
			for(int j=fir+k-1;j>=fir;j--){
				vo.push_back(v[j]);
			}
			fir=fir+k;
		}
		if(fir+k-1>=len){
			for(int j=fir;j<=len-1;j++){
				vo.push_back(v[j]);
			}
		}
		for(int j=0;j<vo.size()-1;j++){
			vo[j].next=vo[j+1].addr;
		}
		v[vo.size()-1].next=-1;
		for(int j=0;j<vo.size()-1;j++){
			printf("%05d %d %05d\n",vo[j].addr,vo[j].data,vo[j].next);
		}
		int j=vo.size()-1;
		printf("%05d %d %d\n",vo[j].addr,vo[j].data,vo[j].next);
		
	}
	return 0;
}

