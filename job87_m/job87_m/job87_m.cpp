//һ�����н������  ����Ϊint t=np.t+1;д����int t=np.c+1;
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
struct  N{//״̬�ṹ�� 
	int a,b,c,t;
};
queue<N>  q;
bool mark[102][102][102];
//��Ҫ������ȫ�� ������ bfs�еĻ��ˣ���   int n,m,s;
void atob(int &a,int va,int &b,int vb){
	if(a<=vb-b){
		b+=a;
		a=0;
		//���a������ ��ôb�����ǲ�����ô����
		//a=0;�߼����ֳ������󣡣���˳����
		//b+=a;
	}
	else {
		//���˳���ǶԵ� ͬ��Ҳ���ܱ�  ������˵Ļ�
		//a ��ֱ�ӱ��0�ˣ�������
		a-=vb-b;
		b=vb;
	}
}

int bfs(int s,int n,int m){
	while (!q.empty()){
		N np=q.front();
		q.pop();
		int a=np.a;int b=np.b; int c=np.c;
		int t=np.t+1;
		//���ﺦ�������˰���  д���˰�����int t=np.c+1;
		if(a==b&&c==0||b==c&&a==0||a==c&&b==0) return t-1;
		N tmp;
		atob(a,s,b,n);
		if(mark[a][b][c]==false){
			mark[a][b][c]=true;
			tmp.a=a;tmp.b=b; tmp.c=c; tmp.t=t;
			q.push(tmp);
		}//�����true �Ļ�  ִ������  �����false�Ļ�Ҳִ������
		//�����������һ������Ҫִ�еĶ���   ������ɸѡ
		a=np.a; b=np.b; c=np.c; t=np.t+1;
		atob(b,n,a,s);
		if(mark[a][b][c]==false){
			mark[a][b][c]=true;
			tmp.a=a;tmp.b=b; tmp.c=c; tmp.t=t;
			q.push(tmp);
		}
		a=np.a; b=np.b; c=np.c; t=np.t+1;
		atob(a,s,c,m);
		if(mark[a][b][c]==false){
			mark[a][b][c]=true;
			tmp.a=a;tmp.b=b; tmp.c=c; tmp.t=t;
			q.push(tmp);
		}
		a=np.a; b=np.b; c=np.c; t=np.t+1;
		atob(c,m,a,s);
		if(mark[a][b][c]==false){
			mark[a][b][c]=true;
			tmp.a=a;tmp.b=b;tmp.c=c; tmp.t=t;
			q.push(tmp);
		}
		a=np.a; b=np.b; c=np.c; t=np.t+1;
		atob(b,n,c,m);
		if(mark[a][b][c]==false){
			mark[a][b][c]=true;
			tmp.a=a;tmp.b=b;tmp.c=c; tmp.t=t;
			q.push(tmp);
		}
		a=np.a; b=np.b; c=np.c; t=np.t+1;
		atob(c,m,b,n);
		if(mark[a][b][c]==false){
			mark[a][b][c]=true;
			tmp.a=a;tmp.b=b;tmp.c=c; tmp.t=t;
			q.push(tmp);
		}
	}
	return -1;
}
int main(){
	int s,n,m;
	freopen("in.txt","r",stdin);
	while (scanf("%d%d%d",&s,&n,&m)!=EOF){
		if(s==0&&n==0&&m==0)break;
        //��һ�� 50% �ļ�֦��䣡��  �����Ļ�������ƽ�֣�
		if(s%2==1) {
			printf("NO\n");
			continue;
		}

		while (!q.empty()) q.pop();
		        for(int i=0;i<=s;i++)
			for(int j=0;j<=n;j++)
				for(int k=0;k<=m;k++)
					mark[i][j][k]=false;

		/*�˴�û��Ҫ ȫ����ʼ��  s n m ���ɷ���̫��ʱ
		for(int i=0;i<102;i++)
			for(int j=0;j<102;j++)
				for(int k=0;k<102;k++)
					mark[i][j][k]=false;
		*/
		N fs;
		fs.a=s;fs.b=0;fs.c=0;fs.t=0;
		mark[s][0][0]=true;
		q.push(fs);
		int ans=bfs(s,n,m);
		if(ans==-1) printf("NO\n");
		else printf("%d\n",ans);
	}
	return 0;
}

