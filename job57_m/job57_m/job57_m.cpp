//ʵ�������� ����ת�� �Լ���������

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
bool binary_seq[12];//��Ϊֻ��1��2
int size;
void trans(int b){
	size=0;
	do{
		binary_seq[size++]=b%2;
		b/=2;
	}
	while (b);
}

int main(){
	freopen("in.txt","r",stdin);
	int a,b;
	while (scanf("%d%d",&a,&b)!=EOF){
		if(a==0&&b==0) break;
		trans(b);
		int sum=1;
		//	for(int i=0;i<=size;i++){//���������˰� <����<=
		for(int i=0;i<size;i++){
			if(binary_seq[i]==1){
				sum*=a;
				sum%=1000;
			}
			a*=a;
			a%=1000;
		}
		printf("%d\n",sum);

	}
	return 0;
	}
