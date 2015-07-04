//这个方法只能得到19分啊   因为 下一层的最后一个节点考虑的不够全面
//所以情况考虑的不周全   换句话说就是层次遍历 没有掌握 
//下面改一下  见  100x_2
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
using namespace std;
const int size=108;
vector <int> v[size];
queue<int> q;
int N,M;
int id,k,child;
int idx;
int output[102];
int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d%d",&N,&M)!=EOF){
		for(int i=1;i<=N;i++){
			v[i].clear();
		}
		while (!q.empty()) q.pop();
		idx=0;
		while (M--!=0){
			scanf("%2d%d",&id,&k);
			while (k--!=0){
				scanf("%2d",&child);
				v[id].push_back(child);
			}
		}
		if(v[1].size()==0){//也就是只有一个节点
			printf("0\n");
			continue;
		} 
		q.push(1);
		output[idx++]=0;
		int last=v[1][v[1].size()-1];
		int num=0;
		int totalleaf=1;
		int lastofallleaf=0xfffffff;
		while (!q.empty()){
			int nowp=q.front();
			q.pop();
			/*  if(nowp==last) {
				output[idx++]=num;
				num=0;
				if(v[last].size()!=0){
				int ss=v[last].size();
				last=v[last][ss-1];
				}
				}
				*/
			if(nowp==lastofallleaf&&nowp!=last){
				output[idx++]=num;
			}
			for(int i=0;i<v[nowp].size();i++){
				int tt=v[nowp][i];
				if(v[tt].size()==0) {
					num++;
				}
				if(tt==last) {
					output[idx++]=num;
					num=0;
					if(v[last].size()!=0){
						int ss=v[last].size();
						last=v[last][ss-1];
					}
				}
				q.push(tt);
				totalleaf++;
				if(totalleaf==N) lastofallleaf=tt;
			}
		}
		for(int i=0;i<idx;i++){
			if(i!=0) printf(" ");
			printf("%d",output[i]);
		}
		printf("\n");


	}

	return 0;
}

