#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
bool judge(int x){
	if(x<=1)return false;
	int bound=(int)sqrt((double)x)+1;//��ӵı����μ���
	//	for(int i=2;i<=(int)sqrt((double)x)+1;i++){//���� ��С�� û�е��ڷ���2��3 �ͻ��жϴ��󣡣���������
	for(int i=2;i<bound;i++){
		if(x%i==0) return false;
	}
	return true;
}
int main(){
	int n;
	while (scanf("%d",&n)!=EOF){
		printf(judge(n)?"yes\n":"no\n");
	}
	return 0;
}
