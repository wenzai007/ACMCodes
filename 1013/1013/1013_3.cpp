//д��һ�� ���ֿ����ò��鼯��  
//���ҹؼ���һ���ǣ���������
//��û��Ҫ  �߶���ߴ���ģ�������ȫ���԰�case�е���������
//�ȴ�����  Ȼ����ÿ��  case �����ٴ�������������
//��ؾͶ��������
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

const int size=1080;//�����Ҳ��size *size/2
int tree[size];
int in_edge[size*size/2][2];//������������еı�  �Ȳ�����

int findroot(int x){//  ���鼯�������Ⱥ���  
	//if(tree[x]==-1) return -1;����ʲôJB������
	if(tree[x]==-1) return x;
	else {
		int tmp=findroot(tree[x]);
		tree[x]=tmp;
		return tmp;
	}
}

int  N,M,K;

int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d",&N)!=EOF){
		scanf("%d%d",&M,&K);
		for(int i=0;i<M;i++){
			scanf("%d%d",&in_edge[i][0],&in_edge[i][1]);
		}
		int tocheck;
		while (K--!=0){
			scanf("%d",&tocheck);
			for(int i=1;i<=N;i++){
				tree[i]=-1;
			}
			for(int i=0;i<M;i++){
				if(in_edge[i][0]==tocheck||in_edge[i][1]==tocheck)
					continue;
				int a=in_edge[i][0];
				int b=in_edge[i][1];
				a=findroot(a);
				b=findroot(b);
				if(a!=b){
					tree[a]=b;
				}
			}
			int ans=0;
			for(int i=1;i<=N;i++){
				if(tree[i]==-1)
					ans++;
			}
			printf("%d\n",ans-2);
		}
	}
	return 0;
}

