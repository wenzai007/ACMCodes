//1  �õ�18��   ������ 
//ԭ�� ������  ��Ϊû�����������18������񵽴�����ˣ�
//�˼�˵ԭ�������ֺͷ�ת�����ֶ���  �����Ļ� ���ǶԵģ�����
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
int N,D;
const int size =1000008;
bool nums[size];//��һ��

void sift(){
	for(int i=2;i<size;i++){
		nums[i]=true;//
	}
	nums[0]=nums[1]=false;
	for(int i=2;i<size;i++){
		if(nums[i]==false)
			continue;
		//�����ж�
		if(i>2000)continue;
		for(int j=i*i;j<size;j+=i){//��һ��������j�����
			nums[j]=false;
		}
	}
} //ɸ����  ���ô洢��
int  str[20];
int main(){
	freopen("in.txt","r",stdin);
	sift();
	srand(time(0));
	int mm=rand();
	while (scanf("%d%d",&N,&D)!=EOF){
		if(N<0) break;
		int idx=0;
		int ori_N=N;//��ʼ���������� ���ﲹ�ϣ�
		int sum=0;int weigh=1;
		do{
			str[idx++]=N%D;
			N/=D;
		}
		while(N);
		for(int i=idx-1;i>=0;i--){
			sum+=str[i]*weigh;
			weigh*=D;
		}
		//if(nums[sum]==true)//�������
		if(nums[sum]==true&&nums[ori_N]==true)
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

