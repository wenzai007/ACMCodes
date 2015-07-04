//所以二分求幂法 完全是有些题目要考察的内容
//如过不这样做的话就会溢出或者是超时的！！
//这是一种必须要掌握的技巧的！！
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
		k_tmp/=2;//这句话之前没有加  所以死循环
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

