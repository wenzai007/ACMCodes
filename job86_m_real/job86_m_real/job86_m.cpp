//�����  ����״̬��  �仯������ �ǵ�
//��������wa��ԭ����  ��ն��е� λ��д���ˣ���
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
int maze[52][52][52];
bool mark[52][52][52];
struct step{
	int x,y,z,t;
};
queue<step>q;
int K,k,a,b,c,tt;
int gotype[][3]={
	-1,0,0,
	1,0,0,
	0,-1,0,
	0,1,0,
	0,0,-1,
	0,0,1
};
int bfs(int a,int b,int c){
	while (!q.empty()){
		step nowp=q.front();
		q.pop();
		if(nowp.x==a-1&&nowp.y==b-1&&nowp.z==c-1) {
			//�˴���Ҫ��ʲôbreak�� ��Ҫ�ж�����Ϊ���break������Ϊ
			//q�ǿ��˲�break��  ����ֱ�ӴӺ����ĵط����ؾͺ��ˣ���
			return nowp.t;
		}
		for(int i=0;i<6;i++){
			int x=nowp.x+gotype[i][0];
			int y=nowp.y+gotype[i][1];
			int z=nowp.z+gotype[i][2];
			int t=nowp.t+1;
			if (mark[x][y][z]==true) continue;
			if(x<0||x>a-1||y<0||y>b-1||z<0||z>c-1) continue ;
			//������ؼ���һ�仰  �����ɵ�� �Թ����û��ǽ�Ļ�����
			//��jbë���Թ��˰�������
			if(maze[x][y][z]==1) continue;  //��ǽ�Ļ�����ë������
			step tmp;
			tmp.x=x;tmp.y=y;tmp.z=z;tmp.t=t;
			mark[x][y][z]=true;
			q.push(tmp);
		}
	}
	return -1;//�����Ѿ�����  ���ǻ���û�е���  �յ㣡��
}
int main(){
	freopen("in.txt","r",stdin);
	scanf("%d",&K);//Ӧ�ò��� EOF�˰�  
	while(!q.empty())q.pop();//������wa��ԭ��  λ��д���ˣ���
	while(K--!=0){
		scanf("%d%d%d%d",&a,&b,&c,&tt);
		while(!q.empty()) q.pop();
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
				for(int k=0;k<c;k++){
					scanf("%d",&maze[i][j][k]);
					mark[i][j][k]=false;
				}
			}
		}
		step st;
		st.x=st.y=st.z=st.t=0;
		q.push(st);
		mark[0][0][0]=true;
		int ans=bfs(a,b,c);
		//if(ans==-1||ans>tt) printf("-1\n");
		//else printf("%d\n",ans);
		if(ans<=tt )printf("%d\n",ans);
		else printf("-1\n");
	}
	
	return 0;
}

