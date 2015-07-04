//一次运行结果不对  是因为int t=np.t+1;写成了int t=np.c+1;
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
struct  N{//状态结构体 
	int a,b,c,t;
};
queue<N>  q;
bool mark[102][102][102];
//不要定义在全局 这样和 bfs中的混了！！   int n,m,s;
void atob(int &a,int va,int &b,int vb){
	if(a<=vb-b){
		b+=a;
		a=0;
		//如果a先置零 那么b不就是不变了么！？
		//a=0;逻辑出现超级错误！！！顺序反了
		//b+=a;
	}
	else {
		//这个顺序是对的 同样也不能变  如果变了的话
		//a 就直接变成0了！！！！
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
		//这里害了我找了半天  写错了啊！！int t=np.c+1;
		if(a==b&&c==0||b==c&&a==0||a==c&&b==0) return t-1;
		N tmp;
		atob(a,s,b,n);
		if(mark[a][b][c]==false){
			mark[a][b][c]=true;
			tmp.a=a;tmp.b=b; tmp.c=c; tmp.t=t;
			q.push(tmp);
		}//如果是true 的话  执行下面  如果是false的话也执行下面
		//不过上面的是一个必须要执行的东西   类似于筛选
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
        //加一句 50% 的剪枝语句！！  奇数的话不可能平分！
		if(s%2==1) {
			printf("NO\n");
			continue;
		}

		while (!q.empty()) q.pop();
		        for(int i=0;i<=s;i++)
			for(int j=0;j<=n;j++)
				for(int k=0;k<=m;k++)
					mark[i][j][k]=false;

		/*此处没必要 全都初始化  s n m 即可否则太耗时
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

