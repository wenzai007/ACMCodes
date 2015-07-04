#define for if(0); else for
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>>//有cmath 但是没有math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
using namespace std;

int loc;
struct node{
	node* lchild;
	node* rchild;
	int v;
}tree[50];

int instr[38];
int poststr[38];
int idx;
node * creat(){
	tree[loc].lchild=tree[loc].rchild=NULL;
	return &tree[loc++];//返回的是一个地址也就是指针
}

node * build(int s1,int e1,int s2,int e2){
	node * ret=creat();//建立节点 
	ret->v=poststr[e1];
	int ix;
	for(ix=s2;ix<=e2;ix++){
		if(instr[ix]==poststr[e1])
			break;
	}
	if(ix!=s2){
		ret->lchild=build(s1,s1+ix-s2-1,s2,ix-1);
	}
	if(ix!=e2){
		ret->rchild=build(e1-(e2-ix),e1-1,ix+1,e2);
	}
	return ret;
}

void leveltravel(node * t){
	queue<node*> q;//可以这样些么？？可以 可以防指针 太好了！
	q.push(t);
	int num=0;
	while(!q.empty()){
		node *  nowp=q.front();
		q.pop();
		if(num!=0) printf(" ");
		printf("%d",nowp->v);
		num++;
		if(nowp->lchild){
			q.push(nowp->lchild);
		}
		if(nowp->rchild){
			q.push(nowp->rchild);
		}
	}
}
int main(){
	freopen("in.txt","r",stdin);
	loc=0;
	while(scanf("%d",&idx)!=EOF){
		for(int i=0;i<idx;i++){
			scanf("%d",&poststr[i]);
		}
		for(int i=0;i<idx;i++){
			scanf("%d",&instr[i]);
		}
		node * root =build(0,idx-1,0,idx-1);
		leveltravel(root);		
		
	}
	return 0;
}

