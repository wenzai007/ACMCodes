//挺顺的  一次就ac!!
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
int idx=0;
char std_pre[12],std_in[12],test_pre[12],test_in[12];
bool flag;
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
node * insert (int x,node* T){//初始考虑T是否为NULL
	if(T==NULL){
		T=creat();
		T->value=x;
	}
	else if(x<T->value)
		T->lchild=insert(x,T->lchild);
	else if(x>T->value)
		T->rchild=insert(x,T->rchild);
	return T;


}
void preoder(node * t){
	//idx=0;
	if(t){
		if(flag==1)std_pre[idx++]=t->value+'0';
		else test_pre[idx++]=t->value+'0';
		if(t->lchild)
			preoder(t->lchild);
		if(t->rchild)
			preoder(t->rchild);
	}
	//if(flag=1)std_pre[idx]=0;
	//else test_pre[idx]=0;
}
void inorder(node * t){
	//idx=0;
	if(t){
		if(t->lchild)
			inorder(t->lchild);
		//printf("%d ",t->value);
		if(flag==1)std_in[idx++]=t->value+'0';
		else test_in[idx++]=t->value+'0';
		if(t->rchild)
			inorder(t->rchild);
	}
	//if(flag=1)std_in[idx]=0;
	//else test_in[idx]=0;



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
char standerd[16];
char test[16];
int main(){
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	while (scanf("%d",&n)!=EOF&&n){
		loc=0;
		node *root=NULL;
		scanf("%s",standerd);
		for(int i=0;i<strlen(standerd);i++){
			root=insert(standerd[i]-'0',root);
		}
		flag=1;
		idx=0;
		preoder(root);
		std_pre[idx]=0;
		idx=0;
		inorder(root);
		std_in[idx]=0;
		while (n--!=0){
			loc=0;
			flag=0;
			scanf("%s",test);
			node * tt=NULL;
			for(int i=0;i<strlen(test);i++){
				tt=insert(test[i]-'0',tt);
			}
			idx=0;
			preoder(tt);
			test_pre[idx]=0;
			idx=0;
			inorder(tt);
			test_in[idx]=0;
			if(strcmp(std_pre,test_pre)==0&&strcmp(std_in,test_in)==0){
				printf("YES\n");
			}
			else printf("NO\n");
		}
	}
	return 0;
}
