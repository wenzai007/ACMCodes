#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>

#include<algorithm>
#include<math.h>

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>
using namespace std;


int primes[]={2,3,5,7,11,13,17,19,23,29,31,37};//12 numbers
int ans[28];
bool mark[28];
int N;//�������������� ����Ļ�  dfs�����Ͳ���ʶN��
bool isprime(int x){
	for(int i=0;i<12;i++){
		if(primes[i]==x)return true;
		//return false ;���� ����ô�ж�������ô�������߼�

	}
	return false;
}



void  dfs(int num){//num �ǵ�ǰ �����ֵ��±�
	if(num>1) {
		if(!isprime(ans[num]+ans[num-1]))
			return;
	}
	if(num==N){
		if(!isprime(ans[num]+ans[1]) ) return;//����� ����ö��
		for(int i=1;i<=N;i++){
			if(i!=1) printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
		//�˴���ʼ���Ǽ�return��  ��ȻҲac����Ϊ�����forѭ����ȫ��false ����ִ����forѭ��֮���Զ�return �� ���� ��ȷ��д���Ǽ���return
		return ;
	}
	for(int i=2;i<=N;i++){
		if(mark[i]==false){
			mark[i]=true;
			ans[num+1]=i;
			dfs(num+1);//������еĻ� �ͻ� ��forѭ��������һ����
			//mark[num+1]=false;�Ұ�һ����ȫû�������������Ϊfalse
			mark[i]=false;
		}
	}
}

int main(){
	freopen("in.txt","r",stdin);
	int cnt=0;
	while (scanf("%d",&N)!=EOF){
		cnt++;
		printf("Case %d:\n",cnt);
		for(int i=1;i<=N;i++){
			mark[i]=false;
		}
		mark[1]=true;
		ans[1]=1;
		//dfs(2);���ո�ȥ ���ֱ�Ӿͷ�����
		//��ö�ٸ�ƨ����
		dfs(1);
		printf("\n");
	}
	return 0;
}

