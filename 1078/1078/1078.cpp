//1.��ʼ��ʱ��17��  Ȼ���1�����������ж���������
//����һ����  �����20�� ����5��
//2.�ҵ���һ��ԭ��  �����ҵĴ����ͻ�Ĺ����ǲ���ȷ��  ����+1  Ȼ������
//���+4  ��������+1�Ļ����Ͻ���+4  ������ʵ��+1 ��+3
//3 ����  �ǿ���ѭ�����д����  ���ϵ�ѭ�� ֻҪ����ѭ���Ĺ������п�λ�Ϳ��Ե� ֪��j*j�е�j����tsize
//Ϊֹ���������Ծ�����Ҫ%һ��msize
//4 �������������Ĺ���̫��ʱ�� ��ʵ�ӿ�ʼ�ĵط���ʼ�жϡ�
//Ȼ�󲻶ϵĵ�����ʵ���ǿ��Ե���   
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>

#include<stack>
#include<queue>
#include<vector>
#include<map>

#include<time.h>
using namespace std;

const int size =100800;
bool mark[size];
int primes[size];
int id;
void init(){
	for(int i=0;i<size;i++){
		mark[i]=true;
	}
	mark[0]=mark[1]=false;
 	id=0;
	for(int i=2;i<size;i++){
		if(mark[i]==false)
			continue;
		primes[id++]=i;
		if(i>400)
			continue;
		for(int j=i*i;j<size;j+=i){
			mark[j]=false;
		}
	}
}

bool judge(int x){
	int bound=(int)sqrt((double)x)+1;
	//�����һ��
	if(x<=1)return false;
	for(int i=2;i<bound;i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}
//bool flag[10001];//��һ������10000��������10007
bool flag[10010];
int tsize,N;

int main(){
	init();
	freopen("in.txt","r",stdin);
	while(scanf("%d",&tsize)!=EOF){
		scanf("%d",&N);
		while(judge(tsize)==false){
			tsize++;
		}
		/*
		if(judge(tsize)==false){//if it is not prime ,make it prime 
			for(int i=0;i<id;i++){// not a good solution  shoud start 
				// from tsize and plus one by one 
				if(primes[i]>tsize){
					tsize=primes[i];
					break;
				}
			}
		}
		*/
		for(int i=0;i<tsize;i++){
			flag[i]=false;
		}
		int nn;
		for(int i=0;i<N;i++){
			scanf("%d",&nn);
			int pos=nn%tsize;
			if(flag[pos]==false){//attention of the last character no space
				if(i==0){
					printf("%d",pos);
				}
				else {
					printf(" %d",pos);
				}
				flag[pos]=true;
				continue;
			}
			int findit=false;
			for(int j=0;j<tsize;j++){// the j is smaller than the tsize
				pos=(nn%tsize+j*j)%tsize;
				if(flag[pos]==false){
					flag[pos]=true;
					findit=true;
					printf(" %d",pos);
					break;
				}
			}
			if(findit==false){
				printf(" -");
			}
			/*ԭ��������� ���Ƿ������ƶ��Ĳ�����ȫ�Ǵ����
			for(int j=1;pos<tsize&&flag[pos]==true;j++){
				pos+=j*j;
			}
			if(pos>=tsize){
				printf(" -");
			}
			else{
				printf(" %d",pos);
				flag[pos]=true;//��������������
			}
			*/
		}
		printf("\n");
	}
	return 0;
}



