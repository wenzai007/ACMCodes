//��Ȼ�� ����� ���� ���������   ��������Ϊ�˹���һ�´����ı���
//  ��ʵֱ��  ���λ  �ͳ˷��Ϳ�����   һλһλ�ĳ˷�  ��Ϊֻ�ǳ���2  ֻҪ��10����d
//�˷��������� һλһλ�ĳ˷�  �������������  Ҫ4λ4λ�Ľ��У���
//4λ���д洢�Ļ� ���ֻ�ܳ���  10000���ڵ�����
#define for if(0);else for
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
const int size=1000;

char instr[80];
char outstr[80];

int hash_in[12];
int hash_out[12];
struct big{
    int nums[size];
	int idx;
	void init(){
		for(int i=0;i<size;i++){
			nums[i]=0;
		}
		idx=0;
	}
	void output(){
		for(int i=idx-1;i>=0;i--){
			if(i==idx-1){
				printf("%d",nums[i]);
			}
			else {
				printf("%04d",nums[i]);
			}
		}
		printf("\n");
	}
	void set( char s[]){
		init();
		int L=strlen(s);
		int c=1,j=0;int sum=0;
		for(int i=L-1;i>=0;i--){
			sum+=(s[i]-'0')*c;
			j++;
			c*=10;
			if(j==4||i==0){
				nums[idx++]=sum;
				c=1;
				j=0;
				sum=0;
			}
		}

	}
	big  operator *(int x)const{//�������ֻ�ܳ���������
		big c;
		c.init();
		int carry=0;
		int sum=0;
		for(int i=0;i<idx;i++){
			sum=nums[i]*x+carry;
			carry=sum/10000;
			sum%=10000;
			c.nums[c.idx++]=sum;
		}
		if(carry!=0){
			c.nums[c.idx++]=carry;
		}
		return c;
	}

};
int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%s",instr)!=EOF){
		big a;
		a.set(instr);
		big b;
		b=a*2;
		for(int i=0;i<12;i++){
			hash_in[i]=0;
			hash_out[i]=0;
		}
		for(int i=0;i<strlen(instr);i++){
			hash_in[instr[i]-'0']++;
		}
		//���鷳�Ķ��� ����2�Ժ�Ľ����λ��⣡����
		int oidx=0;int thenum;
		for(int i=0;i<b.idx;i++){
			thenum=b.nums[i];
			do{
				outstr[oidx++]=thenum%10;
				hash_out[thenum%10]++;
				thenum/=10;
			}
			while(thenum);
		}
		if(oidx!=strlen(instr)){
			printf("No\n");
			b.output();
			continue;
		}
		bool flag=true;
		for(int i=0;i<10;i++){
			if(hash_in[i]!=hash_out[i])
				flag=false;
		}
		if(flag==false){
				printf("No\n");
			b.output();
		}
		else {
			printf("Yes\n");
			b.output();
		}

	}
	return 0;
}

