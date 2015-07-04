#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
char prestr[30];
char instr[30];
struct  node{
	node* lchild;
	node* rchild;
	char c;
}tree[50];
int loc;// 已经创建的节点的个数
node * creat(){
	//机试指南建议的是不用malloc动态分配内存  而是用静态的数组进行分配
	//tree[loc].lchild=tree[loc].rchild=null;//但是指针必须初始化
	//不能写成null 要写成NULL             //否则会出错的
     tree[loc].lchild=tree[loc].rchild=NULL;
	return &tree[loc++];//先返回 再自增!
}
void postorder(node *T){//必然用的指针类型
	if(T){
		if(T->lchild){
			postorder(T->lchild);
		}
		if(T->rchild){
			postorder(T->rchild);
		}
		printf("%c",T->c);
	}
}
node * build(int s1,int e1,int s2,int e2){//时刻为了找根节点
	//实质上是一个递归函数
	node * ret=creat();
	ret->c=prestr[s1];
	int rootidx;
	int i;
	for(i=s2;instr[i]!=prestr[s1];i++);
	rootidx=i;
	if(rootidx>s2){
		ret->lchild=build(s1+1,s1+(rootidx-s2),s2,rootidx-1);
	}
	if(rootidx<e2){
		ret->rchild=build(s1+(rootidx-s2)+1,e1,rootidx+1,e2);
	}
	return ret;

}



int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%s",prestr)!=EOF){
		scanf("%s",instr);
		loc=0;//不能忘记
	    int L=strlen(prestr);//注意和sizeof（求占用总字节）的区别
		node * res=build(0,L-1,0,L-1);
		postorder(res);
		printf("\n");
	}
	return 0;
}









//effect
