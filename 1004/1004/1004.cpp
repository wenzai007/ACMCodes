//�������ֻ�ܵõ�19�ְ�   ��Ϊ ��һ������һ���ڵ㿼�ǵĲ���ȫ��
//����������ǵĲ���ȫ   ���仰˵���ǲ�α��� û������ 
//�����һ��  ��  100x_2
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>>//��cmath ����û��math

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
		if(v[1].size()==0){//Ҳ����ֻ��һ���ڵ�
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

