/*
һ��ʼ����  �о�����  ����һ��  ֻ���˺�����
������������  �����Ͳ��ø��� ��Ϊ�������о����������а�
����  ������Էֽ�� ����ǰ�� ���� ���� 
Ȼ���ж�   ��дһ���жϵĵݹ麯��  Ȼ���к�������ĺ���
���ǹؼ���һ���ǲ�֪����û�п��� ǰ �� �� ���ܹ����������

  �Ҹо������жϵ�  ��Ϊ�жϵĻ��ѶȺܶ�� ���� ���и�����
  �������ж�������ǲ���bst�����侵��  ˵�����Ѿ���һ������
  ����ǰ��  ����ȥ������ж����ǲ���һ������
  �����Ҵ���
  
	���ǿ�����bool �����жϵģ�
	�ҵ�˼·�������ģ�  �������Ĺ��� ����ǹؼ�
	���Ǹ���������������  ����  ��ô  ������������֪��
	Ȼ�����ҵ�����ĸ��ڵ��λ�� ����Ϊ����ֵ
	�����ж����ͬ��ֵ ��ô�������е�һ�����ڸ��ĵ�������
	���ܿ���������һ���ж��ٸ��� Ȼ��������������п�������
	�ǲ��Ƕ���С�ڸ���  �������ô˵��  ����Ķ��Ǵ��ڵ���
	���� ��Ϊ�����Ѿ��ź�����  һ������ô������ ǰ��4������
	С�ڵ�  �����n-4����Ȼ���Ǵ��ڵ��ڵ�  ��Ϊ���������

  ������ж���ͬһ������ �������������Ҫ������  ͬʱ�ҵĸ�
  ���ж����ʱ���ҵ������һ����  ��Ϊ��������С�ڵ��ڵģ�
  Ŷ ����ʵ�������������  Ҳ���� �����ı�һ�¾ͺ���
  ���� ����3��17�� 12:54	 
  ����ȷ	25	1043	C++ (g++)	2	504	wenzai007
*/

#define for if(0); else for 
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>>//��cmath ����û��math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
using namespace std;

const int size=1080;
int n;//һ�����ٸ��ڵ�

struct node{
	node * lchild;
	node*  rchild;
	int v;//��ֵ
}tree[size];
int loc;// ��̬�ļ�¼��ǰ�ж��ٸ��ڵ�
node * creat(){
	tree[loc].lchild=tree[loc].rchild=NULL;
	return &tree[loc++];
}
int prestr[size];
int instr[size];
int postr[size];
bool  flag;//�ж��ǲ��ǳɹ�����
string postout;//�����������������

node * isbst (int s1,int e1,int s2,int e2){
	node * r=creat();
	r->v=prestr[s1];
	int ix;
	for(ix=s2;ix<=e2;ix++){
		if(instr[ix]==prestr[s1])
			break;
	}
	for(int i=s1+1;i<=s1+ix-s2;i++){//s1+1
		if(prestr[i]>=prestr[s1]){
			flag=false;//�����ϵ�ʱ����ֻ�ǽ�����һ����
			// ��һ����������������ͨ��flag�ж��Ƿ񽨳���
			return NULL;/*������Ҫ�󷵻ؿ�ֵ��������һ��
			������ڵ��ڵ�Ҫ���*/
		}
	}
	if(ix!=s2){
		r->lchild=isbst(s1+1,s1+ix-s2,s2,ix-1);
	}
	if(ix!=e2){
		r->rchild=isbst(s1+ix-s2+1,e1,ix+1,e2);
	}
	return r;
}

node * isbstmirror (int s1,int e1,int s2,int e2){
	node *r =creat();
	r->v=prestr[s1];
	int ix;
	for(ix=s2;ix<=e2;ix++){
		if(instr[ix]==prestr[s1])
			break;
	}
	for(int i=s1+1;i<=s1+e2-ix;i++){
		if(prestr[i]<prestr[s1]){
			flag=false;//
			return NULL;
		}
	}
	if(ix!=s2){
		r->rchild=isbstmirror(s1+e2-ix+1,e1,s2,ix-1);
	}
	if(ix!=e2){
		r->lchild=isbstmirror(s1+1,s1+e2-ix,ix+1,e2);
	}
	return r;
}

void postrav(node* t){
	if(t){
		if(t->lchild){
			postrav(t->lchild);
		}
		if(t->rchild){
			postrav(t->rchild);
		}
		char tm[2];
		sprintf(tm," %d",t->v);
		string ttm=tm;
		postout+=ttm;
	}
}
int main(){
	freopen("in.txt","r",stdin);   
	while (scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&prestr[i]);
			instr[i]=prestr[i];
		}
		sort(instr,instr+n);
		flag=true;
		loc=0;
		postout="";
		node * root=isbst(0,n-1,0,n-1);
		if(flag==true){
			postrav(root);
			postout=postout.substr(1);//��1λ�ÿ�ʼ��ȡ ���Ǳ����н��ܵ�
			//��Ҫд����  ����������ԭ����� 
			printf("YES\n%s\n",postout.c_str());//����ط� unhandle ����
			//��Ϊû��c_str()
			continue;
		}
		
		flag=true;
		loc=0;
		postout="";
		//sort(instr,instr+n,greater<int>());
		node *root2=isbstmirror(0,n-1,0,n-1);
		if(flag==true){
			postrav(root2);
			postout=postout.substr(1);
			printf("YES\n%s\n",postout.c_str());
			continue;
		}
		printf("NO\n");
		
	}
	
	return 0;
}

