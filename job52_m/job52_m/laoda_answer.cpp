//��Ȼk��С��10000��˵��������ַ�Χ���ܴܺ�  
//��仰�Ǵ���� ���� ��10000�����������100000���� ����mark�������������Ҫһǧ��
//����������ܶȹ��ƴ���.����Բ���һ�� ����10000�����������Ƕ���
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
//bool  mark[10000000];// yi qian wan  
bool  mark[200000];//�㹻��
//int  prime[10008];//����ҲԽ����Ӧ��??  ����ʱ����󣡣�
//int  prime[10000008];
//int prime[20000];
int prime[50000];
int  size_prime=1;
//int i,j;�������������������  j��Ϊi*i��ʱ��ͻ������?? ��������� long long ����Ҳ���У�����������
//��longlong�ǿ��е� �Ҳ�����Ϊ��û��i Ҳ�ĳ�Longlong
//j=i*i������ʽ�����ʱ�� �ȼ���i*i �����Զ�����һ����ʱ�������洢i*i�Ľ������ΪI��int�� ����������ʱ�洢�ı���Ҳ��int��
//���� ��i=3ʱ�����ȼ���3*3,��temp=9ȥ��¼һ�� Ȼ�� j=9. ��i=10000ʱ ����10000*10000�Ѿ���int ����˸��� Ȼ��j=�������������ֻ��j�ĳ�longlong��û�õ�
int i;
long long j;
void init (){
	for (i=0;i<200000;i++){//���濪200000������ҲҪ��200000
		mark[i]=true;
	}
	for(i=2;i<200000;i++){
		if(mark[i]==false) continue;
		prime[size_prime++]=i;

		if (i<=2000){//����j=i*i��i�Ƚϴ��ʱ�� i*i������int�ķ�Χ ����j��ɸ���������mark[j]�±곬�硣����Ԥ���ж�һ���Ƿ�i<=���ţ�200000����������ǣ��Ǿ�ֱ���Թ��ˡ�Ҳ������longlong��
		for(j=i*i;j<200000;j+=i){
			mark[j]=false;
		}
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