//���Զ������ݷ� ��ȫ����Щ��ĿҪ���������
//������������Ļ��ͻ���������ǳ�ʱ�ģ���
//����һ�ֱ���Ҫ���յļ��ɵģ���
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
const int  mod_value=9973;
int T;
int n,k;
int cross[12];
int map[12][12];
void pow_a(int &a){
	int k_tmp=k;
	int ans=1;
	int tmp=a;
	while (k_tmp){
		if(k_tmp%2==1){
			ans*=tmp;
			ans%=mod_value;
		}
		k_tmp/=2;//��仰֮ǰû�м�  ������ѭ��
		tmp*=tmp;
		tmp%=mod_value;
	}
	a=ans;
}
int main(){
	freopen("in.txt","r",stdin);
	int sum;
	while (scanf("%d",&T)!=EOF&&T){
		while (T--!=0){
			sum=0;
			scanf("%d%d",&n,&k);
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					scanf("%d",&map[i][j]);
				}
				cross[i]=map[i][i];
			}
			for(int i=0;i<n;i++){
				pow_a(cross[i]);
				sum+=cross[i];
				sum%=mod_value;
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}

