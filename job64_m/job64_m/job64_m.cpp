//��ʵ  ����ʲô�������ıȽϷ���   �洢�ַ����Ϳ�����
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
struct bigInteger{
	char nums[1008];
	bool operator <(const bigInteger &b)const {
		int a_len=strlen(nums);int b_len=strlen(b.nums);
		int idx;
		if (a_len!=b_len)
			return  a_len<b_len;
		else {
			for(idx=0;idx<a_len;idx++){
				if(nums[idx]!=b.nums[idx])  break;
			}
			if(idx!=a_len)
				return nums[idx]<b.nums[idx];
			//���˵�Ķ� �������  ��Ϊ�����ȵĻ�Ӧ�÷���false
			//����˵��ȵĻ�ʲôҲ����   �����Ļ�  ֱ��return ��ô
			//���ܻ᷵��true�� Ҳ˵��׼��
			else return false;
		}
	}
}buf[200];
int N;
int main(){
	freopen ("in.txt","r",stdin);
	while (scanf("%d",&N)!=EOF){
		for(int i=0;i<N;i++){
			scanf("%s", buf[i].nums);
		}
		sort(buf,buf+N);
		for(int i=0;i<N;i++){
			printf("%s\n",buf[i].nums);
		}
	}
	return 0;
}

