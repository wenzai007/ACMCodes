/*
�ֱ��¼1�����ҵ�������ľ���ʹ��ҵ���ĸ�����ľ���

  �鷳��  �������ϵ�˼·  ��ʵ���Ǽ�¼һ��������

  ���� ˳ʱ������г��� Ȼ���Ƕ��߾���1�Ĳ�ֵ
  ��������Բ�ܵľ����ȥ  �����ֵ  ���ü�¼��ʱ��ľ����
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
const int size=100080;

int rdis[size];
int ldis[size];
int dif[size];
int N,K;
int main(){
	freopen("in.txt","r",stdin);   
	while (scanf("%d",&N)!=EOF){
		rdis[1]=0;int sum=0;int d;
		for(int i=1;i<N;i++){//ǰn-1����
			scanf("%d",&d);
			dif[i]=d;
			sum+=d;
			rdis[i+1]=sum;
		}
		scanf("%d",&d);//���һ��
		ldis[1]=0;sum=d;
		for(int i=N;i>=2;i--){
			ldis[i]=sum;
			sum+=dif[i-1];
		}
		scanf("%d",&K);
		int a,b;
		while (K--!=0){
			scanf("%d%d",&a,&b);
			if(a>b){
				int tmp=a;
				a=b;
				b=tmp;
			}
			int min1=rdis[b]-rdis[a];
			int min2=ldis[b]+rdis[a];
			printf("%d\n",min1<=min2?min1:min2);
		}

	}
	return 0;
}

