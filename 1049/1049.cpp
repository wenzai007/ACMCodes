/*
����Ҳ���� ��ô�鷳 ��  ��Ϊ����һ��   ��һ�� ÿһ������
�� ���ٸ�1  Ȼ���ۼ�  ��Ȼ���ַ���һ���ᳬʱ�� 
22/30  ���Ѿ��������ˡ�����
���Ե�	���	��ʱ(ms)	�ڴ�(kB)	�÷�/����
		0	����ȷ	2	380	12/12
		1	����ȷ	2	368	3/3
		2	����ȷ	1	256	3/3
		3	����ȷ	2	256	3/3
		4	���г�ʱ			0/4
		5	����ȷ	1	256	1/1
		6	���г�ʱ			0/4

  ��֦��ô��  ��
*/

#define for if(0); else for 
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
int n;

int numof1(int a){
	int sum=0;
	do{
		if(a%10==1)
			sum++;
		a/=10;
	}
	while(a);
	return sum;
}
int main(){
	freopen("in.txt","r",stdin);   
	while (scanf("%d",&n)!=EOF){
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=numof1(i);
		}
		printf("%d\n",sum);
	}
	return 0;
}

