//��Ȼ�ǳ�ͨ����  ���������ߵ� �ṹ������  ��һ�����Ѿ����õģ�
//��һ����δ�����    �ȱ���һ�¿��Ƿ���ͨ  �������0
//����  ����δ���ɵ�  ����ѡ��  ֱ������Ϊ���   �����
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<algorithm>
#include<math.h>

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>
using namespace std;
const int maxsize=108;
int tree[maxsize];
struct  edge_finish{
	int a,b;
	int cost;
}buf_finish[maxsize*maxsize/2];

struct edge_empty{
	int a,b;
	int cost;
	//bool operator <(const edge_empty &b){//��������˰�  ����һ��const ������� ���ؿ��ԡ�
		//���� �ύ��ʱ�����
	bool operator <(const edge_empty &b)const{
		return cost<b.cost;
	}
}buf_empty[maxsize*maxsize/2];

int findroot(int x){
	if(tree[x]==-1)return x;
	else {
		int tmp=findroot(tree[x]);
		tree[x]=tmp;
		return tmp;
	}
}

int N;
int a,b,cost,judge;

int main(){
	
	freopen ("in.txt","r",stdin);
	while (scanf("%d",&N)!=EOF&&N){
		for(int i=1;i<=N;i++){
			tree[i]=-1;
		}
		int finish_id=0,empty_id=0;
		for(int i=0;i<N*(N-1)/2;i++){
			scanf("%d%d%d%d",&a,&b,&cost,&judge);
			if(judge==0){
				buf_empty[empty_id].a=a;
				buf_empty[empty_id].b=b;
				buf_empty[empty_id].cost=cost;
				empty_id++;
			}
			else{
				buf_finish[finish_id].a=a;
				buf_finish[finish_id].b=b;
				buf_finish[finish_id].cost=cost;
				finish_id++;
			}
		}
		for(int i=0;i<finish_id;i++){
			a=findroot(buf_finish[i].a);
			b=findroot(buf_finish[i].b);
			if(a!=b){
				tree[a]=b;
			}
		}
		int root_num=0;
		/*
		for(int i=1;i<=N;i++){
			if(tree[i]==-1)
				root_num++;
		}
		if(root_num==1){
			printf("0\n");
			continue;
		}
		*/
		//wa ���������򰡣��� ������Ļ�������С�������� ����wa
		sort(buf_empty,buf_empty+empty_id);
		int ans=0;
		for(int i=0;i<empty_id;i++){
			a=findroot(buf_empty[i].a);
			b=findroot(buf_empty[i].b);
			cost=buf_empty[i].cost;
			if(a!=b){
				tree[a]=b;
				ans+=cost;
			}
		}
		root_num=0;
		for(int i=1;i<N;i++){
			if(tree[i]==-1)
				root_num++;
		}
		if(root_num>1)
			printf("no MST");
		else printf("%d\n",ans);
	}
	return 0;
}

