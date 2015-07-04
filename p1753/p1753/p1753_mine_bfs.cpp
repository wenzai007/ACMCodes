//1753����������ַ���  ����ö��dfs�ķ���   �Լ�bfs�ķ��� һ�����ŵĻ����ǻ��뵽��bfs�ķ���
//����dfsҲ�ǿ��Ե�ֻҪÿ���������ʱ�����Ǿͷ��ؾͿ�����
//������õ���bfs�ķ��� ͬʱӦ����λ��ѹ���ķ���  ÿһ��ÿһ�д����� ���ϵ���  Ȩ�صݼ� ��16λ����
//������һ��״̬  ����һ��map 4*4������ ����ͱ�ѹ������ һ��1λ������  ��������16���Ŀռ�
#include<stdio.h>
#include<stdlib.h>

#include<string>
#include<string.h>
#include<ctype.h>

#include<math.h>
#include<algorithm>

#include<queue>
#include<stack>
#include<map>
#include<vector>
using namespace std;

struct node{
	int state;
	int step;
};//һ�����ж��ŵİ�
queue <node> q;
int change[16]={//Ҫ�ı��״̬  �����ȥ���

	 51200,58368,29184,12544,  
     35968,20032,10016,4880,  
     2248,1252,626,305,  
     140,78,39,19  
};

bool visited[65536];
char pic[4][4];
int bfs(int np){
	node cur,next;
	cur.state=np;
	cur.step=0;
	visited[cur.state]=true;
	q.push(cur);
	while(!q.empty()){
		cur=q.front();
		q.pop();
		//̫ɵ����  ��Ȼ������ ������ �ǲ�����ѭ����ʲô������~~~������
		if(cur.state==0||cur.state==65535){
			return cur.step;
		}
		for(int i=0;i<16;i++){
			next.state=cur.state^change[i];
			if(visited[next.state]==true)
				continue;
			next.step=cur.step+1;
			//ɵ��  ����û�н���Ӧ��visited��Ϊtrue
			visited[next.state]=true;
			if(next.state==0||next.state==65535){
				return next.step;
			}
			q.push(next);
		}
	}
	return -1;
}

int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%s",&pic[0])!=EOF){
		for(int i=0;i<3;i++){
			scanf("%s",&pic[i+1]);
		}
		int curstate=0;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				//����λ  Ȼ��ֵ  ����16������ ��λҪ15��
				curstate<<=1;
				if(pic[i][j]=='b'){
					curstate+=1;
				}
			}
		}
		memset(visited,false,sizeof(visited));
		int res=bfs(curstate);
		if(res==-1)
			printf("Impossible\n");
		else
			printf("%d\n",res);

	}
	return 0;
}
