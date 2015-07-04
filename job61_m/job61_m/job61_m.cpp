#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
struct bigInteger{
	int digit[1008];//�ܷ�4000λ
	int size;
	void init(){
		for(int i=0;i<1008;i++){
			digit[i]=0;
		}
		size=0;
	}
	void set(int x){
		init();
		do{
			digit[size++]=x%10000;
			x/=10000;
		}
		while(x);
	}
	void output(){
		//for(int i=size-1;i>=0;i++){//���õģ� д++ϰ�����ǲ���
			//�ǲ��ǲ���д�����--��
	    for(int i=size-1;i>=0;i--){
			if(i==size-1)printf("%d",digit[i]);
			else printf("%04d",digit[i]);
		}
		printf("\n");
	}
	//��Ϊ�ǽ׳����Է����Լ�����õ�  ��Ҫ�����·���һ��big��
	//a =a*i; ����֮��Ϳ���д�� a*i;  �Զ����Լ���ֵ�ˣ�
	void operator *(int x){//���ܽ᱾105
		int i,carry;
		//for(i=0,carry=0;i<size;i++){//ȥ��i++
		for(i=0,carry=0;i<size;){
			int tmp=digit[i]*x+carry;
			carry=tmp/10000;
			//digit[size++]=tmp%10000;��Ͳ�����Ҫ����ı�Ļ�
			//��ôӦ�ò���size++ ����i++
			digit[i++]=tmp%10000;
		}
		if(carry!=0) 
			digit[size++]=carry;//��Ϊ������x�����1000���������Ϳ�����
		//����Ļ� Ӧ�ÿ���   λ���ٶ�һЩ
		//���� �����Ҫ�ɵ����������100000 ��ôӦ�ð���Щ��
		//biginteger  ���  ÿ��λһ��ȡ����  
	}
}a;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int value;
	while(scanf("%d",&value)!=EOF){
		a.set(1);
		for(int i=1;i<=value;i++){
			a*i;
		}
		a.output();
	}
	return 0;
}

