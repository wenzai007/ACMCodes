//�������ֻ���ñ����ķ���  Ҳ����ÿһ���㶼dfs
//Ȼ������̵ĵ�   �Լ����ò��鼯���м�����ͨ��֧
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

const int size =10080;
int tree[size];
int height[size];// ����ÿһ���ڵ�ĸ߶ȡ�����
vector <int> v[size];
int findroot (int x){
	if(tree[x]==-1)return x;
	else {
		int tmp=findroot(tree[x]);
		tree[x]=tmp;
		return tmp;
	}
}

int N;
int a,b;
bool mark[size];
void dfs(int id,int &hei,int &sum){//���ܽ�175 д����
	//���ü����÷��Űɣ�
//	mark[id]=true;//����Ϊ�˳�ʼ������õ� �����˷���main
	//��������
	if(sum>hei){
		hei=sum;
	}
	for(int i=0;i<v[id].size();i++){
		if(mark[v[id][i]]==false){
			int nx=v[id][i];
			mark[nx]=true;
			sum+=1;
			dfs(nx,hei,sum);
			sum-=1;
			mark[nx]=false;
		}
	}
	//mark[id]=false;//������
}

int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d",&N)!=EOF){
		for(int i=1;i<=N;i++){
			tree[i]=-1;
		}
		//for(int i=1;i<=N;i++){//д����  ����N-1������N������
		for(int i=1;i<=N-1;i++){
			scanf("%d%d",&a,&b);
			v[a].push_back(b);
			v[b].push_back(a);
			a=findroot(a);
			b=findroot(b);
			if(a!=b){
				tree[a]=b;
			}
		}
		int compo=0;
		for(int i=1;i<=N;i++){
			if(tree[i]==-1) compo++;
		}
		if(compo>1){
			printf("Error: %d components",compo);
			continue;
		}
		for(int i=1;i<=N;i++)
			mark[i]=false;
		for(int i=1;i<=N;i++){
			int hei=-0xffffff;//�Ƚϴ�ĸ���
			int sum=0;
			mark[i]=true;
			dfs(i,hei,sum);
			height[i]=hei;
			mark[i]=false;
		}
		int max=-1;
		for(int i=1;i<=N;i++){
			if(height[i]>max){
				max=height[i];
			}
		}
		int cnt=0;
		for(int i=1;i<=N;i++){
			if(height[i]==max){
				cnt++;
				if(cnt!=1)printf("\n");
				printf("%d",i);
			}
		}
	}
	return 0;
}

