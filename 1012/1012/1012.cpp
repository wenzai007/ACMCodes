
//�ǳ�֮�� ��һ����  ��Ҫ�Լ�����������������⣡��  fuck����
//�μ����ϵĴ���  online  ֻ���˲���60�У���
//���� patò�Ʋ����Ǹ�   while scanf  ��=eof  �����Ϊ��ÿ��caseֻ��һ��
//���ӵ�
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
using namespace std;
int N,M;
struct N{
	int id;
	int c,m,e,a;
	bool operator <(const N &B) const{
		return id<B.id;
	}
}buf[2080];
int c_score[101];
int m_score[101];
int e_score[101];
int a_score[101];

int binary(int the_id){
	int low=0;int high=N-1; int mid;
	while (low<=high){
		mid=(low+high)/2;
		if(buf[mid].id==the_id) return mid;
		if(buf[mid].id<the_id) low=mid+1;
		else high=mid-1;
	}
	return -1;
}

//int  round(double x){//��������Ϊround  ��pat����� �������ص�  �����ϸ�
//  ��������  ����ط���ʵ���Բ������������  ֻ�ǽ�3��������Ӿͺ���
//  ��Ϊֻ�����������������  ���Բμ�online
int  my_round(double x){
	double aa=x>0?x+0.5:x-0.5;
	return (int)aa;
}

int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d%d",&N,&M)!=EOF){
		for(int i=0;i<=100;i++){
			c_score[i]=m_score[i]=e_score[i]=a_score[i]=0;
		}
		for(int i=0;i<N;i++){
			scanf("%d%d%d%d",&buf[i].id,&buf[i].c,&buf[i].m,&buf[i].e);

			c_score[buf[i].c]++;
			m_score[buf[i].m]++;
			e_score[buf[i].e]++;
			int avg= my_round((buf[i].c+buf[i].m+buf[i].e)/3);
			a_score[avg]++;
			buf[i].a=avg;
		}
		//��Ϊ����������hash�ķ�ʽ���д洢��  ���Ը����Ͳ��������
		//ֱ��ͳ��ǰ��һ���ж��ٸ��Ϳ����ˣ�

		//������������Խṹ�尴��ѧ�Ž�������Ļ� ��ô��Ҫnlogn
		//Ȼ���ѯ��ʱ����ֲ�����Ҫ  n*logn
		//���������Ļ�  ��ôÿһ�β��Ҷ���n�� һ����n*n�� 
		//�����������Ļ�   �Ҿ��û�����һ����ȽϺ�һЩ��˵��
		sort(buf,buf+N);
		int checkid;
		for(int i=0;i<M;i++){
			scanf("%d",&checkid);
			int flag=binary(checkid);
			if(flag==-1) {
				printf("N/A\n");
				continue;
			}
			
			int min=0xfffffff; char choose='A';
			int a_perf=buf[flag].a;
			int c_perf=buf[flag].c;
			int m_perf=buf[flag].m;
			int e_perf=buf[flag].e;
			//�˴�������ʵ����������� ����4��if ̫�鷳�� 
			int rank=0;
			//���� ˳��д���ˣ�����
			//for(int i=0;i<a_perf;i++){
			/*
			for(int i=100;i>a_perf;i--){
				rank+=a_score[i]++;//��������ʲô��
				//ΪʲôҪ++  �в����㣡��
			}
			*/
			for(int i=100;i>a_perf;i--){
				rank+=a_score[i];//
			}
			rank+=1;
			if(rank<min){
				min=rank;
				choose='A';
			}
			rank=0;
			for(int i=100;i>c_perf;i--){
				rank+=c_score[i];
			}
			rank+=1;
			if(rank<min){
				min=rank;
				choose='C';
			}
			rank=0;
			for(int i=100;i>m_perf;i--){
				rank+=m_score[i];
			}
			rank+=1;
			if(rank<min){
				min=rank;
				choose='M';
			}
			rank=0;//���Ǽ���
			for(int i=100;i>e_perf;i--){
				rank+=e_score[i];
			}
			rank+=1;
			if(rank<min){
				min=rank;
				choose='E';
			}
			//printf("%d %c\n",rank,choose);//�������Ǵ�ɵb   �������ΪʲôҪ���rank������
		  printf("%d %c\n",min,choose);

		}
	}
	return 0;
}

