//��һ�� wa  ԭ�� �߼����������� ���ǲ��Ծ���
//̰�ĵ�˼��
//��ȷ��˼·�������ģ�  ����  ��M��0 Ȼ�����N��ÿһλ  
//���бȽ�  ���N��k����0  ��ô����m��k���ܲ�����1  �����õ�ǰ��
//λΪ1��ʱ�� ��������Сֵ���ܲ���С�ڵ���U ����1 ������0  ��N��k��Ϊ1��ʱ�� 
//�ٿ��� M��k����ֵ�ܲ�����0 ���ǵ�ǰλΪ0  ��ô�����ֵ�᲻����ڵ���L
//����0 ������1
#define for if(0); else for 
#define pf printf
#define sf  scanf
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>//��cmath ����û��math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
using namespace std;
long long N,M;
long long L,U;
int a[50],b[50];
int ida,idb;
void store(){
	ida=idb=0;
	long long x=N;
	while(x>0){
		a[ida++]=x%2;
		x/=2;
	}
	//x=M;ǧ�����Ӧ�ô������ﰡ ɵ�� ��ʼ��ʱ
	//����M����L ����M���������κ�ֵ�� ����ڹ���㰡
	//�군�أ�����
	x=L;
	while(x>0){
		b[idb++]=x%2;
		x/=2;
	}
}

/*
   long long  justdoit(){//����жϵĶ���д���ˣ���
   long long ans=L;
   for(int i=31;i>=0;i--){
   long long tmp=(long long )1<<i;//����ǵ�ǰ����һλ��Ȩ��
   if(a[i]==0){
   if(ans+tmp<=U){
   ans+=(b[i]==1)?0:tmp;
   }
   }
   else{//һ����1
   if(ans-tmp>=L){
   ans-=(b[i]==0)?0:tmp;
   }
   }
   }
   return ans;
   }
   */

long long  justdoit(){//������Ǹ��жϵĶ���д���ˣ���֪���� �����������
	//1���ж�ʲô  ������0���жϸ���
	//long long ans=0;
	long long sum=0;//��¼ǰ���Ѿ���������λ���ܺ���Ŀ
	for(int i=31;i>=0;i--){
		long long tmp=(long long )1<<i;//����ǵ�ǰ����һλ��Ȩ��
		if(a[i]==0){
			if((sum+tmp)<=U){
				sum+=tmp;
				//b[i]=1;���Բ���д
			}
			else{
				//b[i]=0;���Բ���д
			}
		}
		else{//a[i]==1
			if((sum+tmp-1)>=L){//����ǵ�ǰλ���Ϊ0ʱ������ֵ
				//b[i]=0;
			}
			else{
				sum+=tmp;
				//b[i]=1;����Ϊ1��
			}
		}
	}
	return sum;
}

int main(){
	freopen("in.txt","r",stdin);   
	while(sf("%d%d%d",&N,&L,&U)!=EOF){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		store();
		long long res=justdoit();
		pf("%lld\n",res);
	}
	return 0;
}

