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

int book[508];//books

bool cansplit(int n,int m,int x){
	int sum=0;
	int t=0;//  the numbers of  split line 
	for(int i=0;i<n;i++){
		sum+=book[i];
		if(sum>x){
			sum=book[i];
			t++;
			if(t>m-1){
				return false;
			}
		}
	}
	return true;
}//  feel i miss sth...



int main(){
	freopen("in.txt","r",stdin);   
	int cnum,n,m;
	
	while(scanf("%d",&cnum)!=EOF){
		for(int i=0;i<cnum;i++){
			scanf("%d%d",&n,&m);
			for(int j=0;j<n;j++){
				scanf("%d",&book[j]);
			}
			int maxsum=0;
			int maxofthem=0;// �����ֵ��СҲ��������С����������һ����
			for(int j=0;j<n;j++){
				maxsum+=book[j];
				if(book[j]>maxofthem){
					maxofthem=book[j];
				}
			}
			int l=maxofthem;
			int r=maxsum;
			int mid;
			while(l<r){
				mid=(l+r)/2;
				if(cansplit(n,m,mid)){// ˵��mid̫����
					r=mid;//��r���Ե�ʱ�� ��һ����Ҫr=mid-1 ��Ϊl��r�ӽ�
					//��ʱ�򣨵�����ȵ�ʱ��l+1==r��ʱ�� ������е����Ϊl ������Ϊr�����Ե���mid�൱�ڼ���1
					//��������ν������1,����Ҫ���ǵ�l=199������ r=200���Ե�ʱ��  mid=199  ������  Ȼ��
//����˵������Ҫ��һ���ܹ��໥���������Ʋ��еģ�
//ͦ��ѧ�ĵ���һ�δ���  ����Ϊr=mid �������ѭ���� ������ʱ��l��ֵһ����
//����cansplit��l���ģ���  ��Ϊcansplit��mid����ʱ�� r���mid�����ܵ���l
//���Ƴ������cansplit��mid��Ϊ�ٵĻ�����ôl=mid+1 ��ʱ����������Ļ�
//��ô˵��l+1==r   ������ѭ����r��ֵһֱ��cansplit�ģ�����   
				}
				else{
					//l=mid; ����������д ��Ϊl r��mid���ܵ���l
					//���������Էָ��ʱ�� l����Ҫ��������l=l+1
					//�������l =mid ʼ�ղ����� ��ô�ͻ�������ѭ���У�
					//
					l=mid+1;
				}
			}
			//����������
			if(cansplit(n,m,mid)){
				printf("%d\n",mid);
			}
			else{
				printf("%d\n",l);
			}
			//��  ��ʵ����д��ô���ֱ�����l��ֵ�Ͷ���
			//��Ϊ�˳�ѭ��ֻ�����������һ����r=mid Ҳ����r=l �˳�
			//����һ����l=mid+1 �ǵ�l=r�˳� ���ֶ���д��l�Ͷ���
		}
	}
	
	return 0;
}

