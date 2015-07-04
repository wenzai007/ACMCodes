/*
	我的思路 找到最下面一层 然后 上面的是一个满二叉树 
	这样的话  建立数就很好建立了  中间的
*/

#define for if(0); else for 
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>//有cmath 但是没有math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
using namespace std;

struct node{
	node* lchild;
	node* rchild;
	int v;
}tree[1080];
int n;
int buf[1080];
int loc;
node* creat(){
	tree[loc].lchild=tree[loc].rchild=NULL;
	return &tree[loc++];
}

string op;

int lnum(int n){//给你 满二叉树的个数让你判断根的左边有几个节点
	if(n==1) return 0;
	//int ht=(int)log(double(n))+1;//高度此处错了
	//log默认是以10为底的 应该转化
	int ht=(int)(log(double(n))/log(2.0))+1;
	int upp=(int)pow(2.0,ht-1)-1;//上面一共有多少个点
	int last=(int)pow(2.0,ht-1);//最后一层满的时候有多少个点
	int nlast=n-upp;//最后一层实际有多少个点
	if(nlast<=last/2) 
		return (upp-1)/2+nlast; //此时 左边的总个数
	else 
		return (upp-1)/2+last/2;
}

node * build(int s,int e){
	node * r=creat();
	if(s==e){
		r->v=buf[s];
		return r;
	}
	int tt=e-s+1;
	int lc=lnum(tt);
	int rc=tt-lc-1;//出去根节点
	r->v=buf[s+lc];
	if(lc!=0)
		r->lchild=build(s,s+lc-1);
	if(rc!=0)
		r->rchild=build(s+lc+1,s+lc+1+rc-1);
	return r;
}

void lt(node *root){
	queue<node*> q;
	q.push(root);
	while (!q.empty()){
		node* tmp=q.front();
		q.pop();
		op+=" ";
		string ad;
		//sprintf(ad.c_str(),"%d",tmp.v);//这样是不是不行啊？？试一试
		//果然不行 不能将const char* 转化为 char*
		char aaa[6];
		sprintf(aaa,"%d",tmp->v);
		ad=aaa;
		op+=ad;
		if(tmp->lchild)
			q.push(tmp->lchild);
		if(tmp->rchild)
			q.push(tmp->rchild);
	}
}
int main(){
	freopen("in.txt","r",stdin);   
	while (scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&buf[i]);
		}
		sort(buf,buf+n);
		loc=0;
		node *root = build(0,n-1);
		op="";
		lt(root);
		//op.substr(1);//又一次犯了错 没有接受返回值的东西啊
		op=op.substr(1);
		printf("%s",op.c_str());
	}
	return 0;
}

