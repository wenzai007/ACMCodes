//˼·����  ��ɾȥһ�����Ժ�  ���е����Ϊ��ĵ�
//��Ҫ���½�������Ȼ����ѡ��һ���������Ը��Ӷ�
//������ҪN��ƽ�� 
//��  �����������job81_m_2  ����д

#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>

#include<algorithm>
#include<math.h>

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>
using namespace std;
const int size=528;

queue <int> q;
//��һ��  �ñ���������ˣ���>>���Զһ��
priority_queue <int,vector<int>,greater<int> > p;
//priority_queue <int,vector<int>,greater<int>> p;//����С���� �Ӷ��Զ�̬
//�ĸ�����Ԫ�� ��������  ����ÿһ�ζ�Ҫ��ס�±�
vector<int> v[size];
int indegree[size];
int output[size];
int out_id;
int N,M,a,b;
void p_q(){//����Ҫ�� 
	while(!p.empty()){
		int tmp=p.top();
		p.pop();
		output[out_id++]=tmp;
		q.push(tmp);
	}
}
int main(){
	freopen ("in.txt","r",stdin);
	while (scanf("%d",&N)!=EOF){
		for(int i=1;i<=N;i++){
			v[i].clear();
			indegree[i]=0;
			output[i-1]=0;
		}
		out_id=0;
		while (!q.empty()) q.pop();
		while (!p.empty()) p.pop();
		scanf("%d",&M);
		for(int i=0;i<M;i++){
			scanf("%d%d",&a,&b);
			indegree[b]++;
			v[a].push_back(b);
		}
		int cnt=0;
		for(int i=1;i<=N;i++){
			if(indegree[i]==0){
				p.push(i);
			}
		}
		while (!p.empty()){
			int newp=p.top();
			p.pop();
			cnt++;
			output[out_id++]=newp;
			for(int i=0;i<v[newp].size();i++){
				indegree[v[newp][i]]--;
				if(indegree[v[newp][i]]==0){
					p.push(v[newp][i]);
				}
			}
		}
		int o_num=0;
		for(int i=0;i<out_id;i++){
			if(o_num==0){
				printf("%d",output[i]);//�Ȳ��ܸ�ʽ
			}
			else {
				printf(" %d",output[i]);
			}
			o_num++;
		}
		printf("\n");
	}
	return 0;
}


