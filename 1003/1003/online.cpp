
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
                map[i][j]=INF;//��ʼ��Ϊ����󣬱�ʾ����ͨ   
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
    isVisit[source]=1;//��������ѷ��ʵ�ļ���   
    for(i=0;i<n-1;i++){  
        minDis=INF;  
        index=0;  
        for(j=0;j<n;j++){  
            if(!isVisit[j]&&dist[j]<minDis){//�ҵ���С�����   
                minDis=dist[j];  
                index=j;  
            }  
        }  
        isVisit[index]=1;//��������ѷ��ʵ�ļ���   
        for(j=0;j<n;j++){//����Դ����ÿ����֮��ľ���   
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
            ans++;//���·����+1   
            if(curTeamNum>maxTeamNum)  
                maxTeamNum=curTeamNum;  
        }  
        return;  
    }   
    if(curDis>dist[dest])//��ǰ��·�������Ѿ��������·��,��û�б�Ҫ���������ˡ�   
        return;  
    for(i=0;i<n;i++){  
        if(!isVisit[i]&&map[cId][i]<INF){//����iδ�����ʹ�����cId��i��ͨ   
            dfs(n,i,dest,curDis+map[cId][i],curTeamNum+team[i]);  
            isVisit[i]=0;  
        }  
    }  
}  
  
int main()  
{  
    int n,m,source,dest,i;  
    int c1,c2,l;  
    freopen("C:\\Documents and Settings\\Administrator\\����\\input.txt","r",stdin);  
  
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
