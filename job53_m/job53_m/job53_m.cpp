//�����������ݽṹ����������ķ���
//����ȥ�� �Ϳ����ˣ�
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
bool mark[50000];
int prime[30000];
void init(){
	int size_prime=0;
	for(int i=0;i<50000;i++){
		mark[i]=true;
	}
	//for(int i=0;i<50000;i++){//������ȫ���в���ȥ����� Ҳû�б���  �ִ��� ͬ����  ��2��ʼ
	for(int i=2;i<50000;i++){
		if(mark[i]==false)continue;
		prime[size_prime++]=i;
		if(i>300)continue;
		for(int j=i*i;j<50000;j+=i){
			mark[j]=false;
		}
	}
}


int main(){
	freopen("in.txt","r",stdin);
	//������һ�����ǳ�ʼ����������
	init();
	int even;
	//while (scanf("%d",even)!=EOF&&even){�ڼ���u���󣿣�
	while (scanf("%d",&even)!=EOF&&even){
		int p_idx=0;
		while(prime[p_idx]<even){
			p_idx++;
		}
		p_idx--;//���һ��С��even������
		int pair_num=0,i=0,j=p_idx;
		while(i<=j){
			if(prime[i]+prime[j]==even){
				i++;j--;
				pair_num++;
				continue;
			}
			if(prime[i]+prime[j]<even){
				i++;continue;
			}
			else{
				j--;
			}
		}
		printf("%d\n",pair_num);
	}

	return 0;
}
