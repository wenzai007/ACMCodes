//一次就ac了  给力！！！
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
struct  node{
	node *lchild;
	node *rchild;
	int value;
}tree[108];
int loc;
node * creat(){
	node *p=&tree[loc++];
	p->lchild=p->rchild=NULL;
	return p;
}
void insert (int x,node* T){//初始时刻参数T假定不是空并且已经赋值 不考虑
	node*p=T;//工作指针
	while (p){
		if(x==p->value)break;
		if(x<p->value){
			if(p->lchild){
				p=p->lchild;
				continue;
			}
			else{
				p->lchild=creat();
				p->lchild->value=x;
				break;
			}
		}
		else {//  bigger  right
			if(p->rchild){
				p=p->rchild;
				continue;
			}
			else{
				p->rchild=creat();
				p->rchild->value=x;
				break;
			}
		}
	}
}
void preoder(node * t){
	if(t){
		printf("%d ",t->value);
		if(t->lchild)
			preoder(t->lchild);
		if(t->rchild)
			preoder(t->rchild);
	}
}
void inorder(node * t){
	if(t){
		if(t->lchild)
			inorder(t->lchild);
		printf("%d ",t->value);
		if(t->rchild)
			inorder(t->rchild);
	}
	
}
void postorder(node* t){
	if(t){
		if(t->lchild)
			postorder(t->lchild);
		if(t->rchild)
			postorder(t->rchild);
		printf("%d ",t->value);
	}
}

int main(){
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	while (scanf("%d",&n)!=EOF){
		loc=0;
		int valuetmp;
		node* root=creat();
		scanf("%d",&(root->value));
		for(int i=1;i<=n-1;i++){
			scanf("%d",&valuetmp);
			insert(valuetmp,root);
		}
		//遍历输出
		preoder(root);
		printf("\n");
		inorder(root);
		printf("\n");
		postorder(root);
		printf("\n");
	}
	return 0;
}
