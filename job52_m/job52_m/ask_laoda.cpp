//��Ȼk��С��10000��˵��������ַ�Χ���ܴܺ�  
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
//bool  mark[10000000];// yi qian wan  
bool  mark[200000];
//int  prime[10008];//����ҲԽ����Ӧ��??  ����ʱ����󣡣�
//int  prime[10000008];
//int prime[20000];
int prime[50000];
int  size_prime=1;
//int i,j;�������������������  j��Ϊi*i��ʱ��ͻ������?? ��������� long long ����Ҳ���У�����������
int i;
long long j;
void init (){
	for (i=0;i<100000;i++){
		mark[i]=true;
	}
	for(i=2;i<100000;i++){
		if(mark[i]==false) continue;
		prime[size_prime++]=i;
		for(j=i*i;j<100000;j+=i){
			mark[j]=false;
		}
	}
}

int main(){
	init();
	int n;
	while (scanf("%d",&n)!=EOF){
		printf("%d\n",prime[n]);
	}
	return 0;
}
