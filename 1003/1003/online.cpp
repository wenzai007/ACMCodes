
#include<iostream>   
using namespace std;  
const int INF=1000000;  
const int NUM=505;  
int map[NUM][NUM];  
int team[NUM],isVisit[NUM];  
int dist[NUM];  
int ans,maxTeamNum;  
  
void init()  
{  
    int i,j;  
    for(i=0;i<NUM;i++){  
        isVisit[i]=0;  
        team[i]=0;  
        dist[i]=INF;  
        for(j=0;j<NUM;j++){  
            if(j!=i){  
                map[i][j]=INF;//初始化为无穷大，表示不连通   
                map[j][i]=INF;  
            }  
  
        }  
    }  
}  
void dijskra(int n,int source)  
{  
      
    int i,minDis=INF,index=0,j;  
    for(i=0;i<n;i++){  
        dist[i]=map[source][i];  
    }  
    isVisit[source]=1;//将其加入已访问点的集合   
    for(i=0;i<n-1;i++){  
        minDis=INF;  
        index=0;  
        for(j=0;j<n;j++){  
            if(!isVisit[j]&&dist[j]<minDis){//找到最小距离点   
                minDis=dist[j];  
                index=j;  
            }  
        }  
        isVisit[index]=1;//将其加入已访问点的集合   
        for(j=0;j<n;j++){//更新源点与每个点之间的距离   
            if(map[index][j]<INF&&dist[j]>dist[index]+map[index][j])  
                dist[j]=dist[index]+map[index][j];  
        }  
    }  
      
      
}  
  
void dfs(int n,int cId,int dest,int curDis,int curTeamNum)  
{  
    int i;  
    isVisit[cId]=1;  
    if(cId==dest){  
        if(curDis==dist[dest]){  
            ans++;//最短路径数+1   
            if(curTeamNum>maxTeamNum)  
                maxTeamNum=curTeamNum;  
        }  
        return;  
    }   
    if(curDis>dist[dest])//当前的路径长度已经超过最短路径,就没有必要继续搜索了。   
        return;  
    for(i=0;i<n;i++){  
        if(!isVisit[i]&&map[cId][i]<INF){//城市i未被访问过，且cId到i连通   
            dfs(n,i,dest,curDis+map[cId][i],curTeamNum+team[i]);  
            isVisit[i]=0;  
        }  
    }  
}  
  
int main()  
{  
    int n,m,source,dest,i;  
    int c1,c2,l;  
    freopen("C:\\Documents and Settings\\Administrator\\桌面\\input.txt","r",stdin);  
  
    cin>>n>>m>>source>>dest;  
    init();  
    for(i=0;i<n;i++)  
        cin>>team[i];  
    for(i=0;i<m;i++){  
        cin>>c1>>c2>>l;  
        map[c1][c2]=l;  
        map[c2][c1]=l;  
    }  
    dijskra(n,source);  
    for(i=0;i<n;i++)  
        isVisit[i]=0;  
    dfs(n,source,dest,0,team[source]);  
    cout<<ans<<" "<<maxTeamNum<<endl;  
    return 0;  
  
  
}  
