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
				//对与被占领城市的直接相连的每个城市做BFS  
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
				/*如果现有节点可以遍历所有了所有点，不需要加边，退出。
				  否则独立“孤岛”+1，通过下一个直接相连节点且未被访问的节点，寻找下一个孤岛*/ 
				count++; 
			} 
		} 
		cout<<count-1<<endl;/*需要添加的路，就是连接各个孤岛所需要的最少路径*/ 
	} 
	return 0; 
} 
