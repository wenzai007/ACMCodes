#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>// add graghs  
using namespace std;
const int size = 10000008;
int tree[size];
int num[size];
int n,a,b;
int findroot(int x){
	if(tree[x]==-1)return x;
	else {
		int tmp=findroot(tree[x]);
		tree[x]=tmp;
		return tmp;
	}
}

int main(){
	freopen("in.txt","r",stdin);
	//!!���� ��������0�ģ���while(scanf("%d",&n)!=EOF&&n){
	while(scanf("%d",&n)!=EOF){
		/*���ﲻ���� ÿ�ε���ſ��ܴܺ� ����Ҫȫ����ʼ��
		for(int i=1;i<=n;i++){
		tree[i]=-1;
		num[i]=1;
		}
		*/
		/*���ѭ������Խ��Ӷ��ı��������ı�����ֵ
		for(int i=1;i<=size;i++){
			tree[i]=-1;
			num[i]=1;
		}
		*/
		for(int i=0;i<size;i++){
			tree[i]=-1;
			num[i]=1;
		}
		for(int i=0;i<n;i++){
			scanf("%d%d",&a,&b);
			a=findroot(a);
			b=findroot(b);
			if(a!=b){
				tree[a]=b;
				num[b]+=num[a];
			}
		}
		int maxnum=1;
		for(int i=1;i<=size;i++){
			if(tree[i]==-1&&num[i]>maxnum)
				maxnum=num[i];
		}
		printf("%d\n",maxnum);
	}
	

return 0;
}

