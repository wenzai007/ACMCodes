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

int list[200];
int n;
int sum;
int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&list[i]);
		}
 		//�ǲ���������2¥  Ȼ��2¥������ ҲҪ������  �Ҿ��Ȱ��ռ������
 		int cur=0;
		sum=0;
		for(int i=0;i<n;i++){
			if(list[i]>cur){
				sum+=(list[i]-cur)*6;
				sum+=5;
				cur=list[i];
				continue;
			}
			if(list[i]<cur){
				sum+=(cur-list[i])*4;
				sum+=5;
				cur=list[i];
				continue;
			}
			sum+=5;//�������Ȼ�Ǳ�����еĻ� ��ô��ͣ5��
		}
		printf("%d\n",sum);
	}
	return 0;
}

