/*
��ʵ ����dfs���� ����·����
��ô���Ļ�    ֻ���� ���ڵ��vector�ͺ���  
���ñ��� Ҷ�ӽڵ�  �� Ҳ����˵Ҷ�ӽڵ�� vector��0��

  ����ȷ  30�֣�
*/
#define for if(0); else for 
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

#include<time.h>
using namespace std;


struct node{
	int num;
	int w;
//	bool operator <(const node &b){//�������� ɵ��
	bool operator <(const node &b)const {
		return w>b.w;//�ݼ�����
	}
}tree[108];
vector <node> v[108];

bool mark[108];
int n,par,weigh;

vector<int> sto[108];
vector<int> work;
int np,k,ch;
int sum;  int idx;

void dfs(int nowp){
	if(sum==weigh&&v[nowp].size()==0){
		for(int i=0;i<work.size();i++){
			sto[idx].push_back(work[i]);
			//idx++;����д���˰�   ��������˶��ٸ�vector��
		}
		idx++;
		return;
	}
	else if(sum>weigh) return;//����ǧ������˼�֦����ᳬʱ
	for(int i=0;i<v[nowp].size();i++){
		int num=v[nowp][i].num;
		int w=v[nowp][i].w;
		if(mark[num]==false){
			sum+=w;
			work.push_back(w);
			mark[num]=true;
			dfs(num);
			sum-=w;
			//work.pop_back;��ʼ��ʱ�����û������
			//���bug����һ��Сʱ
			work.pop_back();
			mark[num]=false;
		}
	}
	
}
int main(){
	freopen("in.txt","r",stdin);   
	for(int i=0;i<108;i++){
		tree[i].num=i;		
	}
	while (scanf("%d%d%d",&n,&par,&weigh)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&tree[i].w);
		}
		node tmp;
		for(int i=0;i<par;i++){
			scanf("%d%d",&np,&k);
			for(int j=0;j<k;j++){
				scanf("%d",&ch);
				tmp=tree[ch];
				v[np].push_back(tmp);
				//printf("%d %d",v[np][j].num,v[np][j].w);
			}
			if(k>1){
				sort(v[np].begin(),v[np].end());
			}
		}
		for(int i=0;i<n;i++){
			mark[i]=false;
		}
		sum=tree[0].w;
		idx=0;
		mark[0]=true;
		work.push_back(tree[0].w);
		dfs(0);
		for(int i=0;i<idx;i++){
			for(int j=0;j<sto[i].size();j++){
				if(j!=0) printf(" ");
				printf("%d",sto[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

