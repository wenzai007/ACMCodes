/*
一开始懵了  感觉好难  后来一想  只给了后序列
但是中序序列  根本就不用给出 因为中序序列就是有序序列啊
于是  本题可以分解成 根据前序 中序 建树 
然后判断   再写一个判断的递归函数  然后还有后序遍历的函数
但是关键的一点是不知道有没有可能 前 中 序 不能够建树的情况

  我感觉不用判断的  因为判断的话难度很多大 并且 题中给出的
  是让你判断这棵树是不是bst或者其镜像  说明它已经是一棵树了
  这是前提  不用去刻意的判断他是不是一棵树了
  看来我错了
  
	但是可以用bool 变量判断的！
	我的思路是这样的：  构造树的过程 这个是关键
	就是根据中序和先序进行  构造  那么  中序是隐含已知的
	然后先找到中序的根节点的位置 （因为根的值
	可能有多个相同的值 呢么找中序中第一个等于根的点下这样
	就能看出左子树一共有多少个） 然后在先序的序列中看左子树
	是不是都是小于根的  如果是那么说明  后面的都是大于等于
	根的 因为中序已经排好序了  一共就那么多数字 前面4个都是
	小于的  后面的n-4个必然都是大于等于的  因为总数不变的

  镜像的判断是同一个道理 但是中序的序列要反过来  同时找的根
  当有多个的时候找的是最后一个根  因为左子树是小于等于的！
  哦 我其实不用重新排序的  也可以 参数改变一下就好了
  恩恩 ！！3月17日 12:54	 
  答案正确	25	1043	C++ (g++)	2	504	wenzai007
*/

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

const int size=1080;
int n;//一共多少个节点

struct node{
	node * lchild;
	node*  rchild;
	int v;//其值
}tree[size];
int loc;// 静态的记录当前有多少个节点
node * creat(){
	tree[loc].lchild=tree[loc].rchild=NULL;
	return &tree[loc++];
}
int prestr[size];
int instr[size];
int postr[size];
bool  flag;//判断是不是成功建成
string postout;//用于输出后续遍历的

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
			flag=false;//不符合的时候树只是建成了一部分
			// 是一个不完整的树我们通过flag判断是否建成了
			return NULL;/*不符合要求返回空值否则后面的一定
			满足大于等于的要求的*/
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
			postout=postout.substr(1);//从1位置开始截取 但是必须有接受的
			//需要写等于  不是作用于原对象的 
			printf("YES\n%s\n",postout.c_str());//这个地方 unhandle 报错
			//因为没有c_str()
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

