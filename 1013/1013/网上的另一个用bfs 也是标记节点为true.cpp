#include<iostream>  
#include<string.h>  
using namespace std; 
#include<queue>  
#define N 1001  
int main() 
{ 
	int n,m,k,i,j,t,c1,c2; 
	bool highways[N][N]; 
	int concern[N]; 
	memset(highways,0,sizeof(highways)); 
	memset(concern,0,sizeof(concern)); 
	cin>>n; 
	cin>>m; 
	cin>>k; 
	for(i=0;i<m;i++){ 
		cin>>c1; 
		cin>>c2; 
		highways[c1][c2]=true; 
		highways[c2][c1]=true; 
	} 
	for(i=0;i<k;i++){ 
		cin>>concern[i]; 
	} 
	for(i=0;i<k;i++){ 
		int visit[N],count,tmp; 
		queue<int> q; 
		memset(visit,0,sizeof(visit)); 
		visit[concern[i]]=1; 
		count=0; 
		for(j=1;j<=n;j++){ 
			if(visit[j]!=1){ 
				queue<int> dq; 
				visit[j]=1; 
				dq.push(j); 
				//���뱻ռ����е�ֱ��������ÿ��������BFS  
				while(!dq.empty()){ 
					tmp=dq.front(); 
					dq.pop(); 
					for(t=0;t<=n;t++){ 
						if(highways[tmp][t]!=false&&visit[t]!=1){ 
							dq.push(t); 
							visit[t]=1; 
						} 
					} 
				} 
				/*������нڵ���Ա������������е㣬����Ҫ�ӱߣ��˳���
				  ����������µ���+1��ͨ����һ��ֱ�������ڵ���δ�����ʵĽڵ㣬Ѱ����һ���µ�*/ 
				count++; 
			} 
		} 
		cout<<count-1<<endl;/*��Ҫ��ӵ�·���������Ӹ����µ�����Ҫ������·��*/ 
	} 
	return 0; 
} 
