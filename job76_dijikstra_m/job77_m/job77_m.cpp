//1. ��֪��bool  ����Ҳ��true 
//2  ����  aд��b
//3  ����   ����д����  ����һ���ط��ı�����
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
int N,M;
int dis[108];
bool mark[108];

struct edge{//����߱�Ļ� ֻ�洢next�ڵ�   
	int next;
	int cost;
};
vector <edge> vertexs[108];
int a,b,cost;
int main(){
	freopen ("in.txt","r",stdin);
	while (scanf("%d%d",&N,&M)!=EOF){
		if(!N&&!M) break;
		for(int i=1;i<=N;i++){
			vertexs[i].clear();
			dis[i]=-1;
			mark[i]=0;
			//mark[i]=-1;//���� ֻҪbool���͵Ĳ���0�Ļ�����true ��ʹ�Ǹ���Ҳ��true forgot  at the  first time 
		}
		for(int i=1;i<=M;i++){
			scanf("%d%d%d",&a,&b,&cost);
			edge tmp;
			tmp.next=b;
			tmp.cost=cost;
			vertexs[a].push_back(tmp);
			//tmp.next=b;//���԰���
			tmp.next=a;
			vertexs[b].push_back(tmp);
		}
		mark[1]=true;
		dis[1]=0;
		int newp=1;
		//for(int i=2;i<=N;i++){//!!��������д�ġ��� //һ��Ҫ��n-1��
		for(int i=0;i<N-1;i++){
			for(int j=0;j<vertexs[newp].size();j++){
				int new_next=vertexs[newp][j].next;
				int thecost=vertexs[newp][j].cost;
				if(mark[new_next]==true) continue;
				if(dis[new_next]==-1||dis[newp]+thecost<dis[new_next]){
					//dis[new_next]=dis[newp]+cost;���˰��� �� ����������Ƶ���д��
					dis[new_next]=dis[newp]+thecost;
				}
			}
			int mindis=100000000;
			for(int j=1;j<=N;j++){
				if(mark[j]==1) continue;//���� ɸ��
				if(dis[j]==-1) continue;// ����  ɸ��
				if(dis[j]<mindis){
					newp=j;
					mindis=dis[j];
				}
			}
			// forgot the mark[]again!!!!!!!
			mark[newp]=true;
		}
		printf("%d\n",dis[N]);

	}
	return 0;
}

