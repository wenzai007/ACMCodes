//测试 的数据很大 用long long 都不行   得用字符串来存！！
//但是只是第一次的数据很大 每个位想加之后就不大了
//所以  没有必要用数组去存储这个大整数！！！

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
char str[200];
int digit[20];
int findroot(int sum){
	int idx=0;
	if(sum/10==0) return sum;
	//int total=sum;
	while (sum/10!=0){
		do{
			digit[idx++]=sum%10;
			sum/=10;
		}
		while(sum);//此时sum已经是0了
		for(int j=0;j<idx;j++){
			sum+=digit[j];
		}
		idx=0;
	}
	return sum;
}
int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%s",str)!=EOF){
		int sum=0;
		if(str[0]=='0'&&str[1]==0)break;
		for(int i=0;i<strlen(str);i++){
			sum+=str[i]-'0';
		}
		int root=findroot(sum);
		printf("%d\n",root);
	}
	return 0;
}
