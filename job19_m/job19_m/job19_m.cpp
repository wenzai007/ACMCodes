//�����Ļ� �Ҿ���������ָ��ľͺ�
//�ܽ� ��˼·�ǶԵĵ�����Ȼ����
//���ǰ� �ض���Ķ������Ĺ���
//����85 һ��ʼ��Ȼ��д��25  ����nb��һ����Ϳ
//����n-- ��--n  ���ֻ����һ��Ļ�����
//����ֻҪ�������ķ��Ž�� ��Ҫ���Ǻ���n--����--n
//Ҫ�����n��ѭ���Ļ���Ҫ��while (n--!=0)  
#include<stdio.h>
#include<string.h>
#include <algorithm>
using namespace std;
int buf[85];
int n;
int k;
int i;
int tmp;
int main(){
	//freopen("in.txt","r",stdin);  ��������һ��������ע�� 
	//freopen("out.txt","w",stdout);
	while (scanf("%d",&n)!=EOF&&n){
		//while(--n!=0){//n--������  n-- �� --n��ȫ�ǲ�ͬ�İ�����
						// ǰ������ȼ����ж� ����������ж��ټ� 
						//���� ����Ӧ�����ж��ټ�������
		while(n--!=0){	
			scanf("%d",&k);
			for(i=0;i<k;i++){
				scanf("%d",&tmp);
				buf[i]=tmp;
			}
			int pre=0,work=1,rear=2;//����һֱ�Ѿ�������kҲ���������
									//��������4  ���Բ��ÿ����������
			int cnt=0;//���ڼ���  ���ƿո�����
			if(buf[0]!=buf[1]){
				cnt++;
				printf("0");
			}
			while(rear!=k){
				if((buf[work]>buf[pre]&&buf[work]>buf[rear])||buf[work]<buf[pre]&&buf[work]<buf[rear]){
					if(cnt==0)printf("%d",work);
					else printf(" %d",work);
					cnt++;
				}
				pre++;work++;rear++;
               
			}
			//����ʱ��rearΪk
			if(buf[work]!=buf[pre])printf(" %d",work);
			printf("\n");
		}
	}
	return 0;
}
























//for the middle effect
