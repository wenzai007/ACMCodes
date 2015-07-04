/*
	�ҵ�˼· �ҵ�������һ�� Ȼ�� �������һ���������� 
	�����Ļ�  �������ͺܺý�����  �м��
*/

#define for if(0); else for 
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>//��cmath ����û��math

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

int lnum(int n){//���� ���������ĸ��������жϸ�������м����ڵ�
	if(n==1) return 0;
	//int ht=(int)log(double(n))+1;//�߶ȴ˴�����
	//logĬ������10Ϊ�׵� Ӧ��ת��
	int ht=(int)(log(double(n))/log(2.0))+1;
	int upp=(int)pow(2.0,ht-1)-1;//����һ���ж��ٸ���
	int last=(int)pow(2.0,ht-1);//���һ������ʱ���ж��ٸ���
	int nlast=n-upp;//���һ��ʵ���ж��ٸ���
	if(nlast<=last/2) 
		return (upp-1)/2+nlast; //��ʱ ��ߵ��ܸ���
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
	int rc=tt-lc-1;//��ȥ���ڵ�
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
		//sprintf(ad.c_str(),"%d",tmp.v);//�����ǲ��ǲ��а�������һ��
		//��Ȼ���� ���ܽ�const char* ת��Ϊ char*
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
		//op.substr(1);//��һ�η��˴� û�н��ܷ���ֵ�Ķ�����
		op=op.substr(1);
		printf("%s",op.c_str());
	}
	return 0;
}

