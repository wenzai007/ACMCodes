#include<stdio.h>
//��һ�γ��� ����ʱ����  stack overflow
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

//char map[108][108];����������map���򱨴�
//��map��: ����ȷ�ķ��ſ����ǡ� std::map��
char pic[108][108];
bool mark[108][108];
int m,n;
int go[][2]={//��������  б�ŵ�4��
	-1,0,
	1,0,
	0,1,
	0,-1,
	-1,-1,
	-1,1,
	1,-1,
	1,1
};//���Ǽӷֺţ���
void dfs(int x,int y){
	//int nx=x,ny=y;
	for(int i=0;i<8;i++){
		int nx=x+go[i][0];
		int ny=y+go[i][1];
		//�����nx��ny����������ǵڼ��еڼ���
		//if(nx<0||nx>n-1||ny<0||ny>m-1) continue;
		if(nx<0||nx>m-1||ny<0||ny>n-1) continue;
		//�ټ���һ���жϵ�����߹��� continue��
		//��һ������ѭ��������������
		if(mark[nx][ny]==true) continue;
		if(pic[nx][ny]=='*') continue;
		//ܳ �ټ���һ�仰 mark������������ѭ����
		mark[nx][ny]=true;
		dfs(nx,ny);
	}
}

int main(){
	freopen("in.txt","r",stdin);
	//int m,n;���������ﶨ�� dfs����ʶm��n��
	while (scanf("%d%d",&m,&n)!=EOF){
		if(!m&&!n)break;
		for(int i=0;i<m;i++){
			scanf("%s",pic[i]);//�ܺ� ע������д��
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				mark[i][j]=false;
			}
		}
		/*
		int sx,sy;
		for(sx=0;sx<m;sx++){
			for(sy=0;sy<n;sy++){
				if(pic[sx][sy]=='@')break;
			}
		}
		if(sx==m&&sy==n){//�����û�ҵ���ʱ�������������
			printf("0\n");
			continue;
		}
		mark[sx][sy]=true;
		dfs(sx,sy);
		int ans=0;
		*/
		int ans=0;
		for(int i=0;i<m;i++){//�� д�����ò�������û���˰���
			for(int j=0;j<n;j++){
				if(mark[i][j]==false&&pic[i][j]=='@'){
					mark[i][j]=true;//�ټ�����仰����
					dfs(i,j);
					ans++;
				}
			}
		}
		printf("%d\n",ans);

	}
	return 0;
}

