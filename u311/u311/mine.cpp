//��ʼ��ʱ����ȫû���κ�˼·��
//û���κΰ취������ôֻ�ܿ����˰���a
//̰�Ĳ��� �ȸ��ģ���ĸ����� Ȼ���ٿ�ʼ��С�İ���
//��һ����wa  Ȼ����three����Ĳ��Կ�ʼ�Ķ����������Ķ�
//int three[4][2]={��0,0��,��5,7��,��3,6��,��1,5��};Ȼ��three[0][1]��Ȼ��7 
//�ĳ� {0,0,5,7,3,6,1,5}�Ͷ��� three[0][1] ��Ϊ��0
//Ȼ�� ��С���Ÿĳɴ�����Ҳ�ǶԵ��ˣ�����
//���Լ�סŶ ǧ�����ڶ�ά�����������С����Ŷ �ҷ���ȫ����������ľ�У���

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

int num[7];
int sum;
//int three[4][2]={(0,0),(5,7),(3,6),(1,5)}; 
int three[4][2]={0,0,5,7,3,6,1,5};
//ʮ�ֵ���Ч�ؼ�����if else����� ��һ������˳���ô

//��ȷӦ����(0,0) 0��2 0�� 1 ����
//ֱ�ӵ��´������ļ���Ŷ �ܺõļ���

int main(){
	freopen("in.txt","r",stdin);   
	while(true){
		for(int i=1;i<=6;i++){
			sf("%d",&num[i]);
		}
		bool flag=false;
		for(int i=1;i<=6;i++){
			if(num[i])
				flag=true;
		}
		if(flag==false)
			break;
		sum=0;
		sum+=num[6]+num[5]+num[4]+(num[3]+3)/4;//��ʼ���ܵĸ���
		//���洦��2*2
		int leftfor_2=num[4]*5+three[(num[3]%4)][0];//3��4��5���Ը�2�������
		//���з�������
		if(num[2]<=leftfor_2){
			num[2]-=leftfor_2;
			num[1]-=num[5]*11;
			num[1]-=three[(num[3]%4)][1];
			num[1]-=(0-num[2])*4;//���num[2]����˸���
			if(num[1]>0){
				sum+=(num[1]+35)/36;
			}
		}
		else{
			num[2]-=leftfor_2;
			num[1]-=num[5]*11;
			num[1]-=three[(num[3]%4)][1];
			sum+=(num[2]+8)/9;
			int rem=num[2]%9;
			if(rem!=0)
				num[1]-=(9-rem)*4;
			if(num[1]>0)
				sum+=(num[1]+35)/36;
		}
		pf("%d\n",sum);
	}
	return 0;
}

