//�������ʵ��̰�ĵĲ���  �ҵ�ʱ��  ÿ��ֻ������ĵ�  ��������������///����ô  ֻ�����û��·��  
//����diji��   ����ʲô��Ӫ ֻ�������·�����淽���ֲ�������˵����ⲻ��
//��  ���岻�Ƕ�̬��Ѱ�����Ž� ���Ǿ�̬���ҵ����ŵ�·��   ������֮���ж�
//�����ǲ���  �����  �Ǿ����   ���� �������
//�����Ǳ��жϺϲ����� �������·  ��һ��̰�ĵ��㷨  ��ֻ�����Ž⡢����
//��˵ ���ȿ��Ǿ������  �������ȿ�����Ӫ������
//
//
//
//
//������˼· ��  ��Ϊ����ֻ�ܿ�Խһ����Ӫ ���� �Ѵ�һ�����ı�
//��Ϊ�����   Ȼ���ܴ�2��1  ֻ�ܴ�1��2  �ͺ���  ���������Ļ� Ҫ�����
//ʱ�� ����� �ڽӱ�Ļ��ͻ�Ƚ��鷳һ ��  ����Ϊ��Ҫ���� ������Ҳ���ø�///�Ӷȴ����o��n+e�����Խ��ܣ�
//����һ�ַ�������   ���ٽ־��� ����Ҳ�ǿ��ԵĶ��Ҵ����������������Ĺ�ϵ
//�ĺ�ʱ��ȽϺ�  �ȽϿ�  ��ʱ��Ļ� �����ڽӾ���ʵ������
//2.����   �����Ҳ������ �������  �ҳ�
//�ڶ��ֽⷨ������������Ӫ��ԭͼ��ΪA��B������ͼ����Aͼ����1���������̾��룬��Bͼ����2���������̾��룬���ѡ��һ������������ͬ��Ӫ�Ļ���ʱ����С��һ��·��


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
//û��Ҫ   Ӧ�� ��Ϊ��С�� ���������������� #define inreach  0x7fffffff //Ϊ�˽�2��1�ı߸�Ϊ���ɴ�
const  int maxsize=680;
struct edge{
	int next;
	int t;
};
bool mark[maxsize];
int dis[maxsize];

int camp[maxsize];
 vector<edge> v[maxsize];//!! error C2143: �﷨���� : ȱ�١�;��(�ڡ�<����ǰ��) 
 //��Ϊusing namespace std;�����˺��棡��
int n,m,a,b,t;  

///using namespace std;2b ��Ȼ�����˺���

int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d",&n)!=EOF&&n){
		for(int i=1;i<=n;i++){
			v[i].clear();
			camp[i]=0;
			dis[i]=-1;
			mark[i]=false;
		}
		scanf("%d",&m);
		while (m--!=0){
			scanf("%d%d%d",&a,&b,&t);
			edge tmp;
			tmp.next=a;
			tmp.t=t;
			//vector[b].push_back(tmp);��д��ʲô
			v[b].push_back(tmp);
			tmp.next=b;
			//vector[a].push_back(tmp);
			v[a].push_back(tmp);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&camp[i]);
		}
		for(int i=1;i<=n;i++){
			if(camp[i]==2){
				//for(int j=0;j<=v[i].size();j++){//С��
				for(int j=0;j<v[i].size();j++){
					if(camp[v[i][j].next]==1){
						v[i][j].t=-8;
					}
				}
			}
		}
		// now   dijkstra
		int newp=1;
		dis[1]=0;
		mark[1]=true;
		for(int i=2;i<=n;i++){
			for(int j=0;j<v[newp].size();j++){
				int n_next=v[newp][j].next;
				int tt=v[newp][j].t;
				//if(mark[n_next]==true)continue ;�����������  tt��Ȼ��-8���������dis[n_next]��Ȼ��-1 û���˵�
				if(mark[n_next]==true||tt==-8)continue ;
				if(dis[n_next]==-1||dis[n_next]>dis[newp]+tt){
					dis[n_next]=dis[newp]+tt;
				}
			}
			int mindis=0x7fffffff;
			for(int j=1;j<=n;j++){
				if(mark[j]==true) continue;
				if(dis[j]<0)continue;//�˴�����-1 ����С���� ��Ϊ������
				//�������õĵ���ߣ���
				if(dis[j]<mindis){
					mindis=dis[j];
					newp=j;
				}
			}
			mark[newp]=true;
		}
		if(mark[2]==false) 
			printf("-1\n");
		else printf("%d\n",dis[2]);
	}
	return 0;
}

