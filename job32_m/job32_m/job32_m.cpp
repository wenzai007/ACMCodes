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
int loc;// �Ѿ������Ľڵ�ĸ���
node * creat(){
	//����ָ�Ͻ�����ǲ���malloc��̬�����ڴ�  �����þ�̬��������з���
	//tree[loc].lchild=tree[loc].rchild=null;//����ָ������ʼ��
	//����д��null Ҫд��NULL             //���������
     tree[loc].lchild=tree[loc].rchild=NULL;
	return &tree[loc++];//�ȷ��� ������!
}
void postorder(node *T){//��Ȼ�õ�ָ������
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
node * build(int s1,int e1,int s2,int e2){//ʱ��Ϊ���Ҹ��ڵ�
	//ʵ������һ���ݹ麯��
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
		loc=0;//��������
	    int L=strlen(prestr);//ע���sizeof����ռ�����ֽڣ�������
		node * res=build(0,L-1,0,L-1);
		postorder(res);
		printf("\n");
	}
	return 0;
}









//effect
